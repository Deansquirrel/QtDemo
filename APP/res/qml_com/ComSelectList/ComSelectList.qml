import QtQuick 2.0

import com.com.selectlist 1.0

Item {
    id:rootItem
    implicitHeight: rectContext.height
    implicitWidth: global.defaultWidth

    visible: false

    property alias title: textTitle.text
    property real lineHeight: global.em*2
    property int showItemCount: 5
    property real padding:global.em

    //QStringList
    property var listData:new Array
    onListDataChanged: {
        listView.model=listData
        listView.height=lineHeight*Math.min(showItemCount,listData.length)
    }

    property string currData: ""
    property var currMultiData: new Array

    property bool isMultiSelect: false

    signal selected()
    signal opened()
    signal closed()

    function open(){
        opened()
        rootItem.visible=true
    }

    function close(){
        rootItem.visible=false
        closed()
    }

    function itemSelected(modelData){

    }

    Rectangle{
        id:rectContext
        anchors.centerIn: parent
        width: parent.width
        height: rectList.height+padding*2
        radius: 3
        color:ui.backColor
        Column{
            id:rectList
            width: parent.width-padding*2
            height: itemTitle.height+listView.height+(itemMultiSelectContorl.visible?itemMultiSelectContorl.height:0)
            anchors.centerIn: parent
            Item {
                id:itemTitle
                width: parent.width
                height: textTitle.text===""?0:global.em*2
                Text{
                    id:textTitle
                    color:ui.fontLightColor
                    font.pixelSize: global.em
                    width: parent.width
                    wrapMode: Text.NoWrap
                    elide: Text.ElideRight
                }
            }
            ListView{
                id:listView
                width: parent.width
//                height: lineHeight*showItemCount
                clip:true
//                model: rootItem.listData
                delegate: Item{
                    width: parent.width
                    height: lineHeight
                    Text {
                        text: modelData
                        width: parent.width
                        color:ui.fontColor
                        anchors.centerIn: parent
                    }
                    Rectangle{
                        width: parent.width
                        height: 1
                        color:ui.fontLightColor
                        anchors.top: parent.top
                        visible: index>0
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                           itemSelected(modelData)
                        }
                    }
                }
            }
            Item{
                id:itemMultiSelectContorl
                width: parent.width
                height: lineHeight
                visible: isMultiSelect
                Row{
                    anchors.fill: parent
                    Item{
                        width: parent.width*0.5
                        height: parent.height
                        Text{
                            text:"确定"
                            color:ui.fontTipsColor
                            width: parent.width*0.8
                            wrapMode: Text.NoWrap
                            elide: Text.ElideRight
                            horizontalAlignment: Text.AlignHCenter
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                console.debug("sure")
                                close()
                            }
                        }
                    }
                    Item{
                        width: parent.width*0.5
                        height: parent.height
                        Text{
                            text:"确定"
                            color:ui.fontTipsColor
                            width: parent.width*0.8
                            wrapMode: Text.NoWrap
                            elide: Text.ElideRight
                            horizontalAlignment: Text.AlignHCenter
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                console.debug("sure")
                                close()
                            }
                        }
                    }
                }
            }
        }
    }

    CComSelectList{
        id:cComSelectList
    }
}
