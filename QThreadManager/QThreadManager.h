#ifndef QTHREADMANAGER_H
#define QTHREADMANAGER_H

#include "qthreadmanager_global.h"

#include <QThread>
#include <QMap>
#include <QString>

class QTHREADMANAGERSHARED_EXPORT QThreadManager
{

public:
    QThreadManager();
    int activeThreadCount;
    int maxThreadCount;

    QString createThread();
    void releaseThread(QString threadKey);
    QThread* getThread(QString threadKey);

private:
    QMap<QString,QThread*> _threadPool;

};

#endif // QTHREADMANAGER_H
