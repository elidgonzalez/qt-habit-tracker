#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "habitmanager.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    HabitManager * habits = new HabitManager(&app);
    engine.rootContext()->setContextProperty("habitManager", habits);
    const QUrl url(u"qrc:/HabitTracker/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
