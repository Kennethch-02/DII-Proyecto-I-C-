#include "server.h"
#include "client.h"
#include "json.h"
#include <QLocalSocket>
#include <QTextStream>
#include <QDebug>
#include <QMap>
server::server(QObject *parent)
    :QTcpServer(parent)
{
}
bool server::startServer(quint16 port){
    return listen(QHostAddress::Any, port);
}
void server::Do_Action(){
    if (Received_Message.type == "Data"){
        if (Received_Message.action == "Set"){
            QString Data = Received_Message.data;
            int *b = new int;
            *b = Data.split(" ")[2].toInt();
            dic_Datos.insert(Data.split(" ")[0], b);
        }
    }
    if (Received_Message.type == "Notify"){
        if(Received_Message.action == "Clear"){
            dic_Datos.clear();
        }
    }
    Received_Message.clear();
}
void server::Send_Message(){
    for(auto a : mSockets){
        //Envio de mensajes
        QTextStream M(a);
        QJsonArray array {Json.Parse(Message)};
        Message.clear();
        QJsonDocument jsDoc(array);
        QString String_M = QString::fromLatin1(jsDoc.toJson());
        M<<String_M;
        a->flush();
    }
}
void server::incomingConnection(qintptr handle){
    qDebug()<<"CONECTADO "<<handle;
    auto socket = new client(handle, this);
    mSockets << socket;
    Message.type = "Notify";
    Message.data = ">Servidor: Se ha Conectado";
    Message.action = "null";
    Send_Message();

    connect(socket, &client::AppReadyRead, [&](client *S){
        //Recepcion de Mensajes
        QTextStream T(S);
        auto text = T.readAll();
        Received_Message = Json.getClass(text);
        Do_Action();
    });
    connect(socket, &client::StateChanged, [&](client *S, int ST){
        if (ST == QTcpSocket::UnconnectedState){
            qDebug()<<"UnconnectedState: "<<S->socketDescriptor();
            mSockets.removeOne(S);
            dic_Datos.clear();
        }
    });
}
