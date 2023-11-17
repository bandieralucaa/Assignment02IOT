#ifndef __SCHEDULER__
#define __SCHEDULER__

class Scheduler {
    public:
        virtual void init(int period) = 0;
        // void addTask(Task* task)
        virtual void schedule() = 0;
};

#endif