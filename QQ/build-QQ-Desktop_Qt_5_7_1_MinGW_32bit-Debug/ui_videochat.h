/********************************************************************************
** Form generated from reading UI file 'videochat.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOCHAT_H
#define UI_VIDEOCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoChat
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *myvideo;
    QLabel *friendvideo;
    QWidget *widget_2;
    QToolButton *toolButton;

    void setupUi(QWidget *VideoChat)
    {
        if (VideoChat->objectName().isEmpty())
            VideoChat->setObjectName(QStringLiteral("VideoChat"));
        VideoChat->resize(800, 700);
        verticalLayout = new QVBoxLayout(VideoChat);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(VideoChat);
        widget->setObjectName(QStringLiteral("widget"));
        myvideo = new QLabel(widget);
        myvideo->setObjectName(QStringLiteral("myvideo"));
        myvideo->setGeometry(QRect(11, 11, 386, 661));
        friendvideo = new QLabel(widget);
        friendvideo->setObjectName(QStringLiteral("friendvideo"));
        friendvideo->setGeometry(QRect(404, 11, 385, 661));

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(VideoChat);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        toolButton = new QToolButton(widget_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(276, 0, 161, 61));
        toolButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/GD.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        verticalLayout->addWidget(widget_2);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        retranslateUi(VideoChat);

        QMetaObject::connectSlotsByName(VideoChat);
    } // setupUi

    void retranslateUi(QWidget *VideoChat)
    {
        VideoChat->setWindowTitle(QApplication::translate("VideoChat", "Form", Q_NULLPTR));
        myvideo->setText(QString());
        friendvideo->setText(QString());
        toolButton->setText(QApplication::translate("VideoChat", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoChat: public Ui_VideoChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOCHAT_H
