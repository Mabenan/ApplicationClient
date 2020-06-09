#include "closebutton.h"
#include <ApplicationClient.h>
CloseButton::CloseButton(QString name, QObject * parent) : Button(parent)
{
    this->m_name = name;
}


void CloseButton::clicked()
{
    ApplicationClient::instance()->close();
}

const QString CloseButton::name()
{
    return m_name;
}
