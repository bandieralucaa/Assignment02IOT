#ifndef __DISTANCE_SENSOR__
#define __DISTANCE_SENSOR__

#define MIN_DIST 0.1 //0.1
#define MAX_DIST 0.15 //1

class DistanceSensor {
public:
    virtual double getDistance();
    virtual bool isAboveMax();
    virtual bool isUnderMin();
};


#endif