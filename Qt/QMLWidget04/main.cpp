#include <QApplication>
#include "qmlapplicationviewer.h"
#include "qmlwidget04_01.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    //openglを有効にする
    QApplication::setGraphicsSystem("opengl");
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    //custom elementを登録する
    qmlRegisterType<QMLWidget04_01>("CustomParts", 1, 0, "QMLWidget0401");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/QMLWidget04/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
