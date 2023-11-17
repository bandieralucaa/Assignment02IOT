#include "Task.h"


class Scheduler {
public:

    Task* myTasks[10];
    int amountTask;
    unsigned long basePeriod = 50;

    Scheduler(int amount, Task* myTasks[]){
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
        int i;
        for(i=0; i<amountTask; i++) {
            if (myTasks[i]->updateAndCheckTIme(basePeriod)){
                myTasks[i]->tick();
            }
        }
        
    }

};