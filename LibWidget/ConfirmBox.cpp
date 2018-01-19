#include "ConfirmBox.h"

ConfirmBox::ConfirmBox(QDialog *parent) : QDialog(parent)
{
    this->setWindowFlags(Qt::Popup);

    label = new QLabel();

    confirm = new QPushButton();
    confirm->setDefault(true);
    confirm->setText("确定");

    QObject::connect(confirm,SIGNAL(clicked(bool)),this,SIGNAL(confirmed()));

    cancel = new QPushButton();
    cancel->setText("取消");

    QObject::connect(cancel,SIGNAL(clicked(bool)),this,SIGNAL(canceled()));

    QHBoxLayout * btnLayout = new QHBoxLayout();
    btnLayout->addWidget(cancel);
    btnLayout->addWidget(confirm);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addWidget(label);
    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);
}

void ConfirmBox::show()
{
    this->show();
}
