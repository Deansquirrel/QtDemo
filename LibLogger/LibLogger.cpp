#include "LibLogger.h"

LibLogger::LibLogger()
{
}

void LibLogger::loggerInit(QString logPath,QString folder, QString filePrefix, QString fileSuffix, LogLevel level)
{
    _libLoggerWorker.init(logPath,folder,filePrefix,fileSuffix,this->_logLevelConvert(level));
}

QString LibLogger::getLoggerPath()
{
    return _libLoggerWorker.getPath();
}

QString LibLogger::getLoggerFolder()
{
    return _libLoggerWorker.getFolder();
}

QString LibLogger::getLoggerLevel()
{
    return _libLoggerWorker.getLevel();
}

void LibLogger::setLoggerLevel(const LogLevel &level)
{
    _libLoggerWorker.setLevel(this->_logLevelConvert(level));
}

void LibLogger::outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(getEnabled()){
        _libLoggerWorker.outputMessage(type,context,msg);
    }
}

LibLoggerWorker::LogLevel LibLogger::_logLevelConvert(LibLogger::LogLevel level)
{
    LibLoggerWorker::LogLevel logLevel;
    switch (level) {
    case LibLogger::LOGLEVEL_DEBUG:
        logLevel=LibLoggerWorker::LOGLEVEL_DEBUG;
        break;
    case LibLogger::LOGLEVEL_INFO:
        logLevel=LibLoggerWorker::LOGLEVEL_INFO;
        break;
    case LibLogger::LOGLEVEL_WARN:
        logLevel=LibLoggerWorker::LOGLEVEL_WARN;
        break;
    case LibLogger::LOGLEVEL_ERROR:
        logLevel=LibLoggerWorker::LOGLEVEL_ERROR;
        break;
    default:
        logLevel=LibLoggerWorker::LOGLEVEL_WARN;
        break;
    }
    return logLevel;
}
