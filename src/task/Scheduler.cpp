#include "Task.h"
#include "Scheduler.h"
#include <Arduino.h>

Scheduler::Scheduler(int amount, Task* myTasks[]) {
    int i;
    for(i=0; i<amount;i++){
        this->myTasks[i] = myTasks[i];
    }
    this->amountTask = amount;
}

void Scheduler::init(int period){
    basePeriod = period;
}

void Scheduler::schedule(){
    unsigned long t1 = millis();
    int i;
   
    for(i=0; i<amountTask; i++) {
        if (myTasks[i]->updateAndCheckTime(basePeriod)){
            myTasks[i]->tick();
        }
    }
   
    unsigned long elapsed = millis() - t1;
    unsigned long remain = basePeriod - elapsed;
    delay(remain);
    
}
