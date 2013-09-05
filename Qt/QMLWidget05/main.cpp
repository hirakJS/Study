#include <QtGui/QGuiApplication>
#include <QQmlEngine>
#include "qtquick2applicationviewer.h"
#include "qmlwidget05_01.h"
#include "qmlwidget05_03.h"
#include "qmlwidget05_04.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QMLWidget05_01>("CustomParts", 1, 0, "QMLWidget0501");
    qmlRegisterType<QMLWidget05_03>("CustomParts", 1, 0, "QMLWidget0503");
    qmlRegisterType<QMLWidget05_04>("CustomParts", 1, 0, "QMLWidget0504");

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/QMLWidget05/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
