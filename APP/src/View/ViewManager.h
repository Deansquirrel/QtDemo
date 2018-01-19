#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QJsonObject>
#include <QMap>

class ViewManager : public QObject
{
    Q_OBJECT
public:
    explicit ViewManager(QObject *parent = 0);

    Q_INVOKABLE void pushQml(QString viewKey,QJsonObject initData={});
    Q_INVOKABLE void popQml();

signals:
    void signalPushQml(QString viewUrl,QJsonObject initData);
    void signalPop();

public slots:

private:
    QMap<QString,QString> _viewUrlData;
};

#endif // VIEWMANAGER_H
