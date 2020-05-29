import QtQuick 2.0
import QtQuick.Controls 2.6
import com.applicationclient 1.0 as AppClient

Rectangle {
    visible: true
    ListView {
        id: dashboardView
        anchors.rightMargin: 8
        anchors.leftMargin: 8
        anchors.bottomMargin: 8
        anchors.topMargin: 8
        anchors.fill: parent
        model: AppClient.App.dashboardModel
        delegate: Loader {
                   id: myLoader
                   onLoaded: {
                       if(typeof myLoader.item.setDashboard === 'function'){
                       myLoader.item.setDashboard(edit);
                       }
                   }

                   source: edit.source
        }
    }
}
