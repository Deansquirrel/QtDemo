import QtQuick 2.0
import QtQuick.Controls 2.1

import com.view.newtonsoftjson 1.0

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

    function subConvertJsontoXML(){
        var strXml=cNewtonsoftJson.subConvertJsontoXML()
        console.info(strXml)
        sysBus.showSysNote(strXml)
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
            id:btnJsontoXML
            text:"JsontoXML"
            onClicked: {
                subConvertJsontoXML()
            }
        }
    }

    CNewtonsoftJson{
        id:cNewtonsoftJson
    }

}
