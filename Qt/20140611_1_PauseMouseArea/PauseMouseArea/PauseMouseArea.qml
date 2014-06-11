import QtQuick 2.0

MouseArea {
    id:root
    property alias pauseInterval: tm.interval
    signal pausePositionChanged(variant mouse)
    function pause(){
        console.debug("pause is called. tm.interval="+tm.interval)
        if(tm.isPausing){
            tm.restart()
        }
        else{
            tm.start()
        }

        tm.isPausing = true
    }
    Timer{
        id:tm
        property bool isPausing: false
        onTriggered: {
            tm.isPausing = false
        }
    }
    onPositionChanged: {
        if(!tm.isPausing){
            root.pausePositionChanged(mouse)
        }
    }
}
