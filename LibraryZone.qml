import QtQuick
import QtQuick.Controls
import QtMultimedia
import QtQuick.Dialogs
import MediaLibrary
import Logic.FileDriver

Item {
    id:root

    property bool choose: false

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


        delegate: Component  {
            id: contactDelegate



            Item {
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

                        Video{
                            id: video

                            source: model.url

                            fillMode: VideoOutput.Stretch

                            height: 0.6 * parent.height
                            width: 0.8 * parent.width

                            anchors.horizontalCenter: parent.horizontalCenter

                            volume: 0
                            loops: MediaPlayer.Infinite
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
                            if(visible)
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
        id: fileDialog
        title: "Please choose a file"
        nameFilters: ["Media Files (*.mp4 *.mp3)", "MP4 Files (*.mp4)", "MP3 Files (*.mp3)", "All Files (*)"]
        onAccepted: {
            medialib.addMedia(selectedFile);
            mediaModel.clear();
            readmetadata();
            liblist.re
        }
    }

    Imagebutton{
        source: "resources/images/add.png"

        height: 40
        width: 40

        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
            bottomMargin: 10
        }
        onClicked: {
            // Діалог для додавання пісні до бібліотеки
            var songTitle = "Назва пісні"; // Замініть це на реальну назву пісні
            var songArtist = "Виконавець"; // Замініть це на реального виконавця
            fileDialog.open()
        }
    }

    Row {
        id: choosemenu

        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
        }

        height: parent.height * 0.05


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
