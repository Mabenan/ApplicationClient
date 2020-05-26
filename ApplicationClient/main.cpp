#include <ApplicationClient.h>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication a(argc, argv);

  qDebug() << QCoreApplication::applicationDirPath();
  ApplicationClient *app = ApplicationClient::instance();
  // This will cause the application to exit when
  // the task signals finished.
  QObject::connect(app, SIGNAL(finished()), &a, SLOT(quit()));

  // This will run the task from the application event loop.
  app->start();
  // QTimer::singleShot(0, app, SLOT(start()));
  return a.exec();
}
