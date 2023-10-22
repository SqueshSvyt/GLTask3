import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import Logic.Mediaplayer
import Logic.Audio

Rectangle {
    id: root
    property alias library: root.islib

    default property bool islib: false

    color: "#D8D9DA"
    height: parent.height

    Imagebutton{
        id: sound

        width: parent.height * 0.6
        height: parent.height * 0.6
        anchors{
            verticalCenter: parent.verticalCenter
            right: audioSlider.left
            rightMargin: 10
        }

        source: Audio.isMute ? "../resources/images/mute.png" : "../resources/images/sound.png"

        anchors.verticalCenterOffset: 0

        onClicked: Audio.mute_audio()
    }


    Slider {
        id: audioSlider

        width: parent.width * 0.15

        to: 1.0

        anchors {
           verticalCenter: parent.verticalCenter
           left: parent.left
           leftMargin: parent.width * 0.1
        }

        value: 0.5
        onValueChanged: Audio.setVol(value)
    }


    Row{
        spacing: playpause.height * 0.2

        anchors.centerIn: parent

        Imagebutton{

            id: prev

            anchors.verticalCenter:  parent.verticalCenter

            width: root.height * 0.6
            height: root.height * 0.6

            source: "../resources/images/next.png"

            onClicked: Player.mediaSeek(-5000)
        }

        Imagebutton{

            id: playpause

            anchors.verticalCenter:  parent.verticalCenter

            width: root.height * 0.8
            height: root.height * 0.8

            source: Player.isPlaying ? "../resources/images/pause.png" : "../resources/images/play.png"

            onClicked: Player.playPause();
        }

        Imagebutton{

            id: next

            anchors.verticalCenter:  parent.verticalCenter

            rotation: 180

            width: root.height * 0.6
            height: root.height * 0.6

            source: "../resources/images/next.png"

            onClicked: Player.mediaSeek(5000)
        }
    }


    Imagebutton{
        id: repeatmode

        anchors{
            verticalCenter: parent.verticalCenter
            right: library.right
            rightMargin: 0.1 * parent.width
        }

        width: root.height * 0.6
        height: root.height * 0.6

        source: Player.isRepeat ? "../resources/images/resetmode.png" : "../resources/images/resetmodeoff.png"

        onClicked: {
            Player.changeRepeatStatus();
        }
    }

    Imagebutton{
        id: library

        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
            rightMargin: 0.05 * parent.width
        }

        width: root.height * 0.6
        height: root.height * 0.6

        source: root.islib ? "../resources/images/videochoose.png" : "../resources/images/library.png"

        onClicked: {
            root.islib = !root.islib
        }
    }
}
