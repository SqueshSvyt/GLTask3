import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtMultimedia
import Logic.Mediaplayer

Item {
    id:root

    visible: true

    VideoOutput{
        id: videooutput

        objectName: "VideoOutput"

        anchors.fill: parent

        width: parent.width
        height: parent.height


        fillMode: VideoOutput.PreserveAspectFit

        TapHandler {
            onDoubleTapped: {
                //MetaData
            }
        }
    }
}
