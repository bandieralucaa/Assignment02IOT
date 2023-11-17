#ifndef __CPD__
#define __CPD__

#include "./task/Task.h"
#include "./components/pir/PIR.h"

class CarPresenceDetector : Pir, Task {
public:

    CarPresenceDetector(int pin);
    
};

#endif