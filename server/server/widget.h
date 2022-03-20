#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    enum MsgType{Login,Register,GetFriend,Updata,SendMsg,Exit,
                SearchFriend,AddFriend,AgreeAddFriend,GetFriendIp};//枚举 用户登录  获取好友信息 信息更新
    explicit Widget(QWidget *parent = 0);
    void send_Msg(MsgType type,QDataStream stream);
    void recevid_Msg();
    bool is_Online(QString str);
    bool is_Existence(QString str);
    void add_Friend(QString str1,QString str2);
    QString get_ip(QString user);
    void updata_ip(QString user,QString ip);
    ~Widget();

private:
    Ui::Widget *ui;
    quint16 port;//端口
    quint16 receive_port;//接收端口
    QString uName;//名字
    QUdpSocket *udpSocket;//udp 套接字
    QSqlDatabase db;//数据库
    QString sql;
};

#endif // WIDGET_H
