#ifndef __SCHEDULER__
#define __SCHEDULER__

class Scheduler {
    public:
    
    Scheduler(int amount, Task* myTasks[]);

    void init(int period);

    void schedule();
};

#endif