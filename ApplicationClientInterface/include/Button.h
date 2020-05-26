#ifndef BUTTON_H
#define BUTTON_H

#include "ApplicationClientInterface_export.h"
#include <QObject>
class APPLICATION_CLIENT_INTERFACE Button : public QObject {

  Q_OBJECT
Q_PROPERTY(QString name READ name)
public:
  explicit Button(QObject *parent = nullptr) : QObject(parent) {}
    virtual void clicked() = 0;

    virtual const QString name() = 0;
public slots:
    void click(){
        this->clicked();
    }
};

#endif // BUTTON_H
