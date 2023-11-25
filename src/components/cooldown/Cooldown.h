#ifndef __COOLDOWN__
#define __COOLDOWN__


class Cooldown {
    public:
        //Cooldown(unsigned long clock);
        virtual bool isOver() = 0;
        virtual Cooldown* reset()= 0;
        virtual Cooldown* format(unsigned long newClock) = 0;
        virtual void stop() = 0;
        virtual Cooldown* resume() = 0;
        virtual int percentageComplete() = 0;
};

#endif