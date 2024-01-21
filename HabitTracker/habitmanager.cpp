#include "habitmanager.h"

HabitManager::HabitManager(QObject *parent)
    : QObject{parent}
{}

int HabitManager::checkHabit(QString name)
{
    for (int i = 0; i < habitManager.size(); i++) {
        if (habitManager[i]->getName() == name) {
            return i;
        }
    }
    return -1;
}

bool HabitManager::addNewHabit(QString name, QString description, QString category, QString frequency)
{
    if (checkHabit(name) == -1) {
        Habit* newHabit = new Habit();
        newHabit->setAll(name, description, category, frequency);
        habitManager.push_back(newHabit);
        return true;
    }
    return false;
}

void HabitManager::removeHabit(QString name)
{
    int i = checkHabit(name);
    if (checkHabit(name) != -1) {
        habitManager.remove(i);
    }
}

// QString HabitManager::getHabits()
// {
//     QString allHabits = "";
//     for (int i = 0; i < habitManager.size(); i++) {
//         allHabits += habitManager[i]->getAll();
//     }
//     return allHabits;
// }

void HabitManager::loadHabits()
{
    for (int i = 0; i < habitManager.size(); i++) {
        qInfo() << "This is a test";
        qInfo() << habitManager[i]->getAll();
        emit habitString(habitManager[i]->getAll());
    }
}
