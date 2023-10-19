import QtQuick
import QtQuick.Controls

Window  {
    id: rootwindow

    minimumWidth: 640
    minimumHeight: 480
    width: 1024
    height: 768

    visible: true
    color: "#984063"
    modality: Qt.WindowModal
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

        height: 130
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

            height: 80

            anchors{
                left: footer.left
                right: footer.right
                bottom: footer.bottom
            }

        }
    }

}
