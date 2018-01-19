#ifndef LIBWIDGET_H
#define LIBWIDGET_H

#include "libwidget_global.h"

#include "ConfirmBox.h"

#include <QQmlApplicationEngine>

class LIBWIDGETSHARED_EXPORT LibWidget
{

public:
    LibWidget();

    static void registerType();

    static int mVersion();
    static void setMVersion(int mVersion);

    static int sVersion();
    static void setSVersion(int sVersion);

private:
    static int _mVersion;
    static int _sVersion;
};

#endif // LIBWIDGET_H
