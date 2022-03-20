/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_search
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *searchline;
    QToolButton *seachicon;
    QLabel *label_2;
    QListWidget *listWidget;

    void setupUi(QWidget *search)
    {
        if (search->objectName().isEmpty())
            search->setObjectName(QString::fromUtf8("search"));
        search->resize(300, 600);
        search->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(search);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(search);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:sold 10px rgba(0,0,0);\n"
"background-image:url(:/image/CZBJ.png);\n"
"}"));
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        searchline = new QLineEdit(frame);
        searchline->setObjectName(QString::fromUtf8("searchline"));

        horizontalLayout->addWidget(searchline);

        seachicon = new QToolButton(frame);
        seachicon->setObjectName(QString::fromUtf8("seachicon"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/CZTB.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        seachicon->setIcon(icon);

        horizontalLayout->addWidget(seachicon);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 10);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 2);

        verticalLayout->addWidget(frame);

        listWidget = new QListWidget(search);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);

        retranslateUi(search);

        QMetaObject::connectSlotsByName(search);
    } // setupUi

    void retranslateUi(QWidget *search)
    {
        search->setWindowTitle(QApplication::translate("search", "Form", nullptr));
        label->setText(QString());
        seachicon->setText(QApplication::translate("search", "...", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class search: public Ui_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
