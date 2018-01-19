#ifndef COMSELECTLIST_H
#define COMSELECTLIST_H

#include <QObject>
#include <QQmlEngine>
#include <QDebug>
#include <QList>
#include <QVariant>

class ComSelectList : public QObject
{
    Q_OBJECT
public:
    explicit ComSelectList(QObject *parent = nullptr);

    static void registerQMLTypes();

    QList<QVariant> listData() const;
    void setListData(const QList<QVariant> &listData);

signals:

public slots:

private:
    QList<QVariant> _listData;
};

#endif // COMSELECTLIST_H
