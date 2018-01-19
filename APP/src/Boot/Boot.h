#ifndef BOOT_H
#define BOOT_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QThread>

#include "SubBoot.h"

class Boot : public QObject
{
    Q_OBJECT
public:
    explicit Boot(QObject *parent = 0);

    Q_INVOKABLE void sysBoot();

signals:
    void signalBootSuccess();
    void signalShowMsg(QString msg);
    void signalErr(QString msg);

public slots:
};

#endif // BOOT_H
