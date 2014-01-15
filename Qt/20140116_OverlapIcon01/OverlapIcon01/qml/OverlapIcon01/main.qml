import QtQuick 2.0

Rectangle {
    id:root
    width: 360
    height: 360
    Text {
        text: qsTr("This sample shows how to change icon gradually. Please click the button below.")
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
    }
    OverlapIcon01{
        id:oi01
    }

    MouseArea {
        width: 100
        height: 50
        anchors.horizontalCenter: root.horizontalCenter
        anchors.bottom: root.bottom
        property int currentIcon:0
        onClicked: {
            oi01.source = icons.get(currentIcon++).source
            if(currentIcon >= icons.count)
            {
                currentIcon = 0
            }
        }
        Rectangle{
            anchors.fill: parent
            color: "skyblue"
        }
        Text{
            anchors.centerIn: parent
            text:"change icon"
        }
    }
    ListModel{
        id:icons
        ListElement{ source:"./qt.png" }
        ListElement{ source:"./android.png" }
        ListElement{ source:"./HTML5_Logo.png" }
        ListElement{ source:"./linux.jpg" }
        ListElement{ source:"./python.png" }
    }
}
