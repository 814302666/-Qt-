#include "receivefile.h"
#include "ui_receivefile.h"

ReceiveFile::ReceiveFile(QWidget *parent,QString ip,qint16 port,QString name) :
    QWidget(parent),
    ui(new Ui::ReceiveFile)
{
    ui->setupUi(this);
    ui->toolButton->setIconSize(QSize(50,50));
    myname = name;
    myip = ip;
    myport = port;
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    bytesReceived =0;
    if(!tcpServer.listen(QHostAddress(myip),myport))
    {
        qDebug() << tcpServer.errorString();
        close();
        return;
    }
}

void ReceiveFile::acceptConnection()  //接受连接
{
    tcpServerConnection = new QTcpSocket;
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    qDebug("连接成功");
    tcpServer.close();
}

void ReceiveFile::updateServerProgress()  //更新进度条，接收数据
{
    qDebug("连sss");
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);

    if(bytesReceived <= sizeof(qint64)*2)
    { //如果接收到的数据小于16个字节，那么是刚开始接收数据，我们保存到//来的头文件信息

        if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2)&& (fileNameSize == 0))
        { //接收数据总大小信息和文件名大小信息
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64) * 2;
        }

        if((tcpServerConnection->bytesAvailable() >= fileNameSize)
                && (fileNameSize != 0))
        {  //接收文件名，并建立文件
            QString name;
            in >> name;
            fileName = "F://QTproject//QQchat//file//" + myname + "//" + name;
            bytesReceived += fileNameSize;
            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "open file error!";
                return;
            }
        }

        else return;
    }
    if(bytesReceived < totalBytes)
    {  //如果接收的数据小于总数据，那么写入文件
        bytesReceived += tcpServerConnection->bytesAvailable();
        inBlock = tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesReceived);
    //更新进度条
    if(bytesReceived == totalBytes)
    { //接收数据完成时
        tcpServerConnection->close();
        localFile->close();
        emit fileover();
    }
}

ReceiveFile::~ReceiveFile()
{
    delete ui;
}
