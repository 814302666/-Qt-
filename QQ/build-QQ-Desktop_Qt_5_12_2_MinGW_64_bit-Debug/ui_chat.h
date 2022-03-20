/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QListWidget *msgBrowser;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QFontComboBox *fontCbx;
    QComboBox *sizeBox;
    QToolButton *boldBtn;
    QToolButton *italicTbtn;
    QToolButton *underlineTbtn;
    QToolButton *colorBtn;
    QToolButton *sendfileBtn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *msgTxtEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitBtn;
    QWidget *FIle;
    QVBoxLayout *filevlayout;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;

    void setupUi(QWidget *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QString::fromUtf8("chat"));
        chat->resize(800, 600);
        verticalLayout_6 = new QVBoxLayout(chat);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_8 = new QWidget(chat);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_8);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        msgBrowser = new QListWidget(widget);
        msgBrowser->setObjectName(QString::fromUtf8("msgBrowser"));

        verticalLayout_3->addWidget(msgBrowser);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        fontCbx = new QFontComboBox(frame_2);
        fontCbx->setObjectName(QString::fromUtf8("fontCbx"));

        horizontalLayout_2->addWidget(fontCbx);

        sizeBox = new QComboBox(frame_2);
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->addItem(QString());
        sizeBox->setObjectName(QString::fromUtf8("sizeBox"));

        horizontalLayout_2->addWidget(sizeBox);

        boldBtn = new QToolButton(frame_2);
        boldBtn->setObjectName(QString::fromUtf8("boldBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/JC.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldBtn->setIcon(icon);
        boldBtn->setCheckable(true);

        horizontalLayout_2->addWidget(boldBtn);

        italicTbtn = new QToolButton(frame_2);
        italicTbtn->setObjectName(QString::fromUtf8("italicTbtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/qx.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicTbtn->setIcon(icon1);
        italicTbtn->setCheckable(true);

        horizontalLayout_2->addWidget(italicTbtn);

        underlineTbtn = new QToolButton(frame_2);
        underlineTbtn->setObjectName(QString::fromUtf8("underlineTbtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/`HJ8@K[456G`KN_9@DOB7WC.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineTbtn->setIcon(icon2);
        underlineTbtn->setCheckable(true);

        horizontalLayout_2->addWidget(underlineTbtn);

        colorBtn = new QToolButton(frame_2);
        colorBtn->setObjectName(QString::fromUtf8("colorBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorBtn->setIcon(icon3);

        horizontalLayout_2->addWidget(colorBtn);

        sendfileBtn = new QToolButton(frame_2);
        sendfileBtn->setObjectName(QString::fromUtf8("sendfileBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendfileBtn->setIcon(icon4);

        horizontalLayout_2->addWidget(sendfileBtn);


        verticalLayout->addWidget(frame_2);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        msgTxtEdit = new QTextEdit(widget_3);
        msgTxtEdit->setObjectName(QString::fromUtf8("msgTxtEdit"));

        horizontalLayout_3->addWidget(msgTxtEdit);


        verticalLayout_2->addWidget(widget_3);

        verticalLayout_2->setStretch(0, 4);
        verticalLayout_2->setStretch(2, 2);

        verticalLayout_4->addWidget(widget_4);

        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendBtn = new QPushButton(widget_5);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitBtn = new QPushButton(widget_5);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout->addWidget(exitBtn);


        verticalLayout_4->addWidget(widget_5);


        horizontalLayout_4->addWidget(widget_6);

        FIle = new QWidget(widget_8);
        FIle->setObjectName(QString::fromUtf8("FIle"));
        filevlayout = new QVBoxLayout(FIle);
        filevlayout->setObjectName(QString::fromUtf8("filevlayout"));
        filevlayout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_4->addWidget(FIle);

        widget_7 = new QWidget(widget_8);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_4->addWidget(widget_7);


        verticalLayout_6->addWidget(widget_8);


        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Form", nullptr));
        sizeBox->setItemText(0, QApplication::translate("chat", "5", nullptr));
        sizeBox->setItemText(1, QApplication::translate("chat", "6", nullptr));
        sizeBox->setItemText(2, QApplication::translate("chat", "7", nullptr));
        sizeBox->setItemText(3, QApplication::translate("chat", "8", nullptr));
        sizeBox->setItemText(4, QApplication::translate("chat", "9", nullptr));
        sizeBox->setItemText(5, QApplication::translate("chat", "10", nullptr));
        sizeBox->setItemText(6, QApplication::translate("chat", "11", nullptr));
        sizeBox->setItemText(7, QApplication::translate("chat", "12", nullptr));
        sizeBox->setItemText(8, QApplication::translate("chat", "20", nullptr));
        sizeBox->setItemText(9, QApplication::translate("chat", "50", nullptr));

#ifndef QT_NO_TOOLTIP
        boldBtn->setToolTip(QApplication::translate("chat", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        boldBtn->setText(QApplication::translate("chat", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        italicTbtn->setToolTip(QApplication::translate("chat", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        italicTbtn->setText(QApplication::translate("chat", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        underlineTbtn->setToolTip(QApplication::translate("chat", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        underlineTbtn->setText(QApplication::translate("chat", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        colorBtn->setToolTip(QApplication::translate("chat", "\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        colorBtn->setText(QApplication::translate("chat", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        sendfileBtn->setToolTip(QApplication::translate("chat", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
        sendfileBtn->setText(QApplication::translate("chat", "...", nullptr));
        sendBtn->setText(QApplication::translate("chat", "\345\217\221\351\200\201", nullptr));
        exitBtn->setText(QApplication::translate("chat", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
