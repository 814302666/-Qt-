#ifndef LOGO_H
#define LOGO_H

#include <myinclue.h>
#include <friendlist.h>
#include <userregister.h>

namespace Ui {
class logo;
}

class logo : public QWidget
{
    Q_OBJECT

public:
    explicit logo(QWidget *parent = 0);
    void send_Msg(int type);
    void receive_Msg();
    void user_register();
    void write_user_information(QString key,QString value);
    void read_user_information();
    void closeEvent(QCloseEvent *);//重写关闭事件
    ~logo();

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);

private slots:
    void on_exit_clicked();
    void on_minimize_clicked();

private:
    Ui::logo *ui;
    QPoint mouse_pos;
    quint16 port;//端口
    quint16 receive_port;//服务器端口
    QUdpSocket *udpSocket;//udp 套接字
    friendlist *b;
    UserRegister *r;
    QString myname;
    bool IsRememberPassword;
    bool IsAutoRegister;
};

#endif // LOGO_H
