import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import Logic.FileDriver

Item {
    id: root
    height: 30

    Rectangle{
        height: parent.height
        width: parent.width

        color: "#5D635C"
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        nameFilters: ["Media Files (*.mp4 *.mp3)", "MP4 Files (*.mp4)", "MP3 Files (*.mp3)", "All Files (*)"]
        onAccepted: File.openFile(selectedFile)
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
            }

            Button {
                text: "Load"
                onClicked: {
                    File.openFile(urlText.text)
                    console.log(urlText.text)
                }
            }
        }
        onOpened: { urlPopup.forceActiveFocus() }
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
                onTriggered: {
                    urlPopup.open()
                }
            }

            Action {
                text: qsTr("&Exit");
                onTriggered: {
                    Qt.quit()
                }
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
