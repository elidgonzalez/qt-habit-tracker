#ifndef HABITMANAGER_H
#define HABITMANAGER_H

#include <QObject>
#include <QVector>
#include "habit.h"

class HabitManager : public QObject
{
    Q_OBJECT
public:
    explicit HabitManager(QObject *parent = nullptr);
    int checkHabit(QString);
    void addNewHabit(QString, QString, QString, QString);
    void removeHabit(QString);
    void loadHabits();
private:
    QVector<Habit*> habitManager;
public slots:

signals:
};

#endif // HABITMANAGER_H
