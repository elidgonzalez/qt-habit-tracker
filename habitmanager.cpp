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

void HabitManager::addNewHabit(QString name, QString description, QString category, QString frequency)
{
    if (checkHabit(name) != -1) {
        Habit* newHabit = new Habit();
        newHabit->setAll(name, description, category, frequency);
        habitManager.push_back(newHabit);
    }
}

void HabitManager::removeHabit(QString name)
{
    int i = checkHabit(name);
    if (checkHabit(name) != -1) {
        habitManager.remove(i);
    }
}

void HabitManager::loadHabits()
{

}
