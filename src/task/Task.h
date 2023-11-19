#ifndef __TASK__
#define __TASK__

class Task {
    public:
    virtual void init();
    virtual void tick();
    virtual bool updateAndCheckTime(int millis);
};

#endif