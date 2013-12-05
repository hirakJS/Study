import QtQuick 1.1
import "./parts"

Rectangle {
    id:root
    width: 360
    height: 360
    color: "black"
    Text {
        id:txt01
        text: qsTr("Hello World")
        styleColor: "#d71919"
        style: Text.Outline
        anchors.centerIn: parent
        font.pixelSize: 50
        color: "white"
//        Rectangle{
//            anchors.fill: parent
//            color: "lightgreen"
//            opacity: 0.5
//        }
//        anchors.topMarginの値を負値にすると、同じファイル内にShaderEffectを定義すればゴミが出ないが、
//        部品化(別ファイル）に定義するとゴミが出てしまう。という問題がqt5だとあったが、qt4.8.4では出ていない。
//        MyReflection01{anchors.topMargin: -10;}
        MyReflection01{}
    }
}
