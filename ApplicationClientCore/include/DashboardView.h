#ifndef DASHBOARDVIEW_H
#define DASHBOARDVIEW_H

#include "ApplicationClientCore_global.h"
#include <ApplicationClientCore.Precompiled.h>
#include "MainView.h"
#include "DashboardController.h"
class APPLICATIONCLIENTCORE_EXPORT DashboardView : public MainView<DashboardController>{
 Q_OBJECT
 MAIN_VIEW
public:
    DashboardView() : MainView<DashboardController>("/controls/Dashboard.qml"){
    }

    virtual ~DashboardView() override {;}

};
#endif // DASHBOARDVIEW_H
