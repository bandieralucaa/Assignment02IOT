#include "./state/State.h"

#include "./components/distanceSensor/CarDistanceDetector.h"
//#include "./components/led/LedExtTimered.h"

class EnteringState : public State {

public:
    EnteringState(CarDistanceDetector* sonar);
    void init();
    StateName changeState(); 

private:
    CarDistanceDetector* sonar;
};