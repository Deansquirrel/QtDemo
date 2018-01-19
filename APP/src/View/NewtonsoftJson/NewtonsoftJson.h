#ifndef NEWTONSOFTJSON_H
#define NEWTONSOFTJSON_H

#include <QObject>
#include <LibNewtonsoftJson.h>

class NewtonsoftJson : public QObject
{
    Q_OBJECT
public:
    explicit NewtonsoftJson(QObject *parent = nullptr);

    Q_INVOKABLE QString subConvertJsontoXML();

signals:

public slots:

private:

};

#endif // NEWTONSOFTJSON_H
