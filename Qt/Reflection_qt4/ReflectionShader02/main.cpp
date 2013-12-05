#include <QApplication>
#include "qmlapplicationviewer.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
#ifdef SHADEREFFECTS_USE_OPENGL_GRAPHICSSYSTEM
    QApplication::setGraphicsSystem("opengl");
#endif //SHADEREFFECTS_USE_OPENGL_GRAPHICSSYSTEM
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/ReflectionShader02/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
