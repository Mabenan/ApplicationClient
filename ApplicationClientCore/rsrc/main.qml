import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Window 2.6
import com.applicationclient 1.0 as AppClient
import "controls" as OwnControls

ApplicationWindow {
    id: window
    flags: Qt.Window | Qt.WindowMinMaxButtonsHint | Qt.WindowSystemMenuHint | Qt.FramelessWindowHint
    visibility: "Maximized"
    width: 375
    height: 667
    visible: true

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

