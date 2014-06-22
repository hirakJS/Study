import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.0
import Qt.labs.folderlistmodel 2.1

ApplicationWindow {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
            MenuItem {
                action: openAction
            }
        }
    }

    Column{
        Text {
            id:txt01
            text: qsTr("Hello World")
        }
        Button{
            id:btn01
            action:openAction
        }
        GridView{
            id:gv01
            width: root.width
            height: root.height - txt01.height - btn01.height - 30
            model:folderModel
            cellWidth: 110
            cellHeight: 110
            clip: true
            delegate:Column{
                Rectangle{
                    id:im_ca_base
                    color: "gray"
                    width: gv01.cellWidth - 10
                    height: gv01.cellHeight - 10
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text{
                        id:txt_caph
                        text:(im_ca.status===Image.Null || im_ca.status===Image.Error) ? qsTr("no image") :
                                                                                         (im_ca.status===Image.Loading ? qsTr("loading") : "")
                        anchors.centerIn: parent
                        SequentialAnimation{
                            loops: Animation.Infinite
                            alwaysRunToEnd: true
                            running: im_ca.status===Image.Loading ? true : false
                            NumberAnimation {
                                target: txt_caph;
                                property: "opacity";
                                from: 1; to: 0;
                                duration: 1000;
                                easing.type: Easing.InOutQuad
                            }
                            NumberAnimation {
                                target: txt_caph;
                                property: "opacity";
                                from: 0; to: 1;
                                duration: 1000;
                                easing.type: Easing.InOutQuad
                            }
                        }
                    }

                    Image{
                        id:im_ca
                        source: "image://coverArt/" + filePath
                        anchors.fill: parent
                        sourceSize{
                            width: parent.width
                            height: parent.height
                        }
                    }
                }
                Text{
                    text: fileName
                    width: parent.width
                    clip: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a folder"
        selectFolder: true

        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            txt01.text = folder
        }
        onRejected: {
            console.log("Canceled")
        }
    }
    FolderListModel{
        id:folderModel
        nameFilters: ["*.mp3", "*.m4a"]
        folder:txt01.text
    }

    Action {
        id: openAction
        text: "&Open(select folder media file exists)"
        shortcut: "Ctrl+O"
        onTriggered: fileDialog.open()
        tooltip: "Open an Image"
    }
}
