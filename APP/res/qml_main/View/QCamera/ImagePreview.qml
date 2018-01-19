import QtQuick 2.0
import QtQuick.Controls 2.1
import Qt.labs.platform 1.0

import com.view.ccamera 1.0
import "../../../qml_com"

Rectangle {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    color:ui.backColor

    property string imageSource
    property real imageWidth: 0
    property real imageHeight:0

    StackView.onStatusChanged: {
        if(StackView.status==StackView.Active){
            rootItem.refresh()
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
        if(rootItem.imageSource!==""){
            image.source=rootItem.imageSource
        }
    }

    function subBack(){
        cViewManager.popQml()
    }

    Image {
        id:image
        source: imageSource
        width: height
        height: parent.height * 0.5
        cache: false
        anchors.centerIn: parent
    }

    Text{
        id:textInfo
        anchors.verticalCenterOffset: image.height*0.5+global.em
        anchors.centerIn: parent
        color:"red"
        font.pixelSize: global.em
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
            text: "Open"
            onClicked: {
                fileDialog.open()
            }
        }

//        Button{
//            id:btnCImage
//            text: "Create"
//            onClicked: {
//                image.source="image://img/"+Date.now().toString()
//            }
//        }

        Button{
            id:btnDecoder
            text: "Decoder"
            onClicked: {
                textInfo.text=cCamera.decoder(image)
            }
        }

//        Button{
//            id:btnDecoderToImage
//            text: "DecodeToImage"
//            onClicked: {
//                fileDialogToSave.open()
//            }
//        }
    }


    FileDialog{
        id:fileDialog
        fileMode: FileDialog.OpenFile
        nameFilters: ["Image files (*.png)"]
        onAccepted: {
            image.source=fileDialog.currentFile
        }
    }

//    FileDialog{
//        id:fileDialogToSave
//        fileMode: FileDialog.SaveFile
//        nameFilters: ["Image files (*.png)"]
//        onAccepted: {
//            cCamera.decodeToImage(String(fileDialogToSave.currentFile),String(fileDialogToSave.currentFile).replace("file:///",""))
//        }
//    }

    CCamera{
        id:cCamera
    }
}
