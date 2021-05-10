#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include "message.h"
#include "json.h"
#include <QJsonDocument>
#include <QMap>
class client;

class server : public QTcpServer
{
    Q_OBJECT
public:
    server(QObject *parent = nullptr);
    bool startServer(quint16 port);
protected:
    void incomingConnection(qintptr handle);
private:
    void Send_Message();
    void Do_Action();
    QMap<QString,  int*> dic_Datos;
    message Message;
    message Received_Message;
    json Json;
    QList<client *> mSockets;
};

#endif // SERVER_H
