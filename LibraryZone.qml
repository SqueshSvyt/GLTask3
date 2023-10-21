import QtQuick
import QtQuick.Controls.Basic

Item {
    id:root

    property bool choose: false

    height: parent.height
    width: parent.width

    Row {
        id: choosemenu

        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
        }

        height: parent.height * 0.05


        BaseButton{
            height: parent.height
            width: 0.5 * parent.width

            background: choose ?  "#B931FC" : "#1F4172"
            textcolor: "white"
            text: "Library"

            onClicked: {
                if(!choose){
                    choose = !choose
                }
            }
        }

        BaseButton{
            height: parent.height
            width: 0.5 * parent.width

            background: choose ?  "#1F4172" : "#B931FC"
            textcolor: "white"
            text: "Playlists"

            onClicked: {
                if(choose){
                    choose = !choose
                }
            }
        }
    }



}
