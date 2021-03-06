import QtQuick 2.0
import QtQuick.Controls 2.1

import LibWidget 1.0

import "../../../qml_com"

import com.view.weidgettest 1.0

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

    function subTest(){
//        cWeidgetTest.startWeidget()
        confirmBox.text = "are you sure?";
        confirmBox.show()
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
            text:"Test"
            onClicked: {
                subTest()
            }
        }
    }

    ConfirmBox{
        id:confirmBox
    }

    CWeidgetTest{
        id:cWeidgetTest
    }

}
