#include "closebutton.h"
#include <ApplicationClient.h>
CloseButton::CloseButton(QObject * parent) : Button(parent)
{

}


void CloseButton::clicked()
{
    ApplicationClient::instance()->close();
}

const QString CloseButton::name()
{
    return QStringLiteral("Close");
}
