#ifndef ADDFRIENDRECEIVE_H
#define ADDFRIENDRECEIVE_H

#include <QWidget>
#include <myinclue.h>
#include <friendlist_line.h>

namespace Ui {
class AddFriendReceive;
}

class AddFriendReceive : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriendReceive(QWidget *parent,QString username,QString fname,bool isonlive,QString description);
    void SendMsg(int type);
    void closeEvent(QCloseEvent *);
    ~AddFriendReceive();

private:
    Ui::AddFriendReceive *ui;
    QUdpSocket *udpsocket;
    qint16 Myport;
    qint16 ServerPort;
    QString myname;
    QString friendname;
};

#endif // ADDFRIENDRECEIVE_H
