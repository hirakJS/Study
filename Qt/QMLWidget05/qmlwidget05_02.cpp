#include "qmlwidget05_02.h"
#include <QtGui/QOpenGLFunctions>
#include <QQuickWindow>

QMLWidget05_02::QMLWidget05_02(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void QMLWidget05_02::itemChange(QQuickItem::ItemChange change, const QQuickItem::ItemChangeData &value)
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
//        connect(win, SIGNAL(afterRendering()), this, SLOT(paint()), Qt::DirectConnection);
        connect(win, SIGNAL(beforeRendering()), this, SLOT(paint()), Qt::DirectConnection);

        // If we allow QML to do the clearing, they would clear what we paint
        // and nothing would show.
        win->setClearBeforeRendering(false);
    }
}

void QMLWidget05_02::paint()
{
        if (!m_program) {
            m_program = new QOpenGLShaderProgram();
            m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                               "attribute highp vec4 vertices;"
                                               "varying highp vec2 coords;"
                                               "void main() {"
                                               "    gl_Position = vertices;"
                                               "    coords = vertices.xy;"
                                               "}");
            m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                               "uniform lowp float t;"
                                               "varying highp vec2 coords;"
                                               "void main() {"
                                               "    lowp float i = 1. - (pow(coords.x, 4.) + pow(coords.y, 4.));"
                                               "    i = smoothstep(t - 0.8, t + 0.8, i);"
                                               "    i = floor(i * 20.) / 20.;"
                                               "    gl_FragColor = vec4(coords * .5 + .5, i, i);"
                                               "}");
            m_program->bindAttributeLocation("vertices", 0);
            m_program->link();

            connect(window()->openglContext(), SIGNAL(aboutToBeDestroyed()),
                    this, SLOT(cleanup()), Qt::DirectConnection);
        }
        m_program->bind();

        m_program->enableAttributeArray(0);

        float values[] = {
            -1, -1,
            1, -1,
            -1, 1,
            1, 1
        };
        m_program->setAttributeArray(0, GL_FLOAT, values, 2);
        m_program->setUniformValue("t", (float) 0.5);

        glViewport(0, 0, window()->width(), window()->height());

        glDisable(GL_DEPTH_TEST);

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        m_program->disableAttributeArray(0);
        m_program->release();
}

void QMLWidget05_02::cleanup()
{
    if (m_program) {
        delete m_program;
        m_program = 0;
    }
}
