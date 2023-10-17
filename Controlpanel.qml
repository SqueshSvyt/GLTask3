import QtQuick
import com.company.UIController

Rectangle {
    id: root

    color: "#5E6600"
    height: 100

    Row{
        anchors.centerIn: parent

        spacing: 20

        Imagebutton{
            id: playpause

            width: 64
            height: 64

            source: UIController.isPlaying ? "resources/images/pause.png" : "resources/images/play.png"

            onClicked: UIController.playPause();
        }

    }

}
