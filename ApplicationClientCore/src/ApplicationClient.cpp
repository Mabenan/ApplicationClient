#include <ApplicationClient.h>

#include <QCoreApplication>
#include <QDir>
#include <QGuiApplication>
#include <QLibraryInfo>
#include <QPluginLoader>
#include <QQuickView>
#include <QtQml>
#include <closebutton.h>
#include <QScreen>
#include <QMessageBox>
#include <QQuickStyle>
ApplicationClient *ApplicationClient::_instance = 0;
ApplicationClient::ApplicationClient(QObject *parent)
    : ApplicationClientInterface(parent)  {
    QQuickStyle::setStyle("Material");
    qmlRegisterSingletonType(
        "com.applicationclient", 1, 0, "App",
        [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QJSValue {
          Q_UNUSED(engine)
          QJSValue instance =
              scriptEngine->newQObject(ApplicationClient::instance());
          return instance;
        });
}

void ApplicationClient::start() {
  this->initialize();
}

void ApplicationClient::close() { QGuiApplication::quit(); }

void ApplicationClient::checkScreen(QQuickWindow *window)
{
    QPoint windowPosition = window->position();
    QScreen *screen = QGuiApplication::screenAt(window->position());
    if(screen != nullptr){
    if(screen != window->screen()){
        window->setScreen(screen);
    }
    windowPosition = window->position();
    if(windowPosition.y() <= 0){
        window->setVisibility(QQuickWindow::Maximized);
        windowPosition.setX(screen->geometry().right());
        windowPosition.setY(screen->geometry().top());
    }
    }

}

void ApplicationClient::initialize() {

  // Init parameters to connect to database
  qx::service::QxConnect::getSingleton()->setIp("localhost");
  qx::service::QxConnect::getSingleton()->setPort(8001);
  qx::service::QxConnect::getSingleton()->setMaxWait(600000);
  qx::service::QxConnect::getSingleton()->setSerializationType(
      qx::service::QxConnect::serialization_json);

  QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());
  pluginsDir.cd("plugins");
  pluginsDir.cd("client");
  const auto entryList = pluginsDir.entryList(QDir::Files);
  for (const QString &fileName : entryList) {
    try {
      QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
      QObject *plugin = loader.instance();
      auto pluginInterface =
          qobject_cast<ApplicationClientPluginInterface *>(plugin);
      if (pluginInterface) {
        pluginInterface->install(this);
        pluginInterface->init(this);
        plugins.insert(pluginInterface->getName(), pluginInterface);
      }
    } catch (std::exception *exc) {
      qDebug() << exc->what();
    }
  }
  this->engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}

QObject *ApplicationClient::getValue(QString valueName) {
  if (!this->genericValues.contains(valueName)) {
    return nullptr;
  }
  return this->genericValues[valueName];
}

QList<QObject *> ApplicationClient::getValues(QString valueName) {
  if (!this->genericListValues.contains(valueName)) {
    return QList<QObject *>();
  }
  return this->genericListValues[valueName];
}

void ApplicationClient::setValue(QString valueName, QObject *value) {
  if (!this->genericValues.contains(valueName)) {
    this->genericValues.insert(valueName, value);
  }
  this->genericValues[valueName] = value;
}

void ApplicationClient::addValue(QString valueName, QObject *value) {
  if (!this->genericListValues.contains(valueName)) {
    this->genericListValues.insert(valueName, QList<QObject *>());
  }
  this->genericListValues[valueName].append(value);
}

QVariant ApplicationClient::makeAccisable(QString column, int row, qx::IxModel *model)
{
    int index = model->getColumnIndex(column);
    qx::IxDataMember * member = model->getDataMember(index);
    QVariant input = model->getModelValue(row, column);
    qx::IxFunction::type_any_params params;
    params.push_back(input);
    params.push_back(column);
    qx::any anyRet;
    qx::QxClassX::invokeStatic(member->getParent()->getClass()->getKey(), "makeAccisable",params, &anyRet);
    return qx::any_cast<QVariant>(anyRet);
}



void ApplicationClient::addDashboardItem(DashboardItem *item)
{
    this->m_dashboardModel.AddItem(item);
}

void ApplicationClient::addSideMenuButton(Button *button)
{
    this->m_buttonModel.AddButton(button);
}


void ApplicationClient::removeDashboardItem(DashboardItem *item)
{
    this->m_dashboardModel.RemoveItem(item);
}

void ApplicationClient::removeSideMenuButton(Button *item)
{
    this->m_buttonModel.RemoveButton(item);
}


ApplicationClientPluginInterface *ApplicationClient::GetPlugin(const QString &pluginName)
{
    if(this->plugins.contains(pluginName)){
        return this->plugins.value(pluginName);
    }else{
        return nullptr;
    }
}

#include "moc_ApplicationClient.cpp"


void ApplicationClient::setMessageTexts(const QString &content, const QString &title)
{
    this->m_messageTitle = title;
    this->m_messageContent = content;
    messageTitleChanged();
    messageContentChanged();
}

void ApplicationClient::information(const QString &title, const QString &content)
{
    this->m_showMessageBox = true;
    this->m_messageIcon = QMessageBox::Icon::Information;
    setMessageTexts(content, title);
    messageIconChanged();
    showMessageBoxChanged();
}

void ApplicationClient::error(const QString &title, const QString &content)
{
    this->m_showMessageBox = true;
    this->m_messageIcon = QMessageBox::Icon::Critical;
    setMessageTexts(content, title);
    messageIconChanged();
    showMessageBoxChanged();
}

void ApplicationClient::warning(const QString &title, const QString &content)
{
    this->m_showMessageBox = true;
    this->m_messageIcon = QMessageBox::Icon::Warning;
    setMessageTexts(content, title);
    messageIconChanged();
    showMessageBoxChanged();
}
