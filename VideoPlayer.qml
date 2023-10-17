import QtQuick
import QtMultimedia


Item {
    id:root

    visible: true

    Video{
        id: videooutput

        anchors.fill: parent

        width: parent.width
        height: parent.height

        source: "C:/Users/olegs/Music/cyberpank.mp4"

        loops: MediaPlayer.Infinite
    }

    onVisibleChanged: {
        if (visible)
          videooutput.play()
    }
}
