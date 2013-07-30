#ifndef QMLWIDGET05_03_H
#define QMLWIDGET05_03_H

#include <QQuickItem>
#include <QtGui/QOpenGLShaderProgram>

class QMLWidget05_03 : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLWidget05_03(QQuickItem *parent = 0);
    
    void itemChange(ItemChange change, const ItemChangeData &value);

signals:
    
public slots:
    void paint();
    void cleanup();

private:
    QOpenGLShaderProgram *m_program;
};

#endif // QMLWIDGET05_03_H
