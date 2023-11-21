#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "./task/Task.h"
#include "Timer.h"

class TimerScheduler {

public:
    TimerScheduler(int amount, Task* myTasks[]);
    void init(int period);
    void schedule();
    //bool manageEndPeriod(void *);
private:
    Task* myTasks[10];
    Timer* timer;

    int amountTask;
    unsigned long basePeriod = 50;

};

#endif