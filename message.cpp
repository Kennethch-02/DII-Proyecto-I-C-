#include "message.h"
using namespace std;

message::message()
{
    QString type;
    QString action;
    QString data;
}
void message::setType(QString type){
    this->type = type;
}
void message::setAction(QString action){
    this->action = action;
}
void message::setData(QString data){
    this->data = data;
}
