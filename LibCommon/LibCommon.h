#ifndef LIBCOMMON_H
#define LIBCOMMON_H

#include "libcommon_global.h"
#include "FileOperation.h"
#include "Environmental.h"
#include "SubCommon.h"
#include "LibCommonImageHandler.h"

#include <QImage>

class LIBCOMMONSHARED_EXPORT LibCommon
{

public:
    LibCommon();

    //FileOperation
    /**
     * @brief readIniFile 读取INI文件配置
     * @param file 文件名
     * @param group
     * @param key
     * @param defaultValue 默认值
     * @return
     */
    QString readIniFile(QString file,QString group,QString key,QString defaultValue);
    /**
     * @brief writeIniFile 保存INI文件配置
     * @param file 文件名
     * @param group
     * @param key
     * @param value
     */
    void writeIniFile(QString file,QString group,QString key,QString value);

    //Environmental
    /**
     * @brief getLocalMac  获取MAC地址
     * @return
     */
    QString getLocalMac();
    /**
     * @brief getLocalHostName 获取主机名称
     * @return
     */
    QString getLocalHostName();
    /**
     * @brief getLocalIP 获取本机IP
     * @return
     */
    QString getLocalIP();

    //SubCommon
    /**
     * @brief getMD5 获取字符串MD5值
     * @param data
     * @return
     */
    QString getMD5(QString data);

    //LibCommonImageHandler
    QImage extractQImage(QObject *imageObj,
                         int offsetX = 0, int offsetY = 0,
                         int width = 0, int height = 0);

//    void saveQImage(QObject *imageObj, const QString &path,
//              const int offsetX = 0, const int offsetY = 0,
//              const int width = 0, const int height = 0);

private:
    FileOperation _fileOperation;
};

#endif // LIBCOMMON_H
