import QtQuick
import QtQuick.Controls
import QtMultimedia

Item {
    id:root

    visible: true


    VideoOutput{
        id: videooutput

        objectName: "VideoOutput"

        anchors.fill: parent

        width: parent.width
        height: parent.height


    }

    MouseArea {
        anchors.fill: parent
        onClicked: mediaplayer.play();
    }
}
