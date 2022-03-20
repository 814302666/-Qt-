#-------------------------------------------------
#
# Project created by QtCreator 2022-03-05T17:55:22
#
#-------------------------------------------------

QT       += core gui network sql multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQ
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp \
    logo.cpp \
    friendlist.cpp \
    chat.cpp \
    userregister.cpp \
    mylineedit.cpp \
    friendlist_line.cpp \
    search.cpp \
    addfriend.cpp \
    myinclue.cpp \
    addfriendreceive.cpp \
    sendfile.cpp \
    receivefile.cpp \
    test.cpp \
    videochat.cpp \
    voice.cpp

HEADERS  += widget.h \
    logo.h \
    friendlist.h \
    chat.h \
    userregister.h \
    mylineedit.h \
    friendlist_line.h \
    search.h \
    addfriend.h \
    myinclue.h \
    addfriendreceive.h \
    sendfile.h \
    receivefile.h \
    test.h \
    videochat.h \
    voice.h

FORMS    += widget.ui \
    logo.ui \
    friendlist.ui \
    chat.ui \
    userregister.ui \
    friendlist_line.ui \
    search.ui \
    addfriend.ui \
    addfriendreceive.ui \
    sendfile.ui \
    receivefile.ui \
    test.ui \
    videochat.ui \
    voice.ui

RESOURCES += \
    res.qrc
