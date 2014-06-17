#include <QApplication>
#include <QQmlApplicationEngine>
#include "coverartprovider.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CoverArtProvider caProvier;
    engine.addImageProvider("coverArt", &caProvier);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
