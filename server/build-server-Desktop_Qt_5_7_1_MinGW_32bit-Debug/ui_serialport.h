/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serialport
{
public:

    void setupUi(QWidget *Serialport)
    {
        if (Serialport->objectName().isEmpty())
            Serialport->setObjectName(QStringLiteral("Serialport"));
        Serialport->resize(800, 700);

        retranslateUi(Serialport);

        QMetaObject::connectSlotsByName(Serialport);
    } // setupUi

    void retranslateUi(QWidget *Serialport)
    {
        Serialport->setWindowTitle(QApplication::translate("Serialport", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Serialport: public Ui_Serialport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
