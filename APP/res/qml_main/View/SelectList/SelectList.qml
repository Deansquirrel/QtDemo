import QtQuick 2.0
import QtQuick.Controls 2.1
import com.view.selectlist 1.0

import "../../../qml_com"
import "../../../qml_com/ComSelectList"



Rectangle {
    id:rootRect
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth
    color:ui.backColor

    StackView.onStatusChanged: {
        if(StackView.status==StackView.Active){
            rootRect.refresh()
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
        rootRect.forceActiveFocus()
    }

    function subBack(){
        cViewManager.popQml()
    }

    Column{
        anchors.top: parent.top
        anchors.topMargin: global.em
        anchors.right: parent.right
        anchors.rightMargin: global.em
        spacing: global.em * 0.5

        Button{
            id:btnBack
            text: "Back"
            onClicked: {
                subBack()
            }
        }

        Button{
            id:btnSelFile
            text: "Show"
            onClicked: {
                comSelectList.open()
            }
        }
    }

    Rectangle{
        id:rectBack
        anchors.fill: parent
        color:"black"
        opacity: 0.3
        visible: false
        MouseArea{
            anchors.fill: parent
            onClicked: {
                comSelectList.close()
            }
        }
    }

    SelectListPopup{
        id:comSelectList
        width: parent.width*0.8
        height: parent.height*0.6
        x:(parent.width-width)*0.5
        y:(parent.height-height)*0.5
    }

//    ComSelectList{
//        id:comSelectList
//        anchors.centerIn: parent
//        showItemCount: 6
//        width: parent.width*0.8
//        lineHeight: global.em*3
//        title: "选择列表（待完成）"
//        listData: cSelectList.getStringList()
//        isMultiSelect: true
//        onOpened: {
//            rectBack.visible=true
//        }
//        onClosed: {
//            rectBack.visible=false
//        }
//    }

    CSelectList{
        id:cSelectList
    }
}
