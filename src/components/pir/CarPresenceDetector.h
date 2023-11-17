#ifndef __CPD__
#define __CPD__

#include "./task/Task.h"
#include "./components/pir/PIR.h"

class CarPresenceDetector : Pir, Task {
public:

    // bool isAnyone(){
    //     return isAnyone;
    // }

    // void init(){

    // }

    // void tick(){
    //     if (digitalRead(myPin) == HIGH) { //se c'è qualcuno
    //         isAnyone = true;
    //     } else {
    //         isAnyone = false;
    //     }
    // }
    
    // void updateAndCheckTIme(int millis) {
    //     this->millis += millis;
    // }

};
#endif