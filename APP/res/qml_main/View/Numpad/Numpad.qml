import QtQuick 2.0
import QtQuick.Controls 2.1

import "../../../qml_com"
import "../../../qml_com/ComNumpad"

Rectangle {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    color:ui.backColor

    StackView.onStatusChanged: {
        if(StackView.status==StackView.Active){
            rootItem.refresh()
        }
        if(StackView.status==StackView.Deactivating){

        }
    }

    Keys.enabled: true

    Keys.onReleased: {
        if(event.key===Qt.Key_Back){
            event.accepted = true
            subBack()
        }
    }

    function refresh(){
        rootItem.forceActiveFocus()

    }

    function subBack(){
        cViewManager.popQml()
    }

    function subShowNumpad(){
        comNumpad.open()
    }

    function subHideNumpad(){
        comNumpad.close()
    }

    ComNumpad{
        id:comNumpad
        width: parent.width
        height: width*0.7
        anchors.bottom: parent.bottom

        onOpened: {
            sysBus.showSysNote("Opened")
        }
        onClosed: {
            sysBus.showSysNote("Closed")
        }
        onClicked: {
            console.debug(msg)
        }
        onClickDone: {
            sysBus.showSysNote("Done")
        }
        onClickBack: {
            sysBus.showSysNote("back")
        }
    }

    Column{
        anchors.top: parent.top
        anchors.topMargin: global.em
        anchors.right: parent.right
        anchors.rightMargin: global.em
        spacing: global.em * 0.5

        Button{
            id:btnBack
            text:"Back"
            onClicked: {
                subBack()
            }
        }

        Button{
            id:btnShowNumpad
            text:"Show"
            onClicked: {
                subShowNumpad()
            }
        }

        Button{
            id:btnHideNumpad
            text:"Hide"
            onClicked: {
                subHideNumpad()
            }
        }

        Button{
            id:btnChangeEnabled
            text:"Change"
            onClicked: {
                if(comNumpad.btnEnabled){
                    comNumpad.btnEnabled = false
                }
                else{
                    comNumpad.btnEnabled = true
                }
            }
        }
    }

}
