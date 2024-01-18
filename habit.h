#ifndef HABIT_H
#define HABIT_H

#include <QObject>

class Habit : public QObject
{
    Q_OBJECT
public:
    explicit Habit(QObject *parent = nullptr);
    void setName(QString name) {this->name = name;}
    void setDescription(QString description) {this->description = description;}
    void setCategory(QString category) {this->category = category;}
    void setFrequency(QString frequency) {this->frequency = frequency;}
    void setAll(QString name, QString description, QString category, QString frequency);
    QString getName() {return name;}
    QString getDescription() {return description;}
    QString getCategory() {return category;}
    QString getfrequency() {return frequency;}
private:
    QString name;
    QString description;
    QString category;
    QString frequency;
signals:
};

#endif // HABIT_H
