import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

import "../../../qml_com"

Rectangle {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    color:ui.backColor

//    GridLayout{
//        width: parent.width * 0.9
//        height: parent.height * 0.9
//        columnSpacing: global.em * 0.5
//        rowSpacing: global.em * 0.5

//        anchors.centerIn: parent

//        Button{
//            text: "QCamera Test"
//            onClicked: {
//                cViewManager.pushQml("QCamera")
//            }
//        }
//        Button{
//            text: "ImagePrivew"
//            onClicked: {
//                cViewManager.pushQml("ImagePrivew")
//            }
//        }
//    }

    Flickable{
        anchors.fill: parent
        width: parent.width
        height: parent.height
        contentHeight: column.implicitHeight
        flickableDirection: Flickable.AutoFlickIfNeeded
        ScrollIndicator.vertical: ScrollIndicator { }
        clip: true
        Column{
            id:column
            width: parent.width
            spacing: global.em
            Item{
                width: parent.width
                height: global.em
            }
            Button{
                text: "WeidgetTest"
                width: parent.width*0.6
                anchors.horizontalCenter: parent.horizontalCenter
                visible: global.isWindows
                onClicked: {
                    cViewManager.pushQml("WeidgetTest")
                }
            }
            Button{
                text: "NewtonsoftJson"
                width: parent.width*0.6
                anchors.horizontalCenter: parent.horizontalCenter
                visible: global.isWindows
                onClicked: {
                    cViewManager.pushQml("NewtonsoftJson")
                }
            }
            Button{
                text: "EventLoopTest"
                width: parent.width*0.6
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    cViewManager.pushQml("EventLoopTest")
                }
            }
            Button{
                text: "Numpad"
                width: parent.width*0.6
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    cViewManager.pushQml("Numpad")
                }
            }
            Button{
                text: "SelectList"
                width: parent.width*0.6
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    cViewManager.pushQml("SelectList")
                }
            }
            Button{
                text: "QCamera Test"
                width: parent.width*0.6
                anchors.horizontalCenter: parent.horizontalCenter
                visible: global.isAndroid
                onClicked: {
                    cViewManager.pushQml("QCamera")
                }
            }
            Button{
                text: "ImagePrivew"
                width: parent.width*0.6
                anchors.horizontalCenter: parent.horizontalCenter
                visible: global.isWindows
                onClicked: {
                    cViewManager.pushQml("ImagePrivew")
                }
            }
            Button{
                text: "Test"
                width: parent.width*0.6
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    cViewManager.pushQml("Test")
                }
            }
        }
    }
}
