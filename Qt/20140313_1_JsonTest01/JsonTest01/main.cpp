#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "jsontest01.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    qmlRegisterType<JsonTest01>("com.example.settings", 1, 0, "SettingManager");
    viewer.setMainQmlFile(QStringLiteral("qml/JsonTest01/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
