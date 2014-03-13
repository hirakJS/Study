#ifndef JSONTEST01_H
#define JSONTEST01_H

#include <QQuickItem>
#include <QJsonObject>

class JsonTest01 : public QQuickItem
{
    Q_OBJECT
public:
    explicit JsonTest01(QQuickItem *parent = 0);

signals:

public slots:
    void setValue(QString name, QVariant value);
    QVariant getValue(QString name);
    bool save();

private:
    QJsonObject m_json;
    bool load();
};

#endif // JSONTEST01_H
