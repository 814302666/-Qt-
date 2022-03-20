#ifndef VIDEOCHAT_H
#define VIDEOCHAT_H

#include <QWidget>
#include <myinclue.h>

namespace Ui {
class VideoChat;
}

class VideoChat : public QWidget
{
    Q_OBJECT

public:
    explicit VideoChat(QWidget *parent,QString FriendIp,int mode);
    ~VideoChat();
    QByteArray getImageData(QImage &image);
    QImage getImage(QString &data);
    void closeEvent(QCloseEvent *);

public slots:
    void displayImage(int,QImage image);
    void process_data();

signals:
    void image_process_done();
    void close_sig();

private:
    Ui::VideoChat *ui;
    QCamera *camera;//摄像头
    QCameraViewfinder * viewfinder;//摄像头取景器部件
    QCameraImageCapture * imageCapture;//截图部件
    bool IsTcpConnect;//tcp是否连接
    QTimer *timer;//定时器
    QTcpSocket *tcpClient;//发送者
    QString friendip;
    //接受者
    QTcpServer *tcpServer;
    QTcpSocket *tcpServerConnection;
    QByteArray receive_data;
    QByteArray pastData;
    QString resultStr;
    QTcpSocket *tcpsocket;
};

#endif // VIDEOCHAT_H
