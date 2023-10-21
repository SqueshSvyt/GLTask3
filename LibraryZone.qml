import QtQuick
import QtQuick.Controls
import MediaLibrary
import QtMultimedia


Item {
    id:root

    property bool choose: false

    height: parent.height
    width: parent.width

    MediaLibrary{
        id: medialib
    }


    ListView {
        id: liblist

        visible: choose

        height: parent.height - choosemenu.height
        width: parent.width

        anchors{
            top: choosemenu.bottom
            left: parent.left
            right: parent.right
        }

        ListModel {
            id: mediaModel
        }

        Component.onCompleted: {
            var mediaItems = medialib.getMediaItems();
            for (var i = 0; i < mediaItems.length; i++) {
                mediaModel.append({ url: mediaItems[i] });
            }
        }

        model: mediaModel

        delegate: Item {
            width: parent.width
            height: 100


            Rectangle{
                color: "blue"

                width: parent.width
                height: parent.height
            }

            Text {
                text: model.url
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                text: medialib.getTitle(model.url)

                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 30
            }

            Text {
                text: "Artist: "

                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 60
            }

            Component.onCompleted: {
                mediaPlayer.source = model.url;
                soundEffect.source = model.url;
                mediaPlayer.play();
            }
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

            background: choose ?  "#B931FC" : "#1F4172"
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

            background: choose ?  "#1F4172" : "#B931FC"
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
