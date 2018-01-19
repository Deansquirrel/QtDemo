#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "libwidget_global.h"

class LIBWIDGETSHARED_EXPORT FindDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FindDialog(QDialog *parent = nullptr);
    ~FindDialog();

signals:
    void findNext(const QString &str,Qt::CaseSensitivity cs);
    void findPrevious(const QString &str,Qt::CaseSensitivity cs);

public slots:

private slots:
    void enableFindButton(const QString &str);
    void findClicked();

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

#endif // FINDDIALOG_H
