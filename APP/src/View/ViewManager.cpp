#include "ViewManager.h"

ViewManager::ViewManager(QObject *parent) : QObject(parent)
{
    //    this->_viewUrlData.insert("","");
    this->_viewUrlData.insert("Menu","qrc:/qml_main/View/ViewMenu/ViewMenu.qml");
    this->_viewUrlData.insert("QCamera","qrc:/qml_main/View/QCamera/QCamera.qml");
    this->_viewUrlData.insert("ImagePrivew","qrc:/qml_main/View/QCamera/ImagePreview.qml");
    this->_viewUrlData.insert("SelectList","qrc:/qml_main/View/SelectList/SelectList.qml");
    this->_viewUrlData.insert("Numpad","qrc:/qml_main/View/Numpad/Numpad.qml");
    this->_viewUrlData.insert("EventLoopTest","qrc:/qml_main/View/EventLoopTest/EventLoopTest.qml");
    this->_viewUrlData.insert("NewtonsoftJson","qrc:/qml_main/View/NewtonsoftJson/NewtonsoftJson.qml");
    this->_viewUrlData.insert("WeidgetTest","qrc:/qml_main/View/WeidgetTest/WeidgetTest.qml");
    this->_viewUrlData.insert("Test","qrc:/qml_main/View/Test/Test.qml");
}

void ViewManager::pushQml(QString viewKey, QJsonObject initData)
{
    if(!_viewUrlData.contains(viewKey)){
        qWarning()<<"viewKey - [" + viewKey + "]不存在对应的QML";
        viewKey = "Menu";
    }
    emit this->signalPushQml(_viewUrlData.value(viewKey),initData);
}

void ViewManager::popQml()
{
    emit this->signalPop();
}
