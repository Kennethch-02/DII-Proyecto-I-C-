#include "json.h"
#include "QTextStream"
#include "QString"

json::json()
{

}
QJsonObject json::Parse(message Message){
    QJsonObject Json = *new QJsonObject();
    Json.insert("Type", QJsonValue::fromVariant(Message.type));
    Json.insert("Action", QJsonValue::fromVariant(Message.action));
    Json.insert("Data", QJsonValue::fromVariant(Message.data));
    return Json;
}
message json::getClass(QJsonObject Json){
    message Message;
    QJsonValue type = Json["Type"];
    QJsonValue action = Json["Action"];
    QJsonValue data = Json["Data"];
    Message.setType(type.toString());
    Message.setAction(action.toString());
    Message.setData(data.toString());
    return Message;
}
