import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import com.company.UIController

Item {
    Timer {
        id: positionUpdateTimer
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            timeslider.value = UIController.mediatime / UIController.getMaxTime();
        }
    }

    Slider {
        id: timeslider

        width: parent.width * 0.9

        Material.accent: Material.Blue
        Material.theme: Material.Dark


        to: 1.0

        anchors.centerIn: parent;

        onMoved: UIController.setMediatime(value * UIController.getMaxTime())

    }
}
