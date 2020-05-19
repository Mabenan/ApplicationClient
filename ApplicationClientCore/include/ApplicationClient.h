#ifndef APPLICATION_H
#define APPLICATION_H

#include "ApplicationClientCore_global.h"
#include <QObject>
#include <QThread>
#include <QMap>
#include <QDebug>
#include <ApplicationClientInterface>
#include <QQuickView>


class APPLICATIONCLIENTCORE_EXPORT ApplicationClient : public ApplicationClientInterface
{
    Q_OBJECT
private:
    QMap<QString, QObject *> genericValues;
    QMap<QString, QList<QObject *>> genericListValues;
    explicit ApplicationClient();
    static ApplicationClient * _instance;
    QQuickView *view ;
public:

    void handleUserInput(QString);
        void initialize();
        QThread inputThread;

	virtual QList<QObject *> getValues(QString valueName) override;
	virtual void setValue(QString valueName, QObject * value) override;
	virtual void addValue(QString valueName, QObject * value) override;
	  static ApplicationClient* instance ()
	    {
	       if (!_instance)
	          _instance = new ApplicationClient ();
	       return _instance;
	    }
signals:
    void finished();
public slots:
    void start();
	void close();

    // ApplicationClientInterface interface
public:
	virtual QObject * getValue(QString valueName) override;
};
#if defined(APPLICATIONCLIENTCORE_LIBRARY)
ApplicationClient* ApplicationClient::_instance = 0;
#endif
#endif // APPLICATION_H
