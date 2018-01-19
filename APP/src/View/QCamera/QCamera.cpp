#include "QCamera.h"

QCamera::QCamera(QObject *parent) : QObject(parent)
{
}

QCamera::~QCamera()
{

}

QString QCamera::decoder(QObject *item)
{
    LibQZXing libQZXing;
    return libQZXing.decodeImage(item);
}

QString QCamera::decoder(const QString &imageFilePath)
{
    LibQZXing libQZXing;
    return libQZXing.decodeImage(imageFilePath);
}

void QCamera::threadSleep()
{
    QThread::sleep(5);
}
