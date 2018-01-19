#include "SysConfig.h"

SysConfig::SysConfig(QObject *parent) : QObject(parent)
{

}

QJsonObject SysConfig::getUI()
{
    QJsonObject ui;
    //背景色
    ui.insert("backColor","#F2F2F2");
//    ui.insert("backColor","white");
    //底色
    ui.insert("winColor","#EBEBEB");
    //文本颜色
    ui.insert("fontColor","#333333");
    //文本浅颜色
    ui.insert("fontLightColor","#CCCCCC");
    //文本提示颜色
    ui.insert("fontTipsColor","#3955A3");
    //主题颜色
//    ui.insert("themeColor","#FF4040");
    ui.insert("themeColor","#F02E50");

    return ui;
}

QString SysConfig::getServiceUrl() const
{
    LibCommon libCommon;
    return libCommon.readIniFile("config.ini","ServiceSet","URL","");
}

void SysConfig::setServiceUrl(const QString &serviceUrl)
{
    LibCommon libCommon;
    libCommon.writeIniFile("config.ini","ServiceSet","URL",serviceUrl);
}

QString SysConfig::getServiceKey() const
{
    LibCommon libCommon;
    return libCommon.readIniFile("config.ini","ServiceSet","Key","");
}

void SysConfig::setServiceKey(const QString &serviceKey)
{
    LibCommon libCommon;
    libCommon.writeIniFile("config.ini","ServiceSet","Key",serviceKey);
}
