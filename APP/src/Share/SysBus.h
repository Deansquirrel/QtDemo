#ifndef SYSBUS_H
#define SYSBUS_H

#include <QObject>
#include <QString>
#include <QJsonObject>

class SysBus : public QObject
{
    Q_OBJECT
public:
    explicit SysBus(QObject *parent = 0);

signals:
    Q_INVOKABLE void lockScreen(QString msg="");
    Q_INVOKABLE void unlockScreen();

    Q_INVOKABLE void showSysNote(QString msg,int time = 3000);
    Q_INVOKABLE void loadQml(QString billKey,QJsonObject initData={});

public slots:
};

#endif // SYSBUS_H
