import QtQuick 2.0
import Leap 1.0

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
            Qt.quit();
        }
    }
    LeapGesture{
        onSwipe: {
            console.log("swipe speed="+speed)
            console.log("swipe direction="+angle)
        }
        onCircleCW: {
            console.log("circle clockwise")
        }
        onCircleCCW: {
            console.log("circle counter clockwise")
        }
    }
}
