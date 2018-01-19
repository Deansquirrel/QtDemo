#ifndef LIBNEWTONSOFTJSON_H
#define LIBNEWTONSOFTJSON_H

#include "libnewtonsoftjson_global.h"

#include <QDebug>
#include <QLibrary>

class LIBNEWTONSOFTJSONSHARED_EXPORT LibNewtonsoftJson
{

public:
    LibNewtonsoftJson();

    QString ConvertJsontoXML(QString json);

private:
    char *convertStrToChar(QString str);
};

#endif // LIBNEWTONSOFTJSON_H
