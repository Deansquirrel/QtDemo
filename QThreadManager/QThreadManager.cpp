#include "QThreadManager.h"


QThreadManager::QThreadManager()
{
    activeThreadCount=0;
    maxThreadCount=5;
}

QString QThreadManager::createThread()
{
    return "";
}

void QThreadManager::releaseThread(QString threadKey)
{
    if(_threadPool.keys().contains(threadKey)){
        QThread* qThread = _threadPool.value(threadKey);
        qThread->quit();
        qThread->deleteLater();
        _threadPool.remove(threadKey);
    }
}

QThread *QThreadManager::getThread(QString threadKey)
{
    if(_threadPool.keys().contains(threadKey)){
        return _threadPool.value(threadKey);
    }
    else{
        return nullptr;
    }
}

