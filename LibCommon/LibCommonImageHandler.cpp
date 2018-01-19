#include "LibCommonImageHandler.h"

LibCommonImageHandler::LibCommonImageHandler(QObject *parent) : QObject(parent)
{

}

QImage LibCommonImageHandler::extractQImage(QObject *imageObj, int offsetX, int offsetY, int width, int height)
{
    QImage img;
    QQuickItem *item = qobject_cast<QQuickItem *>(imageObj);
    if(!item||!item->window()->isVisible()){
        qWarning()<<"Item is NULL";
        return QImage();
    }
    QSharedPointer<QQuickItemGrabResult> result=item->grabToImage();
    if(result.isNull()){
        qWarning()<<"grabToImage failed";
        return QImage();
    }
    QEventLoop loop;
    QObject::connect(result.data(),SIGNAL(ready()),&loop,SLOT(quit()));
    loop.exec();

    img=result.data()->image();
    if (offsetX < 0) offsetX = 0;
    if (offsetY < 0) offsetY = 0;
    if (width < 0) width = 0;
    if (height < 0) height = 0;

    if (offsetX>0 || offsetY>0 || width>0 || height>0){
        return img.copy(offsetX, offsetY, width, height);
    }
    else{
        return img;
    }
}

void LibCommonImageHandler::saveQImage(QObject *imageObj, const QString &path, const int offsetX, const int offsetY, const int width, const int height)
{
    QImage img = extractQImage(imageObj, offsetX, offsetY, width, height);
    if(img.isNull()) qDebug()<<"Image is null";
    img.save(path);
}
