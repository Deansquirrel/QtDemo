import QtQuick 2.0
import QtQuick.Controls 2.1

Button {
      id: control
      text: qsTr("Button")

      property color color: ui.fontColor
      property color primaryColor: ui.themeColor
      property color backColor: "white"
      property alias radius: rectBack.radius

      property bool isPrimary: false

      contentItem: Text {
          id:textTitle
          text: control.text
          font: control.font
          color:control.color
          horizontalAlignment: Text.AlignHCenter
          verticalAlignment: Text.AlignVCenter
          elide: Text.ElideRight
      }

      background: Rectangle {
          id:rectBack
          implicitWidth: 100
          implicitHeight: 40
          color:control.backColor
          border.color: control.color
          border.width: 1
          radius: 3
      }

      states: [
          State {
              name: "primaryDisable"
              when: isPrimary&&(!control.enabled)
              PropertyChanges {
                  target: textTitle
                  color:"white"
                  opacity: 0.3
              }
              PropertyChanges {
                  target: rectBack
                  color:control.primaryColor
                  border.color: control.primaryColor
                  opacity: 0.3
              }
          },
          State {
              name: "primary"
              when: isPrimary
              PropertyChanges {
                  target: textTitle
                  color:"white"
              }
              PropertyChanges {
                  target: rectBack
                  color:control.primaryColor
                  border.color: control.primaryColor
              }
          },
          State {
              name: "disable"
              when: !control.enabled
              PropertyChanges {
                  target: textTitle
                  opacity: 0.3
              }
              PropertyChanges {
                  target: rectBack
                  opacity: 0.3
              }
          }
      ]
  }
