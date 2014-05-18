import QtQuick 2.0

Rectangle {
    width: 720
    height: 360
    Item{
        anchors.fill: parent
        GridView{
            id:grid1
            delegate: Icon{id:delegate1; content_parent: page0}
            model: model1
            width: parent.width/2
            height: parent.height
            cellWidth: 80; cellHeight: 80;
        }
        GridView{
            x:grid1.width
//            visible: false
            id:grid2
            delegate: Icon{id:delegate2; content_parent: page1; offsetX: -grid2.x}
            model: model2
            width: grid1.width
            height: grid1.height
//            anchors.left: grid1.right
            cellWidth: grid1.cellWidth; cellHeight: grid1.cellHeight;
        }
    }

    ListModel{
        id:model1
        ListElement{name:"icon0"; gridId:0}
        ListElement{name:"icon1"; gridId:1}
        ListElement{name:"icon2"; gridId:2}
        ListElement{name:"icon3"; gridId:3}
        ListElement{name:"icon4"; gridId:4}
    }

    ListModel{
        id:model2
        ListElement{name:"icon5"; gridId:5}
        ListElement{name:"icon6"; gridId:6}
        ListElement{name:"icon7"; gridId:7}
        ListElement{name:"icon8"; gridId:8}
        ListElement{name:"icon9"; gridId:9}
    }

    MouseArea {
        id:loc
        property int currentId: -1                       // Original position in model
        property int newIndex                            // Current Position in model
        property int index: (mouseX < grid2.x) ? grid1.indexAt(mouseX, mouseY) :  grid2.indexAt(mouseX-grid2.x, mouseY) // Item underneath cursor
        property int page: 0
        Item{
            id:page0
            width:grid1.width
            height: grid1.height
        }
        Item{
            id:page1
            width: grid2.width
            height: grid2.height
            x:grid2.x
            Rectangle{
                anchors.fill: parent
                opacity: 0.5
                color: "salmon"
            }
        }

        anchors.fill: parent
        onPressAndHold: {
            console.log("onPressAndHold is called. index="+index+"  mouseX="+mouseX)
            if(mouse.x < grid2.x){
                loc.page = 0
                currentId = model1.get(newIndex = index).gridId
            }
            else{
                loc.page = 1
                currentId = model2.get(newIndex = index).gridId
            }
        }
        onReleased: currentId = -1
        onPositionChanged: {
            if (loc.currentId != -1 && index != -1 && index != newIndex){
                if(mouse.x < grid2.x){
                    model1.move(newIndex, newIndex = index, 1)
                }
                else{
                    model2.move(newIndex, newIndex = index, 1)
                }
            }
        }
    }
}
