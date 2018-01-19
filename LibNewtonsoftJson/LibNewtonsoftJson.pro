#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T17:27:49
#
#-------------------------------------------------

QT       -= gui

TARGET =  LibNewtonsoftJson
TEMPLATE = lib

DEFINES += LIBNEWTONSOFTJSON_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        LibNewtonsoftJson.cpp

HEADERS += \
        LibNewtonsoftJson.h \
        libnewtonsoftjson_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32 {
    src_dir = $$PWD\*.dll
    CONFIG(debug, debug|release) {
        dst_dir = $$OUT_PWD\\debug\\
    } else {
        dst_dir = $$OUT_PWD\\release\\
    }

    # dst_dir 最后的 \\ 是必须的，用来标示 xcopy 到一个文件夹，若不存在，创建之

    # Replace slashes in paths with backslashes for Windows
    src_dir ~= s,/,\\,g
    dst_dir ~= s,/,\\,g

#    !exists($$dst_dir):system(xcopy $$src_dir $$dst_dir /y /e)
    system(xcopy $$src_dir $$dst_dir /y /e)
}

DISTFILES += \
    ClassLibrary5.dll \
    Newtonsoft.Json.dll
