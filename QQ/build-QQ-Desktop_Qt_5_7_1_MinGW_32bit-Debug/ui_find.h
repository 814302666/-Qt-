/********************************************************************************
** Form generated from reading UI file 'find.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_H
#define UI_FIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_find
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *find)
    {
        if (find->objectName().isEmpty())
            find->setObjectName(QStringLiteral("find"));
        find->resize(350, 50);
        horizontalLayout = new QHBoxLayout(find);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(find);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout->addWidget(toolButton);

        lineEdit = new QLineEdit(find);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(find);

        QMetaObject::connectSlotsByName(find);
    } // setupUi

    void retranslateUi(QWidget *find)
    {
        find->setWindowTitle(QApplication::translate("find", "Form", Q_NULLPTR));
        toolButton->setText(QApplication::translate("find", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class find: public Ui_find {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_H
