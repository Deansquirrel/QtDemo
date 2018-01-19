#include "LibWidget.h"

int LibWidget::_mVersion = 1;
int LibWidget::_sVersion = 0;

LibWidget::LibWidget()
{
}

void LibWidget::registerType()
{
    qmlRegisterType<ConfirmBox>("LibWidget",LibWidget::mVersion(),LibWidget::sVersion(),"ConfirmBox");
}

int LibWidget::mVersion()
{
    return _mVersion;
}

void LibWidget::setMVersion(int mVersion)
{
    _mVersion = mVersion;
}

int LibWidget::sVersion()
{
    return _sVersion;
}

void LibWidget::setSVersion(int sVersion)
{
    _sVersion = sVersion;
}
