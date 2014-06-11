import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    visible: true
    width: 360
    height: 360

    PauseMouseArea {
        anchors.fill: parent
        pauseInterval: 3000
        onPausePositionChanged: {
            console.log("onPausePositionChanged is called. mouse.x="+mouse.x+"   mouse.y="+mouse.y)
            if(mouse.y > 180)
                pause()
        }
        onPositionChanged: {
            if(mouse.y > 200)
                pause()
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
