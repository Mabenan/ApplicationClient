import QtQuick 2.0
import QtQuick.Controls 2.6
import QtQuick.Controls.Material 2.12
import com.applicationclient 1.0 as AppClient

ScrollView {
    id: dashboard
    anchors.fill: parent
    width: parent.width
    height: parent.height
    clip: true

    ListView {
        id: dashboardView
        anchors.fill: parent
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
