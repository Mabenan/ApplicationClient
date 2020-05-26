#ifndef DASHBOARDITEM_H
#define DASHBOARDITEM_H
#include "ApplicationClientInterface_export.h"
#include <QObject>
class APPLICATION_CLIENT_INTERFACE DashboardItem : public QObject {

  Q_OBJECT
Q_PROPERTY(QString source READ source)
public:
  explicit DashboardItem(QObject *parent = nullptr) : QObject(parent) {}

    virtual const QString source()= 0;
public slots:
};

#endif // DASHBOARDITEM_H
