#ifndef QMLWIDGET05_01_H
#define QMLWIDGET05_01_H

#include <QQuickItem>
#include <QtGui/QOpenGLShaderProgram>

class QMLWidget05_01 : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLWidget05_01(QQuickItem *parent = 0);

protected:
    void itemChange(ItemChange change, const ItemChangeData &value);

signals:
    
public slots:
    void paint();
    void cleanup();

private:
    QOpenGLShaderProgram *m_program;
};

#endif // QMLWIDGET05_01_H
