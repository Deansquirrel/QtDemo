#ifndef SUBBOOT_H
#define SUBBOOT_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QThread>

#include <QQmlEngine>

#include "src/View/Test/Test.h"
#include "src/View/QCamera/QCamera.h"
#include "src/View/SelectList/SelectList.h"
#include "src/View/EventLoopTest/EventLoopTest.h"
#include "src/View/NewtonsoftJson/NewtonsoftJson.h"
#include "src/View/WeidgetTest/WeidgetTest.h"

#include "src/Com/ComSelectList/ComSelectList.h"

class SubBoot : public QObject
{
    Q_OBJECT
public:
    explicit SubBoot(QObject *parent = 0);
    ~SubBoot();

signals:
    void signalBootSuccess();
    void signalShowMsg(QString msg);
    void signalErr(QString msg);

public slots:
    void sysBoot();
};

#endif // SUBBOOT_H
