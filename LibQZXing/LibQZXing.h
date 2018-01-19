#ifndef LIBQZXING_H
#define LIBQZXING_H

#include "libqzxing_global.h"
#include <QImage>
#include <QZXing/QZXing.h>

class LIBQZXINGSHARED_EXPORT LibQZXing
{

public:
    LibQZXing();
    ~LibQZXing();

    QString decodeImage(const QImage &image);

    QString decodeImage(QObject *item);

    QString decodeImage(const QString& imageFilePath);

private:
    QZXing _qZXing;
};

#endif // LIBQZXING_H
