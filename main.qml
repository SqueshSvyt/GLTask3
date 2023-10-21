import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Windows

Window  {
    id: rootwindow

    minimumWidth: 640
    minimumHeight: 480
    width: 856
    height: 480

    visible: true
    color: "#61677A"
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


    Rectangle{
        id: footer

        height: 0.15 * parent.height
        color: "#FFF6E0"

        anchors{
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        Controlpanel{
            id: controlpanel

            height: parent.height - timeslider.height

            anchors{
                left: footer.left
                right: footer.right
                bottom: footer.bottom
            }
        }

        TimeSlider{
            id: timeslider
            height: 0.30 * parent.height

            anchors{
                left: footer.left
                right: footer.right
                top: footer.top
            }
        }
    }


    VideoPlayer{
        id: videozone

        visible: !controlpanel.library


        anchors{
            left: parent.left
            right: parent.right
            top: mainmenubar.bottom
            bottom: footer.top
        }

        height: parent.height - (mainmenubar.height + footer.height)
    }

    LibraryZone{
        id: libzone

        visible: controlpanel.library

        anchors{
            left: parent.left
            right: parent.right
            top: mainmenubar.bottom
            bottom: footer.top
        }

        height: parent.height - (mainmenubar.height + footer.height)
    }
}
