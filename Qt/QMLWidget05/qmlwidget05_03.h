#ifndef QMLWIDGET05_03_H
#define QMLWIDGET05_03_H

#include <QQuickItem>
#include <QtGui/QOpenGLShaderProgram>

class QMLWidget05_03 : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int xRot READ xRot WRITE setXRot NOTIFY xRotChanged)
    Q_PROPERTY(int yRot READ yRot WRITE setYRot NOTIFY yRotChanged)
    Q_PROPERTY(int zRot READ zRot WRITE setZRot NOTIFY zRotChanged)
    Q_PROPERTY(int xTranslate READ xTranslate WRITE setXTranslate NOTIFY xTranslateChanged)
    Q_PROPERTY(int yTranslate READ yTranslate WRITE setYTranslate NOTIFY yTranslateChanged)
    Q_PROPERTY(int zTranslate READ zTranslate WRITE setZTranslate NOTIFY zTranslateChanged)
public:
    explicit QMLWidget05_03(QQuickItem *parent = 0);
    int xRot() const
    {
        return m_xRot;
    }

    void setXRot(int value)
    {
        if(m_xRot != value){
            m_xRot = value;
            emit xRotChanged();
            //Macだとupdate()呼んでも再描画が入らない。要調査。
            update();
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
            //Macだとupdate()呼んでも再描画が入らない。要調査。
            update();
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
            //Macだとupdate()呼んでも再描画が入らない。要調査。
            update();
        }
    }

    int xTranslate() const
    {
        return m_xTranslate;
    }

    void setXTranslate(int value)
    {
        if(m_xTranslate != value){
            m_xTranslate = value;
            emit xTranslateChanged();
            update();
        }
    }

    int yTranslate() const
    {
        return m_yTranslate;
    }

    void setYTranslate(int value)
    {
        if(m_yTranslate != value){
            m_yTranslate = value;
            emit yTranslateChanged();
            update();
        }
    }

    int zTranslate() const
    {
        return m_zTranslate;
    }

    void setZTranslate(int value)
    {
        qDebug() << "setZTranslate is called.";
        if(m_zTranslate != value){
            m_zTranslate = value;
            emit zTranslateChanged();
            update();
        }
    }


    void itemChange(ItemChange change, const ItemChangeData &value);

signals:
    void xRotChanged();
    void yRotChanged();
    void zRotChanged();
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
    float m_xTranslate;
    float m_yTranslate;
    float m_zTranslate;
};

#endif // QMLWIDGET05_03_H
