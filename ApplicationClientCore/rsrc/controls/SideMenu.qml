import QtQuick 2.0
import QtQuick.Controls 2.6
import QtQuick.Controls.Material 2.12
import com.applicationclient 1.0 as AppClient

Drawer {
    id: sideMenu

    y: toolBar.height
    width: window.width / 4
    height: window.height - toolBar.height
    Material.background: Material.Orange
    Material.elevation: 6
    ListView {
        id: sidemenuList
        visible: true
        anchors.fill: parent
        model: AppClient.App.buttonModel
        delegate:
            Button {
            width: parent.width

            text: model.display.name
            onClicked: {
                edit.click();
                sideMenu.visible = false;
            }
        }
    }
}



