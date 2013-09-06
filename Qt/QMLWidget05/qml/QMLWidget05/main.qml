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
        GLWidgetManipulator{}
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
        GLWidgetManipulator{}
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
