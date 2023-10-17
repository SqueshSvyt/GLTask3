import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import com.company.UIController

Item {
    id: root
    height: 30

    Rectangle{
        height: parent.height
        width: parent.width

        color: "#5D635C"
    }


    Popup {
        id: urlPopup
        anchors.centerIn: Overlay.overlay

        RowLayout {
            id: rowOpenUrl
            Label {
                text: qsTr("URL:");
            }

            TextInput {
                id: urlText
                focus: true
                Layout.minimumWidth: 400
                wrapMode: TextInput.WrapAnywhere
                Keys.onReturnPressed: {  }
            }

            Button {
                text: "Load"
                onClicked: {  }
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        nameFilters: ["Media Files (*.mp4 *.mp3)", "MP4 Files (*.mp4)", "MP3 Files (*.mp3)", "All Files (*)"]
        onAccepted: UIController.openFile(selectedFile)
    }

    MenuBar {
        id: menuBar
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height


        Menu {
            title: qsTr("&File")
            Action {
                text: qsTr("&Open")
                onTriggered: {
                    fileDialog.open()
                }
            }
            Action {
                text: qsTr("&URL");

            }

            Action {
                text: qsTr("&Exit");

            }
        }

        Menu {
            title: qsTr("&View")
            Action {
                text: qsTr("Metadata")

            }
        }

        Menu {
            title: qsTr("&Tracks")
            Action {
                text: qsTr("Audio")

            }
            Action {
                text: qsTr("Video")

            }
            Action {
                text: qsTr("Subtitles")

            }
        }
    }
}
