#include "widget.h"
#include "ui_widget.h"
#include <QHash>
#include <QDebug>
#include <QHostAddress>
#include <QThread>

QHash<QString,QString> user_information;
QHash<QString,QVector<QString>> user_friend;
QHash<QString,bool> user_isonline;//用户是否在线
void user_Init(){
    user_information.insert("xiaoding","111");
    user_information.insert("xiaowu","222");
    user_information.insert("xiaopang","333");
    user_information.insert("xiaohu","444");
    user_information.insert("xiaozhu","555");
    user_friend.insert("xiaoding",{"xiaowu","xiaopang","xiaohu","xiaozhu"});
    user_friend.insert("xiaowu",{"xiaoding","xiaopang"});
    user_friend.insert("xiaopang",{"xiaoding","xiaowu","xiaozhu"});
    user_friend.insert("xiaohu", {"xiaoding","xiaozhu"});
    user_friend.insert("xiaozhu",{"xiaoding","xiaopang","xiaohu"});
    user_isonline.insert("xiaoding",false);
    user_isonline.insert("xiaowu",false);
    user_isonline.insert("xiaopang",false);
    user_isonline.insert("xiaohu",false);
    user_isonline.insert("xiaozhu",false);
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    user_Init();
    this->port = 6060;
    this->receive_port = 5050;
    this->udpSocket = new QUdpSocket(this);
    //绑定端口
    //采用ShareAddress模式（即允许其他的服务连接到相同的地址和端口）
    //特别是用在多客户端监听同一个服务器端口等待是特别有效
//    udpSocket->bind(QHostAddress::AnyIPv6, port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //监听信号
    connect(udpSocket,&QUdpSocket::readyRead,this,[=](){
        recevid_Msg();
    });
    //连接数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("F://QTproject//QQchat//server//server//user.dat");
    db.open();

}


