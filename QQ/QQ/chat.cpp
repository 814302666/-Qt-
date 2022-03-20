#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent,QString name,QString fname,bool isofflinefile,bool isonline) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    myname = name;
    friendname = fname;
    this->port = 5050;
    this->ServerPort = 6060;
    this->TcpPort = 7070;
    this->udpSocket = new QUdpSocket(this);
    IsOfflineFile = isofflinefile;//离线文件
    isfriendonline = isonline;//朋友是否在线
    myip = "192.168.43.48";
    qDebug() << isonline;
    //udp设置
    //采用ShareAddress模式（即允许其他的服务连接到相同的地址和端口）
    //特别是用在多客户端监听同一个服务器端口等待是特别有效
    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
//    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    //监听信号
    connect(udpSocket,&QUdpSocket::readyRead,this,&chat::ReceiveMessage);
    //连接发送按钮
    connect(ui->sendBtn,&QPushButton::clicked,[=](){
        sendMsg(MyInclue::SendMsg);
    });

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
    //发送文件
    connect(ui->sendfileBtn,&QToolButton::clicked,[=](){
        FileName = QFileDialog::getOpenFileName(this);
        qDebug()<<FileName;
        sendMsg(MyInclue::SendFile);
    });
    //获取好友IP地址
    sendMsg(MyInclue::GetFriendIp);
    //存在离线文件
    if(IsOfflineFile)
    {
        IsOfflineFile = false;
        qDebug() << QString("建立tcp连接");
        rf = new ReceiveFile(nullptr,"192.168.43.48",7070,myname);
        ui->filevlayout->addWidget(rf,0,Qt::AlignTop);
        connect(rf,&ReceiveFile::fileover,[=](){
            delete rf;
        });
        sendMsg(MyInclue::OfflineFileListen);
    }
    //视频聊天
    connect(ui->videobtn,&QToolButton::clicked,[=](){
        qDebug() <<"VideoChat";
        sendMsg(MyInclue::VideoChat);
        v = new VideoChat(nullptr,myip,1);//发起者模式
        v->show();
        vc = new voice(nullptr,myname,friendname);//音频聊天
        connect(v,&VideoChat::close_sig,[=](){
            delete v;
            delete vc;
        });
    });
    //音频聊天
    connect(ui->voicebtn,&QToolButton::clicked,[=](){
        qDebug() << "音频聊天";
        vc = new voice(nullptr,myname,friendname);
        connect(vc,&voice::close_sig,[=](){
            delete vc;
        });
        sendMsg(MyInclue::VoiceChat);
    });
}

void chat::sendMsg(int type)
{
    switch (type) {
    case MyInclue::SendMsg:
    {
        QByteArray array;
        QDataStream stream(&array,QIODevice::WriteOnly);
        stream << type << friendname << myname;
        if(ui->msgTxtEdit->toPlainText() == "")
        {
            QMessageBox::warning(this,"警告","发送的聊天内容不能为空!");
            return;
        }
        QString message = ui->msgTxtEdit->toHtml();
        stream << message;
        ui->msgTxtEdit->clear();
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        //对话框列表
        QListWidgetItem *item = new QListWidgetItem();//每一行
        ui->msgBrowser->addItem(item);
        item->setSizeHint(QSize(80,80));//行的尺寸
        QToolButton *bin = new QToolButton(this);//头像图标 按钮
        bin->setAutoRaise(true);//按钮边缘设置透明
        bin->setIcon(QPixmap(QString(":/image/%1.jpg").arg(myname)));
        bin->setIconSize(QSize(80,80));//图标尺寸
        QLabel *label = new QLabel(message);//聊天内容
        QHBoxLayout *hlayout = new QHBoxLayout();//水平布局
        hlayout->addWidget(label);
        hlayout->addWidget(bin);
        hlayout->setAlignment(Qt::AlignRight);
        QWidget *widget = new QWidget();
        widget->setLayout(hlayout);//将布局添加至widget中
        ui->msgBrowser->setItemWidget(item,widget);//将widget加入至listwidget中
        udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port);
        break;
    }
    case MyInclue::GetFriendIp:
    {
        QByteArray array;
        QDataStream stream(&array,QIODevice::WriteOnly);
        stream << type << myname << friendname;
        udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->ServerPort);
        break;
    }
    case MyInclue::SendFile:
    {
        QByteArray array;
        QDataStream stream(&array,QIODevice::WriteOnly);
        stream << type << friendname << myname;
        qDebug() << friendname;
        qDebug() << myname;
        if(isfriendonline) udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port);
        else udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->ServerPort);
        qDebug() << "SendFile";
        break;
    }
    case MyInclue::StartListen:
    {
        QByteArray array;
        QDataStream stream(&array,QIODevice::WriteOnly);
        stream << type << friendname << myname;
        udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port);
        break;
    }
    case MyInclue::OfflineFileListen:
    {
        QByteArray array;
        QDataStream stream(&array,QIODevice::WriteOnly);
        qDebug() << "OfflineFileListen";
        stream << type << friendname << myname;
        udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->ServerPort);
        break;
    }
    case MyInclue::VideoChat:
    {
        QByteArray array;
        QDataStream stream(&array,QIODevice::WriteOnly);
        qDebug() << "VideoChat";
        stream << type << friendname << myname;
        udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port);
        break;
    }
    case MyInclue::VoiceChat:
    {
        QByteArray array;
        QDataStream stream(&array,QIODevice::WriteOnly);
        stream << type << friendname << myname;
        udpSocket->writeDatagram(array.data(),array.size(),QHostAddress::Broadcast,this->port);
        break;
    }
    }
}

