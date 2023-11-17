#ifndef __SCHEDULER__
#define __SCHEDULER__

class Scheduler {
    public:

//         virtual void init(int period) = 0;
//         // void addTask(Task* task)
//         virtual void schedule() = 0;

    Scheduler(int amount, Task* myTasks[]);

    void init(int period);

    void schedule();


protected:
    Task* myTasks[10];
    int amountTask;
    unsigned long basePeriod = 50;
};

#endif