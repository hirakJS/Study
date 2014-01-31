import QtQuick 2.0
import com.nobo66.qmlcomponents 1.0

Rectangle {
    width: 360
    height: 360
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("myPlugin.prop1="+myPlugin.prop1)
        }
    }
    MyPlugin01{
        id:myPlugin
        prop1: "prop1_value"
    }
}
