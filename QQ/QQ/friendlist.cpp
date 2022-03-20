#include "friendlist.h"
#include "ui_friendlist.h"

friendlist::friendlist(QWidget *parent,QString username) :
    QWidget(parent),
    ui(new Ui::friendlist)
{
    ui->setupUi(this);

    myname = username;
    //设置图标
    this->setWindowIcon(QIcon(QString(":/image/%1.jpg").arg(myname)));
    //设置名称
    this->setWindowTitle("qq 2020");
    //设置头像行
    ui->toolButton->setIcon(QIcon(QString(":/image/%1.jpg").arg(myname)));
    ui->toolButton->setIconSize(QSize(100,100));
    QFont font("Microsoft YaHei", 10, 75);
    ui->label->setStyleSheet("color:white");
    ui->label->setFont(font);
    ui->label->setText(myname);
    //设置搜索行
    ui->searchline->setFixedSize(QSize(250,30));
    //端口号
    this->port = 5050;
    this->receive_port = 6060;
    this->udpSocket = new QUdpSocket(this);
    //绑定端口
    //采用ShareAddress模式（即允许其他的服务连接到相同的地址和端口）
    //特别是用在多客户端监听同一个服务器端口等待是特别有效
    udpSocket->bind(QHostAddress::Any,port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //监听信号
    connect(udpSocket,&QUdpSocket::readyRead,this,[=](){
             receive_Msg();
            });
    send_Msg(MyInclue::GetFriend);//获取用户好友信息

    //加好友
    connect(ui->addfriend,&QToolButton::clicked,[=](){
        s = new search(nullptr,myname);
        s->show();
    });

    //搜索行
    connect(ui->searchline,&MyLineEdit::clicked,[=](){
        ui->searchline->clear();
        //清楚好友列表
        int num = ui->listWidget->count();
        for(int i = 0;i < num;i++)
        {
            QListWidgetItem *item = ui->listWidget->takeItem(0);
            delete item;
        }
        if(serch_close_btn == false)
        {
            QToolButton *close_btn = new QToolButton();
            serch_close_btn = true;
            ui->horizontalLayout_2->addWidget(close_btn,0,Qt::AlignRight);
            close_btn->setIcon(QIcon(QString(":/image/close.png")));
            close_btn->setIconSize(QSize(50,30));
            //关闭按钮
            connect(close_btn,&QToolButton::clicked,[=](){
                ui->searchline->clear();//清楚搜索行
                //清楚搜索列表
                int num = ui->listWidget->count();
                for(int i = 0;i < num;i++)
                {
                    QListWidgetItem *item = ui->listWidget->takeItem(0);
                    delete item;
                }
                //显示好友列表
                for(auto it = myfriend.begin();it != myfriend.end();it++)
                {
                    Friendlist_line *f = new Friendlist_line(nullptr,it.key(),it.value());
                    myfriendlistline[it.key()] = f;
                    QListWidgetItem *item = new QListWidgetItem();
                    item->setSizeHint(QSize(300,100));
                    ui->listWidget->addItem(item);
                    ui->listWidget->setItemWidget(item,f);
                 }
                serch_close_btn = false;
                delete close_btn;
            });
        }
    });

    //搜索事件
    connect(ui->searchline,&QLineEdit::textEdited,[=](){
        //清楚搜索列表
        int num = ui->listWidget->count();
        for(int i = 0;i < num;i++)
        {
            QListWidgetItem *item = ui->listWidget->takeItem(0);
            delete item;
        }
        search_friend();
    });

    //数据库连接  本地好友和在线状态
    QString path = "F://QTproject//QQchat//QQ//QQ//sql//" + myname + ".dat";
    QFileInfo *fileinfo = new QFileInfo(path);
    //不存在数据库 新建数据库
    if(!fileinfo->exists()){
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
        db.open();
        sql = "CREATE TABLE userinformation ("
              "friendname VARCHAR(40) NOT NULL, "
              "isonlive INTEGER)";
        QSqlQuery query;
        query.exec(sql);
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
        db.open();
    }

    send_Msg(MyInclue::OfflineFile);
}

void friendlist::search_friend()
{
    QString text = ui->searchline->text();
    sql = QString("SELECT * FROM userinformation where friendname like '%1%' ").arg(text);
    QSqlQuery query;
    query.exec(sql);
    if(query.next() == false) return;
    QVector<QString> names;
    QVector<bool> isonlive;
    query.first();
    names.push_back(query.value(0).toString());
    isonlive.push_back(query.value(1).toInt());
    while(query.next() != false)
    {
        names.push_back(query.value(0).toString());
        isonlive.push_back(query.value(1).toInt());
//        qDebug() << query.value(0).toString();
    }
    for(int i = 0;i < names.size();i++)
    {
        Friendlist_line *f = new Friendlist_line(nullptr,names[i],isonlive[i]);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(300,100));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,f);
     }
}

void friendlist::closeEvent(QCloseEvent *)
{
    send_Msg(MyInclue::Exit);
    udpSocket->close();
    udpSocket->destroyed();
}

