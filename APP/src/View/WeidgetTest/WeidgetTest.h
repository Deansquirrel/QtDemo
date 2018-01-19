#ifndef WEIDGETTEST_H
#define WEIDGETTEST_H

#include <QObject>
#include <QDebug>

#include <FindDialog.h>

class WeidgetTest : public QObject
{
    Q_OBJECT
public:
    explicit WeidgetTest(QObject *parent = nullptr);

    Q_INVOKABLE void startWeidget();

signals:

public slots:
};

#endif // WEIDGETTEST_H
