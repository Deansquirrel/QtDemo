#ifndef EVENTLOOPTEST_H
#define EVENTLOOPTEST_H

#include <QObject>
#include <QEventLoop>
#include <QDebug>

class EventLoopTest : public QObject
{
    Q_OBJECT
public:
    explicit EventLoopTest(QObject *parent = nullptr);

    Q_INVOKABLE void subTest();

    Q_INVOKABLE void confirmed();

signals:
    void signalShowPopup();
    void signalConfirmed();

public slots:
};

#endif // EVENTLOOPTEST_H
