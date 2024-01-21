import QtQuick
import QtQuick.Controls
import com.edg.habitmanager

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
        HabitManager {
            id: habitManager
            onHabitString: function(data) {
                data = data.split("|")
                console.log(data)
                var habit = Qt.createComponent("Habit.qml")
                habit.visible = true
                console.log(habit)
                if (habit.status == Component.Ready) {
                    var habitLine = habit.createObject(habitsCol)
                    console.log(habitLine.children)
                }
            }
        }
        Rectangle {
            id: habits
            color: "red"
            height: parseInt(parent.height * 2 / 3)
            width: parent.width
            Column {
                id: habitsCol
                anchors.fill: parent
            }
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
                    TextField {
                        id: name
                        placeholderText: qsTr("Habit Name!")
                    }

                }
                Row {
                    spacing: 10
                    Label {
                        text: "Description"
                    }
                    TextField {
                        id: description
                        placeholderText: qsTr("lore ipsum....")
                    }
                }
                Row {
                    spacing: 10
                    Label {
                        text: "Category"
                    }
                    TextField {
                        id: category
                        placeholderText: qsTr("#cats")
                    }
                }
                Row {
                    spacing: 10
                    Label {
                        text: "Frequency"
                    }
                    ComboBox {
                        id: freqInterval
                        model: ["Daily", "Weekly", "Monthly", "Yearly"]
                    }
                    TextField {
                        id: freqTime
                        placeholderText: qsTr("Time HH:MM")
                    }

                }
                Row {
                    Button {
                        id: addNew
                        text: qsTr("Add New Habit")
                        onClicked: {
                            if(habitManager.addNewHabit(name.text, description.text, category.text, freqInterval.currentText + " " + freqTime.text)) {
                                habitManager.loadHabits()
                            }
                            else {
                                console.log("Habit " + name.text + " already exists")
                            }

                        }
                    }
                }
            }
        }
    }

}
