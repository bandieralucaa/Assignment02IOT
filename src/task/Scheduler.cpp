#include "Task.h"
#include "Scheduler.h"
#include <Arduino.h>

class Scheduler{
public:
    Task* myTasks[10];
    int amountTask;
    unsigned long basePeriod = 50;

    Scheduler(int amount, Task* myTasks[]) {
        int i;
        for(i=0; i<amount;i++){
            this->myTasks[i] = myTasks[i];
        }
        this->amountTask = amount;
    }

    void init(int period){
        amountTask = period;
    }

    void schedule(){
        unsigned long t1 = millis();
        int i;
        for(i=0; i<amountTask; i++) {
            if (myTasks[i]->updateAndCheckTIme(basePeriod)){
                myTasks[i]->tick();
            }
        }
        unsigned long elapsed = millis() - t1;
        unsigned long remain = basePeriod - elapsed;
        delay(remain);
        
    }

};