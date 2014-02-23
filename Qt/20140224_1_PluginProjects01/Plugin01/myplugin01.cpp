#include "myplugin01.h"

MyPlugin01::MyPlugin01(QQuickItem *parent):
    QQuickItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

MyPlugin01::~MyPlugin01()
{
}

const QString &MyPlugin01::prop1() const
{
    return m_prop1;
}

void MyPlugin01::setProp1(const QString &value)
{
    if(m_prop1 == value)
        return;
    m_prop1 = value;
    emit prop1Changed(m_prop1);
}

