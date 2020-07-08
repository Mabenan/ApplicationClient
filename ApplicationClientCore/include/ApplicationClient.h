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
#include <QMessageBox>


class APPLICATIONCLIENTCORE_EXPORT ApplicationClient
    : public ApplicationClientInterface {
  Q_OBJECT
  Q_PROPERTY(QVariant buttonModel READ buttonModel)
  Q_PROPERTY(QVariant dashboardModel READ dashboardModel)
  Q_PROPERTY(bool showMessageBox READ getshowMessageBox WRITE setshowMessageBox NOTIFY showMessageBoxChanged )
    Q_PROPERTY(QMessageBox::Icon messageIcon READ getmessageIcon NOTIFY messageIconChanged )
    Q_PROPERTY(QString messageTitle READ getmessageTitle NOTIFY messageTitleChanged )
    Q_PROPERTY(QString messageContent READ getmessageContent NOTIFY messageContentChanged )
    Q_PROPERTY(QVariant mainView READ getMainView NOTIFY mainViewChanged )
private:
  QMap<QString, QObject *> genericValues;
  QMap<QString, QList<QObject *>> genericListValues;
  explicit ApplicationClient(QObject *parent = nullptr);
  static ApplicationClient *_instance;
  bool m_showMessageBox = false;
  QMessageBox::Icon m_messageIcon = QMessageBox::Icon::NoIcon;
  QString m_messageTitle = QLatin1String("");
  QString m_messageContent = QLatin1String("");
  QThread inputThread;
  QQmlApplicationEngine engine;
  ButtonModel m_buttonModel;
  DashboardModel m_dashboardModel;
  QMap<QString, ApplicationClientPluginInterface* > plugins;
  QObject * m_mainView;

  void setMessageTexts(const QString &content, const QString &title);

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

  bool getshowMessageBox(){
      return m_showMessageBox;
  }

  void setshowMessageBox(const bool & showMessageBox){
      m_showMessageBox = showMessageBox;
  }

  QMessageBox::Icon getmessageIcon(){
      return m_messageIcon;
  }

  QString getmessageTitle(){
      return m_messageTitle;
  }

  QString getmessageContent(){
      return m_messageContent;
  }

  QVariant getMainView(){
      return QVariant::fromValue(m_mainView);
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
  void showMessageBoxChanged();
  void messageIconChanged();
  void messageTitleChanged();
  void messageContentChanged();
  void mainViewChanged();
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

  // ApplicationClientInterface interface
public:
  void information(const QString &title, const QString &content) override;
  void error(const QString &title, const QString &content) override;

  // ApplicationClientInterface interface
public:
  void warning(const QString &title, const QString &content) override;

  // ApplicationClientInterface interface
public:
  void showView(QObject *view) override;
};
#endif // APPLICATION_H
