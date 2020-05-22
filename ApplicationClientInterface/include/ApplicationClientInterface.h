#ifndef APPLICATIONClientINTERFACE_H
#define APPLICATIONClientINTERFACE_H

#include <ApplicationClientInterface_export.h>
#include <QObject>
#include <QString>
class APPLICATION_CLIENT_INTERFACE ApplicationClientInterface : public QObject {
  Q_OBJECT
public:
  ApplicationClientInterface(QObject *parent = nullptr) : QObject(parent) {}
  ApplicationClientInterface(ApplicationClientInterface *copy)
      : QObject(copy->parent()) {}
  ~ApplicationClientInterface() override = default;

  virtual QObject *getValue(QString valueName) = 0;
  virtual void setValue(QString valueName, QObject *value) = 0;
  virtual QList<QObject *> getValues(QString valueName) = 0;
  virtual void addValue(QString valueName, QObject *value) = 0;
};

#endif // APPLICATIONClientINTERFACE_H
