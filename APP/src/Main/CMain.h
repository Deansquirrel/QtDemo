#ifndef CMAIN_H
#define CMAIN_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QJsonObject>
#include <QMap>

class CMain : public QObject
{
    Q_OBJECT
public:
    explicit CMain(QObject *parent = 0);

    Q_INVOKABLE void loadQml(QString billKey,QJsonObject initData);

signals:
    void signalLoadQml(QString billUrl,QJsonObject billData);

public slots:

private:
    QMap<QString,QString> _billUrlData;
};

#endif // CMAIN_H
