#include "LibQZXing.h"


LibQZXing::LibQZXing()
{
    _qZXing.setDecoder(QZXing::DecoderFormat_QR_CODE | QZXing::DecoderFormat_CODE_128);
}

LibQZXing::~LibQZXing()
{
}

QString LibQZXing::decodeImage(const QImage &image)
{
    return _qZXing.decodeImage(image);
}

QString LibQZXing::decodeImage(QObject *item)
{
    return _qZXing.decodeImageQML(item);
}

QString LibQZXing::decodeImage(const QString &imageFilePath)
{
    return _qZXing.decodeImageFromFile(imageFilePath);
}

//QImage LibQZXing::encodeData(const QString &data)
//{
//    QZXing _qZXing;
//    return _qZXing.encodeData(data);
//}

//void LibQZXing::encodeDataImage(const QString &data, QString &imageFilePath)
//{
//    this->encodeData(data).save(imageFilePath);
//}
