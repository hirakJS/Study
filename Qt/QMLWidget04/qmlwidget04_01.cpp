#include "qmlwidget04_01.h"

QMLWidget04_01::QMLWidget04_01(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
  ,m_xRot(0)
  ,m_yRot(0)
  ,m_zRot(0)
  ,m_xTranslate(0)
  ,m_yTranslate(0)
  ,m_zTranslate(1)
{
    setFlag(ItemHasNoContents, false);
}

void QMLWidget04_01::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    static GLfloat vertices [8][3] =

    {
        {-50.5f, -50.5f,  50.5f},

        { 50.5f, -50.5f,  50.5f},

        { 50.5f,  50.5f,  50.5f},

        {-50.5f,  50.5f,  50.5f},

        { 50.5f, -50.5f, -50.5f},

        {-50.5f, -50.5f, -50.5f},

        {-50.5f,  50.5f, -50.5f},

        { 50.5f,  50.5f, -50.5f}

    };



    // http://qt-project.org/doc/qt-4.8/qpainter.html#beginNativePainting
    //の説明を理解する必要があるだろう。OpenGLの基礎知識不足で理解できていない。。。
    painter->beginNativePainting();
    //カリングを有効にする
    glEnable(GL_CULL_FACE);

    //平行移動。z軸方向は拡大・縮小すると思っているのだが、しない。視体積を外れると消える模様。
    glTranslatef(m_xTranslate, m_yTranslate, m_zTranslate);

    //回転
    glRotatef(m_xRot, 1.0, 0.0, 0.0);
    glRotatef(m_yRot, 0.0, 1.0, 0.0);
    glRotatef(m_zRot, 0.0, 0.0, 1.0);

    /* 前 */

    glBegin(GL_POLYGON);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex3fv(vertices[0]);

        glVertex3fv(vertices[1]);

        glColor3f(1.0f, 0.0f, 0.0f);

        glVertex3fv(vertices[2]);

        glVertex3fv(vertices[3]);

    glEnd();



    /* 後 */

    glBegin(GL_POLYGON);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex3fv(vertices[4]);

        glVertex3fv(vertices[5]);

        glColor3f(1.0f, 0.0f, 0.0f);

        glVertex3fv(vertices[6]);

        glVertex3fv(vertices[7]);

    glEnd();



    /* 右 */

    glBegin(GL_POLYGON);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex3fv(vertices[1]);

        glVertex3fv(vertices[4]);

        glColor3f(1.0f, 0.0f, 0.0f);

        glVertex3fv(vertices[7]);

        glVertex3fv(vertices[2]);

    glEnd();



    /* 左 */

    glBegin(GL_POLYGON);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex3fv(vertices[5]);

        glVertex3fv(vertices[0]);

        glColor3f(1.0f, 0.0f, 0.0f);

        glVertex3fv(vertices[3]);

        glVertex3fv(vertices[6]);

    glEnd();



    /* 上 */

    glBegin(GL_POLYGON);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex3fv(vertices[3]);

        glVertex3fv(vertices[2]);

        glVertex3fv(vertices[7]);

        glVertex3fv(vertices[6]);

    glEnd();



    /* 下 */

    glBegin(GL_POLYGON);

        glColor3f(1.0f, 0.0f, 0.0f);

        glVertex3fv(vertices[1]);

        glVertex3fv(vertices[0]);

        glVertex3fv(vertices[5]);

        glVertex3fv(vertices[4]);

    glEnd();
    //カリングを無効にする。これをやらないと、前フレームの描画が残る。
    glDisable(GL_CULL_FACE);
    painter->endNativePainting();
}
