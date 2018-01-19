#ifndef SELECTLIST_H
#define SELECTLIST_H

#include <QObject>
#include <QStringList>

class SelectList : public QObject
{
    Q_OBJECT
public:
    explicit SelectList(QObject *parent = 0);

    Q_INVOKABLE QStringList getStringList();

signals:

public slots:
};

#endif // SELECTLIST_H
