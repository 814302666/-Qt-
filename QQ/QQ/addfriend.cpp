#include "addfriend.h"
#include "ui_addfriend.h"
#include <friendlist_line.h>
#include <qlistwidget.h>
#include <QListWidgetItem>

Addfriend:: Addfriend(QWidget *parent,QString username,QString fname,bool isonlive) :
    QWidget(parent),
    ui(new Ui::Addfriend)
{
    ui->setupUi(this);
    //设置名称
    this->setWindowTitle("添加好友");
    myname = username;
    friendname = fname;
    QListWidgetItem *item = new QListWidgetItem();
    Friendlist_line *f = new Friendlist_line(nullptr,friendname,isonlive);
    item->setSizeHint(QSize(100,100));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,f);
    ui->label->setText("请输入验证信息");
    ui->label->setStyleSheet("color:red");
    ui->lineEdit->setFixedSize(QSize(300,100));
    ui->toolButton->setFixedSize(QSize(300,100));

    //udp端口设置
    Myport = 5050;
    ServerPort = 6060;
    udpsocket = new QUdpSocket();
    udpsocket->bind(QHostAddress::Any,Myport,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    connect(ui->toolButton,&QToolButton::clicked,[=](){
        SendMsg(MyInclue::AddFriend);
        this->close();
    });

}

void Addfriend::closeEvent(QCloseEvent *)
{
    udpsocket->close();;
    udpsocket->destroyed();
}

void Addfriend::SendMsg(int type)
{
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    QString description = ui->lineEdit->text();
    stream << type << myname << friendname << description;
    udpsocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,ServerPort);
}


Addfriend::~Addfriend()
{
    delete ui;
}
