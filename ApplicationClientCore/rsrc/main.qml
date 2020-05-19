import QtQuick 2.6
import QtQuick.Controls 2.6
import com.applicationclient 1.0;
Rectangle {
    id: rectangle
    visible: true
    color: "#ccc8c8"

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

       ToolButton {
           id: toolButton
           text: qsTr("Close")
           onClicked: {
               App.close();
           }
       }
   }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:40;anchors_width:640;anchors_x:0;anchors_y:0}
}
##^##*/
