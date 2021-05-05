#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>


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
    QList<client *> mSockets;

};

#endif // SERVER_H
