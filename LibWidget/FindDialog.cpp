#include "FindDialog.h"

FindDialog::FindDialog(QDialog *parent) : QDialog(parent)
{
    label = new QLabel(tr("Find &what"));
    lineEdit = new QLineEdit();
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("&Close"));

    QObject::connect(lineEdit,SIGNAL(textChanged(QString)),
                     this,SLOT(enableFindButton(QString)));
    QObject::connect(findButton,SIGNAL(clicked(bool)),
                     this,SLOT(findClicked()));
    QObject::connect(closeButton,SIGNAL(clicked(bool)),
                     this,SLOT(close()));

    this->resize(350,150);

    QHBoxLayout* topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout* leftLayout = new QVBoxLayout();
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    //rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
}

FindDialog::~FindDialog()
{
    delete label;
    delete lineEdit;
    delete caseCheckBox;
    delete backwardCheckBox;
    delete findButton;
    delete closeButton;
}

void FindDialog::enableFindButton(const QString &str)
{

}

void FindDialog::findClicked()
{

}
