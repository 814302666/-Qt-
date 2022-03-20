#include "widget.h"
#include <QApplication>
#include <logo.h>
#include <chat.h>
#include <userregister.h>
#include <search.h>
#include <addfriend.h>
#include <addfriendreceive.h>
#include <test.h>
#include <videochat.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    logo start;
    start.show();
//    test b;
//    b.show();
    return a.exec();
}
