#ifndef __MY_COOLDOWN__
#define __MY_COOLDOWN__

#include "./components/cooldown/Cooldown.h"
#include "./task/Task.h"

// #include "./.codespellrc"


class MyCooldown : public Task, public Cooldown {
    public:
        MyCooldown(unsigned long clock);


        void init();
        void tick();


        bool isOver() = 0;
        Cooldown* reset();
        Cooldown* format(unsigned long newClock);
        void stop();
        Cooldown* resume();
        int percentageComplete() = 0;

    private:
        unsigned long amountTime;
        unsigned long initTime;
        unsigned long stopTime;
        bool isStopped= false;
};

#endif