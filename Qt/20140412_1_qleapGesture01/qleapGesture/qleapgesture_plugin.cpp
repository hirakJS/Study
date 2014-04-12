#include "qleapgesture_plugin.h"
#include "qleapgesture.h"

#include <qqml.h>

void QLeapGesturePlugin::registerTypes(const char *uri)
{
    // @uri Leap
    qmlRegisterType<QLeapGesture>(uri, 1, 0, "LeapGesture");
}


