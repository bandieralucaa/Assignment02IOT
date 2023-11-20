#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "./task/Task.h"


class TimerScheduler {

public:
    TimerScheduler(int amount, Task* myTasks[]);
    void init(int period);
    void schedule();
    bool manageEndPeriod(void *);


};

#endif