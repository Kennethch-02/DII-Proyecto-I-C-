#include "mainwindow.h"
#include "server.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.Connect();
    w.show();
    return a.exec();
}
