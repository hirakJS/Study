#include <QtGui/QGuiApplication>
#include <QQmlEngine>
#include "qtquick2applicationviewer.h"
#include "qmlwidget05_01.h"
#include "qmlwidget05_02.h"
#include "qmlwidget05_03.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QMLWidget05_01>("CustomParts", 1, 0, "QMLWidget0501");
    qmlRegisterType<QMLWidget05_02>("CustomParts", 1, 0, "QMLWidget0502");
    qmlRegisterType<QMLWidget05_03>("CustomParts", 1, 0, "QMLWidget0503");

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/QMLWidget05/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
