#ifndef APPLICATION_H
#define APPLICATION_H

#include "ApplicationClientCore_global.h"
#include <ApplicationClientCore.Precompiled.h>
#include <ApplicationClientInterface>
#include <QDebug>
#include <QMap>
#include <QObject>
#include <QQuickView>
#include <QThread>
#include <QQmlApplicationEngine>
#include <ButtonModel.h>
#include <DashboardModel.h>
#include <QxModelView.h>

class APPLICATIONCLIENTCORE_EXPORT ApplicationClient
    : public ApplicationClientInterface {
  Q_OBJECT
  Q_PROPERTY(QVariant buttonModel READ buttonModel)

    Q_PROPERTY(QVariant dashboardModel READ dashboardModel)
private:
  QMap<QString, QObject *> genericValues;
  QMap<QString, QList<QObject *>> genericListValues;
  explicit ApplicationClient(QObject *parent = nullptr);
  static ApplicationClient *_instance;

  QThread inputThread;
  QQmlApplicationEngine engine;
  ButtonModel m_buttonModel;
  DashboardModel m_dashboardModel;
  QMap<QString, ApplicationClientPluginInterface* > plugins;

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

  Q_INVOKABLE QVariant makeAccisable(QString column,int row, qx::IxModel * model);

  QVariant buttonModel(){
      return QVariant::fromValue(&m_buttonModel);
  }

  QVariant dashboardModel(){
      return QVariant::fromValue(&m_dashboardModel);
  }

Q_SIGNALS:
  void finished();
public Q_SLOTS:
  void start();
  void close();
  void checkScreen(QQuickWindow * window);

  // ApplicationClientInterface interface
public:
  QObject *getValue(QString valueName) override;

  // ApplicationClientInterface interface
public:
  void addDashboardItem(DashboardItem *item) override;
  void addSideMenuButton(Button *button) override;

  // ApplicationClientInterface interface
public:
  void removeDashboardItem(DashboardItem *item) override;
  void removeSideMenuButton(Button *item) override;

  // ApplicationClientInterface interface
public:
  ApplicationClientPluginInterface *GetPlugin(const QString &pluginName) override;
};
#endif // APPLICATION_H
