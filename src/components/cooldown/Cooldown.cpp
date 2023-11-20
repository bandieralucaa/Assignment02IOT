#include "Cooldown.h"

Cooldown::Cooldown(unsigned long clock){
    this->amountTime = clock;
    this->period = 100;
}

bool Cooldown::isOver() {
    return actTime >= amountTime;
}

void Cooldown::reset(){
    this->actTime=0;
}

Cooldown* Cooldown::format(unsigned long newClock){
    this->amountTime = newClock;
    this->reset();
    return this;
}

void Cooldown::init() {
}

void Cooldown::tick() {
    if (!this->isOver()){
        this->actTime += this->period;
    }
};
