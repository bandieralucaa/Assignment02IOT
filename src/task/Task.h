#ifndef __TASK__
#define __TASK__

class Task {
    public:
<<<<<<< HEAD
    virtual void init();
    virtual void tick();
    virtual bool updateAndCheckTIme(int millis);
=======
        virtual void init() = 0;
        virtual void tick() = 0;
        virtual bool updateAndCheckTIme(int millis) = 0;
>>>>>>> main
};

#endif