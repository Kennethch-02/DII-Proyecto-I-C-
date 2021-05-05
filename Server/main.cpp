#include <QCoreApplication>
#include <server.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server Server;
    if (!Server.startServer(1234)){
        qDebug()<< Server.errorString();
        return 1;
    }
    qDebug()<<"Servidor Iniciado";
    return a.exec();
}
