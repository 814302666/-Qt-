/********************************************************************************
** Form generated from reading UI file 'friendlist_line.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_LINE_H
#define UI_FRIENDLIST_LINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Friendlist_line
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *icon;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QLabel *state;
    QLabel *label;

    void setupUi(QWidget *Friendlist_line)
    {
        if (Friendlist_line->objectName().isEmpty())
            Friendlist_line->setObjectName(QString::fromUtf8("Friendlist_line"));
        Friendlist_line->resize(350, 100);
        horizontalLayout = new QHBoxLayout(Friendlist_line);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        icon = new QToolButton(Friendlist_line);
        icon->setObjectName(QString::fromUtf8("icon"));

        horizontalLayout->addWidget(icon);

        widget = new QWidget(Friendlist_line);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(widget);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout->addWidget(name);

        state = new QLabel(widget);
        state->setObjectName(QString::fromUtf8("state"));

        verticalLayout->addWidget(state);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        verticalLayout->setStretch(0, 1);

        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(0, 4);

        retranslateUi(Friendlist_line);

        QMetaObject::connectSlotsByName(Friendlist_line);
    } // setupUi

    void retranslateUi(QWidget *Friendlist_line)
    {
        Friendlist_line->setWindowTitle(QApplication::translate("Friendlist_line", "Form", nullptr));
        icon->setText(QApplication::translate("Friendlist_line", "...", nullptr));
        name->setText(QString());
        state->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Friendlist_line: public Ui_Friendlist_line {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_LINE_H
