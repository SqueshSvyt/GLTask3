import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import Logic.Mediaplayer

Item {

    Timer {
        id: positionUpdateTimer
        interval: 250
        running: true
        repeat: true
        onTriggered: {
            timeslider.value = Player.mediatime / Player.mediaTime();
        }
    }

    Slider {
        id: timeslider
        opacity: 1
        width: parent.width * 0.9
        height: parent.height

        Material.accent: Material.Blue
        Material.theme: Material.Dark


        to: 1.0

        anchors{
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 10
        }

        onMoved: Player.setMediatime(value * Player.mediaTime())

    }


    Text {
        text: "Current Position: " + formatTime(Player.position)

        font.pixelSize: parent.height * 0.3

        anchors{
            top: parent.top
            right: parent.right
            topMargin: 5
            rightMargin: 10
        }
    }

    Text {
        text: "Total Duration: " + formatTime(Player.duration)

        font.pixelSize: parent.height * 0.3

        anchors{
            top: parent.top
            left: parent.left
            topMargin: 5
            leftMargin: 10
        }
    }


    function formatTime(time) {
        if (isNaN(time))
            return "0:00";

        var minutes = Math.floor(time / 60000);
        var seconds = ((time % 60000) / 1000).toFixed(0);
        return minutes + ":" + (seconds < 10 ? "0" : "") + seconds;
    }
}
