#include "qmlwidget05_04.h"
#include <QtGui/QOpenGLFunctions>
#include <QQuickWindow>
#include "Cube.h"

QMLWidget05_04::QMLWidget05_04(QQuickItem *parent) :
    QQuickItem(parent)
  ,m_xRot(30)
  ,m_yRot(40)
  ,m_zRot(0)
  ,m_xScale(1)
  ,m_yScale(1)
  ,m_zScale(1)
  ,m_xTranslate(0)
  ,m_yTranslate(0)
  ,m_zTranslate(0)
{
    //Scene Graphを使わずにQQuickWindow::afterRendering signalを利用して直接openglで描画しているからか、
    //ItemHasContentsフラグを設定しなくても特に問題は発生しない。
//    setFlag(QQuickItem::ItemHasContents, true);
}

//Qt5.1.0(?)以降はwindowChanged signal を使ったほうが良いだろう。
//http://qt.gitorious.org/qt/qtdeclarative/commit/d5e612fb3e9753c762b741d135fabd2b1f8ae1a6
void QMLWidget05_04::itemChange(QQuickItem::ItemChange change, const QQuickItem::ItemChangeData &value)
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

void QMLWidget05_04::paint()
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
    //視体積の設定(透視投影)　perspectiveかfrustumのどちらかを利用する。near/farの設定の理解がイマイチ。予想した位置でクリップされない。
    pmvMatrix.perspective(60, 1, 0.5, -0.5);
//    pmvMatrix.frustum(-1, 1, -1, 1, 1.5, -1);
    //視野変換
    pmvMatrix.lookAt(QVector3D(0,0,2.5), QVector3D(0,0,0),QVector3D(0,1,0));

    //平行移動
    pmvMatrix.translate(m_xTranslate, m_yTranslate);
    //回転
    pmvMatrix.rotate(m_xRot, 1,0,0);
    pmvMatrix.rotate(m_yRot, 0,1,0);
    pmvMatrix.rotate(m_zRot, 0,0,1);
    //拡大・縮小
    pmvMatrix.scale(m_xScale,m_yScale,m_zScale);

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

void QMLWidget05_04::cleanup()
{
    if (m_program) {
        delete m_program;
        m_program = 0;
    }
}
