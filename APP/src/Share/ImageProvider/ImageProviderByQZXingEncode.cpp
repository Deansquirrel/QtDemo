#include "ImageProviderByQZXingEncode.h"


ImageProviderByQZXingEncode::ImageProviderByQZXingEncode()
    :QQuickImageProvider(QQuickImageProvider::Image)
{
}

QImage ImageProviderByQZXingEncode::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    qDebug()<<id<<size<<requestedSize;
//    LibQZXing libQZXing;
//    QImage img=libQZXing.encodeData(id);
    return QImage();
}
