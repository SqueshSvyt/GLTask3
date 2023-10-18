import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import com.company.UIController

Rectangle {
    id: root

    color: "#313866"
    height: 100

    Imagebutton{
        id: sound

        width: 40
        height: 40
        anchors{
            verticalCenter: parent.verticalCenter
            right: audioSlider.left
            rightMargin: 10
        }
        source: "resources/images/sound.png"
        anchors.verticalCenterOffset: 0
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
        onValueChanged: UIController.setVolume(value) // Update the audio volume in C++

    }


    Row{
        spacing: 20

        anchors.centerIn: parent



        Imagebutton{

            id: playpause

            width: 64
            height: 64

            source: UIController.isPlaying ? "resources/images/pause.png" : "resources/images/play.png"

            onClicked: UIController.playPause();
        }

    }

}
