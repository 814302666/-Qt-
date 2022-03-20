#ifndef CHAT_H
#define CHAT_H

#include <myinclue.h>
#include <sendfile.h>
#include <receivefile.h>
#include <videochat.h>
#include <voice.h>

namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent,QString name,QString fname,bool isofflinefile,bool isonline);
    QString getName();//获取名字
    QString getMsg();//获取聊天信息
    void sendMsg(int type);//发送消息
    void ReceiveMessage();//接受UDP的消息
    void closeEvent(QCloseEvent *);//重写关闭事件
    ~chat();

signals:
    void closeWidget();

private:
    Ui::chat *ui;
    QString friendname;
    QString myname;
    quint16 port;//端口
    quint16 ServerPort;//服务器端口
    quint16 TcpPort;//文件传输端口
    QString uName;//名字
    QUdpSocket *udpSocket;//udp 套接字
    QString FriendIp;//朋友IP地址
    QString myip;//我的ip
    SendFile *sf;
    ReceiveFile *rf;
    QString FileName;//文件名
    bool IsOfflineFile;//是否有离线文件
    bool isfriendonline;//朋友是否在线
    VideoChat *v;//视频聊天窗口
    voice *vc;//语音聊天

};

#endif // CHAT_H
