#include "Test.h"

Test::Test(QObject *parent) : QObject(parent)
{
}

void Test::subTest()
{
    QString testStr = "testStr";
    LibCryptoInQt libCryptoInQt;
    qDebug()<<"---------------------------------------------------------------------";
    QString result = "";
    try{
        result = libCryptoInQt.CalcDynamicDigestCode4Len5(QDateTime::currentDateTime(),testStr);
    }
    catch(QString errmsg){
        qDebug()<<"errmsg - "<<errmsg;
        return;
    }
    qDebug()<<"5位动态数字摘要字符串 - "<<result;
    qDebug()<<"---------------------------------------------------------------------";
    qDebug()<<"当前时间验证";
    qDebug()<< libCryptoInQt.VerifyDynamicDigestCode4Len5(QDateTime::currentDateTime(),testStr,result);
    qDebug()<<"---------------------------------------------------------------------";
    qDebug()<<"当前时间 + 9 验证";
    qDebug()<<libCryptoInQt.VerifyDynamicDigestCode4Len5(QDateTime::currentDateTime().addSecs(60 * 9),testStr,result);
    qDebug()<<"---------------------------------------------------------------------";
    qDebug()<<"当前时间 + 11 验证";
    qDebug()<<libCryptoInQt.VerifyDynamicDigestCode4Len5(QDateTime::currentDateTime().addSecs(60 * 11),testStr,result);
    qDebug()<<"---------------------------------------------------------------------";
    qDebug()<<"当前时间 - 9 验证";
    qDebug()<<libCryptoInQt.VerifyDynamicDigestCode4Len5(QDateTime::currentDateTime().addSecs(-60 * 9),testStr,result);
    qDebug()<<"---------------------------------------------------------------------";
    qDebug()<<"当前时间 - 11 验证";
    qDebug()<<libCryptoInQt.VerifyDynamicDigestCode4Len5(QDateTime::currentDateTime().addSecs(-60 * 11),testStr,result);
    qDebug()<<"---------------------------------------------------------------------";
    qDebug()<<"异常字符串 验证";
    qDebug()<<libCryptoInQt.VerifyDynamicDigestCode4Len5(QDateTime::currentDateTime(),"testStr2",result);
    qDebug()<<"---------------------------------------------------------------------";

}
