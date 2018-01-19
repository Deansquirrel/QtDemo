import QtQuick 2.0

import com.boot 1.0

Item {
    id:rootItem

    property alias textMsg: textMsg.text

    Rectangle{
        anchors.fill: parent
        color:ui.backColor
        Text{
            id:textMsg
            text: String("系统正在初始化")
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: global.em
            width: parent.width * 0.8
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        }
    }

    CBoot{
        id:cBoot
        onSignalShowMsg: {
            textMsg.text=msg
        }
        onSignalErr: {
            sysBus.showSysNote(msg)
        }
        onSignalBootSuccess: {
            sysBus.loadQml("View")
        }
    }

    Component.onCompleted: {
        cBoot.sysBoot()
    }
}
