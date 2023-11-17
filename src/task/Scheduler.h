#ifndef __SCHEDULER__
#define __SCHEDULER__

class Scheduler {
    public:
    
    Scheduler(int amount, Task* myTasks[]);

    void init(int period);

    void schedule();


protected:
    Task* myTasks[10];
    int amountTask;
    unsigned long basePeriod = 50;
};

#endif