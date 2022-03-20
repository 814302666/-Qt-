/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
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
    QTextBrowser *msgBrowser;
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
    QToolButton *saveBtn;
    QToolButton *clearBtn;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *msgTxtEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *userNumLbl;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *usrTblWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1098, 674);
        verticalLayout_6 = new QVBoxLayout(Widget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_8 = new QWidget(Widget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_8);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_4 = new QVBoxLayout(widget_6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        msgBrowser = new QTextBrowser(widget);
        msgBrowser->setObjectName(QString::fromUtf8("msgBrowser"));

        verticalLayout_3->addWidget(msgBrowser);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
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

        saveBtn = new QToolButton(frame_2);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/bc.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        saveBtn->setIcon(icon4);

        horizontalLayout_2->addWidget(saveBtn);

        clearBtn = new QToolButton(frame_2);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/qingchu.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearBtn->setIcon(icon5);

        horizontalLayout_2->addWidget(clearBtn);


        verticalLayout->addWidget(frame_2);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
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
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendBtn = new QPushButton(widget_5);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        userNumLbl = new QLabel(widget_5);
        userNumLbl->setObjectName(QString::fromUtf8("userNumLbl"));

        horizontalLayout->addWidget(userNumLbl);

        horizontalSpacer_2 = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(widget_5);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));

        horizontalLayout->addWidget(exitBtn);

        horizontalLayout->setStretch(2, 1);

        verticalLayout_4->addWidget(widget_5);


        horizontalLayout_4->addWidget(widget_6);

        widget_7 = new QWidget(widget_8);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        usrTblWidget = new QTableWidget(widget_7);
        if (usrTblWidget->columnCount() < 1)
            usrTblWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usrTblWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        usrTblWidget->setObjectName(QString::fromUtf8("usrTblWidget"));

        verticalLayout_5->addWidget(usrTblWidget);


        horizontalLayout_4->addWidget(widget_7);


        verticalLayout_6->addWidget(widget_8);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        sizeBox->setItemText(0, QApplication::translate("Widget", "5", nullptr));
        sizeBox->setItemText(1, QApplication::translate("Widget", "6", nullptr));
        sizeBox->setItemText(2, QApplication::translate("Widget", "7", nullptr));
        sizeBox->setItemText(3, QApplication::translate("Widget", "8", nullptr));
        sizeBox->setItemText(4, QApplication::translate("Widget", "9", nullptr));
        sizeBox->setItemText(5, QApplication::translate("Widget", "10", nullptr));
        sizeBox->setItemText(6, QApplication::translate("Widget", "11", nullptr));
        sizeBox->setItemText(7, QApplication::translate("Widget", "12", nullptr));
        sizeBox->setItemText(8, QApplication::translate("Widget", "20", nullptr));
        sizeBox->setItemText(9, QApplication::translate("Widget", "50", nullptr));

#ifndef QT_NO_TOOLTIP
        boldBtn->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        boldBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        italicTbtn->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        italicTbtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        underlineTbtn->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        underlineTbtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        colorBtn->setToolTip(QApplication::translate("Widget", "\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        colorBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        saveBtn->setToolTip(QApplication::translate("Widget", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
        saveBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        clearBtn->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
#endif // QT_NO_TOOLTIP
        clearBtn->setText(QApplication::translate("Widget", "...", nullptr));
        sendBtn->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        userNumLbl->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\344\272\272\346\225\260\357\274\2320\344\272\272", nullptr));
        exitBtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = usrTblWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
