import QtQuick 2.0
import com.self 1.0

Rectangle {
    width: 360
    height: 360
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
    Recorder{
        id:recorder01
    }
    Rectangle{
        width: 100
        height: 50
        color: "red"
        Text{
            anchors.centerIn: parent
            text:"record"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                recorder01.record()
            }
        }
    }

    Rectangle{
        anchors.right: parent.right
        width: 100
        height: 50
        color: "steelblue"
        Text{
            anchors.centerIn: parent
            text:"stop"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                recorder01.stop()
            }
        }
    }
}
