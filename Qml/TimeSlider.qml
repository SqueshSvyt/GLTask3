import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import Logic.Mediaplayer

Item {
    opacity: 0.5

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

        anchors.centerIn: parent;

        onMoved: Player.setMediatime(value * Player.mediaTime())

    }
}
