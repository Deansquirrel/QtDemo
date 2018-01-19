import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import com.main 1.0

import "../../qml_com"

ApplicationWindow {
    visible: true
    width: global.defaultWidth
    height: global.defaultHeight
    title: global.showName

    color:ui.backColor

    Text{
        text: String("加载中")
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: global.em
        width: parent.width * 0.8
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    }

    Loader{
        id:loader
        anchors.fill: parent
        focus: true
        onFocusChanged: {
            if(!focus){
                loader.focus = true
            }
        }
    }

    Note{
        id:note
        x:(parent.width - note.width) * 0.5
        y:(parent.height - note.height) * 0.5
        leftMargin: parent.width * 0.05
        rightMargin: parent.width * 0.05
        maxWidth: parent.width * 0.9
    }

    CMain{
        id:cMain
        onSignalLoadQml: {
//            console.debug("加载界面："+billUrl)
//            console.debug("初始化数据："+JSON.stringify(billData))
            loader.setSource(billUrl,billData)
        }
    }

    Connections{
        target: sysBus

        onShowSysNote: {
            note.text=msg
            note.time=time
            note.show()
        }

        onLoadQml: {
            cMain.loadQml(billKey,initData)
        }
    }

    Component.onCompleted: {
        sysBus.loadQml("Boot",{"textMsg":"系统正在初始化"})
    }
}

