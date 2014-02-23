#ifndef MYPLUGIN01_H
#define MYPLUGIN01_H

#include <QQuickItem>

class MyPlugin01 : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(MyPlugin01)
    Q_PROPERTY(QString prop1 READ prop1 WRITE setProp1 NOTIFY prop1Changed)

public:
    MyPlugin01(QQuickItem *parent = 0);
    ~MyPlugin01();

    const QString &prop1() const;
    void setProp1(const QString &value);

signals:
    void prop1Changed(const QString &value);

private:
    QString m_prop1;
};

#endif // MYPLUGIN01_H