void chat::ReceiveMessage()
{
    qint64 size = udpSocket->pendingDatagramSize();
    int mysize = static_cast<int>(size);
    QByteArray *array = new QByteArray(mysize,0);
    udpSocket->readDatagram((*array).data(),size);
    QDataStream stream(array,QIODevice::ReadOnly);
    int mytype;
    stream >> mytype;
    QString name,fname;
    stream >> name >> fname;
    if(name != myname || fname != friendname) return;//不是xx发给我的消息
    switch (mytype) {
    case MyInclue::SendMsg:
    {
        QString text;
        stream >> text;
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        //对话框列表
        QListWidgetItem *item = new QListWidgetItem();//每一行
        ui->msgBrowser->addItem(item);
        item->setSizeHint(QSize(80,80));//行的尺寸
        QToolButton *bin = new QToolButton(this);//头像图标 按钮
        bin->setAutoRaise(true);//按钮边缘设置透明
        bin->setIcon(QPixmap(QString(":/image/%1.jpg").arg(friendname)));
        bin->setIconSize(QSize(80,80));//图标尺寸
        QLabel *label = new QLabel(text);//聊天内容
        QHBoxLayout *hlayout = new QHBoxLayout();//水平布局
        hlayout->addWidget(bin);
        hlayout->addWidget(label);
        hlayout->setAlignment(Qt::AlignLeft);
        QWidget *widget = new QWidget();
        widget->setLayout(hlayout);//将布局添加至widget中
        ui->msgBrowser->setItemWidget(item,widget);//将widget加入至listwidget中
        break;
    }
    case MyInclue::GetFriendIp:
    {
        stream >> FriendIp;
        break;
    }
    case MyInclue::SendFile:
    {
        rf = new ReceiveFile(nullptr,FriendIp,7070,myname);
        ui->filevlayout->addWidget(rf,0,Qt::AlignTop);
        connect(rf,&ReceiveFile::fileover,[=](){
            delete rf;
        });
        sendMsg(MyInclue::StartListen);
        break;
    }
    case MyInclue::StartListen:
    {
        sf = new SendFile(nullptr,FileName,FriendIp,7070);
        ui->filevlayout->addWidget(sf,0,Qt::AlignTop);
        connect(sf,&SendFile::fileover,[=](){
            delete sf;
        });
        break;
    }
    case MyInclue::OfflineFileListen:
    {
        qDebug() << "rOfflineFileListen";
        sf = new SendFile(nullptr,FileName,"192.168.43.31",7070);//好友不在线 发给服务器
        ui->filevlayout->addWidget(sf,0,Qt::AlignTop);
        connect(sf,&SendFile::fileover,[=](){
            delete sf;
        });
        break;
    }
    case MyInclue::VideoChat:
    {
        qDebug() << "rVideoChat";
        v = new VideoChat(nullptr,FriendIp,2);
        v->show();
        vc = new voice(nullptr,myname,friendname);
        connect(v,&VideoChat::close_sig,[=](){
            delete vc;
            delete v;
        });
    }
    case MyInclue::VoiceChat:
    {
        qDebug() << "rVoiceChat";
        vc = new voice(nullptr,myname,friendname);
        vc->show();
        connect(vc,&voice::close_sig,[=](){
            delete vc;
        });
    }
    }
}


void chat::closeEvent(QCloseEvent *)
{
    emit closeWidget();
    udpSocket->close();
    udpSocket->destroyed();
}

chat::~chat()
{
    delete ui;
}
