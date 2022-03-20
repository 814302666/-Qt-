#include "logo.h"
#include "ui_logo.h"



logo::logo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logo)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint);
    //窗口背景设为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    //按钮提示 最小化和关闭
    ui->minimize->setToolTip("最小化");
    ui->exit->setToolTip("关闭");
    //注册按钮设置
    ui->Register->setAutoRaise(true);//背景透明
    ui->Register->setStyleSheet("color:white");//字体白色
    //端口号
    this->port = 5050;
    this->receive_port = 6060;
    this->udpSocket = new QUdpSocket(this);
    //绑定端口
    //采用ShareAddress模式（即允许其他的服务连接到相同的地址和端口）
    //特别是用在多客户端监听同一个服务器端口等待是特别有效
    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
//    udpSocket->bind(port);
    //监听信号
    connect(udpSocket,&QUdpSocket::readyRead,this,[=](){
             receive_Msg();
            });
    //读取ini文件  账户 记住密码 自动登录
    read_user_information();
    //登录
    connect(ui->log_in,&QPushButton::clicked,[=](){
        send_Msg(MyInclue::Login);
    });
    //注册
    connect(ui->Register,&QToolButton::clicked,[=](){
       user_register();
    });
    //记住密码
    connect(ui->remember,&QCheckBox::clicked,[=](){
        if(ui->remember->isChecked() == true) IsRememberPassword = true;
        else
        {
            IsRememberPassword = false;
            IsAutoRegister = false;
            ui->autoregister->setChecked(false);
        }
    });
    //自动登录
    connect(ui->autoregister,&QCheckBox::clicked,[=](){
       if(ui->autoregister->isChecked() == true) {
           IsAutoRegister = true;
           IsRememberPassword = true;
           ui->remember->setChecked(true);
       }
       else IsAutoRegister = false;
    });
}

//窗口关闭事件
void logo::closeEvent(QCloseEvent *)
{
    udpSocket->close();
    udpSocket->destroyed();
}

//用户注册
void logo::user_register()
{
    r = new UserRegister();
    r->show();
}

//向ini文件读取信息
void logo::read_user_information()
{
    QString path = "user_information.ini";

    //创建配置文件操作对象
    QSettings *config = new QSettings(path, QSettings::IniFormat);

    //读取配置信息
    QString username = config->value(QString("config/") + "username").toString();
    QString password = config->value(QString("config/") + "password").toString();
    QString isremember = config->value(QString("config/") + "isremember").toString();
    QString isautoregister = config->value(QString("config/") + "isautoregeister").toString();
    ui->username->setText(username);
    ui->password->setText(password);
    if(isautoregister == "YES")
    {
        send_Msg(MyInclue::Login);
        IsAutoRegister = true;
        ui->autoregister->setChecked(true);
    }
    else
    {
        IsAutoRegister = false;
        ui->autoregister->setChecked(false);
    }
    if(isremember == "YES")
    {
        IsRememberPassword = true;
        ui->remember->setChecked(true);
    }
    else
    {
        IsRememberPassword = false;
        ui->remember->setChecked(false);
    }
    delete config;
}

//向ini文件写入信息
void logo::write_user_information(QString key,QString value)
{
    QString path = "user_information.ini";

    //创建配置文件操作对象
    QSettings *config = new QSettings(path, QSettings::IniFormat);

    //将信息写入配置文件
    config->beginGroup("config");
    config->setValue(key, value);
    config->endGroup();
    delete config;
}

//发送信息
void logo::send_Msg(int type)
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    myname = username;
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream<<type<<username<<password;
    //书写报文
    udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->receive_port);
//    udpSocket->writeDatagram(array.data(),array.size(),QHostAddress("192.168.43.31"),this->receive_port);
}

//接收信号
void logo::receive_Msg()
{
    qint64 size = udpSocket->pendingDatagramSize();
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    udpSocket->readDatagram((*array).data(),size);
    QDataStream stream(array,QIODevice::ReadOnly);
    int mytype;
    stream >> mytype;
    QString state;
    stream >> state;
    if(mytype == MyInclue::Login)
    {
        if(state == "OK")
        {
            QString username = ui->username->text();
            QString password = ui->password->text();
            //记录账号 密码 记住密码 自动登录
            if(IsRememberPassword == true)
            {
                write_user_information("username",username);
                write_user_information("password",password);
                write_user_information("isremember","YES");
            }
            else
            {
                password = "";
                write_user_information("username",username);
                write_user_information("password",password);
                write_user_information("isremember","NO");
            }
            if(IsAutoRegister == true) write_user_information("isautoregeister","YES");
            else write_user_information("isautoregeister","NO");
            //进入主界面
            friendlist *b = new friendlist(nullptr,myname);
            b->show();
            this->close();
        }
        else if(state == "FALSE")
        {
            QMessageBox::warning(this,"警告","密码错误");
        }
        else if(state == "USERISONLINE")
        {
            QMessageBox::warning(this,"警告","用户已经登录");
        }
    }
}

//获取鼠标位置
void logo::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
//        mouse_press = true;
        //求坐标差
        mouse_pos = e->globalPos() - this->frameGeometry().topLeft();
    }
}
//鼠标移动
void logo::mouseMoveEvent(QMouseEvent *e)
{
//    if(e->button() & Qt::LeftButton)
//    {
        //移动到左上角
        this->move(e->globalPos() - mouse_pos);
//    }
}


void logo::on_exit_clicked()
{
    close();
}

void logo::on_minimize_clicked()
{
    showMinimized();
}

logo::~logo()
{
    delete ui;
}
