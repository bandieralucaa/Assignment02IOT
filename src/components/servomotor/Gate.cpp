#include "Gate.h"

#define AMOUNT_MOVE 30

Gate::Gate(int pin, bool isActOpen) {
    this->actOpen = isActOpen;

    this->motor.attach(pin);
    this->period = SERVO_MOTOR_PERIOD;

    this->stopGate();
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

void Gate::stopGate() {
    this->direction = 0;
}


void Gate::tick(){
    int newGrade = this->actGrade + (this->direction * AMOUNT_MOVE);

    #ifdef SERVO_MOTOR_DEBUG
    Serial.print("Servo motor grade: " + (String)newGrade);
    #endif
    
    this->motor.write(newGrade);
    this->actGrade = newGrade;

    this->actOpen = this->actGrade >= MAX_ANGLE;
    this->actClose = this->actGrade <= MIN_ANGLE;
}



void Gate::init(){
    this->actGrade = MIN_ANGLE;
    this->motor.write(this->actGrade);
};