#include "client.h"

client::client(qintptr handle, QObject *parent)
    :QTcpSocket(parent)
{
    setSocketDescriptor(handle);
    connect(this, &client::readyRead,[&](){
        emit AppReadyRead(this);
    });
    connect(this, &client::stateChanged, [&](int S){
        emit StateChanged(this, S);
    });
}
