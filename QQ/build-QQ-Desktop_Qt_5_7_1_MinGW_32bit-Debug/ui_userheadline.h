/********************************************************************************
** Form generated from reading UI file 'userheadline.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERHEADLINE_H
#define UI_USERHEADLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserHeadLine
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *UserHeadLine)
    {
        if (UserHeadLine->objectName().isEmpty())
            UserHeadLine->setObjectName(QStringLiteral("UserHeadLine"));
        UserHeadLine->resize(350, 100);
        UserHeadLine->setStyleSheet(QString::fromUtf8("QToolButton { \n"
"border-radius:150px; //\345\234\206\350\247\222\345\244\247\345\260\217\n"
"}\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(UserHeadLine);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(UserHeadLine);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame {\n"
"background-image:url(:/image/CZBJ.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton { \n"
"border-radius:150px; //\345\234\206\350\247\222\345\244\247\345\260\217\n"
"}\n"
""));

        horizontalLayout->addWidget(toolButton);

        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget);


        verticalLayout_2->addWidget(frame);


        retranslateUi(UserHeadLine);

        QMetaObject::connectSlotsByName(UserHeadLine);
    } // setupUi

    void retranslateUi(QWidget *UserHeadLine)
    {
        UserHeadLine->setWindowTitle(QApplication::translate("UserHeadLine", "Form", Q_NULLPTR));
        toolButton->setText(QApplication::translate("UserHeadLine", "...", Q_NULLPTR));
        label->setText(QApplication::translate("UserHeadLine", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserHeadLine: public Ui_UserHeadLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERHEADLINE_H
