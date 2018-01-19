#include "Boot.h"

Boot::Boot(QObject *parent) : QObject(parent)
{

}

void Boot::sysBoot()
{
    QThread* qThread=new QThread();
    SubBoot* subBoot=new SubBoot();
    subBoot->moveToThread(qThread);
    //线程启动信号连接
    QObject::connect(qThread,SIGNAL(started()),subBoot,SLOT(sysBoot()));
    //i线程信号连接
    QObject::connect(subBoot,SIGNAL(signalShowMsg(QString)),
                     this,SIGNAL(signalShowMsg(QString)));
    QObject::connect(subBoot,SIGNAL(signalBootSuccess()),
                     this,SIGNAL(signalBootSuccess()));
    QObject::connect(subBoot,SIGNAL(signalErr(QString)),
                     this,SIGNAL(signalErr(QString)));
    //线程结束
//    QObject::connect(subBoot,SIGNAL(signalBootSuccess()),subBoot,SLOT(deleteLater()));
    QObject::connect(subBoot,SIGNAL(signalBootSuccess()),qThread,SLOT(quit()));
    QObject::connect(qThread,SIGNAL(finished()),qThread,SLOT(deleteLater()));

    qThread->start();
}
