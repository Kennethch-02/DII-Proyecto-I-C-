#include "mainwindow.h"
#include "server.h"
#include <QApplication>
#include <QDebug>
/**
* \brief Main de la aplicacion, ejecuta la ventana
* principal del IDE
* @param QApplication
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
