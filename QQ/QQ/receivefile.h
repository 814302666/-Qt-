#ifndef RECEIVEFILE_H
#define RECEIVEFILE_H

#include <QWidget>
#include <myinclue.h>

namespace Ui {
class ReceiveFile;
}

class ReceiveFile : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveFile(QWidget *parent,QString ip,qint16 port,QString name);
    ~ReceiveFile();


private slots:
    void acceptConnection();  //建立连接
    void updateServerProgress();  //更新进度条，接收数据

signals:
    void fileover();

private:
    Ui::ReceiveFile *ui;
    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
    qint64 totalBytes;  //存放总大小信息
    qint64 bytesReceived;  //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息
    QString fileName;   //存放文件名
    QFile *localFile;   //本地文件
    QByteArray inBlock;   //数据缓冲区
    QString myip;
    qint16 myport;
    QString myname;
};

#endif // RECEIVEFILE_H
