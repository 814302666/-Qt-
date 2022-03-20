#include "userregister.h"
#include "ui_userregister.h"

UserRegister::UserRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserRegister)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint);
    //窗口背景设为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    //注册按钮颜色设置
//    ui->confirm->setStyleSheet("background-color:blue");
    //按钮提示 最小化和关闭
    ui->minimize->setToolTip("最小化");
    ui->close->setToolTip("关闭");
    //端口初始化
    this->port = 5050;
    this->server_port = 6060;
    //UDP初始化
    this->udpsocket = new QUdpSocket(this);
    udpsocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
//    udpsocket->bind(QHostAddress("192.168.31.105"),port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
//    //监听信号  接收事件
    connect(udpsocket,&QUdpSocket::readyRead,this,[=](){
             ReceiveMsg();
            });
    //注册按钮
    connect(ui->confirm,&QToolButton::clicked,[=](){
        sendMsg(MyInclue::Register);
    });
    //昵称行
    connect(ui->username,&MyLineEdit::clicked,[=](){
        if(ui->username->text() == "昵称") ui->username->clear();
    });
    //密码行
    connect(ui->password,&MyLineEdit::clicked,[=](){
        if(ui->password->text() == "密码") ui->password->clear();
    });
    //重复确认行
    connect(ui->password2,&MyLineEdit::clicked,[=](){
        if(ui->password2->text() == "确认密码") ui->password2->clear();
    });
}

//关闭事件
void UserRegister::closeEvent(QCloseEvent *)
{
    udpsocket->close();
    udpsocket->destroyed();
}

//发送函数
void UserRegister::sendMsg(int type)
{
    QString username = ui->username->text();
    QString pasword = ui->password->text();
    QString pasword2 = ui->password2->text();
    if(username == "")
    {
        QMessageBox::warning(this,"警告","昵称不能为空");
    }
    else if(pasword == "")
    {
       QMessageBox::warning(this,"警告","密码不能为空");
    }
    else if(pasword != pasword2)
    {
        QMessageBox::warning(this,"警告","两次输入密码不一致");
        ui->password->clear();
        ui->password2->clear();
    }
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream << type << username << pasword;
    udpsocket->writeDatagram(array,array.size(),QHostAddress::Broadcast,this->server_port);
}

//接收函数
void UserRegister::ReceiveMsg()
{
    qint64 size = udpsocket->pendingDatagramSize();
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    udpsocket->readDatagram((*array).data(),size);
    QDataStream stream(array,QIODevice::ReadOnly);
    int mytype;
    stream >> mytype;
    switch (mytype) {
    case MyInclue::Register:
    {
       QString state;
       stream >> state;
       if(state == "OK")
       {
           this->close();
       }
       else
       {
           QMessageBox::warning(this,"警告","账户名已注册");
           ui->username->clear();
       }
    }
    }
}

//获取鼠标位置
void UserRegister::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
//        mouse_press = true;
        //求坐标差
        mouse_pos = e->globalPos() - this->frameGeometry().topLeft();
    }
}
//鼠标移动
void UserRegister::mouseMoveEvent(QMouseEvent *e)
{
//    if(e->button() & Qt::LeftButton)
//    {
        //移动到左上角
        this->move(e->globalPos() - mouse_pos);
//    }
}

UserRegister::~UserRegister()
{
    delete ui;
}

void UserRegister::on_minimize_clicked()
{
    showMinimized();
}

void UserRegister::on_close_clicked()
{
    close();
}
