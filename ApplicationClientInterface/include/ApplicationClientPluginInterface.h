#ifndef ApplicationClientPluginInterface_H
#define ApplicationClientPluginInterface_H

#include <ApplicationClientInterface>

#include <QObject>
#include <QtPlugin>
#include <qstring.h>
#include <ApplicationClientInterface_export.h>
#define ApplicationClientPluginInterface_iid "com.applicationClient.ApplicationClientPluginInterface/1.0"

class APPLICATION_CLIENT_INTERFACE ApplicationClientPluginInterface : public QObject
{
    Q_OBJECT
public:
    ApplicationClientPluginInterface(QObject* parent): QObject(parent){

    }
    virtual~ApplicationClientPluginInterface(){}
    virtual void init(ApplicationClientInterface * app) = 0;
    virtual void install(ApplicationClientInterface * app) = 0;
};

Q_DECLARE_INTERFACE(ApplicationClientPluginInterface, ApplicationClientPluginInterface_iid)
#endif // ApplicationClientPluginInterface_H
