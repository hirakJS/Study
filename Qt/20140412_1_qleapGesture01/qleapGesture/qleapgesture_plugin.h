#ifndef QLEAPGESTURE_PLUGIN_H
#define QLEAPGESTURE_PLUGIN_H

#include <QQmlExtensionPlugin>

class QLeapGesturePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QLEAPGESTURE_PLUGIN_H

