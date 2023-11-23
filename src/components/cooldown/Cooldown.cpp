// #include "Cooldown.h"
// #include "Arduino.h"

// volatile bool isFinish = false;

// Cooldown::Cooldown(unsigned long clock){
//     this->setupPeriod(clock);   
//     this->amountTime = clock;
//     this->initTime = millis();
// };

// bool Cooldown::isOver(){
//     return !this->isStopped && isFinish;
// };

// Cooldown* Cooldown::reset(){
//     return format(this->amountTime);
// }

// Cooldown* Cooldown::format(unsigned long newClock){
//     Cooldown* c = new Cooldown(newClock);
//     this->~Cooldown();
//     return c;
// }

// void Cooldown::stop(){
//     this->isStopped = true;
//     this->stopTime = millis();
// }

// Cooldown* Cooldown::resume(){
//     return format(this->amountTime - ((this->isStopped ? this->stopTime : millis())  - this->initTime));
// }

// void goneOverTime() {
//     isFinish = true;
// }

// ISR(TIMER1_COMPA_vect) : ISR(TIMER1_COMPA_vect) {
    


// }


