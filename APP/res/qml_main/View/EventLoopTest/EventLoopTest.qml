import QtQuick 2.0
import QtQuick.Controls 2.1

import com.view.eventlooptest 1.0
import "../../../qml_com"

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

    function subShowConfirm(){
        confirmBox.open()
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
            id:btnShow
            text:"Show"
            onClicked: {
                cEventLoopTest.subTest()
            }
        }
    }

    Rectangle{
        id:rectBack
        anchors.fill: parent
        color: "black"
        opacity: 0.3
        visible: false
        MouseArea{
            anchors.fill: parent
            onClicked: {
            }
        }
    }

    ConfirmBox{
        id:confirmBox
        height: global.em*5
        width: parent.width*0.6

        x:(parent.width-width)*0.5
        y:(parent.height-height)*0.5

        onConfirmed: {
            cEventLoopTest.confirmed()
        }

        onOpened: {
            rectBack.visible=true
        }
        onClosed: {
            rectBack.visible=false
        }
    }

    CEventLoopTest{
        id:cEventLoopTest
        onSignalShowPopup: {
            subShowConfirm()
        }
    }

}
