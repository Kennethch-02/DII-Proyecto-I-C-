#include "server.h"
#include "client.h"
#include "json.h"
#include <QLocalSocket>
#include <QTextStream>
#include <QDebug>
#include <QMap>
#include "string"
#include <sstream>
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
            QStringList a = Received_Message.data.split(" ");
            if(a[0]=="int"){
                Memory.new_int(a[1], a[3].toInt());
                Message.type = "RAM";
                Message.action = "Set";
                qDebug()<<Memory.get_int(a[1]);
                int *x = Memory.get_int(a[1]);
                std::stringstream ss;
                ss << x;
                std::string address = ss.str();
                QString m = QString::fromStdString(address)+" ";
                Message.data = m+a[1]+" "+a[3]+" 1";
                Send_Message();
            }
            if(a[0]=="string"){
                Memory.new_string(a[1], a[3]);
                Message.type = "RAM";
                Message.action = "Set";
                QString *x = Memory.get_string(a[1]);
                std::stringstream ss;
                ss << x;
                std::string address = ss.str();
                QString m = QString::fromStdString(address)+" ";
                Message.data = m+a[1]+" "+a[3]+" 1";
                Send_Message();
            }
            if(a[0]=="char"){
                Memory.new_char(a[1], a[3][0]);
                Message.type = "RAM";
                Message.action = "Set";
                QChar *x = Memory.get_char(a[1]);
                std::stringstream ss;
                ss << x;
                std::string address = ss.str();
                QString m = QString::fromStdString(address)+" ";
                Message.data = m+a[1]+" "+a[3]+" 1";
                Send_Message();
            }
            if(a[0]=="long"){
                Memory.new_long(a[1], a[3].toLongLong());
                Message.type = "RAM";
                Message.action = "Set";
                qlonglong *x = Memory.get_long(a[1]);
                std::stringstream ss;
                ss << x;
                std::string address = ss.str();
                QString m = QString::fromStdString(address)+" ";
                Message.data = m+a[1]+" "+a[3]+" 1";
                Send_Message();
            }
            if(a[0]=="float"){
                Memory.new_float(a[1], a[3].toFloat());
                Message.type = "RAM";
                Message.action = "Set";
                float *x = Memory.get_float(a[1]);
                std::stringstream ss;
                ss << x;
                std::string address = ss.str();
                QString m = QString::fromStdString(address)+" ";
                Message.data = m+a[1]+" "+a[3]+" 1";
                Send_Message();
            }
        }
    }
    if (Received_Message.type == "Notify"){
        if(Received_Message.action == "Clear"){
            Memory.free_space();
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
