import QtQuick 1.1
import Qt.labs.shaders 1.0

Item{
    id:root
    width: sourceItem.width
    height: sourceItem.height
    anchors.top: sourceItem.bottom
    anchors.horizontalCenter: sourceItem.horizontalCenter
    property variant sourceItem:parent //映り込みのソースとなるelementを指定
    property real length:0.7 //映り込みの長さを設定
    ShaderEffectSource {
        id: theSource
        sourceItem: root.sourceItem
    }
    ShaderEffectItem {
        anchors.fill: root
        property variant source: theSource
        property real length:root.length
        fragmentShader: "
            uniform sampler2D source;
            uniform lowp float qt_Opacity;
            uniform highp float height;
            uniform highp float length;
            varying highp vec2 qt_TexCoord0;
            void main() {
                lowp vec4 c = texture2D(source, qt_TexCoord0);
                gl_FragColor = qt_Opacity * (length - qt_TexCoord0.y) * 0.7 * c;
            }"
        vertexShader: "
            uniform highp mat4 qt_ModelViewProjectionMatrix;
            uniform highp float height;
            attribute highp vec4 qt_Vertex;
            attribute highp vec2 qt_MultiTexCoord0;
            varying highp vec2 qt_TexCoord0;
            void main() {
                qt_TexCoord0 = qt_MultiTexCoord0;
                highp vec4 pos = qt_Vertex;
                pos.y = height - qt_Vertex.y;
                gl_Position = qt_ModelViewProjectionMatrix * pos;
            }"
    }

}
