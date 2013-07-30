import QtQuick 1.1
import CustomParts 1.0

Rectangle {
    id: root
    width: 360
    height: 360
    color: "gray"


    Text {
        id:txt01
        text: qsTr("OpenGLのWidgetよりも順番では先(z方向だと後ろ)に描画するテキスト")
//        anchors.centerIn: parent
        x:10;y:10
        width: root.width
        color: "white"
        font.bold: true
        font.pixelSize: 20
        opacity: 0.7
        wrapMode: Text.WordWrap
    }
    QMLWidget0401{
        id: qmlwidget
        anchors.centerIn: parent
        width: root.width/2
        height: root.height/2
    }

    Text {
        id:txt02
        x:txt01.x
        y:txt01.y+txt01.height
        width: txt01.width
        text: qsTr("OpenGLのWidgetよりも順番では後(z方向だと手前)に描画するテキスト")
        color: txt01.color
        font.bold: txt01.font.bold
        font.pixelSize: txt01.font.pixelSize
        opacity: txt01.opacity
        wrapMode: txt01.wrapMode
    }
    Text {
        text: qsTr("操作方法：\nX,Y方向平行移動：Shift+マウスドラッグ\nX,Y軸周りの回転：マウスドラッグ\nZ軸周りの回転：Shift+Ctrl+Y方向マウスドラッグ")
//        anchors.centerIn: parent
        anchors.bottom: root.bottom
        anchors.bottomMargin: 10
        anchors.left: root.left
        anchors.leftMargin: 10
        width: root.width
        color: "white"
        font.pixelSize: 15
        opacity: 1.0
    }
    Rectangle{
        x:txt02.x
        y:txt02.y+txt02.height
        width: 150
        height: 70
        opacity: 0.7
        color: "blue"
//        anchors.fill: root
        Text{
            anchors.fill: parent
            text:"OpenGLのWidgetよりも順番では後(z方向だと手前)に描画するRectangle(青色)。"
            wrapMode: Text.WordWrap
        }
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
            console.log("onPositionChanged is called");
            if((mouse.modifiers & Qt.ShiftModifier) && (mouse.modifiers & Qt.ControlModifier)){
                qmlwidget.zRot += mouseY - prevMouseY
            }
            else if(mouse.modifiers & Qt.ShiftModifier){
                qmlwidget.xTranslate += mouseX - prevMouseX
                qmlwidget.yTranslate += mouseY - prevMouseY
            }
            else if(mouse.modifiers & Qt.ControlModifier){
                //拡大・縮小すると思っているのだが、実際にはしない。原因不明。
                console.log("zTranslate is changed")
                qmlwidget.zTranslate += (mouseX - prevMouseX)*1000
            }
            else{
                qmlwidget.xRot += mouseY - prevMouseY
                qmlwidget.yRot -= mouseX - prevMouseX
            }
            prevMouseX = mouseX
            prevMouseY = mouseY
        }
    }
}
