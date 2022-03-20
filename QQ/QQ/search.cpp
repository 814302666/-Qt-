#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent,QString name) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    //设置名称
    this->setWindowTitle("查找");
    myname = name;
    //设置搜索图标
    ui->seachicon->setIconSize(QSize(80,50));
    ui->seachicon->setToolButtonStyle(Qt::ToolButtonIconOnly);
    ui->seachicon->setAutoRaise(true);
    //设置搜寻框
    ui->searchline->setFixedSize(QSize(180,50));
    //端口初始化
    this->port = 5050;
    this->server_port = 6060;
    //UDP初始化
    this->udpsocket = new QUdpSocket(this);
    udpsocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //监听信号  接收事件
    connect(udpsocket,&QUdpSocket::readyRead,this,[=](){
             receive_Msg();
            });
    //搜索按钮
    connect(ui->seachicon,&QToolButton::clicked,[=](){
        send_Msg(MyInclue::SearchFriend);
    });
//    QListWidgetItem *item = new QListWidgetItem();
//    Friendlist_line *f = new Friendlist_line(nullptr,"xiaoding",true);
//    item->setSizeHint(QSize(300,100));
//    ui->listWidget->addItem(item);
//    ui->listWidget->setItemWidget(item,f);
//    connect(f,&Friendlist_line::mycliked,[=](){
//           a = new Addfriend(nullptr,"xiaowu","xiaoding",true);
//           a->show();
//    });
}

void search::closeEvent(QCloseEvent *)
{
    udpsocket->close();
    udpsocket->destroyed();
}

void search::send_Msg(int type)
{
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    QString username = ui->searchline->text();
    stream << type << myname << username;
    udpsocket->writeDatagram(array,array.size(),QHostAddress::Broadcast,this->server_port);
}

void search::receive_Msg()
{
    qint64 size = udpsocket->pendingDatagramSize();
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    udpsocket->readDatagram((*array).data(),size);
    QDataStream stream(array,QIODevice::ReadOnly);
    int mytype;
    QString name;
    stream >> name >> mytype;
    if(name != myname) return;
    switch (mytype) {
    case MyInclue::SearchFriend:
    {
       QString state;
       stream >> state;
       if(state == "YES")
       {
           QString name;
           bool isonlive;
           stream >> name >> isonlive;
           QListWidgetItem *item = new QListWidgetItem();
           Friendlist_line *f = new Friendlist_line(nullptr,name,isonlive);
           item->setSizeHint(QSize(300,100));
           ui->listWidget->addItem(item);
           ui->listWidget->setItemWidget(item,f);
           connect(f,&Friendlist_line::mycliked,[=](){
                  a = new Addfriend(nullptr,myname,name,isonlive);
                  a->show();
           });
       }
       else
       {
           QMessageBox::warning(this,"警告","用户不存在");
       }
    }
    }
}

search::~search()
{
    delete ui;
}
