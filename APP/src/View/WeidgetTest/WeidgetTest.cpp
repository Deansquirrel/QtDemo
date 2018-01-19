#include "WeidgetTest.h"

WeidgetTest::WeidgetTest(QObject *parent) : QObject(parent)
{

}

void WeidgetTest::startWeidget()
{
    qDebug()<<"startWeidget";
    FindDialog findDialog;
    findDialog.exec();
}
