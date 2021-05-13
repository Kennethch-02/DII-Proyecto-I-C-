#include <QCoreApplication>
#include <QApplication>
#include <QTextStream>
#include <server.h>
#include "window.h"
#include "iostream"

//#include <QDataStream>
int main(int argc, char *argv[])
{    
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    window w;
    w.exec();
    //return a.exec();
}
