/********************************************************************************
** Form generated from reading UI file 'find_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_UI_H
#define UI_FIND_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_Find_ui
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_6;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    MyLineEdit *lineEdit;
    QListWidget *listWidget;

    void setupUi(QWidget *Find_ui)
    {
        if (Find_ui->objectName().isEmpty())
            Find_ui->setObjectName(QString::fromUtf8("Find_ui"));
        Find_ui->resize(300, 800);
        verticalLayout_4 = new QVBoxLayout(Find_ui);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(Find_ui);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-image:url(:/image/CZBJ.png);\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        toolButton_3 = new QToolButton(frame_2);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setStyleSheet(QString::fromUtf8("QToolButton { \n"
"border-radius:150px; //\345\234\206\350\247\222\345\244\247\345\260\217\n"
"}\n"
""));

        horizontalLayout_3->addWidget(toolButton_3);

        widget_4 = new QWidget(frame_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        verticalSpacer_6 = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);


        horizontalLayout_3->addWidget(widget_4);


        verticalLayout_4->addWidget(frame_2);

        frame_3 = new QFrame(Find_ui);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-image:url(:/image/CZBJ.png);\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit = new MyLineEdit(frame_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout_4->addWidget(frame_3);

        listWidget = new QListWidget(Find_ui);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_4->addWidget(listWidget);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 19);

        retranslateUi(Find_ui);

        QMetaObject::connectSlotsByName(Find_ui);
    } // setupUi

    void retranslateUi(QWidget *Find_ui)
    {
        Find_ui->setWindowTitle(QApplication::translate("Find_ui", "Form", nullptr));
        toolButton_3->setText(QApplication::translate("Find_ui", "...", nullptr));
        label_3->setText(QApplication::translate("Find_ui", "TextLabel", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Find_ui: public Ui_Find_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_UI_H
