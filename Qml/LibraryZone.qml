import QtQuick
import QtQuick.Controls
import QtMultimedia
import QtQuick.Dialogs
import QtQuick.Layouts
import MediaLibrary
import Logic.FileDriver
import Logic.Mediaplayer
import PlayList

Item {
    id:root

    property bool choose: false
    default property int pl_counter: 0

    function readmetadata(){
        var mediaItems = medialib.getMediaItems();
        for (var i = 0; i < mediaItems.length; i++) {
            mediaModel.append({ url: mediaItems[i],
                                title: medialib.getTitle(mediaItems[i]),
                                genre: medialib.getGenre(mediaItems[i]),
                                releasedate: medialib.getReleaseDate(mediaItems[i]),
                              });

        }
    }

    GridView {
        id: listview

        visible: !choose

        height: parent.height - choosemenu.height
        width: parent.width

        cellWidth: 150; cellHeight: 150

        anchors{
            top: choosemenu.bottom
            topMargin: 20
            left: parent.left
            leftMargin: 20
            right: parent.right
        }

        model: ListModel {
            id:listmodel
        }

        delegate: Item {
            width: listview.cellHeight
            height: listview.cellWidth

            PlayList{
                id: currentplaylist

            }

            Rectangle {
                width: parent.width
                height: parent.height
                color: "#FFDFDF"
                border.color: "gray"
                radius: 5

                ColumnLayout {
                    width: parent.width
                    height: parent.height * 0.75

                    spacing: 7

                    Text {
                        text: "Name: " + model.name
                        Layout.alignment: Qt.AlignHCenter
                    }

                    Text {
                        text: "Genre: " + model.genre
                        Layout.alignment: Qt.AlignHCenter
                    }
                }

                Row{
                    id: buttonzone

                    width: parent.width

                    height: parent.height * 0.3

                    spacing: 7

                    anchors{
                        bottom: parent.bottom
                        bottomMargin: 0.05 * parent.width
                        left: parent.left
                        leftMargin: 0.05 * parent.width
                        right: parent.right
                    }


                    Imagebutton{
                        source: "../resources/images/delete.png"
                        height: 40
                        width: 40
                        anchors.verticalCenter:  parent.verticalCenter
                        onClicked: {
                            listmodel.remove(index)
                        }
                    }

                    FileDialog {
                        id: fileDialog
                        title: "Please choose a file"
                        nameFilters: ["Media Files (*.mp4 *.mp3)", "MP4 Files (*.mp4)", "MP3 Files (*.mp3)", "All Files (*)"]
                        onAccepted: {
                            currentplaylist.add(selectedFile);
                        }
                    }

                    Imagebutton{
                        source: "../resources/images/plus.png"
                        height: 40
                        width: 40
                        anchors.verticalCenter:  parent.verticalCenter
                        onClicked: {
                            fileDialog.open()
                        }
                    }

                    Imagebutton{
                        source: "../resources/images/playlist.png"
                        height: 40
                        width: 40
                        anchors{
                            verticalCenter: parent.verticalCenter
                        }
                        onClicked: {
                            Player.setPlaylist(currentplaylist)
                        }
                    }
                }
            }
        }
    }

    Dialog {
        id: createPlaylistDialog
        title: "Create New Playlist"
        standardButtons: Dialog.Ok | Dialog.Cancel

        height: 0.2 * parent.width
        width: 0.2 * parent.width


        onAccepted: {
            var playlistName = playlistNameInput.text;
            if (playlistName.trim() !== "") {
                listview.model.append({
                                        name: playlistNameInput.text,
                                        genre: playlistGenreInput.text,



                                      })
            }
        }

        contentItem: ColumnLayout {
            TextField  {
                id: playlistNameInput
                placeholderText: "Enter playlist name"
                Layout.alignment: Qt.AlignHCenter
            }

            TextField  {
                id: playlistGenreInput
                placeholderText: "Enter genre"
                Layout.alignment: Qt.AlignHCenter
            }
        }
    }

    Imagebutton{
        source: "../resources/images/add.png"

        visible: !choose

        height: 40
        width: 40

        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
            bottomMargin: 10
        }
        onClicked: {
            createPlaylistDialog.open()
        }
    }

    height: parent.height
    width: parent.width

    MediaLibrary{
        id: medialib

    }

    ListModel {
        id: mediaModel

    }

    GridView {
        id: liblist

        visible: choose

        height: parent.height - choosemenu.height
        width: parent.width

        cellWidth: 240; cellHeight: 310

        anchors{
            top: choosemenu.bottom
            topMargin: 20
            left: parent.left
            leftMargin: 20
            right: parent.right
        }

        model: mediaModel

        Component.onCompleted: {
            readmetadata();
        }

        displaced: Transition {
            NumberAnimation { properties: "x,y"; duration: 1000 }
        }

        onAddChanged: {
            videoreload();
        }

        delegate: Component  {
            id: contactDelegate

            Item {
                function videoreload(){
                    video.play()
                }

                opacity: mousezone.containsMouse ? 0.75 : 1

                width: liblist.cellWidth; height: liblist.cellHeight
                Rectangle{

                    height: parent.height - 20
                    width: parent.width - 20

                    radius: 10

                    color: "#FFDFDF"

                    border{
                        color: "#FFF6F6"
                        //width: 5
                    }

                    Column {
                        anchors.fill: parent

                        topPadding: 10

                        spacing: 10

                        Rectangle{

                            height: 0.6 * parent.height
                            width: 0.8 * parent.width

                            anchors.horizontalCenter: parent.horizontalCenter

                            radius: 10

                            Video{
                                id: video

                                source: model.url

                                fillMode: VideoOutput.Stretch
                                height: parent.height
                                width: parent.width

                                Rectangle{

                                    height: parent.height
                                    width: parent.width

                                    color: "transparent"

                                    border{
                                        width: 2
                                        color: "black"
                                    }
                                }

                                anchors.horizontalCenter: parent.horizontalCenter

                                volume: 0
                                loops: MediaPlayer.Infinite
                            }
                        }

                        Text {
                            text: model.title;
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: model.genre;
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: model.releasedate;
                            anchors.horizontalCenter: parent.horizontalCenter
                        }



                        onVisibleChanged: {
                            if (!liblist.visible)
                                video.stop()
                            video.play()
                        }


                        focus: true
                    }

                    MouseArea{

                        id: mousezone

                        anchors.fill: parent

                        onDoubleClicked: {
                            File.openFile(model.url)

                        }

                    }

                }
            }
        }
    }

    FileDialog {
        id: fileDialogadd
        title: "Please choose a file"
        nameFilters: ["Media Files (*.mp4 *.mp3)", "MP4 Files (*.mp4)", "MP3 Files (*.mp3)", "All Files (*)"]
        onAccepted: {
            medialib.addMedia(selectedFile);
            mediaModel.clear();
            readmetadata();
        }
    }

    Imagebutton{
        source: "../resources/images/add.png"

        visible: choose

        height: 40
        width: 40

        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
            bottomMargin: 10
        }
        onClicked: {
            fileDialogadd.open()
        }
    }

    Row {
        id: choosemenu

        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
        }

        height: 30


        BaseButton{
            height: parent.height
            width: 0.5 * parent.width

            background: choose ?  "#ED7D31" : "#6C5F5B"
            textcolor: "white"
            text: "Library"

            onClicked: {
                if(!choose){
                    choose = !choose
                }
            }
        }

        BaseButton{
            height: parent.height
            width: 0.5 * parent.width

            background: choose ?  "#6C5F5B" : "#ED7D31"
            textcolor: "white"
            text: "Playlists"

            onClicked: {
                if(choose){
                    choose = !choose
                }
            }
        }
    }
}
