#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <myinclue.h>

namespace Ui {
class Addfriend;
}

class Addfriend : public QWidget
{
    Q_OBJECT

public:
    explicit Addfriend(QWidget *parent,QString username,QString fname,bool isonlive);
    void SendMsg(int type);
    void closeEvent(QCloseEvent *);
    ~Addfriend();

private:
    Ui::Addfriend *ui;
    QUdpSocket *udpsocket;
    qint16 Myport;
    qint16 ServerPort;
    QString myname;
    QString friendname;
};

#endif // ADDFRIEND_H
