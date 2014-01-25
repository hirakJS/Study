import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Dialogs 1.0

ApplicationWindow {
    title: qsTr("recorder")
    width: 900
    height: 480

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
    Column{
        spacing: 10
        anchors.fill: parent
        anchors.margins: 10
        Row{
            Label{
                id:lb01
                width: 150
                text:qsTr("save folder:")
            }
            TextField{
                id:tf01
                width:600
            }
            Button {
                id: bt01
                text: qsTr("Select Folder")
                action: openAction
            }
        }
        Row{
            Label{
                text:qsTr("album name:")
                width:lb01.width
            }
            TextField{
                id:tf02
                width:tf01.width
            }
        }
        Row{
            Label{
                text:qsTr("file name:")
                width:lb01.width
            }
            TextField{
                id:tf03
                width:tf01.width
            }
        }
        Label{
            text:qsTr("recorded files:")
        }
        TableView {
            width:800
            focus:true
            TableViewColumn{ role: "file"  ; title: "File" ; width: 150 }
            TableViewColumn{ role: "album" ; title: "Album" ; width: 500 }
            model: libraryModel
            Keys.onPressed: {
                console.log("key pressed")
            }
            Keys.onDeletePressed: {
                console.log("delete pressed")
            }
        }
        Row{
            spacing: 10
            Button{
                id:bt_rec
                width: 100
                height: 100
                action:recordAction
            }
            Button{
                width: bt_rec.width
                height: bt_rec.height
                action:stopAction
            }
        }
    }

    ListModel {
       id: libraryModel
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph1_01" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph1_02" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph1_03" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph2_01" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph2_02" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph2_03" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph3" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph4" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph5" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph6" }
       ListElement{ album: "Qt WebEngine Technology Preview Available" ; file: "paragraph7" }
       ListElement{ album: "The future of Qt on Android looks bright" ; file: "paragraph1" }
       ListElement{ album: "The future of Qt on Android looks bright" ; file: "paragraph2" }
       ListElement{ album: "The future of Qt on Android looks bright" ; file: "paragraph3" }
       ListElement{ album: "The future of Qt on Android looks bright" ; file: "paragraph4" }
       ListElement{ album: "The future of Qt on Android looks bright" ; file: "paragraph5" }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        selectFolder: true
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            tf01.text = folder
        }
        onRejected: {
            console.log("Canceled")
        }
    }

    Action {
        id: openAction
        text: "&Open"
        shortcut: "Ctrl+O"
//        iconSource: "images/qt.png"
        onTriggered: fileDialog.open()
        tooltip: "Open an Image"
    }
    Action {
        id: recordAction
        text: "Record(F5)"
        shortcut: "F5"
        onTriggered: {
            console.log("record!!")
        }

        tooltip: "Start recording"
    }
    Action {
        id: stopAction
        text: "Stop(F6)"
        shortcut: "F6"
        onTriggered: {
            console.log("stop!!")
        }
        tooltip: "Stop recording"
    }

}