//接收信息
void Widget::recevid_Msg()
{
    qint64 size = udpSocket->pendingDatagramSize();
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    QHostAddress ip;
    udpSocket->readDatagram((*array).data(),size,&ip);
//    QHostAddress *ip = Q_NULLPTR;//ip
//    udpSocket->readDatagram((*array).data(),size,ip);
    QDataStream stream(array,QIODevice::ReadOnly);
    int mytype;
    stream >> mytype;
    qDebug()<<mytype;
    QByteArray sendarray,sendarray2;
    QDataStream send_stream(&sendarray,QIODevice::ReadWrite);
    QDataStream send_stream2(&sendarray2,QIODevice::ReadWrite);
    //QDataStream send_stream(&sendarray,QIODevice::WriteOnly);
    switch (mytype)
    {
        case Register:
        {
            QString user_name,user_passport;
            stream >> user_name >> user_passport;
            QString Message = "FALSE";
            sql = QString("SELECT * FROM user where username = '%1' ")//查询
                    .arg(user_name);
            QSqlQuery query;
            query.exec(sql);
            if(query.next() == false)
            {
                sql = QString("INSERT INTO user (username, password,ip) VALUES ('%1', '%2',%3)")//插入
                        .arg(user_name).arg(user_passport).arg(ip.toString());
                QSqlQuery query;
                query.exec(sql);
                Message = "OK";
            }
            else Message = "FALSE";
            QByteArray RegisterArray;
            QDataStream RegisterStream(&RegisterArray,QIODevice::WriteOnly);
            RegisterStream << Message;
            udpSocket->writeDatagram(RegisterArray.data(),RegisterArray.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
        case Login:
        {
            qDebug()<<"login";
            QString user_name,user_passport;
            stream >> user_name >> user_passport;
            QString Message;
            sql = QString("SELECT * FROM user where username = '%1' and password = '%2' ")
                    .arg(user_name).arg(user_passport);
            QSqlQuery query;
            query.exec(sql);
            if(query.next() != false)
            {
                if(query.value(2)==1)
                {
                    QByteArray UpdataArray;
                    QDataStream UpdataStream(&UpdataArray,QIODevice::WriteOnly);
                    QString state = "USERISONLINE";
                    UpdataStream <<Login<< state;
                    udpSocket->writeDatagram(UpdataArray.data(),UpdataArray.size(),QHostAddress::Broadcast,this->receive_port);
                    return ;
                }
                Message = "OK";
                //更新数据库
                sql = QString("UPDATE  user  SET isonline=1  WHERE  username='%1' ")//更新
                        .arg(user_name);
                query.exec(sql);
                qDebug()<<ip.toString();
                updata_ip(user_name,ip.toString().mid(7));

                //向其好友发送更新
                sql = QString("SELECT * FROM user where username = '%1' ")
                        .arg(user_name);
                query.exec(sql);
                while(query.next()){
                    QString friendList = query.value(3).toString();
                    QStringList list = friendList.split(",");//QString字符串分割函数
                    for(auto it = list.begin();it != list.end();it++)
                        {
                            qDebug()<<"login"<<*it;
                            QByteArray UpdataArray;
                            QDataStream UpdataStream(&UpdataArray,QIODevice::WriteOnly);
                            UpdataStream << *it << Updata << user_name;
                            udpSocket->writeDatagram(UpdataArray.data(),UpdataArray.size(),QHostAddress::Broadcast,this->receive_port);

                    }
                }
            }
            else Message = "FALSE";
            send_stream << mytype << Message; 
            qDebug()<<udpSocket->writeDatagram(sendarray.data(),sendarray.size(),QHostAddress::Broadcast,this->receive_port);
//            qDebug()<<udpSocket->writeDatagram(sendarray.data(),sendarray.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
        case GetFriend:
        {
            qDebug()<<"getfriend";
            QString user_name;
            stream >> user_name;
            send_stream << user_name << mytype;
            sql = QString("SELECT * FROM user where username = '%1' ")
                    .arg(user_name);
            QSqlQuery query;
            query.exec(sql);
            QStringList list;
            while(query.next()){
                QString friendList = query.value(3).toString();
                list = friendList.split(",");//QString字符串分割函数
                }
            for(auto it = list.begin();it != list.end();it++){
                sql = QString("SELECT * FROM user where username = '%1' ")
                        .arg(*it);
                query.exec(sql);
                while(query.next()){
                    qDebug()<<"get friend"<<*it;
                    bool isOnline = query.value(2)==0?false:true;
                    send_stream << *it << isOnline;
                }

            }
            qDebug()<<udpSocket->writeDatagram(sendarray.data(),sendarray.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
        case Exit:
        {
            qDebug()<<"exit";
            QString user_name;
            stream >> user_name;
            sql = QString("UPDATE  user  SET isonline=0  WHERE  username='%1' ")
                    .arg(user_name);
            QSqlQuery query;
            query.exec(sql);
            break;
        }
        case SearchFriend:
        {
            qDebug()<<"SearchFriend";
            QString user_name,user_name2;
            stream >> user_name >> user_name2;
            bool isOnline = false;
            QString isFind = is_Existence(user_name2)==1?"YES":"NO";
            if(isFind=="YES")
            {
                isOnline = is_Online(user_name2);
            }
            send_stream<<user_name<<mytype<<isFind<<user_name2<<isOnline;
            udpSocket->writeDatagram(sendarray.data(),sendarray.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
        case AddFriend:
        {
            qDebug()<<"AddFriend";
            QString user_name,user_name2,message;
            stream >> user_name >> user_name2 >> message;
            bool isOnline = is_Online(user_name);
            send_stream << user_name2 << mytype << user_name << isOnline << message;
            udpSocket->writeDatagram(sendarray.data(),sendarray.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
        case AgreeAddFriend:
        {
            qDebug()<<"AgreeAddFriend";
            QString user_name, user_name2;
            stream >> user_name >> user_name2;
            add_Friend(user_name,user_name2);
            add_Friend(user_name2,user_name);
            bool isOnline = is_Online(user_name2);
            send_stream << user_name << mytype << user_name2 << isOnline ;
            udpSocket->writeDatagram(sendarray.data(),sendarray.size(),QHostAddress::Broadcast,this->receive_port);
            isOnline = is_Online(user_name);
            send_stream2 << user_name2 << mytype << user_name << isOnline ;
            udpSocket->writeDatagram(sendarray2.data(),sendarray2.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
        case GetFriendIp:
        {
            qDebug()<<"GetFriendIp";
            QString user_name, user_name2,ip1;
            stream >> user_name >> user_name2;
            ip1 = get_ip(user_name2);
            send_stream  << mytype << user_name<< user_name2 << ip1 ;
            udpSocket->writeDatagram(sendarray.data(),sendarray.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
    }
}

bool Widget::is_Online(QString str)
{
    bool isOnline = false;
    sql = QString("SELECT * FROM user where username = '%1' ")
        .arg(str);
    QSqlQuery query;
    query.exec(sql);
    while(query.next()!=false){
        isOnline = query.value(2)==0?false:true;
    }
    return isOnline;
}

bool Widget::is_Existence(QString str)
{
    bool isExistence = false;
    sql = QString("SELECT * FROM user where username = '%1' ")
        .arg(str);
    QSqlQuery query;
    query.exec(sql);
    if(query.next()!=false){
        isExistence = true;
    }
    return isExistence;
}

void Widget::add_Friend(QString str1, QString str2)
{
    //str2 添加到 str1 的好友列表
    sql = QString("SELECT * FROM user where username = '%1' ")
        .arg(str1);
    QSqlQuery query;
    query.exec(sql);
    QString friendList;
    while(query.next()){
        friendList = query.value(3).toString();
    }
    if(friendList!="")
    {
        friendList = friendList + "," + str2;
    }
    else
    {
        friendList = str2;
    }

    sql = QString("UPDATE  user  SET friends='%1'  WHERE  username='%2' ")
            .arg(friendList).arg(str1);
    query.exec(sql);
}

QString Widget::get_ip(QString user)
{
    QString ip;
    sql = QString("SELECT * FROM user where username = '%1' ").arg(user);
    QSqlQuery query;
    query.exec(sql);
    while(query.next()){
        ip = query.value(5).toString();
    }
    return ip;
}

void Widget::updata_ip(QString user, QString ip)
{
    sql = QString("UPDATE  user  SET ip='%1'  WHERE  username='%2' ")
            .arg(ip).arg(user);
    QSqlQuery query;
    query.exec(sql);
}


Widget::~Widget()
{
    db.close();
    delete ui;
}
