import QtQuick 2.0
import com.example.settings 1.0

Rectangle {
    width: 360
    height: 360
    Text {
        text: qsTr("loaded data:
test1="+sm01.getValue("test1")+"
test2="+sm01.getValue("test2")+"
test3="+sm01.getValue("test3")+"
test4="+sm01.getValue("test4")+"
test5="+sm01.getValue("test5")+"
rect01.width="+sm01.getValue("rect01.width")+"
rect01.height="+sm01.getValue("rect01.height")+"
rect01.x="+sm01.getValue("rect01.x")+"
rect01.y="+sm01.getValue("rect01.y")+"
")
        anchors.centerIn: parent
        horizontalAlignment:Text.AlignLeft
    }
    Rectangle{
        id:rect01
        color: "steelblue"
        opacity: 0.7
        width: 'string' === typeof sm01.getValue("rect01.width") ? 100 : sm01.getValue("rect01.width")
        height: 'string' === typeof sm01.getValue("rect01.height") ? 100 : sm01.getValue("rect01.height")
        x: 'string' === typeof sm01.getValue("rect01.x") ? 0 : sm01.getValue("rect01.x")
//        y: 'string' === typeof sm01.getValue("rect01.y") ? 0 : sm01.getValue("rect01.y")
        y: "" === sm01.getValue("rect01.y") ? 0 : sm01.getValue("rect01.y")
//        y: sm01.getValue("rect01.y")
    }

    SettingManager{
        id:sm01
        Component.onDestruction: {
            console.log("onDestruction is called.")
            sm01.save()
        }
    }

    MouseArea {
        anchors.fill: parent
        drag.target: rect01
        onClicked: {
            sm01.setValue("test1",1)
            sm01.setValue("test2",2)
            sm01.setValue("test3",3)
            sm01.setValue("test4","test4value")
            sm01.setValue("test5",true)
            sm01.setValue("rect01.width",100)
            sm01.setValue("rect01.height",200)
            sm01.setValue("rect01.x",rect01.x)
            sm01.setValue("rect01.y",rect01.y)
            sm01.save()
        }
        onReleased: {
            sm01.setValue("rect01.x",rect01.x)
            sm01.setValue("rect01.y",rect01.y)
        }
    }
}
