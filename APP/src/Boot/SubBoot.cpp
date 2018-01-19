#include "SubBoot.h"

SubBoot::SubBoot(QObject *parent) : QObject(parent)
{
}

SubBoot::~SubBoot()
{
    qDebug()<<"SubBoot des";
}

void SubBoot::sysBoot()
{
    qDebug()<<"系统启动初始化 开始";

    //类型注册
    qmlRegisterType<Test>("com.view.test",1,0,"CTest");
    qmlRegisterType<QCamera>("com.view.ccamera",1,0,"CCamera");
    qmlRegisterType<SelectList>("com.view.selectlist",1,0,"CSelectList");
    qmlRegisterType<EventLoopTest>("com.view.eventlooptest",1,0,"CEventLoopTest");
    qmlRegisterType<NewtonsoftJson>("com.view.newtonsoftjson",1,0,"CNewtonsoftJson");
    qmlRegisterType<WeidgetTest>("com.view.weidgettest",1,0,"CWeidgetTest");


    //QML组件类型注册
    ComSelectList::registerQMLTypes();

    //参数加载


    emit signalBootSuccess();
    qDebug()<<"系统启动初始化 结束";
}
