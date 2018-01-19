import QtQuick 2.6
  import QtQuick.Controls 2.0

  Popup {
      id: popup

      property alias titleFont: textTitle.font
      property alias title: textTitle.text

      property real lineHeight:global.em*2

      //列表最大可见项数量
      property int showItemCount: 5

      //列表数据
      property var listData:new Array

      modal: true

      closePolicy: Popup.NoAutoClose

      background: Rectangle {
          implicitWidth: 200
          implicitHeight: 200
          color:ui.backColor
          radius: 3
      }
      contentItem: Column {
          spacing: global.em*0.5
          Item{
              width: parent.width
              height: lineHeight*(textTitle.text===""?0:1)
              visible: textTitle.text!==""
              Text{
                  id:textTitle
                  width: parent.width
                  anchors.verticalCenter: parent.verticalCenter
                  wrapMode: Text.NoWrap
                  elide: Text.ElideRight
                  font.pixelSize: global.em
                  color:ui.fontLightColor
              }
          }
          ListView{
              width: parent.width
              height: showItemCount*lineHeight
              clip: true
              model: showItemCount*3
              delegate: Rectangle{
                  width: parent.width
                  height: lineHeight
                  Text{
                      text:index
                      anchors.centerIn: parent
                      font.pixelSize: global.em
                  }
              }
          }

          Row{
              width: parent.width-global.em*2
              height: global.em*2
              spacing: global.em
              anchors.horizontalCenter: parent.horizontalCenter
              Rectangle{
                  width: (parent.width-parent.spacing)*0.5
                  height: parent.height
                  color:"blue"
                  Text{
                      text:"Btn"
                      color:"red"
                      font.pixelSize: global.em
                      width: parent.width
                      wrapMode: Text.NoWrap
                      elide: Text.ElideRight
                      anchors.verticalCenter: parent.verticalCenter
                      horizontalAlignment: Text.AlignHCenter
                  }
                  MouseArea{
                      anchors.fill: parent
                      onClicked: {
                          popup.close()
                      }
                  }
              }
              Rectangle{
                  width: (parent.width-parent.spacing)*0.5
                  height: parent.height
                  color:"blue"
                  Text{
                      text:"Btn"
                      color:"red"
                      font.pixelSize: global.em
                      width: parent.width
                      wrapMode: Text.NoWrap
                      elide: Text.ElideRight
                      anchors.verticalCenter: parent.verticalCenter
                      horizontalAlignment: Text.AlignHCenter
                  }
              }
          }
      }
  }
