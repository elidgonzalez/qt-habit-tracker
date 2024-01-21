#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "habitmanager.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<HabitManager>("com.edg.habitmanager", 1, 0, "HabitManager");

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
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

