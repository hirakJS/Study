import QtQuick 2.0

Item {
    id:root
    property real duration:500
    property string source

    Item{
        id:internal_value
        property int currentItem:0
    }

    onSourceChanged: {
        console.log("onSourceChanged is called")
        if(internal_value.currentItem === 0){
            img01.source = root.source
            img01.opacity = 1
            internal_value.currentItem = 1
        }
        else if(internal_value.currentItem === 1){
            img02.source = root.source
            img02.opacity = 1
            img01.opacity = 0
            internal_value.currentItem = 2
        }
        else{
            img01.source = root.source
            img01.opacity = 1
            img02.opacity = 0
            internal_value.currentItem = 1
        }
    }

    Image{
        id:img01
        opacity:0
        Behavior on opacity{
            NumberAnimation{duration: root.duration}
        }
    }
    Image{
        id:img02
        opacity:0
        Behavior on opacity{
            NumberAnimation{duration: root.duration}
        }
    }
}
