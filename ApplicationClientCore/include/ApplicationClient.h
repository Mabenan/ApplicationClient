#ifndef APPLICATION_H
#define APPLICATION_H

#include "ApplicationClientCore_global.h"
#include <ApplicationClientInterface>
#include <QDebug>
#include <QMap>
#include <QObject>
#include <QQuickView>
#include <QThread>

class APPLICATIONCLIENTCORE_EXPORT ApplicationClient
    : public ApplicationClientInterface {
  Q_OBJECT
private:
  QMap<QString, QObject *> genericValues;
  QMap<QString, QList<QObject *>> genericListValues;
  explicit ApplicationClient(QObject *parent = nullptr);
  static ApplicationClient *_instance;
  QQuickView *view;
  QThread inputThread;

public:
  void handleUserInput(QString);
  void initialize();

  QList<QObject *> getValues(QString valueName) override;
  void setValue(QString valueName, QObject *value) override;
  void addValue(QString valueName, QObject *value) override;
  static ApplicationClient *instance() {
    if (!_instance)
      _instance = new ApplicationClient();
    return _instance;
  }
Q_SIGNALS:
  void finished();
public Q_SLOTS:
  void start();
  void close();

  // ApplicationClientInterface interface
public:
  QObject *getValue(QString valueName) override;
};
#if defined(APPLICATIONCLIENTCORE_LIBRARY)
ApplicationClient *ApplicationClient::_instance = 0;
#endif
#endif // APPLICATION_H
