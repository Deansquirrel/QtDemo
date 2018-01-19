QT += qml quick widgets multimedia gui core

CONFIG += c++11

TARGET = QtDemo

#是否为调试模式，正式编译时注释下面一行
DEFINES += SETTINGS_DEBUG

SOURCES += main.cpp \
    src/Share/Global.cpp \
    src/Share/SysBus.cpp \
    src/Share/SysConfig.cpp \
    src/Main/CMain.cpp \
    src/Boot/Boot.cpp \
    src/Boot/SubBoot.cpp \
    src/View/ViewManager.cpp \
    src/View/QCamera/QCamera.cpp \
    src/Share/ImageProvider/ImageProviderByQZXingEncode.cpp \
    src/View/SelectList/SelectList.cpp \
    src/Com/ComSelectList/ComSelectList.cpp \
    src/View/EventLoopTest/EventLoopTest.cpp \
    src/View/NewtonsoftJson/NewtonsoftJson.cpp \
    src/View/WeidgetTest/WeidgetTest.cpp \
    src/View/Test/Test.cpp

RESOURCES += \
    res/image.qrc \
    res/qml_com.qrc \
    res/qml_main.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH = $$PWD/../Plugin/
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#Release模式下，日志输出文件及行号
DEFINES += QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_FILE = ./myapp.rc

HEADERS += \
    src/Share/Global.h \
    src/Share/SysBus.h \
    src/Share/SysConfig.h \
    src/Main/CMain.h \
    src/Boot/Boot.h \
    src/Boot/SubBoot.h \
    src/View/ViewManager.h \
    src/View/QCamera/QCamera.h \
    src/Share/ImageProvider/ImageProviderByQZXingEncode.h \
    src/View/SelectList/SelectList.h \
    src/Com/ComSelectList/ComSelectList.h \
    src/View/EventLoopTest/EventLoopTest.h \
    src/View/NewtonsoftJson/NewtonsoftJson.h \
    src/View/WeidgetTest/WeidgetTest.h \
    src/View/Test/Test.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibCommon/release/ -lLibCommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibCommon/debug/ -lLibCommon
else:unix: LIBS += -L$$OUT_PWD/../LibCommon/ -lLibCommon

INCLUDEPATH += $$PWD/../LibCommon
DEPENDPATH += $$PWD/../LibCommon

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibLogger/release/ -lLibLogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibLogger/debug/ -lLibLogger
else:unix: LIBS += -L$$OUT_PWD/../LibLogger/ -lLibLogger

INCLUDEPATH += $$PWD/../LibLogger
DEPENDPATH += $$PWD/../LibLogger

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibQZXing/release/ -lLibQZXing
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibQZXing/debug/ -lLibQZXing
else:unix: LIBS += -L$$OUT_PWD/../LibQZXing/ -lLibQZXing

INCLUDEPATH += $$PWD/../LibQZXing
DEPENDPATH += $$PWD/../LibQZXing

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibNewtonsoftJson/release/ -lLibNewtonsoftJson
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibNewtonsoftJson/debug/ -lLibNewtonsoftJson
else:unix: LIBS += -L$$OUT_PWD/../LibNewtonsoftJson/ -lLibNewtonsoftJson

INCLUDEPATH += $$PWD/../LibNewtonsoftJson
DEPENDPATH += $$PWD/../LibNewtonsoftJson

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibWidget/release/ -lLibWidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibWidget/debug/ -lLibWidget
else:unix: LIBS += -L$$OUT_PWD/../LibWidget/ -lLibWidget

INCLUDEPATH += $$PWD/../LibWidget
DEPENDPATH += $$PWD/../LibWidget

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/res/values-zh-rCN/strings.xml \
    android/res/values/style.xml \
    android/res/values/color.xml \
    qmldir

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibCryptoInQt/release/ -lLibCryptoInQt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibCryptoInQt/debug/ -lLibCryptoInQt
else:unix: LIBS += -L$$OUT_PWD/../LibCryptoInQt/ -lLibCryptoInQt

INCLUDEPATH += $$PWD/../LibCryptoInQt
DEPENDPATH += $$PWD/../LibCryptoInQt
