import QtQuick 2.0
import "./parts"

Rectangle {
    id:root
    width: 360
    height: 360
    color: "black"
    Text {
        id:txt01
        text: qsTr("Hello World")
        styleColor: "lime"
        style: Text.Outline
        anchors.centerIn: parent
        font.pixelSize: 50
        color: "white"
//        Rectangle{
//            anchors.fill: parent
//            color: "lightgreen"
//            opacity: 0.5
//        }
//        anchors.topMarginの値を負値にすると、同じファイル内にShaderEffectを定義(下記id:root2のelement)すればゴミが出ないが、
//        部品化(別ファイル）に定義するとゴミが出てしまう。原因不明。
//        MyReflection01{anchors.topMargin: -20;}
        MyReflection01{}
    }






// anchors.topMarginの値を負値にする時、同じファイル内にShaderEffectを定義すればゴミが出ない。
//    Item{
//        id:root2
//        width: sourceItem.width
//        height: sourceItem.height
//        anchors.top: sourceItem.bottom
//        anchors.topMargin: -20
//        anchors.horizontalCenter: sourceItem.horizontalCenter
//        property variant sourceItem:txt01
//        ShaderEffectSource {
//            id: theSource
//            sourceItem: root2.sourceItem
//        }
//        ShaderEffect {
//            anchors.fill: root2
//            property variant source: theSource
//            fragmentShader: "
//                uniform sampler2D source;
//                uniform lowp float qt_Opacity;
//                uniform highp float height;
//                varying highp vec2 qt_TexCoord0;
//                void main() {
//                    lowp vec4 c = texture2D(source, qt_TexCoord0);
//                    gl_FragColor = qt_Opacity * (qt_TexCoord0.y - 0.3) * 0.7 * c;
//                }"
//            vertexShader: "
//                uniform highp mat4 qt_Matrix;
//                uniform highp float height;
//                attribute highp vec4 qt_Vertex;
//                attribute highp vec2 qt_MultiTexCoord0;
//                varying highp vec2 qt_TexCoord0;
//                void main() {
//                    qt_TexCoord0 = qt_MultiTexCoord0;
//                    highp vec4 pos = qt_Vertex;
//                    pos.y = height - qt_Vertex.y;
//                    gl_Position = qt_Matrix * pos;
//                }"
//        }

//    }

}
