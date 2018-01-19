#include "Global.h"

int Global::_em = 0;
//int Global::_defaultHeight = 618;
//int Global::_defaultWidth = 360;
int Global::_defaultHeight = 768;
int Global::_defaultWidth = 1024;

QStringList Global::_fontFamily;

QString Global::_appName = "";
QString Global::_version = "";
QString Global::_showName = "";

bool Global::_isAndroid=false;
bool Global::_isWindows=false;

Global::Global(QObject *parent) : QObject(parent)
{

}

int Global::getEm()
{
    return _em;
}

void Global::setEm(int em)
{
    _em = em;
}

QString Global::getVersion()
{
    return _version;
}

void Global::setVersion(const QString &version)
{
    _version = version;
}

int Global::getDefaultWidth()
{
    return _defaultWidth;
}

void Global::setDefaultWidth(int defaultWidth)
{
    _defaultWidth = defaultWidth;
}

int Global::getDefaultHeight()
{
    return _defaultHeight;
}

void Global::setDefaultHeight(int defaultHeight)
{
    _defaultHeight = defaultHeight;
}

QString Global::getShowName()
{
    return _showName;
}

void Global::setShowName(const QString &showName)
{
    _showName = showName;
}

QString Global::getAppName()
{
    return _appName;
}

void Global::setAppName(const QString &appName)
{
    _appName = appName;
}

QStringList Global::getFontFamily()
{
    return _fontFamily;
}

void Global::setFontFamily(const QStringList &fontFamily)
{
    _fontFamily = fontFamily;
}

bool Global::getIsAndroid()
{
    return _isAndroid;
}

void Global::setIsAndroid(bool isAndroid)
{
    _isAndroid = isAndroid;
}

bool Global::getIsWindows()
{
    return _isWindows;
}

void Global::setIsWindows(bool isWindows)
{
    _isWindows = isWindows;
}
