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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mserver
{
public:
    QWidget *centralwidget;
    QTextEdit *CMD;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Connect;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *Status;

    void setupUi(QMainWindow *mserver)
    {
        if (mserver->objectName().isEmpty())
            mserver->setObjectName(QString::fromUtf8("mserver"));
        mserver->resize(336, 141);
        centralwidget = new QWidget(mserver);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CMD = new QTextEdit(centralwidget);
        CMD->setObjectName(QString::fromUtf8("CMD"));
        CMD->setGeometry(QRect(10, 50, 311, 81));
        CMD->setReadOnly(true);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 311, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Connect = new QPushButton(widget);
        Connect->setObjectName(QString::fromUtf8("Connect"));

        horizontalLayout->addWidget(Connect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        Status = new QLabel(widget);
        Status->setObjectName(QString::fromUtf8("Status"));

        horizontalLayout->addWidget(Status);

        mserver->setCentralWidget(centralwidget);

        retranslateUi(mserver);

        QMetaObject::connectSlotsByName(mserver);
    } // setupUi

    void retranslateUi(QMainWindow *mserver)
    {
        mserver->setWindowTitle(QCoreApplication::translate("mserver", "mserver", nullptr));
        Connect->setText(QCoreApplication::translate("mserver", "Connect", nullptr));
        label->setText(QCoreApplication::translate("mserver", "Status: ", nullptr));
        Status->setText(QCoreApplication::translate("mserver", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mserver: public Ui_mserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSERVER_H
