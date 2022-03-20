/********************************************************************************
** Form generated from reading UI file 'userregister.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREGISTER_H
#define UI_USERREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_UserRegister
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    MyLineEdit *username;
    MyLineEdit *password;
    MyLineEdit *password2;
    QToolButton *confirm;
    QToolButton *minimize;
    QToolButton *close;

    void setupUi(QWidget *UserRegister)
    {
        if (UserRegister->objectName().isEmpty())
            UserRegister->setObjectName(QStringLiteral("UserRegister"));
        UserRegister->resize(400, 680);
        UserRegister->setStyleSheet(QLatin1String("QFrame{\n"
"border:sold 10px rgba(0,0,0);\n"
"background-image:url(:/image/zcbj.jpg);\n"
"}\n"
"QLineEdit{\n"
"color:#8d98a1;\n"
"background-color:#405361;\n"
"font-size:16px;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QToolButton{\n"
"background:#ced1d8;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(UserRegister);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(UserRegister);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        username = new MyLineEdit(frame);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(80, 120, 251, 61));
        password = new MyLineEdit(frame);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(80, 230, 251, 61));
        password2 = new MyLineEdit(frame);
        password2->setObjectName(QStringLiteral("password2"));
        password2->setGeometry(QRect(80, 340, 251, 61));
        confirm = new QToolButton(frame);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(80, 450, 251, 71));
        confirm->setIconSize(QSize(20, 20));
        minimize = new QToolButton(frame);
        minimize->setObjectName(QStringLiteral("minimize"));
        minimize->setGeometry(QRect(310, 10, 31, 21));
        close = new QToolButton(frame);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(350, 10, 31, 21));

        horizontalLayout->addWidget(frame);


        retranslateUi(UserRegister);

        QMetaObject::connectSlotsByName(UserRegister);
    } // setupUi

    void retranslateUi(QWidget *UserRegister)
    {
        UserRegister->setWindowTitle(QApplication::translate("UserRegister", "Form", Q_NULLPTR));
        username->setText(QApplication::translate("UserRegister", "\346\230\265\347\247\260", Q_NULLPTR));
        password->setText(QApplication::translate("UserRegister", "\345\257\206\347\240\201", Q_NULLPTR));
        password2->setText(QApplication::translate("UserRegister", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        confirm->setText(QApplication::translate("UserRegister", "\347\241\256\350\256\244\346\263\250\345\206\214", Q_NULLPTR));
        minimize->setText(QApplication::translate("UserRegister", "-", Q_NULLPTR));
        close->setText(QApplication::translate("UserRegister", "X", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserRegister: public Ui_UserRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREGISTER_H
