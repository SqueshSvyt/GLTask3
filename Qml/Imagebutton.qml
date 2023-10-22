import QtQuick


Item {

    property alias source: image.source

    id: root

    opacity: buttonmousearea.containsMouse ? 0.5 : 1

    signal clicked

    Image {
        id: image

        height: parent.height
        width: parent.width

        mipmap: true
    }

    MouseArea{
        id: buttonmousearea

        anchors.fill: parent

        hoverEnabled: true

        onClicked: {
            root.clicked()
        }
    }
}


