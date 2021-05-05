#include "server.h"
#include "client.h"
#include "json.h"
#include <QLocalSocket>
#include <QTextStream>
#include <QDebug>
server::server(QObject *parent)
    :QTcpServer(parent)
{
}
bool server::startServer(quint16 port){
    return listen(QHostAddress::Any, port);
}
void server::incomingConnection(qintptr handle){
    qDebug()<<"CONECTADO "<<handle;
    auto socket = new client(handle, this);
    mSockets << socket;
    for(auto a : mSockets){
        QTextStream M(a);
        M<<"Servidor: Se ha Conectado";
        a->flush();
    }
    connect(socket, &client::AppReadyRead, [&](client *S){
        //Recepcion de Mensajes
        QTextStream T(S);
        auto text = T.readAll();
        json j;
        message M = j.getClass(text);
        qDebug()<<M.action;
        qDebug()<<M.data;
        qDebug()<<M.type;
    });
    connect(socket, &client::StateChanged, [&](client *S, int ST){
        if (ST == QTcpSocket::UnconnectedState){
            qDebug()<<"UnconnectedState: "<<S->socketDescriptor();
            mSockets.removeOne(S);
            for (auto i : mSockets){
                QTextStream K(i);
                K<<"Mensaje que se desea enviar";
                i->flush();
            }
        }
    });
}