/********************************************************************************
** Form generated from reading UI file 'receivefile.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVEFILE_H
#define UI_RECEIVEFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceiveFile
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QProgressBar *progressBar;

    void setupUi(QWidget *ReceiveFile)
    {
        if (ReceiveFile->objectName().isEmpty())
            ReceiveFile->setObjectName(QStringLiteral("ReceiveFile"));
        ReceiveFile->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ReceiveFile);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton = new QToolButton(ReceiveFile);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/WJ.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout->addWidget(toolButton);

        progressBar = new QProgressBar(ReceiveFile);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        retranslateUi(ReceiveFile);

        QMetaObject::connectSlotsByName(ReceiveFile);
    } // setupUi

    void retranslateUi(QWidget *ReceiveFile)
    {
        ReceiveFile->setWindowTitle(QApplication::translate("ReceiveFile", "Form", Q_NULLPTR));
        toolButton->setText(QApplication::translate("ReceiveFile", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReceiveFile: public Ui_ReceiveFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVEFILE_H
