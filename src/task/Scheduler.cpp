#include "PIR.h"

class CarPresenceDetector : Pir, Task {
public:

    int myPin = 0;
    unsigned long millis;

    unsigned long period = 200;

    bool isAnyone = false;

    CarPresenceDetector(int pin){

    }

    bool isAnyone(){
        return isAnyone;
    }

    void init(){

    }

    void tick(){
        if (true) { //se c'è qualcuno
            isAnyone = true;
        } else {
            isAnyone = false;
        }
    }
    
    void updateAndCheckTIme(int millis) {
        this->millis += millis;
    }

};