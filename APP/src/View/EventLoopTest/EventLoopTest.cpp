#include "EventLoopTest.h"

EventLoopTest::EventLoopTest(QObject *parent) : QObject(parent)
{

}

void EventLoopTest::subTest()
{
    emit signalShowPopup();
//    QEventLoop loop;
//    QObject::connect(this,SIGNAL(signalConfirmed()),&loop,SLOT(quit()));
//    qDebug()<<"Start QEventLoop";
//    loop.exec();
//    qDebug()<<"Quit QEventLoop";
}

void EventLoopTest::confirmed()
{
    emit this->signalConfirmed();
}
