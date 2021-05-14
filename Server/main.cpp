#include <QCoreApplication>
#include <server.h>

//#include <QDataStream>
int main(int argc, char *argv[])
{    
    QCoreApplication a(argc, argv);
    server s;
    s.startServer(1234);
    qDebug()<<"Servidor iniciado";
    return a.exec();
}
