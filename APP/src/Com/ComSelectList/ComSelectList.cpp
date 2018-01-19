#include "ComSelectList.h"

ComSelectList::ComSelectList(QObject *parent) : QObject(parent)
{

}

void ComSelectList::registerQMLTypes()
{
    qmlRegisterType<ComSelectList>("com.com.selectlist", 1, 0, "CComSelectList");
}

QList<QVariant> ComSelectList::listData() const
{
    return _listData;
}

void ComSelectList::setListData(const QList<QVariant> &listData)
{
    _listData = listData;
}
