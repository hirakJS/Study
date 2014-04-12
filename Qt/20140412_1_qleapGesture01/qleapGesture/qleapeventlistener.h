#ifndef QLEAPEVENTLISTENER_H
#define QLEAPEVENTLISTENER_H

#include <QQuickItem>
#include "Leap.h"
using namespace Leap;

class QLeapEventListener : public Listener
{
public:
    QLeapEventListener(QQuickItem*);
    virtual void onInit(const Controller&);
    virtual void onConnect(const Controller&);
    virtual void onDisconnect(const Controller&);
    virtual void onExit(const Controller&);
    virtual void onFrame(const Controller&);
    virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);

private:
    QQuickItem *m_listener;
    void onSwipe(const SwipeGesture&);
};

#endif // QLEAPEVENTLISTENER_H
