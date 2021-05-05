#ifndef MESSAGE_H
#define MESSAGE_H
#include <QTcpSocket>
#include "QString"

using namespace std;
class message
{
public:
    message();
    void setType(QString type);
    void setAction(QString action);
    void setData(QString data);
    QString type;
    QString action;
    QString data;
};

#endif // MESSAGE_H
