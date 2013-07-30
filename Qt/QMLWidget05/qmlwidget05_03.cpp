#include "qmlwidget05_03.h"
#include <QtGui/QOpenGLFunctions>
#include <QQuickWindow>

QMLWidget05_03::QMLWidget05_03(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void QMLWidget05_03::itemChange(QQuickItem::ItemChange change, const QQuickItem::ItemChangeData &value)
{
    Q_UNUSED(value);
    // The ItemSceneChange event is sent when we are first attached to a window.
    if (change == ItemSceneChange) {
        QQuickWindow *win = window();
        if (!win)
            return;

        // Connect the beforeRendering signal to our paint function.
        // Since this call is executed on the rendering thread it must be
        // a Qt::DirectConnection
        connect(win, SIGNAL(afterRendering()), this, SLOT(paint()), Qt::DirectConnection);
        //        connect(win, SIGNAL(beforeRendering()), this, SLOT(paint()), Qt::DirectConnection);

        // If we allow QML to do the clearing, they would clear what we paint
        // and nothing would show.
        win->setClearBeforeRendering(false);
    }
}

void QMLWidget05_03::paint()
{
    static int vertexLocation = 0;
    static int matrixLocation = 0;
    static int colorLocation = 0;
    if (!m_program) {
        m_program = new QOpenGLShaderProgram();
        m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                           "attribute highp vec4 vertex;\n"
                                           "uniform highp mat4 matrix;\n"
                                           "void main(void)\n"
                                           "{\n"
                                           "   gl_Position = matrix * vertex;\n"
                                           "}");
        m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                           "uniform mediump vec4 color;\n"
                                           "void main(void)\n"
                                           "{\n"
                                           "   gl_FragColor = color;\n"
                                           "}");

        m_program->link();
        vertexLocation = m_program->attributeLocation("vertex");
        matrixLocation = m_program->uniformLocation("matrix");
        colorLocation = m_program->uniformLocation("color");

        connect(window()->openglContext(), SIGNAL(aboutToBeDestroyed()),
                this, SLOT(cleanup()), Qt::DirectConnection);
    }
    m_program->bind();

    //    static GLfloat const triangleVertices[] = {
    //        60.0f,  10.0f,  0.0f,
    //        110.0f, 110.0f, 0.0f,
    //        10.0f,  110.0f, 0.0f
    //    };
    /*static*/ GLfloat const triangleVertices[] = {
        x()+width()/2,  y(),  0.0f,
        x()+width(), y()+height(), 0.0f,
        x(),  y()+height(), 0.0f
    };
    static GLfloat vertices [] =

    {
        -50.5f, -50.5f,  50.5f,

         50.5f, -50.5f,  50.5f,

         50.5f,  50.5f,  50.5f,

        -50.5f,  50.5f,  50.5f,

         50.5f, -50.5f, -50.5f,

        -50.5f, -50.5f, -50.5f,

        -50.5f,  50.5f, -50.5f,

         50.5f,  50.5f, -50.5f,
        0,0,0,
        10,10,0,
        0,10,0,
        x()+width()/2,  y(),  0.0f,
        x()+width(), y()+height(), 0.0f,
        x(),  y()+height(), 0.0f

    };

    //    QColor color(0, 255, 0, 255);
    QColor color(255, 0, 255, 255);

    QMatrix4x4 pmvMatrix;
    //    pmvMatrix.ortho(rect());
    pmvMatrix.ortho(x(), x()+width(), y()+height(), y(), -1, 1);

    m_program->enableAttributeArray(vertexLocation);
//    m_program->setAttributeArray(vertexLocation, triangleVertices, 3);
    m_program->setAttributeArray(vertexLocation, vertices, 3);
    m_program->setUniformValue(matrixLocation, pmvMatrix);
    m_program->setUniformValue(colorLocation, color);

        glViewport(0, 0, window()->width(), window()->height());
//    glViewport(x(), window()->height() - (y()+height()), width(), height());

    glDisable(GL_DEPTH_TEST);

    //    glEnable(GL_BLEND);
    //    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFunc(GL_DST_COLOR, GL_ONE);
    //    glBlendFunc(GL_DST_COLOR, GL_ZERO);

//    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 8, 3);

    m_program->disableAttributeArray(vertexLocation);
    m_program->release();
}

void QMLWidget05_03::cleanup()
{
    if (m_program) {
        delete m_program;
        m_program = 0;
    }
}
