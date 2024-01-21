#include "habit.h"

Habit::Habit(QObject *parent)
    : QObject{parent}
{
    name = "";
    description = "";
    category = "";
    frequency = "";
}

void Habit::setAll(QString name, QString description, QString category, QString frequency)
{
    this->name = name;
    this->description = description;
    this->category = category;
    this->frequency = frequency;
}

QString Habit::getAll()
{
    QString habit = getName() + "|" + getDescription() + "|" + getCategory() + "|" + getfrequency();
    return habit;
}
