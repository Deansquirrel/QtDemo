#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QDateTime>

#include "LibCryptoInQt.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    Q_INVOKABLE void subTest();

signals:

public slots:
};

#endif // TEST_H
