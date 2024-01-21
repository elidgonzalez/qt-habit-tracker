import QtQuick
import QtQuick.Controls
Item {
    height: 50
    width: parent.width
    Rectangle {
        color: "purple"
        anchors.fill: parent
        Row {
            Text {
                text: qsTr("Test")
            }
            Text {
                text: qsTr("text")
            }
            Button {
                text: "-"
            }
        }
    }
}
