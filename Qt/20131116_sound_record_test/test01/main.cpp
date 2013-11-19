#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QtQml>
#include "myaudiorecorder01.h"

void record(QObject* parent);

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    qmlRegisterType<MyAudioRecorder01>("com.self", 1, 0, "Recorder");
    viewer.setMainQmlFile(QStringLiteral("qml/test01/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
