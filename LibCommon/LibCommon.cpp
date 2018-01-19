#include "LibCommon.h"


LibCommon::LibCommon()
{
}

QString LibCommon::readIniFile(QString file, QString group, QString key, QString defaultValue)
{
    return _fileOperation.readIniFile(file,group,key,defaultValue);
}

void LibCommon::writeIniFile(QString file, QString group, QString key, QString value)
{
    _fileOperation.writeIniFile(file,group,key,value);
}

QString LibCommon::getLocalMac()
{
    Environmental environmental;
    return environmental.getLocalMac();
}

QString LibCommon::getLocalHostName()
{
    Environmental environmental;
    return environmental.getLocalHostName();
}

QString LibCommon::getLocalIP()
{
    Environmental environmental;
    return environmental.getLocalIP();
}

QString LibCommon::getMD5(QString data)
{
    SubCommon subCommon;
    return subCommon.getMD5(data);
}

QImage LibCommon::extractQImage(QObject *imageObj, int offsetX, int offsetY, int width, int height)
{
    LibCommonImageHandler libCommonImageHandler;
    return libCommonImageHandler.extractQImage(imageObj,offsetX,offsetY,width,height);
}

//void LibCommon::saveQImage(QObject *imageObj, const QString &path, const int offsetX, const int offsetY, const int width, const int height)
//{
//    LibCommonImageHandler libCommonImageHandler;
//    libCommonImageHandler.saveQImage(imageObj,path,offsetX,offsetY,width,height);
//}
