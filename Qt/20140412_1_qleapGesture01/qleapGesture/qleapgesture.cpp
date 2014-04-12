#include "qleapgesture.h"

QLeapGesture::QLeapGesture(QQuickItem *parent):
    QQuickItem(parent)
  ,m_qleapLitener(NULL)
  ,m_controller(NULL)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
    this->addListener();
}

QLeapGesture::~QLeapGesture()
{
    this->removeListener();
}

void QLeapGesture::addListener()
{
    m_qleapLitener = new QLeapEventListener(this);
    m_controller = new Controller();
    if((NULL != m_qleapLitener) && (NULL != m_controller)){
        m_controller->addListener(*m_qleapLitener);
    }
}

void QLeapGesture::removeListener()
{
    if(NULL != m_controller){
        m_controller->removeListener(*m_qleapLitener);
    }
}

