#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "ApplicationClientInterface_export.h"
#include <QObject>
#include <QVariant>
template<class C>
class MainView : public QObject {
private:
    QString m_src;
    C * m_controller;
public:
    MainView(QString src, QObject * parent = nullptr) : QObject(parent){
        this->m_src = src;
        this->m_controller = new C();
    }

    virtual ~MainView() { ; }

    QString getSRC(){
        return this->m_src;
    }

    QVariant getController(){
        return QVariant::fromValue(this->m_controller);
    }
};

#define MAIN_VIEW \
Q_PROPERTY(QString src READ getSRC)\
Q_PROPERTY(QVariant controller READ getController)

#endif // MAINVIEW_H
