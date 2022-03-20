#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTime>
#include <QDataStream>
#include <QColorDialog>
#include <QFileDialog>


Widget::Widget(QWidget *parent,QString name) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    myname = name;

    this->port = 9999;
    this->udpSocket = new QUdpSocket(this);
    //绑定端口
    //采用ShareAddress模式（即允许其他的服务连接到相同的地址和端口）
    //特别是用在多客户端监听同一个服务器端口等待是特别有效
    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //监听信号
    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::ReceiveMessage);
    //连接发送按钮
    connect(ui->sendBtn,&QPushButton::clicked,[=](){
        sendMsg(Msg);
    });
    //新用户进入
    sendMsg(UserEnter);

    connect(ui->exitBtn,&QPushButton::clicked,[=](){
        this->close();
    });
    //颜色
    connect(ui->fontCbx,&QFontComboBox::currentFontChanged,[=](const QFont &font){
        ui->msgTxtEdit->setFontFamily(font.toString());
        ui->msgTxtEdit->setFocus();
    });
    //颜色选择框
    connect(ui->colorBtn,&QToolButton::clicked,[=](){
       QColor color = QColorDialog::getColor(color,this);
       ui->msgTxtEdit->setTextColor(color);
    });
    //尺寸
    void (QComboBox:: *sizebtn)(const QString &text) = &QComboBox::currentIndexChanged;
    connect(ui->sizeBox,sizebtn,[=](const QString &text){
        ui->msgTxtEdit->setFontPointSize(text.toDouble());
        ui->msgTxtEdit->setFocus();
    });
    //加粗
    connect(ui->boldBtn,&QToolButton::clicked,[=](bool checked){
        if(checked)
        {
            ui->msgTxtEdit->setFontWeight(QFont::Bold);
        }
        else
        {
            ui->msgTxtEdit->setFontWeight(QFont::Normal);
        }
    });
    //倾斜
    connect(ui->italicTbtn,&QToolButton::clicked,[=](bool checked){
        ui->msgTxtEdit->setFontItalic(checked);
        ui->msgTxtEdit->setFocus();
    });
    //下划线
    connect(ui->underlineTbtn,&QToolButton::clicked,[=](bool checked){
        ui->msgTxtEdit->setFontUnderline(checked);
        ui->msgTxtEdit->setFocus();
    });
    //清空
    connect(ui->clearBtn,&QToolButton::clicked,[=](){
        ui->msgBrowser->clear();
    });
    //保存
    connect(ui->saveBtn,&QToolButton::clicked,[=](){
        if(ui->msgBrowser->toPlainText().isEmpty())
        {
            QMessageBox::warning(this,"警告","警告:保存内容不能为空!");
            return;
        }
        QString filename = QFileDialog::getSaveFileName(this,"保存聊天记录","聊天记录","(*.txt)");
        if(!filename.isEmpty())
        {
            QFile file(filename);
            file.open(QIODevice::WriteOnly | QFile::Text);
            QTextStream stream(&file);
            stream<<ui->msgBrowser->toPlainText();
            file.close();
        }
    });

}

void Widget::closeEvent(QCloseEvent *){
    emit this->closeWidget();//发送信号
    sendMsg(UserLeft);
    udpSocket->close();
    udpSocket->destroyed();
}

//获取名字
QString Widget::getName()
{
    return this->myname;
}

//获取聊天信息
QString Widget::getMsg()
{
    QString msg = ui->msgTxtEdit->toHtml();//返回输入框内容
    ui->msgTxtEdit->clear();//将内容清空
    ui->msgTxtEdit->setFocus();//设置光标
    return msg;
}

//发送广播信息
void Widget::sendMsg(Widget::MsgType type)
{
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);

    stream<<type<<this->getName();

    switch (type) {
    case Msg:
        if(ui->msgTxtEdit->toPlainText() == "")
        {
            QMessageBox::warning(this,"警告","发送的聊天内容不能为空!");
            return;
        }
        stream<<this->getMsg();
        break;
    case UserEnter:
        break;
    case UserLeft:
        break;
    default:
        break;
    }
    //书写报文
    udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port);
}

void Widget::ReceiveMessage()
{
    qint64 size = udpSocket->pendingDatagramSize();
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    udpSocket->readDatagram((*array).data(),size);
    QDataStream stream(array,QIODevice::ReadOnly);
    int mytype;
    stream>>mytype;
    QString name,msg;//用户名 聊天内容
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    switch (mytype) {
    case Msg:
        stream>>name>>msg;
        ui->msgBrowser->setTextColor(QColor(Qt::blue));
        ui->msgBrowser->append("[" + name + "]" + time);
        ui->msgBrowser->append(msg);
        break;
    case UserLeft:
        stream>>name;
        userLeft(name,time);
        break;
    case UserEnter:
        stream>>name;
        userEnter(name);
        break;
    default:
        break;
    }
}

void Widget::userEnter(QString username)
{
    bool IsEmpty = ui->usrTblWidget->findItems(username,Qt::MatchExactly).isEmpty();
    if(IsEmpty)
    {
        QTableWidgetItem *table = new QTableWidgetItem(username);
        ui->usrTblWidget->insertRow(0);
        ui->usrTblWidget->setItem(0,0,table);

        ui->msgBrowser->setTextColor(QColor(Qt::gray));
        ui->msgBrowser->append(username + "已上线");
        ui->userNumLbl->setText(QString("在线人数:%1").arg(ui->usrTblWidget->rowCount()));
        sendMsg(UserEnter);//相当于所有人都发送进入
    }
}

void Widget::userLeft(QString username,QString time)
{
    bool IsEmpty = ui->usrTblWidget->findItems(username,Qt::MatchExactly).isEmpty();
    if(!IsEmpty)
    {
        int row = ui->usrTblWidget->findItems(username,Qt::MatchExactly).first()->row();
        ui->usrTblWidget->removeRow(row);
        ui->msgBrowser->append(QString("%1用户于%2离开").arg(username).arg(time));
        ui->userNumLbl->setText(QString("在线人数:%1").arg(ui->usrTblWidget->rowCount()));

    }
}

Widget::~Widget()
{
    delete ui;
}
