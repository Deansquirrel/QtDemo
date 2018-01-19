#ifndef IMAGEPROVIDERBYQZXINGENCODE_H
#define IMAGEPROVIDERBYQZXINGENCODE_H

#include <QQuickImageProvider>
#include <QImage>

#include <LibQZXing.h>

class ImageProviderByQZXingEncode : public QQuickImageProvider
{
public:
    ImageProviderByQZXingEncode();

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);

};

#endif // IMAGEPROVIDERBYQZXINGENCODE_H
