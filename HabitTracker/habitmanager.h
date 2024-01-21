#ifndef HABITMANAGER_H
#define HABITMANAGER_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include <QVariant>
#include "habit.h"

class HabitManager : public QObject
{
    Q_OBJECT
public:
    explicit HabitManager(QObject *parent = nullptr);
    int checkHabit(QString);
private:
    QVector<Habit*> habitManager;
public slots:
    bool addNewHabit(QString, QString, QString, QString);
    void removeHabit(QString);
    // QString getHabits();
    void loadHabits();

signals:
    void habitString(QString);
};

#endif // HABITMANAGER_H
