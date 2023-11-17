#include "Cooldown.h"

#include "./task/Task.h"

class Cooldown : public Cooldown, Task{

    unsigned long amountTime;
    unsigned long elapsedTime;

    Cooldown::Cooldown(unsigned long time) {
        this->amountTime = time;
    }

    bool Cooldown::isOver() {
        return elapsedTime >= amountTime;
    }
    
}

