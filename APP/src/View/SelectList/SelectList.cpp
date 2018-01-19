#include "SelectList.h"

SelectList::SelectList(QObject *parent) : QObject(parent)
{

}

QStringList SelectList::getStringList()
{
    QStringList result;
    for(int i=0;i<20;i++){
        result.append("TestSelect-"+QString::number(i));
    }
    return result;
}
