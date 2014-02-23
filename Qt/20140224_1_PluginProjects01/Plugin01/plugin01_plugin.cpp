#include "plugin01_plugin.h"
#include "myplugin01.h"

#include <qqml.h>

void Plugin01Plugin::registerTypes(const char *uri)
{
    // @uri com.nobo66.qmlcomponents
    qmlRegisterType<MyPlugin01>(uri, 1, 0, "MyPlugin01");
}


