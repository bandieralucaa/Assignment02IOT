#include "./state/State.h"

#include "./components/distanceSensor/CarDistanceDetector.h"

#include <arduino-timer.h>

class LeftingState : public State {
public:
    LeftingState(CarDistanceDetector* sonar, Timer<3>* clock);
    void init();
    StateName changeState(); 

private:
    CarDistanceDetector* sonar;
    Timer<3>* clock;
    void flushTimer();
};