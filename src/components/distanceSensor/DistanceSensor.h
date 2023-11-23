#ifndef __DISTANCE_SENSOR__
#define __DISTANCE_SENSOR__

#define MIN_DIST 0.1
#define MAX_DIST 2

class DistanceSensor {
public:
    virtual double getDistance();
    virtual bool isAboveMax();
    virtual bool isUnderMin();
};


#endif