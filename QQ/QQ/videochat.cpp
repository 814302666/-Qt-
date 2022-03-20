#include "videochat.h"
#include "ui_videochat.h"

VideoChat::VideoChat(QWidget *parent,QString FriendIp,int mode) :
    QWidget(parent),
    ui(new Ui::VideoChat)
{
    ui->setupUi(this);
    friendip = FriendIp;

    camera=new QCamera;//摄像头
    imageCapture=new QCameraImageCapture(camera);//截图部件

    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start(); //启动摄像头

    //定时器设置
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        imageCapture->capture();
    });
    timer->start(1000);//50ms  20帧

    IsTcpConnect = false;
    if(mode == 1)  //发送者监听
    {
        tcpServer = new QTcpServer(this);
        qDebug("Yes");
        connect(tcpServer,&QTcpServer::newConnection,this,[=](){
            IsTcpConnect = true;
            tcpsocket = new QTcpSocket();
            tcpsocket = tcpServer->nextPendingConnection();
            connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(process_data()));
            qDebug("连接成功");
            tcpServer->close();
        });
        if(!tcpServer->listen(QHostAddress(friendip),9090))
        {
            qDebug() << tcpServer->errorString();
        }

    }
    else if(mode == 2)//接收者连接
    {
        //tcp 设置
        tcpsocket = new QTcpSocket();
        connect(tcpsocket,&QTcpSocket::connected,this,[=](){
            qDebug()<<"连接成功";
            IsTcpConnect = true;
        });
        //当连接服务器成功时，发出connected()信号，我们开始传送文件
        tcpsocket->connectToHost(QHostAddress(friendip),9090);//连接
        connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(process_data()));
    }

    connect(this,&VideoChat::image_process_done,[=](){
        qDebug() << "over";
        QImage image = getImage(resultStr);
        ui->friendvideo->setPixmap(QPixmap::fromImage(image.scaled(ui->friendvideo->size())));
        ui->friendvideo->setScaledContents(true);
    });
    //关闭按钮
    ui->toolButton->setAutoRaise(true);
    ui->toolButton->setIconSize(QSize(200,100));
    connect(ui->toolButton,&QToolButton::clicked,[=](){
       tcpsocket->close();
       emit close_sig();
    });
}

void VideoChat::closeEvent(QCloseEvent *)
{
    tcpsocket->close();
    camera->stop();
}

QImage VideoChat::getImage(QString &data)
{
    QByteArray imageData = QByteArray::fromBase64(data.toLatin1());
    QImage image;
    image.loadFromData(imageData);
    return image;
}

void VideoChat::process_data()
{
    QByteArray bufData = tcpsocket->readAll();
//    qDebug() << bufData;
    qDebug() << "process_data";
    if(bufData.contains("@")&(!bufData.contains("#")))
    {
      pastData.clear();
      pastData.append(bufData);
    }
    //无头无尾中部数据 直接追加
    if((!bufData.contains("@"))&(!bufData.contains("#"))&(!pastData.isEmpty()))
    {
      pastData.append(bufData);
    }
    //无头有尾 如果数据之前不为空则继续追加 已经读取完成 清空变量
    if((!bufData.contains("@"))&bufData.contains("#")&(!pastData.isEmpty()))
    {
      pastData.append(bufData);
      resultStr = tr(pastData);
      pastData.clear();

    }
    //有头有尾 清空之前数据直接追加
    if(bufData.contains("@")&bufData.contains("#"))
    {
      pastData.clear();
      pastData.append(bufData);
      resultStr = tr(pastData);
      pastData.clear();
    }
    if(!resultStr.isEmpty())
    {
       resultStr.remove("@");
       resultStr.remove("#");
       qDebug() << "done";
       emit image_process_done();
//       qDebug()<<resultStr.toUtf8();
       resultStr.clear();
    }
}

void VideoChat::displayImage(int,QImage image)
{
    image=image.convertToFormat(QImage::Format_RGB888);
    ui->myvideo->setScaledContents(true);
    ui->myvideo->setPixmap(QPixmap::fromImage(image.scaled(ui->myvideo->size())));
    QByteArray resultData;
    QByteArray imageData = getImageData(image);
    resultData.append("@").append(imageData).append("#");
    if(IsTcpConnect)
    {
        qint64 num = tcpsocket->write(resultData);
        if(num == -1) {
            tcpsocket->close();
            emit close_sig();//tcp关闭连接  发送不成功
        }
    }

}

QByteArray VideoChat::getImageData(QImage &image)
{
    QByteArray imageData;
    QBuffer buffer(&imageData);
    image.save(&buffer, "jpg");
    imageData = imageData.toBase64();
    return imageData;
}

VideoChat::~VideoChat()
{
    camera->stop();
    delete ui;
}
