import QtQuick

Image {
    id: root

    signal clicked

    opacity: buttonmousearea.containsMouse ? 0.75 : 1

    mipmap: true

    MouseArea{
        id: buttonmousearea

        anchors.fill: parent

        hoverEnabled: true

        onClicked: {
            root.clicked()
        }
    }
}
