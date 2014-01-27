import QtQuick 2.1
import QtQuick.Controls 1.0
import Qt.labs.folderlistmodel 2.1

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
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

    Button {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    TableView {
        anchors.fill: parent
        focus:true
        TableViewColumn{ role: "filePath"  ; title: "Path" ; width: 300 }
        TableViewColumn{ role: "fileName" ; title: "FileName" ; width: 150 }
        model: folderModel

        FolderListModel {
            id: folderModel
            folder:"/"  //folder to reference
        }
    }


}
