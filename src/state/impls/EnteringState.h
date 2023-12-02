#include "./state/State.h"
#include "./components/distanceSensor/CarDistanceDetector.h"

class EnteringState : public State {

public:
    EnteringState(CarDistanceDetector* sonar);
    void init();
    StateName changeState(); 

private:
    CarDistanceDetector* sonar;
};