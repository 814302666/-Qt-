/********************************************************************************
** Form generated from reading UI file 'friendlist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_H
#define UI_FRIENDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_friendlist
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    MyLineEdit *searchline;
    QListWidget *listWidget;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QToolButton *addfriend;

    void setupUi(QWidget *friendlist)
    {
        if (friendlist->objectName().isEmpty())
            friendlist->setObjectName(QStringLiteral("friendlist"));
        friendlist->resize(300, 800);
        verticalLayout_2 = new QVBoxLayout(friendlist);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(friendlist);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QLatin1String("QFrame {\n"
"background-image:url(:/image/CZBJ.png);\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(frame_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton { \n"
"border-radius:150px; //\345\234\206\350\247\222\345\244\247\345\260\217\n"
"}\n"
""));

        horizontalLayout->addWidget(toolButton);

        widget_2 = new QWidget(frame_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget_2);


        verticalLayout_2->addWidget(frame_2);

        frame_3 = new QFrame(friendlist);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setStyleSheet(QLatin1String("QFrame {\n"
"background-image:url(:/image/CZBJ.png);\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        searchline = new MyLineEdit(frame_3);
        searchline->setObjectName(QStringLiteral("searchline"));

        horizontalLayout_2->addWidget(searchline);


        verticalLayout_2->addWidget(frame_3);

        listWidget = new QListWidget(friendlist);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        frame = new QFrame(friendlist);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addfriend = new QToolButton(frame);
        addfriend->setObjectName(QStringLiteral("addfriend"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/jhys.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        addfriend->setIcon(icon);
        addfriend->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(addfriend);


        verticalLayout_2->addWidget(frame);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 17);
        verticalLayout_2->setStretch(3, 2);

        retranslateUi(friendlist);

        QMetaObject::connectSlotsByName(friendlist);
    } // setupUi

    void retranslateUi(QWidget *friendlist)
    {
        friendlist->setWindowTitle(QApplication::translate("friendlist", "Form", Q_NULLPTR));
        toolButton->setText(QApplication::translate("friendlist", "...", Q_NULLPTR));
        label->setText(QApplication::translate("friendlist", "TextLabel", Q_NULLPTR));
        searchline->setText(QApplication::translate("friendlist", "\346\220\234\347\264\242", Q_NULLPTR));
        addfriend->setText(QApplication::translate("friendlist", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class friendlist: public Ui_friendlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_H
