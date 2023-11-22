#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "./task/Task.h"
#include <arduino-timer.h>

class TimerScheduler {

public:
    TimerScheduler(int amount, Task* myTasks[]);
    void init(int period);
    void schedule();
    void completeTimer();
    //bool manageEndPeriod(void *);
private:
    Task* myTasks[10];
    Timer<1> timer;

    int amountTask;
    unsigned long basePeriod = 50;

};

#endif