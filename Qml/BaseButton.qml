import QtQuick

Item {
    id: root

    property alias background: background.color
    property alias textcolor: text.color
    property alias text: text.text

    signal clicked()


    height: parent.height
    width: parent.width

    Rectangle{
        id: background

        height: parent.height
        width: parent.width

    }

    Text{
        id: text

        anchors{
            centerIn: parent
        }

        font.pixelSize: 0.5 * parent.height
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}
