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
        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }
    }

    QMLWidget0503{
        id:glwidget2
        x:150
        y:200
        width: 100
        height: 100
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
                if((mouse.modifiers & Qt.ShiftModifier) && (mouse.modifiers & Qt.ControlModifier)){
                    glwidget2.zRot += mouseY - prevMouseY
                }
                else if(mouse.modifiers & Qt.ShiftModifier){
                    //QMLWidgetの座標を変えて平行移動。
                    glwidget2.x += mouseX - prevMouseX
                    glwidget2.y += mouseY - prevMouseY
//                    glwidget2.xTranslate += mouseX - prevMouseX
//                    glwidget2.yTranslate += mouseY - prevMouseY
                }
                else if(mouse.modifiers & Qt.ControlModifier){
                    //拡大・縮小すると思っているのだが、実際にはしない。原因不明。
                    console.log("zTranslate is changed")
                    glwidget2.zTranslate += (mouseX - prevMouseX)*1000
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
    Rectangle{
        x:30
        y:30
        width: 100
        height: 100
        color: "#88ff0000"
        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }
    }

    Text {
        text: qsTr("■操作方法
四角形、三角形はdragで平行移動
立方体はshift+dragで平行移動、dragでX,Y軸回転、shift+ctrl+y方向dragでz軸回転
■残課題
・背景(QMLWidget0502)が環境によって右上1/4しか表示されない
・Cube(QMLWidget0503)の拡大縮小が対応できていない
・Cube(QMLWidget0503)の平行移動がスムーズではない、マウスに追従しない
・MACだとCubeのQQuickItemのupdate()を呼んでも再描画が走らない模様。")
//        anchors.centerIn: parent
        anchors.bottom: parent.bottom
        width: parent.width
        color: "white"
//        font.pixelSize: 20
        wrapMode: Text.WordWrap
    }


}
