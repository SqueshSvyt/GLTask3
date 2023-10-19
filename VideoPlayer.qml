import QtQuick
import QtQuick.Controls
import QtQuick.Window
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

        fillMode: VideoOutput.PreserveAspectFit

        TapHandler {
            onDoubleTapped: {
                parent.fullScreen ?  showNormal() : showFullScreen()
                parent.fullScreen = !parent.fullScreen
            }
            onTapped: {
                //Fot_Meta_data
            }
        }
    }
}
