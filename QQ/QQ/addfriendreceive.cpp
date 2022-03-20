#include "addfriendreceive.h"
#include "ui_addfriendreceive.h"

AddFriendReceive::AddFriendReceive(QWidget *parent,QString username,QString fname,bool isonlive,QString description) :
    QWidget(parent),
    ui(new Ui::AddFriendReceive)
{
    ui->setupUi(this);
    //设置名称
    this->setWindowTitle("好友申请");
    myname = username;
    friendname = fname;
    QListWidgetItem *item = new QListWidgetItem();
    Friendlist_line *f = new Friendlist_line(nullptr,friendname,isonlive);
    item->setSizeHint(QSize(100,100));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,f);
    ui->label->setText("对方描述");
    ui->label->setStyleSheet("color:red");
    ui->lineEdit->setFixedSize(QSize(300,100));
    ui->lineEdit->setText(description);
    ui->lineEdit->setReadOnly(true);
    ui->toolButton->setFixedSize(QSize(300,100));

    //udp端口设置
    Myport = 5050;
    ServerPort = 6060;
    udpsocket = new QUdpSocket();
    udpsocket->bind(Myport,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    connect(ui->toolButton,&QToolButton::clicked,[=](){
        SendMsg(MyInclue::AgreeAddFriend);
        this->close();
    });

}

void AddFriendReceive::closeEvent(QCloseEvent *)
{
    udpsocket->close();;
    udpsocket->destroyed();
}

void AddFriendReceive::SendMsg(int type)
{
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream << type << myname << friendname;
    udpsocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,ServerPort);
}


AddFriendReceive::~AddFriendReceive()
{
    delete ui;
}