void friendlist::send_Msg(int type)
{
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    switch(type){
        case MyInclue::GetFriend:
        {
            stream<<type<<myname;
            //书写报文
            udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
        case MyInclue::Exit:
        {
            stream<<type<<myname;
            //书写报文
            udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
        case MyInclue::OfflineFile:
        {
            qDebug() << "OfflineFile";
            stream<<type<<myname;
            //书写报文
            udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->receive_port);
            break;
        }
    }
}

void friendlist::receive_Msg()
{
        qint64 size = udpSocket->pendingDatagramSize();
        int mysize = static_cast<int>(size);
        QByteArray *array = new QByteArray(mysize,0);
        udpSocket->readDatagram((*array).data(),size);
        QDataStream stream(array,QIODevice::ReadOnly);
        QString name;
        stream >> name;
        if(name != myname) return;//不是自己的消息
        int mytype;
        stream >> mytype;
        switch (mytype) {
            case MyInclue::GetFriend:
            {
                if(name == myname)
                {
                    while(!stream.atEnd()){
                        QString name;
                        bool IsOnline;
                        stream >> name >> IsOnline;
                        myfriend[name] = IsOnline;
                        sql = QString("SELECT * FROM userinformation where friendname = '%1' ").arg(name);
                        QSqlQuery query;//无数据 插入
                        query.exec(sql);
                        if(query.next() == false){
                            sql = QString("INSERT INTO userinformation (friendname,isonlive) VALUES ('%1','%2')").arg(name).arg(IsOnline);
                            query.exec(sql);
                        }
                        else
                        {
                            //更新在线状态
                            sql = QString("UPDATE  userinformation  SET isonlive='%1'  WHERE  friendname='%2' ")
                                    .arg(IsOnline).arg(name);
                            QSqlQuery query;
                            query.exec(sql);
                        }
                    }
                    display();
                    break;
                }
            }
            case MyInclue::Updata:
            {
                QString FriendName;
                stream >> FriendName;
                myfriend[FriendName] = true;
                sql = QString("UPDATE  userinformation  SET isonlive=1  WHERE  friendname ='%1' ")
                        .arg(FriendName);
                QSqlQuery query;
                query.exec(sql);
                if(serch_close_btn == false) display();
                else
                {
                    Friendlist_line *f = new Friendlist_line(nullptr,FriendName,true);
                    myfriendlistline[FriendName] = f;
                }
                break;
            }
            case MyInclue::AddFriend:
            {
                QString FriendName,description;
                bool isonlive;
                stream >> FriendName >> isonlive >> description;
                a = new AddFriendReceive(nullptr,myname,FriendName,isonlive,description);
                a->show();
                break;
            }
            case MyInclue::AgreeAddFriend:
            {
                QString FriendName;
                bool isonlive;
                stream >> FriendName >> isonlive;
                myfriend[FriendName] = isonlive;
                sql = QString("INSERT INTO userinformation (friendname,isonlive) VALUES ('%1','%2')").arg(FriendName).arg(isonlive);
                //添加好友行
                Friendlist_line *f = new Friendlist_line(nullptr,FriendName,isonlive);
                myfriendlistline[FriendName] = f;
                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(300,100));
                ui->listWidget->addItem(item);
                ui->listWidget->setItemWidget(item,f);
                //添加聊天窗口事件
                connect(f,&Friendlist_line::mycliked,[=](){
                    if(IsShow[FriendName] == false){
                        IsShow[FriendName] = true;
                        chat *widget = new chat(nullptr,myname,FriendName,false,myfriend[FriendName]);
                        widget->setWindowIcon(QIcon(QString(":/image/%1.jpg").arg(FriendName)));
                        widget->setWindowTitle(FriendName);
                        widget->show();
                        //关闭时将对应的IsShow变为false;
                        connect(widget,&chat::closeWidget,this,[=](){
                            IsShow[FriendName] = false;
                        });
                    }
                });
            }
            case MyInclue::OfflineFile:
            {
                qDebug() << "rOfflineFile";
                bool flag;
                stream >> flag;
                if(flag == false) return;//没有离线文件
                QString friendname;
                stream >> friendname;
                if(IsShow[friendname] == false){
                    IsShow[friendname] = true;
                    qDebug() << QString("发送离线文件");
                    chat *widget = new chat(nullptr,myname,friendname,true,myfriend[friendname]);
                    widget->setWindowIcon(QIcon(QString(":/image/%1.jpg").arg(friendname)));
                    widget->setWindowTitle(friendname);
                    widget->show();
                    //关闭时将对应的IsShow变为false;
                    connect(widget,&chat::closeWidget,this,[=](){
                        IsShow[friendname] = false;
                    });
                }
            }
        }
}

void friendlist::display()
{
        for(auto it = myfriend.begin();it != myfriend.end();it++)
        {
            if(myfriendlistline[it.key()] == nullptr)
            {
                Friendlist_line *f = new Friendlist_line(nullptr,it.key(),it.value());
                myfriendlistline[it.key()] = f;
                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(300,100));
                ui->listWidget->addItem(item);
                ui->listWidget->setItemWidget(item,f);
            }
            else myfriendlistline[it.key()]->change_state(it.value());
         }
         for(auto it = myfriendlistline.begin();it != myfriendlistline.end();it++)
            {
                connect(it.value(),&Friendlist_line::mycliked,[=](){
                    if(IsShow[it.key()] == false){
                        IsShow[it.key()] = true;
                        chat *widget = new chat(nullptr,myname,it.key(),false,myfriend[it.key()]);
                        widget->setWindowIcon(QIcon(QString(":/image/%1.jpg").arg(it.key())));
                        widget->setWindowTitle(it.key());
                        widget->show();
                        //关闭时将对应的IsShow变为false;
                        connect(widget,&chat::closeWidget,this,[=](){
                            IsShow[it.key()] = false;
                        });
                    }
                });
            }
}




friendlist::~friendlist()
{
    delete ui;
}
