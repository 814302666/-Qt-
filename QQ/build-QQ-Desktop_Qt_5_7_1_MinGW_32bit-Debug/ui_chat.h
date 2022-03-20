/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QToolButton *videobtn;
    QToolButton *voicebtn;
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
            chat->setObjectName(QStringLiteral("chat"));
        chat->resize(800, 600);
        verticalLayout_6 = new QVBoxLayout(chat);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_8 = new QWidget(chat);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_8);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_4);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        msgBrowser = new QListWidget(widget);
        msgBrowser->setObjectName(QStringLiteral("msgBrowser"));

        verticalLayout_3->addWidget(msgBrowser);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        fontCbx = new QFontComboBox(frame_2);
        fontCbx->setObjectName(QStringLiteral("fontCbx"));

        horizontalLayout_2->addWidget(fontCbx);

        sizeBox = new QComboBox(frame_2);
        sizeBox->setObjectName(QStringLiteral("sizeBox"));

        horizontalLayout_2->addWidget(sizeBox);

        boldBtn = new QToolButton(frame_2);
        boldBtn->setObjectName(QStringLiteral("boldBtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/JC.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldBtn->setIcon(icon);
        boldBtn->setCheckable(true);

        horizontalLayout_2->addWidget(boldBtn);

        italicTbtn = new QToolButton(frame_2);
        italicTbtn->setObjectName(QStringLiteral("italicTbtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/qx.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicTbtn->setIcon(icon1);
        italicTbtn->setCheckable(true);

        horizontalLayout_2->addWidget(italicTbtn);

        underlineTbtn = new QToolButton(frame_2);
        underlineTbtn->setObjectName(QStringLiteral("underlineTbtn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/`HJ8@K[456G`KN_9@DOB7WC.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineTbtn->setIcon(icon2);
        underlineTbtn->setCheckable(true);

        horizontalLayout_2->addWidget(underlineTbtn);

        colorBtn = new QToolButton(frame_2);
        colorBtn->setObjectName(QStringLiteral("colorBtn"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorBtn->setIcon(icon3);

        horizontalLayout_2->addWidget(colorBtn);

        sendfileBtn = new QToolButton(frame_2);
        sendfileBtn->setObjectName(QStringLiteral("sendfileBtn"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendfileBtn->setIcon(icon4);

        horizontalLayout_2->addWidget(sendfileBtn);

        videobtn = new QToolButton(frame_2);
        videobtn->setObjectName(QStringLiteral("videobtn"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/SPTX.png"), QSize(), QIcon::Normal, QIcon::Off);
        videobtn->setIcon(icon5);

        horizontalLayout_2->addWidget(videobtn);

        voicebtn = new QToolButton(frame_2);
        voicebtn->setObjectName(QStringLiteral("voicebtn"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/YY.png"), QSize(), QIcon::Normal, QIcon::Off);
        voicebtn->setIcon(icon6);

        horizontalLayout_2->addWidget(voicebtn);


        verticalLayout->addWidget(frame_2);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        msgTxtEdit = new QTextEdit(widget_3);
        msgTxtEdit->setObjectName(QStringLiteral("msgTxtEdit"));

        horizontalLayout_3->addWidget(msgTxtEdit);


        verticalLayout_2->addWidget(widget_3);

        verticalLayout_2->setStretch(0, 4);
        verticalLayout_2->setStretch(2, 2);

        verticalLayout_4->addWidget(widget_4);

        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendBtn = new QPushButton(widget_5);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitBtn = new QPushButton(widget_5);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout->addWidget(exitBtn);


        verticalLayout_4->addWidget(widget_5);


        horizontalLayout_4->addWidget(widget_6);

        FIle = new QWidget(widget_8);
        FIle->setObjectName(QStringLiteral("FIle"));
        filevlayout = new QVBoxLayout(FIle);
        filevlayout->setObjectName(QStringLiteral("filevlayout"));
        filevlayout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_4->addWidget(FIle);

        widget_7 = new QWidget(widget_8);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_4->addWidget(widget_7);


        verticalLayout_6->addWidget(widget_8);


        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Form", Q_NULLPTR));
        sizeBox->clear();
        sizeBox->insertItems(0, QStringList()
         << QApplication::translate("chat", "5", Q_NULLPTR)
         << QApplication::translate("chat", "6", Q_NULLPTR)
         << QApplication::translate("chat", "7", Q_NULLPTR)
         << QApplication::translate("chat", "8", Q_NULLPTR)
         << QApplication::translate("chat", "9", Q_NULLPTR)
         << QApplication::translate("chat", "10", Q_NULLPTR)
         << QApplication::translate("chat", "11", Q_NULLPTR)
         << QApplication::translate("chat", "12", Q_NULLPTR)
         << QApplication::translate("chat", "20", Q_NULLPTR)
         << QApplication::translate("chat", "50", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        boldBtn->setToolTip(QApplication::translate("chat", "\345\212\240\347\262\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        boldBtn->setText(QApplication::translate("chat", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        italicTbtn->setToolTip(QApplication::translate("chat", "\345\200\276\346\226\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        italicTbtn->setText(QApplication::translate("chat", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        underlineTbtn->setToolTip(QApplication::translate("chat", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        underlineTbtn->setText(QApplication::translate("chat", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        colorBtn->setToolTip(QApplication::translate("chat", "\351\242\234\350\211\262", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        colorBtn->setText(QApplication::translate("chat", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sendfileBtn->setToolTip(QApplication::translate("chat", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        sendfileBtn->setText(QApplication::translate("chat", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        videobtn->setToolTip(QApplication::translate("chat", "\350\247\206\351\242\221\350\201\212\345\244\251", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        videobtn->setText(QApplication::translate("chat", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        voicebtn->setToolTip(QApplication::translate("chat", "\350\257\255\351\237\263\350\201\212\345\244\251", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        voicebtn->setText(QApplication::translate("chat", "...", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("chat", "\345\217\221\351\200\201", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("chat", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
