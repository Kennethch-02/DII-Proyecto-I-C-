#include "server.h"
#include "client.h"
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
    auto socket = new client(handle, this);
    mSockets << socket;
    qDebug()<<"CONECTADO";
    connect(socket, &client::AppReadyRead, [&](client *S){
        QTextStream T(S);
        auto text = T.readAll();
        qDebug()<< text;
        for(auto i : mSockets){
            QTextStream K(i);
            K<<text;
            i->flush();
        }
    });
    connect(socket, &client::StateChanged, [&](client *S, int ST){
        if (ST == QTcpSocket::UnconnectedState){
            mSockets.removeOne(S);
            for (auto i : mSockets){
                QTextStream K(i);
                K<<"Mensaje que se desea enviar";
                i->flush();
            }
        }
    });
}
