#ifndef SEARCH_H
#define SEARCH_H

#include <myinclue.h>
#include <addfriend.h>
#include <friendlist_line.h>

namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QWidget *parent,QString name);
    void send_Msg(int type);
    void receive_Msg();
    void closeEvent(QCloseEvent *);
    ~search();


private:
    Ui::search *ui;
    QUdpSocket *udpsocket;
    qint16 port;
    qint16 server_port;
    Addfriend *a;
    QString myname;
};

#endif // SEARCH_H
