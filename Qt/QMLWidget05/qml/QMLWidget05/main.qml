import QtQuick 2.0
import CustomParts 1.0

Rectangle {
    width: 360
    height: 360
    color: "black"
    QMLWidget0501{
        id:glwidget
        x:220
        y:40
        width: 100
        height: 100
        Text{
            anchors.bottom: glwidget.top
            anchors.horizontalCenter: glwidget.horizontalCenter
            color: "white"
            text: qsTr("↓GLES2.0で三角形描画")
        }
        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }
    }

    QMLWidget0503{
        id:glwidget2
        x:40
        y:180
        width: 100
        height: 100
        Text{
            anchors.bottom: glwidget2.top
            anchors.horizontalCenter: glwidget2.horizontalCenter
            color: "white"
            text: qsTr("↓GLES2.0でCube(平行投影)")
        }
        MouseArea {
            property real prevMouseX: mouseX
            property real prevMouseY: mouseY
            property bool shift_key: false
            property bool ctrl_key: false
            anchors.fill: parent
            onPressed: {
                prevMouseX = mouseX
                prevMouseY = mouseY
            }

            onPositionChanged: {
                drag.target = null
                if((mouse.modifiers & Qt.ShiftModifier) && (mouse.modifiers & Qt.ControlModifier)){
                    glwidget2.zRot += mouseY - prevMouseY
                }
                else if((mouse.modifiers & Qt.ShiftModifier) && (mouse.modifiers & Qt.AltModifier)){
                    //translateを使って平行移動。
                    glwidget2.xTranslate += (mouseX - prevMouseX)*0.01
                    glwidget2.yTranslate -= (mouseY - prevMouseY)*0.01
                }
                else if(mouse.modifiers & Qt.ShiftModifier){
                    //glwidget2の座標を変えて平行移動。
                    drag.target = glwidget2
                }
                else if(mouse.modifiers & Qt.ControlModifier){
                    //拡大・縮小
                    glwidget2.xScale += (mouseX - prevMouseX)*0.01
                    glwidget2.yScale += (mouseX - prevMouseX)*0.01
                    glwidget2.zScale += (mouseX - prevMouseX)*0.01
                }
                else{
                    glwidget2.xRot += mouseY - prevMouseY
                    glwidget2.yRot += mouseX - prevMouseX
                }
                prevMouseX = mouseX
                prevMouseY = mouseY
            }
        }
    }

    QMLWidget0504{
        id:glwidget3
        x:220
        y:180
        width: 100
        height: 100
        Text{
            anchors.bottom: glwidget3.top
            anchors.horizontalCenter: glwidget3.horizontalCenter
            color: "white"
            text: qsTr("↓GLES2.0でCube(透視投影)")
        }
        MouseArea {
            property real prevMouseX: mouseX
            property real prevMouseY: mouseY
            property bool shift_key: false
            property bool ctrl_key: false
            anchors.fill: parent
            onPressed: {
                prevMouseX = mouseX
                prevMouseY = mouseY
            }

            onPositionChanged: {
                drag.target = null
                if((mouse.modifiers & Qt.ShiftModifier) && (mouse.modifiers & Qt.ControlModifier)){
                    glwidget3.zRot += mouseY - prevMouseY
                }
                else if((mouse.modifiers & Qt.ShiftModifier) && (mouse.modifiers & Qt.AltModifier)){
                    //translateを使って平行移動。
                    glwidget3.xTranslate += (mouseX - prevMouseX)*0.01
                    glwidget3.yTranslate -= (mouseY - prevMouseY)*0.01
                }
                else if(mouse.modifiers & Qt.ShiftModifier){
                    //glwidget3の座標を変えて平行移動。
                    drag.target = glwidget3
                }
                else if(mouse.modifiers & Qt.ControlModifier){
                    //拡大・縮小
                    glwidget3.xScale += (mouseX - prevMouseX)*0.01
                    glwidget3.yScale += (mouseX - prevMouseX)*0.01
                    glwidget3.zScale += (mouseX - prevMouseX)*0.01
                }
                else{
                    glwidget3.xRot += mouseY - prevMouseY
                    glwidget3.yRot += mouseX - prevMouseX
                }
                prevMouseX = mouseX
                prevMouseY = mouseY
            }
        }
    }
    Rectangle{
        id:rect
        x:40
        y:40
        width: 100
        height: 100
        color: "#88ff0000"
        Text{
            anchors.bottom: rect.top
            anchors.horizontalCenter: rect.horizontalCenter
            color: "white"
            text: qsTr("↓QMLのRect(z位置確認用)")
        }
        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }
    }

    Text {
        text: qsTr("■操作方法
四角形、三角形はdragで平行移動
立方体はshift+dragでQMLのElementが平行移動、shift+alt+dragで3D座標空間内を平行移動、dragでX,Y軸回転、shift+ctrl+y方向dragでz軸回転、ctrl+x方向dragで拡縮")
        anchors.bottom: parent.bottom
        width: parent.width
        color: "white"
        wrapMode: Text.WordWrap
    }


}
