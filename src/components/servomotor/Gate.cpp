#include "Gate.h"

#define AMOUNT_MOVE 1

Gate::Gate(int pin, bool isActOpen) {
    this->pin = pin; //VALUTA SE ELIMINARMI
    this->actOpen = isActOpen;
    this->direction = 0;
    this->motor.attach(pin);
    this->period = 100;
}

bool Gate::isOpen() {
    return this->actOpen;
}

bool Gate::isClose() {
    return this->actClose;
}

void Gate::open() {
    this->direction = 1;
}

void Gate::close() {
    this->direction = -1;
}

void Gate::stop() {
    this->direction = 0;
}





void Gate::tick(){
    int newGrade = this->actGrade + this->direction * AMOUNT_MOVE;
    this->motor.write(newGrade);
}



void Gate::init(){ };


// bool Gate::updateAndCheckTime(int millis) {
//     bool res = false;
//     this->millis += millis;
//     if (this->millis>period){
//         res = true;
//         this->millis = 0;
//     }
//     return res;
// }