import QtQuick 2.0

Item{
    property variant content_parent
    id:main
    width: grid1.cellWidth; height: grid1.cellHeight
    Rectangle{
        id:item
        parent:main.content_parent
        x:main.x; y:main.y
//        x: main.x + 5; y: main.y + 5
        width: main.width - 10; height: main.height - 10;
//        width: 100
//        height: 100
        color: "steelblue"
        Text {
            text: name
        }
        Behavior on x { enabled: item.state != "active"; NumberAnimation { duration: 400; easing.type: Easing.OutBack } }
        Behavior on y { enabled: item.state != "active"; NumberAnimation { duration: 400; easing.type: Easing.OutBack } }
        states: State {
            name: "active"; when: loc.currentId == gridId
            PropertyChanges { target: item; x: loc.mouseX/* - width/2*/; y: loc.mouseY /*- height/2*/; scale: 0.8; z: 10 }
        }
        transitions: Transition { NumberAnimation { property: "scale"; duration: 200} }
    }
}

