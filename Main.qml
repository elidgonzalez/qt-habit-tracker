import QtQuick
import QtQuick.Controls

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("Habit Tracker")

    Grid {
        height: parent.height
        width: parent.width
        columns: 1
        rows: 2
        Rectangle {
            id: habits
            color: "red"
            height: parseInt(parent.height * 2 / 3)
            width: parent.width
        }
        Rectangle {
            id: newHabitInput
            color: "green"
            height: parseInt(parent.height / 3)
            width: parent.width
            Column {
                Row {
                    spacing: 10
                    Label {
                        text: "Name"
                    }
                    Rectangle {
                        border.width: 2
                        height: parent.height
                        width: 100
                        TextInput {
                            text: "Habit Name"
                            color: "lightgray"
                        }
                    }
                }
                Row {
                    spacing: 10
                    Label {
                        text: "Description"
                    }
                    Rectangle {
                        border.width: 2
                        height: parent.height
                        width: 100
                        TextInput {
                            text: "lore ipsum"
                            color: "lightgray"
                        }
                    }
                }
                Row {
                    spacing: 10
                    Label {
                        text: "Category"
                    }
                    Rectangle {
                        border.width: 2
                        height: parent.height
                        width: 100
                        TextInput {
                            text: "#work"
                            color: "lightgray"
                        }
                    }
                }
                Row {
                    spacing: 10
                    Label {
                        text: "Frequency"
                    }
                    ComboBox {
                        model: ["Daily", "Weekly", "Monthly", "Yearly"]
                    }
                    Rectangle {
                        border.width: 2
                        height: parent.height
                        width: 100
                        TextInput {
                            text: "Time HH:MM"
                            color: "lightgray"
                        }
                    }

                }
                Row {
                    Button {
                        text: "Add New Habit"
                    }
                }
            }
        }
    }

}

