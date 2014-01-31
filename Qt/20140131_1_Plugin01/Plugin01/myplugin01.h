#ifndef MYPLUGIN01_H
#define MYPLUGIN01_H

#include <QQuickItem>

class MyPlugin01 : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(MyPlugin01)

public:
    MyPlugin01(QQuickItem *parent = 0);
    ~MyPlugin01();
};

#endif // MYPLUGIN01_H

