#ifndef SYSCONFIG_H
#define SYSCONFIG_H

#include <QObject>
#include <QString>

#include <QJsonObject>

#include "LibCommon.h"

class SysConfig : public QObject
{
    Q_OBJECT
public:
    explicit SysConfig(QObject *parent = 0);

    QJsonObject getUI();

    QString getServiceUrl() const;
    void setServiceUrl(const QString &serviceUrl);

    QString getServiceKey() const;
    void setServiceKey(const QString &serviceKey);

signals:

public slots:

private:
};

#endif // SYSCONFIG_H
