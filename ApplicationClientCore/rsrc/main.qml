import QtQuick 2.6
import QtQuick.Controls 2.6
import com.applicationclient 1.0 as AppClient
import "controls" as OwnControls

ApplicationWindow {
    id: window
    flags: Qt.Window | Qt.WindowMinMaxButtonsHint | Qt.WindowSystemMenuHint | Qt.FramelessWindowHint
    visibility: "Maximized"
    width: 375
    height: 667
    visible: true

    Rectangle {
        id: rectangle
        visible: true
        color: "#999999"
        anchors.fill: parent

        ToolBar {
            id: toolBar
            width: 0
            height: 40
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0

            MouseArea {
                id: mouseArea
                anchors.fill: parent

                Connections {
                    target: mouseArea
                    onDoubleClicked: {
                        console.log(window.visibility);
                        if(window.visibility !== 2){
                            window.visibility = "Windowed";
                        }
                        else{
                            window.visibility = "Maximized";
                        }
                    }
                }
            }

            ToolButton {
                id: toolButton
                text: "Menu"
                display: AbstractButton.IconOnly
                autoRepeat: false
                onClicked: {
                    sideMenu.visible = !sideMenu.visible;
                }

                Image {
                    id: image
                    layer.enabled: false
                    layer.mipmap: false
                    anchors.fill: parent
                    source: "menu.png"
                    fillMode: Image.PreserveAspectFit
                }
            }

        }

        OwnControls.Dashboard {
            id: dashboard
            anchors.topMargin: 40
            anchors.fill: parent
        }

        OwnControls.SideMenu {
            id: sideMenu
            width:  parent.width * 0.3
            visible: false
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 40
        }

    }
}
/*##^##
Designer {
    D{i:3;anchors_height:100;anchors_width:100}D{i:6;anchors_x:6;anchors_y:6}D{i:8;anchors_x:8;anchors_y:46}
}
##^##*/
