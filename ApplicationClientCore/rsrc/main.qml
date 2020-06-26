import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Window 2.6
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.12
import com.applicationclient 1.0 as AppClient
import "controls" as OwnControls

ApplicationWindow {
    id: window
    flags: Qt.Window | Qt.WindowMinMaxButtonsHint | Qt.WindowSystemMenuHint | Qt.FramelessWindowHint
    visibility: "Maximized"
    width: 375
    height: 667
    visible: true

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Timer {
        id: timer
    }

    function delayStart(delayTime, cb) {
        timer.interval = delayTime;
        timer.repeat = true;
        timer.triggered.connect(cb);
        timer.start();
    }
    function delayStop(){
        timer.stop();

    }

    Action{
        id: drawerAction
        icon.source: "menu.png"
        onTriggered: {
            sideMenu.visible = !sideMenu.visible;
        }
    }

    MessageDialog {
        id: messageDialog
        visible: AppClient.App.showMessageBox
        icon: AppClient.App.messageIcon
        title: AppClient.App.messageTitle
        text: AppClient.App.messageContent
        onAccepted: {
            AppClient.App.showMessageBox = false;
        }
    }

    header: ToolBar {
        id: toolBar

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            property variant clickPos: "1,1"
            property bool dragActive: false
            property bool dragMax: false
            onDoubleClicked: {
                dragActive = false;
                console.log(window.visibility);
                if(window.visibility !== 2){
                    window.visibility = "Windowed";
                }
                else{
                    window.visibility = "Maximized";
                }
            }
            function max(){
                if(!dragActive && window.y <= 0 && dragMax){
                    dragMax = false;
                    console.log("Dropped at top");
                    window.visibility = "Windowed"
                    window.visibility = "Maximized"
                    delayStop();
                }
            }

            onPressed: {
                dragActive = true;
                clickPos = Qt.point(mouse.x,mouse.y)
            }

            onReleased: {
                dragActive = false;
            }

            onPositionChanged: {
                if(dragActive){
                    var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
                    var new_x = window.x + delta.x
                    var new_y = window.y + delta.y


                    if (window.visibility !== 2 && new_y > 0){
                        window.visibility = "Windowed"
                    }else if(new_y <= 0){
                        window.visibility = "Maximized"
                        dragMax = true;

                        delayStart(10, function() {
                            max();
                        })
                    }
                    window.x = new_x
                    window.y = new_y
                }
            }
        }

        ToolButton {
            action: drawerAction
        }

        OwnControls.Dashboard {
            id: dashboard
            visible: true
        }

        OwnControls.SideMenu {
            id: sideMenu
            visible: false
        }

    }
}

