#include "Cooldown.h"

#include "./task/Task.h"

class Cooldown : public Cooldown, Task{

    unsigned long amountTime;
    unsigned long elapsedTime;
    unsigned long millis;

    Cooldown::Cooldown(unsigned long time) {
        this->amountTime = time;
    }

    bool Cooldown::isOver() {
        return elapsedTime >= amountTime;
    }

    void Task::init() {
    }

    void Task::tick() {
        
    }

    bool Task::updateAndCheckTIme(int millis) {
        this->millis += millis;
    }

    
}

