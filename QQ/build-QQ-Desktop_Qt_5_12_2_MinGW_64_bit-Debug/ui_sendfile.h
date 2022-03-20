/********************************************************************************
** Form generated from reading UI file 'sendfile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDFILE_H
#define UI_SENDFILE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendFile
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QProgressBar *progressBar;

    void setupUi(QWidget *SendFile)
    {
        if (SendFile->objectName().isEmpty())
            SendFile->setObjectName(QString::fromUtf8("SendFile"));
        SendFile->resize(400, 300);
        horizontalLayout = new QHBoxLayout(SendFile);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton = new QToolButton(SendFile);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/WJ.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout->addWidget(toolButton);

        progressBar = new QProgressBar(SendFile);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        retranslateUi(SendFile);

        QMetaObject::connectSlotsByName(SendFile);
    } // setupUi

    void retranslateUi(QWidget *SendFile)
    {
        SendFile->setWindowTitle(QApplication::translate("SendFile", "Form", nullptr));
        toolButton->setText(QApplication::translate("SendFile", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendFile: public Ui_SendFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDFILE_H
