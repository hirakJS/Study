#ifndef QMLWIDGET05_04_H
#define QMLWIDGET05_04_H

#include <QQuickItem>
#include <QtGui/QOpenGLShaderProgram>
#include <QtQuick/QQuickWindow>

class QMLWidget05_04 : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int xRot READ xRot WRITE setXRot NOTIFY xRotChanged)
    Q_PROPERTY(int yRot READ yRot WRITE setYRot NOTIFY yRotChanged)
    Q_PROPERTY(int zRot READ zRot WRITE setZRot NOTIFY zRotChanged)
    Q_PROPERTY(float xScale READ xScale WRITE setXScale NOTIFY xScaleChanged)
    Q_PROPERTY(float yScale READ yScale WRITE setYScale NOTIFY yScaleChanged)
    Q_PROPERTY(float zScale READ zScale WRITE setZScale NOTIFY zScaleChanged)
    Q_PROPERTY(float xTranslate READ xTranslate WRITE setXTranslate NOTIFY xTranslateChanged)
    Q_PROPERTY(float yTranslate READ yTranslate WRITE setYTranslate NOTIFY yTranslateChanged)
    Q_PROPERTY(float zTranslate READ zTranslate WRITE setZTranslate NOTIFY zTranslateChanged)
public:
    explicit QMLWidget05_04(QQuickItem *parent = 0);
    
    int xRot() const
    {
        return m_xRot;
    }

    void setXRot(int value)
    {
        if(m_xRot != value){
            m_xRot = value;
            emit xRotChanged();
            //Qt5.1.0だとupdate()呼んでも再描画が入らない問題があった。
            //本クラスはScene Graphを使わずに直接opeglを使ってScene Graphの描画とは別に描画しているので、
            //QQuickItem::update()ではなく、QQuickWindow::update()を呼んで再描画させるのが正しいのかもしれない。
            //http://doc-snapshot.qt-project.org/qt5-stable/qtquick/qquickwindow.html#update
            //によると、
            //Calling QQuickWindow::update() differs from QQuickItem::update() in that it always triggers a repaint,
            //regardless of changes in the underlying scene graph or not.
            //とのことなので。
//            update();
            window()->update();
        }
    }

    int yRot() const
    {
        return m_yRot;
    }

    void setYRot(int value)
    {
        if(m_yRot != value){
            m_yRot = value;
            emit yRotChanged();
            window()->update();
        }
    }

    int zRot() const
    {
        return m_zRot;
    }

    void setZRot(int value)
    {
        if(m_zRot != value){
            m_zRot = value;
            emit zRotChanged();
            window()->update();
        }
    }

    float xScale() const
    {
        return m_xScale;
    }

    void setXScale(float value)
    {
        if(m_xScale != value){
            m_xScale = value;
            emit xScaleChanged();
            window()->update();
        }
    }

    float yScale() const
    {
        return m_yScale;
    }

    void setYScale(float value)
    {
        if(m_yScale != value){
            m_yScale = value;
            emit yScaleChanged();
            window()->update();
        }
    }

    float zScale() const
    {
        return m_zScale;
    }

    void setZScale(float value)
    {
        if(m_zScale != value){
            m_zScale = value;
            emit zScaleChanged();
            window()->update();
        }
    }

    float xTranslate() const
    {
        return m_xTranslate;
    }

    void setXTranslate(float value)
    {
        if(m_xTranslate != value){
            m_xTranslate = value;
            emit xTranslateChanged();
            window()->update();
        }
    }

    float yTranslate() const
    {
        return m_yTranslate;
    }

    void setYTranslate(float value)
    {
        if(m_yTranslate != value){
            m_yTranslate = value;
            emit yTranslateChanged();
            window()->update();
        }
    }

    float zTranslate() const
    {
        return m_zTranslate;
    }

    void setZTranslate(float value)
    {
        qDebug() << "setZTranslate is called.";
        if(m_zTranslate != value){
            m_zTranslate = value;
            emit zTranslateChanged();
            window()->update();
        }
    }


    void itemChange(ItemChange change, const ItemChangeData &value);

signals:
    void xRotChanged();
    void yRotChanged();
    void zRotChanged();
    void xScaleChanged();
    void yScaleChanged();
    void zScaleChanged();
    void xTranslateChanged();
    void yTranslateChanged();
    void zTranslateChanged();

public slots:
    void paint();
    void cleanup();

private:
    QOpenGLShaderProgram *m_program;

private:
    int m_xRot;
    int m_yRot;
    int m_zRot;
    float m_xScale;
    float m_yScale;
    float m_zScale;
    float m_xTranslate;
    float m_yTranslate;
    float m_zTranslate;
};

#endif // QMLWIDGET05_04_H
