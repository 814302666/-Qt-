/********************************************************************************
** Form generated from reading UI file 'voice.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOICE_H
#define UI_VOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_voice
{
public:
    QToolButton *closebtn;
    QToolButton *headbtn;

    void setupUi(QWidget *voice)
    {
        if (voice->objectName().isEmpty())
            voice->setObjectName(QStringLiteral("voice"));
        voice->resize(400, 700);
        closebtn = new QToolButton(voice);
        closebtn->setObjectName(QStringLiteral("closebtn"));
        closebtn->setGeometry(QRect(170, 440, 27, 26));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/GD.png"), QSize(), QIcon::Normal, QIcon::Off);
        closebtn->setIcon(icon);
        headbtn = new QToolButton(voice);
        headbtn->setObjectName(QStringLiteral("headbtn"));
        headbtn->setGeometry(QRect(170, 200, 47, 21));

        retranslateUi(voice);

        QMetaObject::connectSlotsByName(voice);
    } // setupUi

    void retranslateUi(QWidget *voice)
    {
        voice->setWindowTitle(QApplication::translate("voice", "Form", Q_NULLPTR));
        closebtn->setText(QApplication::translate("voice", "...", Q_NULLPTR));
        headbtn->setText(QApplication::translate("voice", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class voice: public Ui_voice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOICE_H
