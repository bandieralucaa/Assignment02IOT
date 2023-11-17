#include "Cooldown.h"

#include "./task/Task.h"

class Cooldown : Cooldown, Task{

    unsigned long amountTime;
    unsigned long elapsedTime;
    unsigned long millis;

    Cooldown(){}

    Cooldown::Cooldown(unsigned long time) {
        this->amountTime = time;
    }

    bool Cooldown::isOver() {
        return elapsedTime >= amountTime;
    }

    void init() {
    }

    void tick() {
        
    }

    bool updateAndCheckTime(int millis) {
        this->elapsedTime += millis;
        this->millis += millis;
    }

    
}

