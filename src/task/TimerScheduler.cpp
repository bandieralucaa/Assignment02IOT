#include "TimerScheduler.h"
#include "Task.h"

class TimerScheduler{
    Task* myTasks[10];
    //Timer<1> timer;
    Timer* timer;
    int amountTask;
    unsigned long basePeriod = 50;
    
    TimerScheduler(int amount, Task* myTasks[]){
        int i;
        for(i=0; i<amount;i++){
            this->myTasks[i] = myTasks[i];
        }
        this->amountTask = amount;
        //this->timer = timer_create_default();
    };

    void init(int period){
        timer.every(period, manageEndPeriod);
    }

    void schedule(){
        timer.tick();
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
        delay(remain);
        return true;
    }
};