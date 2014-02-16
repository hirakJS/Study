import QtQuick 2.0
import com.nobo66.qmlcomponents 1.0

Rectangle {
    id:root
    width: 360
    height: 360
    property string test_string:"prop1_value"
    Text {
        id:txt01
        text: qsTr("this sample shows how to create custom qml element. MyPlugin01 element is implemented in plugin01.pro.
click here to check set and get prop1 value of MyPlugin01 element.")
        anchors.fill: parent
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(root.test_string === myPlugin.prop1){
                txt01.text = "succeeded to set and get prop1 value of MyPlugin01.
root.test_string="+root.test_string+"
myPlugin.prop1="+myPlugin.prop1
            }
            else
            {
                txt01.text = "failed to set and get prop1 value of MyPlugin01.
root.test_string="+root.test_string+"
myPlugin.prop1="+myPlugin.prop1
            }
        }
    }
    MyPlugin01{
        id:myPlugin
        prop1: root.test_string
    }
}
