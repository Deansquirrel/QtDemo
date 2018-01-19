#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QString>

class Global : public QObject
{
    Q_OBJECT
public:
    explicit Global(QObject *parent = 0);

    Q_PROPERTY(int em READ getEm WRITE setEm NOTIFY emChanged)
    Q_PROPERTY(int defaultWidth READ getDefaultWidth CONSTANT)
    Q_PROPERTY(int defaultHeight READ getDefaultHeight CONSTANT)

    Q_PROPERTY(QString appName READ getAppName CONSTANT)
    Q_PROPERTY(QString version READ getVersion CONSTANT)
    Q_PROPERTY(QString showName READ getShowName CONSTANT)

    Q_PROPERTY(bool isAndroid READ getIsAndroid CONSTANT)
    Q_PROPERTY(bool isWindows READ getIsWindows CONSTANT)

    static int getEm();
    static void setEm(int em);

    static QString getVersion();
    static void setVersion(const QString &version);

    static int getDefaultWidth();
    static void setDefaultWidth(int defaultWidth);

    static int getDefaultHeight();
    static void setDefaultHeight(int defaultHeight);

    static QString getShowName();
    static void setShowName(const QString &showName);

    static QString getAppName();
    static void setAppName(const QString &appName);

    static QStringList getFontFamily();
    static void setFontFamily(const QStringList &fontFamily);

    static bool getIsAndroid();
    static void setIsAndroid(bool isAndroid);

    static bool getIsWindows();
    static void setIsWindows(bool isWindows);

signals:
    void emChanged(int _em);

public slots:

private:
    static int _em;
    static int _defaultWidth;
    static int _defaultHeight;

    //系统可用字体列表
    static QStringList _fontFamily;

    //APP信息
    static QString _version;
    static QString _appName;
    static QString _showName;

    static bool _isAndroid;
    static bool _isWindows;
};

#endif // GLOBAL_H
