#include "qleapeventlistener.h"
#include "qleapgesture.h"

QLeapEventListener::QLeapEventListener(QQuickItem *listener)
    :m_listener(listener)
{
}

void QLeapEventListener::onInit(const Controller &)
{

}

void QLeapEventListener::onConnect(const Controller & controller)
{
    controller.enableGesture(Gesture::TYPE_CIRCLE);
    controller.enableGesture(Gesture::TYPE_KEY_TAP);
    controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
    controller.enableGesture(Gesture::TYPE_SWIPE);
}

void QLeapEventListener::onDisconnect(const Controller &)
{

}

void QLeapEventListener::onExit(const Controller &)
{

}

void QLeapEventListener::onFrame(const Controller & controller)
{
    const Frame frame = controller.frame();
    // Get gestures
    const GestureList gestures = frame.gestures();
    for (int g = 0; g < gestures.count(); ++g) {
      Gesture gesture = gestures[g];

      switch (gesture.type()) {
        case Gesture::TYPE_CIRCLE:
        {
          CircleGesture circle = gesture;
          std::string clockwiseness;

          if (circle.pointable().direction().angleTo(circle.normal()) <= PI/4) {
            clockwiseness = "clockwise";
          } else {
            clockwiseness = "counterclockwise";
          }

          // Calculate angle swept since last frame
          float sweptAngle = 0;
          if (circle.state() != Gesture::STATE_START) {
            CircleGesture previousUpdate = CircleGesture(controller.frame(1).gesture(circle.id()));
            sweptAngle = (circle.progress() - previousUpdate.progress()) * 2 * PI;
          }
          std::cout << "Circle id: " << gesture.id()
                    << ", state: " << gesture.state()
                    << ", progress: " << circle.progress()
                    << ", radius: " << circle.radius()
                    << ", angle " << sweptAngle * RAD_TO_DEG
                    <<  ", " << clockwiseness << std::endl;
          break;
        }
        case Gesture::TYPE_SWIPE:
        {
          SwipeGesture swipe = gesture;
          std::cout << "Swipe id: " << gesture.id()
            << ", state: " << gesture.state()
            << ", direction: " << swipe.direction()
            << ", speed: " << swipe.speed() << std::endl;
          onSwipe(swipe);
          break;
        }
        case Gesture::TYPE_KEY_TAP:
        {
          KeyTapGesture tap = gesture;
          std::cout << "Key Tap id: " << gesture.id()
            << ", state: " << gesture.state()
            << ", position: " << tap.position()
            << ", direction: " << tap.direction()<< std::endl;
          break;
        }
        case Gesture::TYPE_SCREEN_TAP:
        {
          ScreenTapGesture screentap = gesture;
          std::cout << "Screen Tap id: " << gesture.id()
          << ", state: " << gesture.state()
          << ", position: " << screentap.position()
          << ", direction: " << screentap.direction()<< std::endl;
          break;
        }
        default:
          std::cout << "Unknown gesture type." << std::endl;
          break;
      }
    }
}

void QLeapEventListener::onFocusGained(const Controller &)
{

}

void QLeapEventListener::onFocusLost(const Controller &)
{

}

void QLeapEventListener::onSwipe(const SwipeGesture &gesture)
{
    QLeapGesture *listener = qobject_cast<QLeapGesture*>(m_listener);
    float angle = (gesture.direction()).angleTo(Vector(1.0, 0.0, 0.0));
    if(listener){
        emit listener->swipe(angle);
    }
}
