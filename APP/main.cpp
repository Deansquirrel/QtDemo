#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QTextCodec>
#include <QStringList>
#include <QString>
#include <QFont>
#include <QFontDatabase>
#include <QJsonObject>
#include <QDebug>
#include <QList>
#include <QQmlError>
#include <QStandardPaths>

#include "src/Share/Global.h"
#include "src/Share/SysBus.h"
#include "src/Share/SysConfig.h"
#include "src/Share/ImageProvider/ImageProviderByQZXingEncode.h"

#include "src/Main/CMain.h"
#include "src/Boot/Boot.h"
#include "src/View/ViewManager.h"

#include "LibLogger.h"

#include "LibWidget.h"

void myMessageOutput(QtMsgType type,const QMessageLogContext &context,const QString &msg){
    LibLogger libLogger;
    libLogger.outputMessage(type,context,msg);
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);

    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QQmlApplicationEngine engine;

    LibWidget::registerType();

//    --------------------------------------------------------------------------------
//    编译时根据日志情况进行设置

    #ifndef SETTINGS_DEBUG
    qInstallMessageHandler(myMessageOutput);
    LibLogger libLogger;
    libLogger.setEnabled(true);
    libLogger.loggerInit(QStandardPaths::writableLocation((QStandardPaths::GenericDataLocation)),"A_myLog","","log",LibLogger::LOGLEVEL_INFO);
    #endif
//    --------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    //解析启动参数
//    QStringList arg =  app.arguments();
//    logger.debug("启动参数 - " + arg.join("|"));
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
//    注册图片提供类
//    engine.addImageProvider(QLatin1String("img"), new ImageProviderByQZXingEncode());
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    //注册QML可用CPP类
    qmlRegisterType<CMain>("com.main",1,0,"CMain");
    qmlRegisterType<Boot>("com.boot",1,0,"CBoot");
    qmlRegisterType<ViewManager>("com.view.viewmanager",1,0,"CViewManager");
    //--------------------------------------------------------------------------------
//    engine.addImportPath("../QmlPlugin/PSelectList");
//    qDebug()<<engine.importPathList();

//    engine.addImportPath("E:/T/QMLPlugin/QMLPluginTest/")
    //--------------------------------------------------------------------------------
    //注册QML全局对象
    SysBus sysBus;
    engine.rootContext()->setContextProperty("sysBus",&sysBus);

    Global global;
    engine.rootContext()->setContextProperty("global",&global);

    SysConfig sysConfig;
    engine.rootContext()->setContextProperty("sysConfig",&sysConfig);

    QJsonObject ui = sysConfig.getUI();
    engine.rootContext()->setContextProperty("ui",ui);
    //--------------------------------------------------------------------------------
    //字体
    QFontDatabase fontDatabase;
//        QStringList fontList=fontDatabase.families(QFontDatabase::SimplifiedChinese);
    QStringList fontList=fontDatabase.families(QFontDatabase::Any);
    Global::setFontFamily(fontList);
    QString fontName="";

    #ifdef Q_OS_ANDROID
        Global::setIsAndroid(true);
    #endif

    #ifdef Q_OS_WIN
        Global::setIsWindows(true);
    #endif

    #ifdef Q_OS_ANDROID
    //定义安卓下默认字体
    if(fontList.contains("Roboto")){
        fontName="Roboto";
    }
    if(fontList.contains("Noto Sans SC")){
        fontName="Noto Sans SC";
    }
    #endif

    #ifdef Q_OS_WIN
    //定义Windows下默认字体
    if(fontList.contains("黑体")){
        fontName="黑体";
    }
    if(fontList.contains("微软雅黑")){
        fontName="微软雅黑";
    }
    if(fontList.contains("Microsoft YaHei UI")){
        fontName="Microsoft YaHei UI";
    }
    #endif
    if(fontName!=""){
        QFont font(fontName);
        QApplication::setFont(font);
    }
    //--------------------------------------------------------------------------------

    //界面元素初始化
    Global::setEm(16);

    Global::setDefaultHeight(618);
    Global::setDefaultWidth(360);

//    Global::setDefaultHeight(767);
//    Global::setDefaultWidth(1024);
    //--------------------------------------------------------------------------------

    engine.load(QUrl(QLatin1String("qrc:/qml_main/Main/Main.qml")));
    qInfo()<<"系统启动";
    return app.exec();
}
