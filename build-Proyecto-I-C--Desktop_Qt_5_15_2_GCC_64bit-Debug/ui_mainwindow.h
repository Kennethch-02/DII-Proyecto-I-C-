/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *BTN_RUN;
    QPushButton *BTN_STOP;
    QPushButton *BTN_NEXT;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *NUM_LINE;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *TEXT_CODE;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *RAM_1;
    QTextEdit *RAM_2;
    QTextEdit *RAM_3;
    QTextEdit *RAM_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *CMD_TEXT;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *CLEAR;
    QLineEdit *APLICATION_LOG;
    QProgressBar *ProgressBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(799, 770);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 801, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        BTN_RUN = new QPushButton(horizontalLayoutWidget_2);
        BTN_RUN->setObjectName(QString::fromUtf8("BTN_RUN"));

        horizontalLayout->addWidget(BTN_RUN);

        BTN_STOP = new QPushButton(horizontalLayoutWidget_2);
        BTN_STOP->setObjectName(QString::fromUtf8("BTN_STOP"));
        BTN_STOP->setEnabled(false);

        horizontalLayout->addWidget(BTN_STOP);

        BTN_NEXT = new QPushButton(horizontalLayoutWidget_2);
        BTN_NEXT->setObjectName(QString::fromUtf8("BTN_NEXT"));
        BTN_NEXT->setEnabled(false);

        horizontalLayout->addWidget(BTN_NEXT);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(70, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 40, 72, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        NUM_LINE = new QTextEdit(verticalLayoutWidget);
        NUM_LINE->setObjectName(QString::fromUtf8("NUM_LINE"));
        NUM_LINE->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("Source Code Pro"));
        font.setPointSize(14);
        NUM_LINE->setFont(font);
        NUM_LINE->setLayoutDirection(Qt::RightToLeft);
        NUM_LINE->setAutoFillBackground(false);
        NUM_LINE->setReadOnly(true);

        verticalLayout->addWidget(NUM_LINE);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(40, 40, 541, 461));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        TEXT_CODE = new QTextEdit(verticalLayoutWidget_2);
        TEXT_CODE->setObjectName(QString::fromUtf8("TEXT_CODE"));
        QFont font1;
        font1.setPointSize(14);
        TEXT_CODE->setFont(font1);
        TEXT_CODE->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_2->addWidget(TEXT_CODE);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(580, 40, 221, 461));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        RAM_1 = new QTextEdit(horizontalLayoutWidget_3);
        RAM_1->setObjectName(QString::fromUtf8("RAM_1"));
        RAM_1->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RAM_1->sizePolicy().hasHeightForWidth());
        RAM_1->setSizePolicy(sizePolicy);
        RAM_1->setMaximumSize(QSize(50, 16777215));
        RAM_1->setReadOnly(true);

        horizontalLayout_3->addWidget(RAM_1);

        RAM_2 = new QTextEdit(horizontalLayoutWidget_3);
        RAM_2->setObjectName(QString::fromUtf8("RAM_2"));
        RAM_2->setEnabled(true);
        RAM_2->setMaximumSize(QSize(50, 16777215));
        RAM_2->setReadOnly(true);

        horizontalLayout_3->addWidget(RAM_2);

        RAM_3 = new QTextEdit(horizontalLayoutWidget_3);
        RAM_3->setObjectName(QString::fromUtf8("RAM_3"));
        RAM_3->setEnabled(true);
        RAM_3->setMaximumSize(QSize(50, 16777215));
        RAM_3->setReadOnly(true);

        horizontalLayout_3->addWidget(RAM_3);

        RAM_4 = new QTextEdit(horizontalLayoutWidget_3);
        RAM_4->setObjectName(QString::fromUtf8("RAM_4"));
        RAM_4->setEnabled(true);
        RAM_4->setMaximumSize(QSize(50, 16777215));
        RAM_4->setReadOnly(true);

        horizontalLayout_3->addWidget(RAM_4);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 500, 801, 191));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        CMD_TEXT = new QTextEdit(verticalLayoutWidget_3);
        CMD_TEXT->setObjectName(QString::fromUtf8("CMD_TEXT"));
        CMD_TEXT->setReadOnly(true);

        verticalLayout_3->addWidget(CMD_TEXT);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 690, 801, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        CLEAR = new QLineEdit(gridLayoutWidget);
        CLEAR->setObjectName(QString::fromUtf8("CLEAR"));
        CLEAR->setEnabled(true);
        CLEAR->setReadOnly(true);

        gridLayout->addWidget(CLEAR, 1, 1, 1, 1);

        APLICATION_LOG = new QLineEdit(gridLayoutWidget);
        APLICATION_LOG->setObjectName(QString::fromUtf8("APLICATION_LOG"));
        APLICATION_LOG->setEnabled(true);
        APLICATION_LOG->setReadOnly(true);

        gridLayout->addWidget(APLICATION_LOG, 1, 0, 1, 1);

        ProgressBar = new QProgressBar(gridLayoutWidget);
        ProgressBar->setObjectName(QString::fromUtf8("ProgressBar"));
        ProgressBar->setValue(0);

        gridLayout->addWidget(ProgressBar, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "C!-IDE", nullptr));
        BTN_RUN->setText(QCoreApplication::translate("MainWindow", "RUN", nullptr));
        BTN_STOP->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        BTN_NEXT->setText(QCoreApplication::translate("MainWindow", "NEXT", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "RAM LIVE VIEW", nullptr));
        NUM_LINE->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Source Code Pro'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        CMD_TEXT->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&gt;</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
