#ifndef USERREGISTER_H
#define USERREGISTER_H

#include <myinclue.h>

namespace Ui {
class UserRegister;
}

class UserRegister : public QWidget
{
    Q_OBJECT

public:
    explicit UserRegister(QWidget *parent = 0);
    void sendMsg(int type);
    void ReceiveMsg();
    void closeEvent(QCloseEvent *);//关闭事件重写
    ~UserRegister();

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);

private slots:
    void on_minimize_clicked();
    void on_close_clicked();

private:
    Ui::UserRegister *ui;
    QUdpSocket *udpsocket;//udp套接字
    qint16 port;//本机端口
    qint16 server_port;//服务器端口
    QPoint mouse_pos;//鼠标位置
};

#endif // USERREGISTER_H
