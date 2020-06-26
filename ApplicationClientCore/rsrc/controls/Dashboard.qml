import QtQuick 2.0
import QtQuick.Controls 2.6
import QtQuick.Controls.Material 2.12
import com.applicationclient 1.0 as AppClient

ScrollView {
    id: dashboard
    anchors.fill: parent
    anchors.topMargin: toolBar.height
    anchors.leftMargin: sideMenu.visible ? sideMenu.width : undefined
    ScrollBar.horizontal.interactive: true
    ScrollBar.vertical.interactive: true
    height: window.height - toolBar.height;

    ListView {
        id: dashboardView
        model: AppClient.App.dashboardModel
        width: parent.width
        height: childrenRect.height
        delegate: Loader {
            width: parent.width
            height: childrenRect.height
            id: myLoader
            onLoaded: {
                if(typeof myLoader.item.setDashboard === 'function'){
                    myLoader.item.setDashboard(model.display);
                }
            }

            source: model.display.source
        }
    }
}
