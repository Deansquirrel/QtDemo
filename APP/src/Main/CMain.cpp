#include "CMain.h"

CMain::CMain(QObject *parent) : QObject(parent)
{
//    this->_billUrlData.insert("","");
    this->_billUrlData.insert("Boot","qrc:/qml_main/Boot/Boot.qml");
    this->_billUrlData.insert("View","qrc:/qml_main/View/ViewManager.qml");
//    this->_billUrlData.insert("Settings","qrc:/qml/Settings/Settings.qml");
//    this->_billUrlData.insert("Menu","qrc:/qml/Menu/MenuViewManager.qml");
}

void CMain::loadQml(QString billKey, QJsonObject initData)
{
    if(!_billUrlData.contains(billKey)){
        qWarning()<<"billKey - [" + billKey + "]不存在对应的QML";
        billKey = "Boot";
    }
    emit this->signalLoadQml(_billUrlData.value(billKey),initData);
}
