#include "WashingMachineButton.h"
#include "Arduino.h"

WashingMachineButton::WashingMachineButton(int pin){
    this->myPin = pin;
    this->period = 200;
    this->pushed = false;
}

bool WashingMachineButton::isPressed(){
    return this->pushed;
}

void WashingMachineButton::init(){
    
}

void WashingMachineButton::tick(){
    this->pushed = digitalRead(this->myPin) == HIGH ? true : false;
}
