#ifndef __COOLDOWN__
#define __COOLDOWN__

#include "./task/Task.h"

class Cooldown : Task {
    public:
        Cooldown(unsigned long clock);
        bool isOver();
        void reset();
        Cooldown* format(unsigned long newClock);

        void init();
        void tick();
    private:
        unsigned long amountTime;
        unsigned long actTime;

};

#endif