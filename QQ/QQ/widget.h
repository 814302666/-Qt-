#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    enum MsgType{Msg,UserEnter,UserLeft};//枚举 分别代表 普通用户 用户进入 用户离开
    explicit Widget(QWidget *parent,QString name);
    //重写关闭事件
    void closeEvent(QCloseEvent *);
    void sendMsg(MsgType type);//广播udp信息
    QString getName();//获取名字
    QString getMsg();//获取聊天信息
    void userEnter(QString username);//处理用户进入
    void userLeft(QString username,QString time);//处理用户离开
    void ReceiveMessage();//接受UDP的消息
    ~Widget();

signals:
    void closeWidget();

private:
    Ui::Widget *ui;
    QString myname;
    quint16 port;//端口
    QString uName;//名字
    QUdpSocket *udpSocket;//udp 套接字
};

#endif // WIDGET_H
