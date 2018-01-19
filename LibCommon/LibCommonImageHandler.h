#ifndef LIBCOMMONIMAGEHANDLER_H
#define LIBCOMMONIMAGEHANDLER_H

#include <QObject>
#include <QImage>
#include <QString>
#include <QQuickItem>
#include <QQuickWindow>
#include <QSharedPointer>
#include <QQuickItemGrabResult>
#include <QDebug>
#include <QEventLoop>

class LibCommonImageHandler : public QObject
{
    Q_OBJECT
public:
    explicit LibCommonImageHandler(QObject *parent = 0);

    QImage extractQImage(QObject *imageObj,
                         int offsetX = 0, int offsetY = 0,
                         int width = 0, int height = 0);

signals:

public slots:
    void saveQImage(QObject *imageObj, const QString &path,
              const int offsetX = 0, const int offsetY = 0,
              const int width = 0, const int height = 0);

private:

};

#endif // LIBCOMMONIMAGEHANDLER_H
