import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import Logic.Mediaplayer
import Logic.Audio

Rectangle {
    id: root

    color: "#313866"
    height: parent.height

    Imagebutton{
        id: sound

        width: 40
        height: 40
        anchors{
            verticalCenter: parent.verticalCenter
            right: audioSlider.left
            rightMargin: 10
        }

        source: Audio.isMute ? "resources/images/mute.png" : "resources/images/sound.png"

        anchors.verticalCenterOffset: 0

        onClicked: Audio.mute_audio()
    }


    Slider {
        id: audioSlider

        width: parent.width * 0.2

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
        spacing: 20

        anchors.centerIn: parent



        Imagebutton{

            id: playpause

            width: 64
            height: 64

            source: Player.isPlaying ? "resources/images/pause.png" : "resources/images/play.png"

            onClicked: Player.playPause();
        }

    }
}
