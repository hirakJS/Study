import QtQuick 2.0
import CustomParts 1.0

Item {
    width: 360
    height: 360
    QMLWidget0502{}
    QMLWidget0501{
        id:glwidget
        x:50
        y:100
        width: 100
        height: 100
    }

    QMLWidget0503{
        id:glwidget2
        x:150
        y:200
        width: 100
        height: 100
    }
    Rectangle{
        x:30
        y:30
        width: 100
        height: 100
        color: "#88ff0000"
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
        color: "white"
        font.pixelSize: 50
    }
    MouseArea {
        anchors.fill: parent
        drag.target: glwidget
        onClicked: {
//            Qt.quit();
            glwidget.x += 1
            glwidget.y += 1
        }
    }
}
