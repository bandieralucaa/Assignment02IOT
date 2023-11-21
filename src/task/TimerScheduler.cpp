#include "TimerScheduler.h"
#include "Timer.h"
#include <Arduino.h>

TimerScheduler::TimerScheduler(int amount, Task* myTasks[]){
    int i;
    for(i=0; i<amount;i++){
        this->myTasks[i] = myTasks[i];
    }
    this->amountTask = amount;
};

void TimerScheduler::init(int period){
    this->timer = new Timer();
    this->timer -> setupPeriod(period);
}

void TimerScheduler::schedule(){
    int i;
    for(i=0; i<amountTask; i++) {
        if (myTasks[i]->updateAndCheckTime(basePeriod)){
            myTasks[i]->tick();
        }
    }

    this->timer->waitForNextTick();
}
