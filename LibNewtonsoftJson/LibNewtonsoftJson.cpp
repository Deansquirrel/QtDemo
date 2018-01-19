#include "LibNewtonsoftJson.h"

//#using "lib\\net40\\Newtonsoft.Json.dll"
//using namespace Newtonsoft;


LibNewtonsoftJson::LibNewtonsoftJson()
{

}

QString LibNewtonsoftJson::ConvertJsontoXML(QString json)
{
    QString strT="";

    QLibrary myLib("ClassLibrary5.dll");
    myLib.load();
    if(!myLib.isLoaded()){
        qWarning()<<"ClassLibrary5.dll 加载失败";
        return "";
    }
    qDebug()<<"------------------------------------------------------------------------------------------------------";
    typedef char * (*DllfunSubConvertJsonToXML)(char *);
    DllfunSubConvertJsonToXML subConvertJsonToXML = (DllfunSubConvertJsonToXML) myLib.resolve("subConvertJsonToXML");
    if (subConvertJsonToXML){
        qDebug()<<"subConvertJsonToXML 函数加载成功";
        strT =subConvertJsonToXML(convertStrToChar(json));
        qDebug()<<"strT - "<<strT;
    }
    else{
        qDebug()<<"subConvertJsonToXML 函数不存在";
    }
    qDebug()<<"------------------------------------------------------------------------------------------------------";
//    typedef char * (*DllfunSubExportConvertByC)(char *);
//    DllfunSubExportConvertByC subExportConvertByC = (DllfunSubExportConvertByC) myLib.resolve("subExportConvertByC");
//    if (subExportConvertByC){
//        QString strT =subExportConvertByC(convertStrToChar(json));
//        qDebug()<<"strT - "<<strT;
//        qDebug()<<"subExportConvertByC 函数加载成功";
//    }
//    else{
//        qDebug()<<"subExportConvertByC 函数不存在";
//    }
//    qDebug()<<"------------------------------------------------------------------------------------------------------";
//    typedef void (*DllfunSubConvertByC)(char *);
//    DllfunSubConvertByC subConvertByC = (DllfunSubConvertByC) myLib.resolve("subConvertByC");
//    if (subConvertByC){
//        subConvertByC(convertStrToChar(json));
//        qDebug()<<"subConvertByC 函数加载成功";
//    }
//    else{
//        qDebug()<<"subConvertByC 函数不存在";
//    }
//    qDebug()<<"------------------------------------------------------------------------------------------------------";
//    typedef void (*DllfunSubTest)();
//    DllfunSubTest subTest = (DllfunSubTest) myLib.resolve("subTest");
//    if (subTest){
//        subTest();
//        qDebug()<<"subTest 函数加载成功";
//    }
//    else{
//        qDebug()<<"subTest 函数不存在";
//    }
//    qDebug()<<"------------------------------------------------------------------------------------------------------";
    myLib.unload();
    return strT;
}

char *LibNewtonsoftJson::convertStrToChar(QString str)
{
#ifdef Q_OS_WIN
    const char *charT = str.toStdString().c_str();
    char *buf=new char[strlen(charT)+1];
    strcpy_s(buf,strlen(charT)+1,charT);
    return buf;
#else
    char* a;
    return a;
#endif
}
