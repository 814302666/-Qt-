#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <myinclue.h>
#include <friendlist_line.h>
#include <search.h>
#include <chat.h>
#include <friendlist_line.h>
#include <addfriendreceive.h>

namespace Ui {
class friendlist;
}

class friendlist : public QWidget
{
    Q_OBJECT

public:
    explicit friendlist(QWidget *parent,QString username);
    void send_Msg(int type);
    void receive_Msg();
    void display();
    void closeEvent(QCloseEvent *);//重写关闭事件
    void search_friend();//搜索好友
    ~friendlist();

private:
    Ui::friendlist *ui;
    quint16 port;//端口
    quint16 receive_port;//服务器端口
    QUdpSocket *udpSocket;//udp 套接字
    QHash<QString,bool> myfriend;//用户好友登录状态
    QHash<QString,Friendlist_line*> myfriendlistline;
    QHash<QString,bool> IsShow;//聊天窗口打开
    QString myname;
    search *s;//查找好友
    AddFriendReceive *a;//加好友
    QSqlDatabase db;//数据库
    QString sql;//数据库查询语句
    bool serch_close_btn = false;//搜索行关闭按钮
};

#endif // FRIENDLIST_H
