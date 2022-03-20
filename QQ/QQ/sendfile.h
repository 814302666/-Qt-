#ifndef SENDFILE_H
#define SENDFILE_H

#include <QWidget>
#include <myinclue.h>

namespace Ui {
class SendFile;
}

class SendFile : public QWidget
{
    Q_OBJECT

public:
    explicit SendFile(QWidget *parent,QString FileName,QString IP,qint16 port);
    ~SendFile();

private slots:
    void startTransfer();  //发送文件大小等信息
    void updateClientProgress(qint64); //发送数据，更新进度条

signals:
    void fileover();

private:
    Ui::SendFile *ui;
    QTcpSocket *tcpClient;
    QFile *localFile;  //要发送的文件
    qint64 totalBytes;  //数据总大小
    qint64 bytesWritten;  //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize;   //每次发送数据的大小
    QString fileName;  //保存文件路径
    QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据
    QString myip;
    qint16 myport;
};

#endif // SENDFILE_H
