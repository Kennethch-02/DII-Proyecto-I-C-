/********************************************************************************
** Form generated from reading UI file 'mserver.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSERVER_H
#define UI_MSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mserver
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *Port;
    QLabel *label_2;
    QTextEdit *Memory;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *Connect;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *CMD;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *mserver)
    {
        if (mserver->objectName().isEmpty())
            mserver->setObjectName(QString::fromUtf8("mserver"));
        mserver->resize(444, 415);
        centralwidget = new QWidget(mserver);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 441, 412));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Port = new QSpinBox(widget);
        Port->setObjectName(QString::fromUtf8("Port"));

        gridLayout->addWidget(Port, 2, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        Memory = new QTextEdit(widget);
        Memory->setObjectName(QString::fromUtf8("Memory"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(Memory->sizePolicy().hasHeightForWidth());
        Memory->setSizePolicy(sizePolicy);
        Memory->setMaximumSize(QSize(10000, 30));

        gridLayout->addWidget(Memory, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Connect = new QPushButton(widget);
        Connect->setObjectName(QString::fromUtf8("Connect"));

        verticalLayout->addWidget(Connect);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        CMD = new QTextEdit(widget);
        CMD->setObjectName(QString::fromUtf8("CMD"));
        CMD->setEnabled(false);
        CMD->setMinimumSize(QSize(0, 320));

        verticalLayout_2->addWidget(CMD);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        gridLayout_2->addLayout(verticalLayout_2, 2, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 1, 1, 1);

        mserver->setCentralWidget(centralwidget);

        retranslateUi(mserver);

        QMetaObject::connectSlotsByName(mserver);
    } // setupUi

    void retranslateUi(QMainWindow *mserver)
    {
        mserver->setWindowTitle(QCoreApplication::translate("mserver", "mserver", nullptr));
        label->setText(QCoreApplication::translate("mserver", "Memory", nullptr));
        label_2->setText(QCoreApplication::translate("mserver", "Port", nullptr));
        Connect->setText(QCoreApplication::translate("mserver", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mserver: public Ui_mserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSERVER_H
