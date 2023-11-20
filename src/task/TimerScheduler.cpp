#include "TimerScheduler.h"
#include "Timer.h"
#include <Arduino.h>

class TimerScheduler{
    Task* myTasks[10];
    Timer* timer;

    int amountTask;
    unsigned long basePeriod = 50;
    
    TimerScheduler(int amount, Task* myTasks[]){
        int i;
        for(i=0; i<amount;i++){
            this->myTasks[i] = myTasks[i];
        }
        this->amountTask = amount;
    };

    void init(int period){
        timer = new Timer();
        timer -> setupPeriod(period);
    }

    void schedule(){
        timer->waitForNextTick();
    }

    bool manageEndPeriod(void *){
        unsigned long t1 = millis();
        int i;
        for(i=0; i<amountTask; i++) {
            if (myTasks[i]->updateAndCheckTime(basePeriod)){
                myTasks[i]->tick();
            }
        }
        unsigned long elapsed = millis() - t1;
        unsigned long remain = basePeriod - elapsed;
        schedule();
        return true;
    }
};