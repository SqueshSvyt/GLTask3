import QtQuick

Window {
    minimumWidth: 640
    minimumHeight: 480
    width: 1024
    height: 768

    visible: true
    color: "#984063"
    title: qsTr("MediaPlayerSSV")

    MenuBarPlayer{
        id: mainmenubar

        anchors{
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: videozone.top
        }

    }



    VideoPlayer{
        id: videozone

        anchors{
            left: parent.left
            right: parent.right
            top: mainmenubar.bottom
            bottom: footer.top
        }

        height: parent.height - (mainmenubar.height + footerbutton.height)
    }

    Rectangle{
        id: footer

        height: 150
        color: "#41436A"

        anchors{
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        TimeSlider{
            id: timeslider
            height: 50

            anchors{
                left: footer.left
                right: footer.right
                top: footer.top
            }
        }

        Controlpanel{
            id: controlpanel

            anchors{
                left: footer.left
                right: footer.right
                bottom: footer.bottom
            }

        }
    }

}
