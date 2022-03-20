/********************************************************************************
** Form generated from reading UI file 'logo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGO_H
#define UI_LOGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logo
{
public:
    QFrame *Qframe;
    QLineEdit *username;
    QLineEdit *password;
    QCheckBox *remember;
    QPushButton *log_in;
    QToolButton *minimize;
    QToolButton *exit;
    QToolButton *Register;
    QCheckBox *autoregister;

    void setupUi(QWidget *logo)
    {
        if (logo->objectName().isEmpty())
            logo->setObjectName(QStringLiteral("logo"));
        logo->resize(600, 480);
        logo->setStyleSheet(QLatin1String("QFrame{\n"
"border:sold 10px rgba(0,0,0);\n"
"background-image:url(:/image/BJ.png);\n"
"}"));
        Qframe = new QFrame(logo);
        Qframe->setObjectName(QStringLiteral("Qframe"));
        Qframe->setGeometry(QRect(-20, 0, 641, 500));
        Qframe->setStyleSheet(QLatin1String("QFrame{\n"
"border:sold 10px rgba(0,0,0);\n"
"background-image:url(:/image/BJ.png);\n"
"}\n"
"QLineEdit{\n"
"color:#8d98a1;\n"
"background-color:#405361;\n"
"font-size:16px;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QPushButton{\n"
"background:#ced1d8;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgb(224,0,0);\n"
"border-style:inset;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QCheckBox{\n"
"background:rgba(85,170,255,0);\n"
"color:white;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QLabel{\n"
"background:rgba(85,170,255,0);\n"
"color:white;\n"
"font-style:MingLiU-ExtB;\n"
"font-size:14px;\n"
"}"));
        Qframe->setFrameShape(QFrame::StyledPanel);
        Qframe->setFrameShadow(QFrame::Raised);
        username = new QLineEdit(Qframe);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(140, 80, 341, 71));
        password = new QLineEdit(Qframe);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(140, 200, 341, 71));
        remember = new QCheckBox(Qframe);
        remember->setObjectName(QStringLiteral("remember"));
        remember->setGeometry(QRect(160, 300, 91, 19));
        log_in = new QPushButton(Qframe);
        log_in->setObjectName(QStringLiteral("log_in"));
        log_in->setGeometry(QRect(140, 350, 341, 61));
        minimize = new QToolButton(Qframe);
        minimize->setObjectName(QStringLiteral("minimize"));
        minimize->setGeometry(QRect(530, 20, 31, 21));
        exit = new QToolButton(Qframe);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(570, 20, 31, 21));
        Register = new QToolButton(Qframe);
        Register->setObjectName(QStringLiteral("Register"));
        Register->setGeometry(QRect(50, 440, 71, 21));
        autoregister = new QCheckBox(Qframe);
        autoregister->setObjectName(QStringLiteral("autoregister"));
        autoregister->setGeometry(QRect(270, 300, 91, 19));

        retranslateUi(logo);

        QMetaObject::connectSlotsByName(logo);
    } // setupUi

    void retranslateUi(QWidget *logo)
    {
        logo->setWindowTitle(QApplication::translate("logo", "Form", Q_NULLPTR));
        username->setText(QString());
        password->setText(QString());
        remember->setText(QApplication::translate("logo", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        log_in->setText(QApplication::translate("logo", "\347\231\273\345\275\225", Q_NULLPTR));
        minimize->setText(QApplication::translate("logo", "-", Q_NULLPTR));
        exit->setText(QApplication::translate("logo", "X", Q_NULLPTR));
        Register->setText(QApplication::translate("logo", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
        autoregister->setText(QApplication::translate("logo", "\350\207\252\345\212\250\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class logo: public Ui_logo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGO_H
