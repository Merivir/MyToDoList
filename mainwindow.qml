import QtQuick 2.12
import QtQuick.Controls 2.12

ListView {
    id: listView
    width: 200
    height: 300
    model: taskModel
    delegate: Item {
        Text { text: modelData }
    }
    Button {
        x: 50
        y: 139
        text: "Add Task"
        onClicked: taskModel.append("New Task")
    }
    Button {
        x: 50
        y: 320
        text: "Remove Task"
        onClicked: taskModel.remove(listView.currentIndex)
    }
}

