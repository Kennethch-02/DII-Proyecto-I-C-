/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QPushButton *Accept;
    QPushButton *Cancel;
    QSpinBox *port;
    QSpinBox *memory;

    void setupUi(QDialog *window)
    {
        if (window->objectName().isEmpty())
            window->setObjectName(QString::fromUtf8("window"));
        window->resize(319, 161);
        gridLayoutWidget = new QWidget(window);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 301, 61));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Accept = new QPushButton(gridLayoutWidget);
        Accept->setObjectName(QString::fromUtf8("Accept"));

        gridLayout->addWidget(Accept, 0, 2, 1, 1);

        Cancel = new QPushButton(gridLayoutWidget);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        gridLayout->addWidget(Cancel, 1, 2, 1, 1);

        port = new QSpinBox(gridLayoutWidget);
        port->setObjectName(QString::fromUtf8("port"));
        port->setMinimum(1200);
        port->setMaximum(9000);

        gridLayout->addWidget(port, 1, 1, 1, 1);

        memory = new QSpinBox(gridLayoutWidget);
        memory->setObjectName(QString::fromUtf8("memory"));
        memory->setMinimum(2048);
        memory->setMaximum(20000);

        gridLayout->addWidget(memory, 0, 1, 1, 1);


        retranslateUi(window);

        QMetaObject::connectSlotsByName(window);
    } // setupUi

    void retranslateUi(QDialog *window)
    {
        window->setWindowTitle(QCoreApplication::translate("window", "Server Settings", nullptr));
        label_2->setText(QCoreApplication::translate("window", "Port", nullptr));
        label->setText(QCoreApplication::translate("window", "Memory (bits)", nullptr));
        Accept->setText(QCoreApplication::translate("window", "Accept", nullptr));
        Cancel->setText(QCoreApplication::translate("window", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window: public Ui_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
