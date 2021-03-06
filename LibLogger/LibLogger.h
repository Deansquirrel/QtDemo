#ifndef LIBLOGGER_H
#define LIBLOGGER_H

#include "liblogger_global.h"
#include "LibLoggerWorker.h"

#include <QString>

class LIBLOGGERSHARED_EXPORT LibLogger
{

public:
    LibLogger();

    enum LogLevel {
        LOGLEVEL_DEBUG,
        LOGLEVEL_INFO,
        LOGLEVEL_WARN,
        LOGLEVEL_ERROR};

    void loggerInit(QString logPath,QString folder,QString filePrefix,QString fileSuffix,LogLevel level);
    QString getLoggerPath();
    QString getLoggerFolder();
    QString getLoggerLevel();
    void setLoggerLevel(const LogLevel &level);

    bool getEnabled(){ return _libLoggerWorker.getEnabled();}
    void setEnabled(bool enabled){ _libLoggerWorker.setEnabled(enabled);}

    void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private:
    LibLoggerWorker _libLoggerWorker;
    LibLoggerWorker::LogLevel _logLevelConvert(LogLevel level);
};

#endif // LIBLOGGER_H
