import QtQuick 2.0
import QtQuick.Controls 2.2

import "../../../qml_com"

Popup {
    id:popup

    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    property real fontPixelSize:global.em

    closePolicy: Popup.NoAutoClose

    signal confirmed()

    background: Rectangle{
        id:rectBack
        radius: 3
        color: ui.backColor
    }

    contentItem: Item{
        Button{
            id:btnConfirm
            text: "Confirm"
            anchors.centerIn: parent
            onClicked: {
                popup.close()
                confirmed()
            }
        }
    }
}
