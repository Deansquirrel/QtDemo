import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

import com.view.viewmanager 1.0

import "../../qml_com"

Item {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

//    color:ui.backColor

    StackView{
        id:rootStackView
//        visible: rootStackView.depth > 0
        anchors.fill: parent
        focus: true
    }

    CViewManager{
        id:cViewManager
        onSignalPop: {
            if(rootStackView.depth>1){
                rootStackView.pop()
            }
            else{
                rootStackView.clear()
                Qt.quit()
            }
        }
        onSignalPushQml: {
//            console.debug("------------------------------------------")
//            console.debug("pushQml " + url)
//            console.debug("data - " + JSON.stringify(data))
            rootStackView.push(viewUrl,initData)
//            console.debug("pushQml " + url + " Completed")
//            console.debug("------------------------------------------")
        }
    }

    Component.onCompleted: {
        cViewManager.pushQml("Menu")
    }
}
