#ifndef CONFIRMBOX_H
#define CONFIRMBOX_H

#include <QObject>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>



#include <LibWidget.h>

#include "libwidget_global.h"

class LIBWIDGETSHARED_EXPORT ConfirmBox : public QDialog
{
    Q_OBJECT
public:
    explicit ConfirmBox(QDialog *parent = nullptr);

    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString confirmText READ getConfirmText WRITE setConfirmText NOTIFY confirmTextChanged)
    Q_PROPERTY(QString cancelText READ getCancelText WRITE setCancelText NOTIFY cancelTextChanged)

    Q_INVOKABLE void show();

    void setText(const QString text){ label->text() = text;}
    QString getText(){return label->text();}

    void setConfirmText(const QString confirmText){ confirm->text() = confirmText;}
    QString getConfirmText(){return confirm->text();}

    void setCancelText(const QString cancelText){ cancel->text() = cancelText;}
    QString getCancelText(){return cancel->text();}

signals:
    void textChanged();
    void confirmTextChanged();
    void cancelTextChanged();

    void confirmed();
    void canceled();

public slots:

private:
    QLabel * label;
    QPushButton * confirm;
    QPushButton * cancel;
};

#endif // CONFIRMBOX_H
