#ifndef __CDD__
#define __CDD__

#include "./task/Task.h"
#include "./components/distanceSensor/DistanceSensor.h"

class CarDistanceDetector : public DistanceSensor, public Task {
public:
    CarDistanceDetector(int trigPin, int echoPin);

    double getDistance();
    bool isAboveMax();
    bool isUnderMin();

    void init();
    void tick();

private:
    int trigPin;
    int echoPin;
    double lastRead;
};

#endif