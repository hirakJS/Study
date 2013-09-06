import QtQuick 2.0

MouseArea {
    id:root
    property real prevMouseX: mouseX
    property real prevMouseY: mouseY
    property bool shift_key: false
    property bool ctrl_key: false
    property variant target: parent
    anchors.fill: parent
    onPressed: {
        prevMouseX = mouseX
        prevMouseY = mouseY
    }

    onPositionChanged: {
        drag.target = null
        if((mouse.modifiers & Qt.ShiftModifier) && (mouse.modifiers & Qt.ControlModifier)){
            target.zRot += mouseY - prevMouseY
        }
        else if((mouse.modifiers & Qt.ShiftModifier) && (mouse.modifiers & Qt.AltModifier)){
            //translateを使って平行移動。
            target.xTranslate += (mouseX - prevMouseX)*0.01
            target.yTranslate -= (mouseY - prevMouseY)*0.01
        }
        else if(mouse.modifiers & Qt.ShiftModifier){
            //targetの座標を変えて平行移動。
            drag.target = target
        }
        else if(mouse.modifiers & Qt.ControlModifier){
            //拡大・縮小
            target.xScale += (mouseX - prevMouseX)*0.01
            target.yScale += (mouseX - prevMouseX)*0.01
            target.zScale += (mouseX - prevMouseX)*0.01
        }
        else{
            target.xRot += mouseY - prevMouseY
            target.yRot += mouseX - prevMouseX
        }
        prevMouseX = mouseX
        prevMouseY = mouseY
    }
}

