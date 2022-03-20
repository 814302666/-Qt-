/********************************************************************************
** Form generated from reading UI file 'addfriendreceive.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDRECEIVE_H
#define UI_ADDFRIENDRECEIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendReceive
{
public:
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QToolButton *toolButton;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *AddFriendReceive)
    {
        if (AddFriendReceive->objectName().isEmpty())
            AddFriendReceive->setObjectName(QStringLiteral("AddFriendReceive"));
        AddFriendReceive->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(AddFriendReceive);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(AddFriendReceive);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(listWidget);

        frame = new QFrame(AddFriendReceive);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame{\n"
"border:sold 10px rgba(0,0,0);\n"
"background-image:url(:/image/JHY.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        toolButton = new QToolButton(widget_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout_2->addWidget(toolButton);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addWidget(widget_2);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);


        verticalLayout_2->addWidget(frame);


        retranslateUi(AddFriendReceive);

        QMetaObject::connectSlotsByName(AddFriendReceive);
    } // setupUi

    void retranslateUi(QWidget *AddFriendReceive)
    {
        AddFriendReceive->setWindowTitle(QApplication::translate("AddFriendReceive", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("AddFriendReceive", "TextLabel", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        toolButton->setText(QApplication::translate("AddFriendReceive", "\345\220\214\346\204\217", Q_NULLPTR));
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddFriendReceive: public Ui_AddFriendReceive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDRECEIVE_H
