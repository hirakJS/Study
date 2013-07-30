#ifndef QMLWIDGET05_02_H
#define QMLWIDGET05_02_H

#include <QQuickItem>
#include <QtGui/QOpenGLShaderProgram>

class QMLWidget05_02 : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLWidget05_02(QQuickItem *parent = 0);
    
protected:
    void itemChange(ItemChange change, const ItemChangeData &value);

signals:
    
public slots:
    void paint();
    void cleanup();

private:
    QOpenGLShaderProgram *m_program;
};

#endif // QMLWIDGET05_02_H
