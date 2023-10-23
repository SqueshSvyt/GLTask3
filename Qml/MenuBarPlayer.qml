import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import Logic.FileDriver
import Logic.Mediaplayer

Item {
    id: root
    height: 30

    property string m_title: "NotFound"
    property string m_author: "NotFound"
    property string m_genre: "NotFound"
    property string m_date: "NotFound"
    property string m_albumTitle: "NotFound"
    property string m_language: "NotFound"
    property string m_description: "NotFound"
    property string m_videoCodec: "NotFound"
    property string m_audioCodec: "NotFound"
    property string m_mediaType: "NotFound"
    property string m_fileFormat: "NotFound"
    property string m_duration: "NotFound"


    function setMetaData(){
        var meta = Player.plmetadata();

        m_title = meta[0];
        m_author = meta[1];
        m_genre = meta[2];
        m_date = meta[3];
        m_albumTitle = meta[4];
        m_language = meta[5];
        m_description = meta[6];
        m_videoCodec = meta[7];
        m_audioCodec = meta[8];
        m_mediaType = meta[9];
        m_fileFormat = meta[10];
        m_duration = meta[11];
    }

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
            }

            Button {
                text: "Load"
                onClicked: {
                    File.openFile(urlText.text)
                    setMetaData();
                }
            }
        }
        onOpened: { urlPopup.forceActiveFocus() }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        nameFilters: ["Media Files (*.mp4 *.mp3)", "MP4 Files (*.mp4)", "MP3 Files (*.mp3)", "All Files (*)"]
        onAccepted:{
            File.openFile(selectedFile);
            setMetaData();
        }
    }

    Dialog {
        id: metadataDialog
        title: "Media Metadata"

        contentItem: Column {
            spacing: 10

            Text {
                text: "Title: " + m_title
            }

            Text {
                text: "Author: " + m_author
            }

            Text {
                text: "Genre: " + m_genre
            }

            Text {
                text: "Date: " + m_date
            }

            Text {
                text: "AlbumTitle: " + m_albumTitle
            }

            Text {
                text: "Language: " + m_language
            }

            Text {
                text: "Description: " + m_description
            }

            Text {
                text: "VideoCodec: " + m_videoCodec
            }

            Text {
                text: "AudioCodec: " + m_audioCodec
            }

            Text {
                text: "MediaType: " + m_mediaType
            }

            Text {
                text: "FileFormat: " + m_fileFormat
            }

            Text {
                text: "Duration: " + m_duration
            }
        }

        standardButtons: Dialog.Ok

        onAccepted: metadataDialog.close()
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
                onTriggered: metadataDialog.open()
            }
        }
    }
}
