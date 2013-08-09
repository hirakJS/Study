#include "qmlwidget05_03.h"
#include <QtGui/QOpenGLFunctions>
#include <QQuickWindow>
#include "Cube.h"

QMLWidget05_03::QMLWidget05_03(QQuickItem *parent) :
    QQuickItem(parent)
  ,m_xRot(0)
  ,m_yRot(0)
  ,m_zRot(0)
  ,m_xTranslate(0)
  ,m_yTranslate(0)
  ,m_zTranslate(1)
{
    //Scene Graphを使わずにQQuickWindow::afterRendering signalを利用して直接openglで描画しているからか、
    //ItemHasContentsフラグを設定しなくても特に問題は発生しない。
//    setFlag(QQuickItem::ItemHasContents, true);
}

//Qt5.1.0(?)以降はwindowChanged signal を使ったほうが良いだろう。
//http://qt.gitorious.org/qt/qtdeclarative/commit/d5e612fb3e9753c762b741d135fabd2b1f8ae1a6
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
    QQuickItem::itemChange(change, value);
}

void QMLWidget05_03::paint()
{
    static int vertexLocation = 0;
    static int matrixLocation = 0;
    static int colorLocation = 0;
    if (!m_program) {
        m_program = new QOpenGLShaderProgram();
        m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                           "attribute vec3 av3colour;\n"
                                           "attribute highp vec4 vertex;\n"
                                           "uniform highp mat4 matrix;\n"
                                           "varying vec3 vv3colour;\n"
                                           "void main(void)\n"
                                           "{\n"
                                           "   vv3colour = av3colour;\n"
                                           "   gl_Position = matrix * vertex;\n"
                                           "}");
        m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                           "varying vec3 vv3colour;\n"
                                           "void main(void)\n"
                                           "{\n"
                                           "   gl_FragColor = vec4(vv3colour,1.0);\n"
                                           "}");

        m_program->link();
        vertexLocation = m_program->attributeLocation("vertex");
        matrixLocation = m_program->uniformLocation("matrix");
        colorLocation = m_program->attributeLocation("av3colour");

        connect(window()->openglContext(), SIGNAL(aboutToBeDestroyed()),
                this, SLOT(cleanup()), Qt::DirectConnection);
    }
    m_program->bind();

    QMatrix4x4 pmvMatrix;
    static GLfloat scale_x = 50;
    static GLfloat scale_y = 50;
    static GLfloat scale_z = 50;
    //回転
    pmvMatrix.rotate(m_xRot, 1,0,0);
    pmvMatrix.rotate(m_yRot, 0,1,0);
    pmvMatrix.rotate(m_zRot, 0,0,1);
    pmvMatrix.scale(scale_x,scale_y,scale_z);

    //nearPlane,farPlaneの値がCubeの見た目のサイズに影響する。なぜ？
    pmvMatrix.ortho(x(), x()+width(), y()+height(), y(), -50, 50);

    //透視投影やろうとしたが、うまくできていない
//    pmvMatrix.frustum(x(), x()+width(), y()+height(), y(), -100, 100);
//    pmvMatrix.frustum(0, window()->width(), window()->height(), 0, -100, 100);
//    pmvMatrix.perspective(90, 1, -100, 100);

    pmvMatrix.translate(x() + width()/2, y() + height()/2);
    //下の行を有効にすると表示されなくなる。適切な位置に表示されていないのだろう。
//    pmvMatrix.translate(x() + width()/2 + m_xTranslate, y() + height()/2 + m_yTranslate);

    m_program->enableAttributeArray(vertexLocation);
    m_program->setAttributeArray(vertexLocation, vertices, 3);
    m_program->enableAttributeArray(colorLocation);
    m_program->setAttributeArray(colorLocation, colors, 3);
    m_program->setUniformValue(matrixLocation, pmvMatrix);

    glEnable(GL_CULL_FACE);

    glViewport(x(), window()->height() - (y()+height()), width(), height());

    glDisable(GL_DEPTH_TEST);

    //blendについて、色々試してた
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_ONE, GL_SRC_ALPHA);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//    glBlendFunc(GL_DST_COLOR, GL_ONE);
    //    glBlendFunc(GL_DST_COLOR, GL_ZERO);

    glDrawArrays(GL_TRIANGLES, 0, 36);

    m_program->disableAttributeArray(vertexLocation);
    m_program->disableAttributeArray(colorLocation);
    m_program->release();

    glDisable(GL_CULL_FACE);
}

void QMLWidget05_03::cleanup()
{
    if (m_program) {
        delete m_program;
        m_program = 0;
    }
}
