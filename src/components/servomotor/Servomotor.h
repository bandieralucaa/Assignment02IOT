#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

class Servomotor {
public:
    virtual bool isOpen() = 0;
    virtual bool isClose() = 0;
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void stop() = 0;

};


#endif