#ifndef QCAMERA_H
#define QCAMERA_H

#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QString>
#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QLabel>

#include <QThread>

//#include "LibReadCode.h"
#include "LibCommon.h"
//#include "LibZXing.h"
#include "LibQZXing.h"

class QCamera : public QObject
{
    Q_OBJECT
public:
    explicit QCamera(QObject *parent = 0);
    ~QCamera();

    Q_INVOKABLE QString decoder(QObject *item);
    Q_INVOKABLE QString decoder(const QString& imageFilePath);

    Q_INVOKABLE void threadSleep();

signals:

public slots:

private:

};

#endif // QCAMERA_H
