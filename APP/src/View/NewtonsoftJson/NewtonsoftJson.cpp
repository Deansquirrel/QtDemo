#include "NewtonsoftJson.h"

NewtonsoftJson::NewtonsoftJson(QObject *parent) : QObject(parent)
{

}

QString NewtonsoftJson::subConvertJsontoXML()
{
    QString json;
    json="{\"a\":\"aa\"}";
    qDebug()<<"json:"<<json;
    LibNewtonsoftJson _lib;
    QString xml=_lib.ConvertJsontoXML(json);
    qDebug()<<"xml:"<<xml;
    return xml;
}
