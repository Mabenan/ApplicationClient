#ifndef APPLICATION_H
#define APPLICATION_H

#include "ApplicationClientCore_global.h"
#include <QObject>
#include <QThread>
#include <QMap>
#include <QDebug>
#include <ApplicationClientInterface>


class APPLICATIONCLIENTCORE_EXPORT ApplicationClient : public ApplicationClientInterface
{
    Q_OBJECT
private:
    QMap<QString, QObject *> genericValues;
    QMap<QString, QList<QObject *>> genericListValues;
public:
    explicit ApplicationClient(QObject *parent = nullptr);
    void handleUserInput(QString);
        void initialize();
        QThread inputThread;

	virtual QList<QObject *> getValues(QString valueName) override;
	virtual void setValue(QString valueName, QObject * value) override;
	virtual void addValue(QString valueName, QObject * value) override;

signals:
    void finished();
    void startInput();
public slots:
    void start();

    // ApplicationClientInterface interface
public:
	virtual QObject * getValue(QString valueName) override;
};

#endif // APPLICATION_H
