#include <ApplicationClient.h>

#include <QCoreApplication>
#include <QDir>
#include <QGuiApplication>
#include <QLibraryInfo>
#include <QPluginLoader>
#include <QQuickView>
#include <QtQml>
ApplicationClient::ApplicationClient(QObject *parent)
    : ApplicationClientInterface(parent) {
  this->view = new QQuickView;
}

void ApplicationClient::start() {
  this->initialize();
  qmlRegisterSingletonType(
      "com.applicationclient", 1, 0, "App",
      [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QJSValue {
        Q_UNUSED(engine)
        QJSValue instance =
            scriptEngine->newQObject(ApplicationClient::instance());
        return instance;
      });

  this->view->setFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowSystemMenuHint | Qt::FramelessWindowHint);
  this->view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
  this->view->showMaximized();
}

void ApplicationClient::close() { this->view->close(); }

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
      }
    } catch (std::exception *exc) {
      qDebug() << exc->what();
    }
  }
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

#include "moc_ApplicationClient.cpp"
