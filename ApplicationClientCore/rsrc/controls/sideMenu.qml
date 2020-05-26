import QtQuick 2.0
import QtQuick.Controls 2.6
import com.applicationclient 1.0 as AppClient

Rectangle {
    id: sidemenu
    width: 365
    height: 693
    color: "#cc700c"
    visible: true

    ListView {
        id: buttonList
        anchors.rightMargin: 8
        anchors.leftMargin: 8
        anchors.bottomMargin: 8
        anchors.topMargin: 8
        anchors.fill: parent
        model: AppClient.App.buttonModel
        delegate:
            Button {

                    anchors.fill: parent
                    text: edit.name
                    onClicked: {
                        edit.click();
                    }
                }
    }
}


/*##^##
Designer {
    D{i:1;anchors_height:160;anchors_width:110;anchors_x:31;anchors_y:75}
}
##^##*/
