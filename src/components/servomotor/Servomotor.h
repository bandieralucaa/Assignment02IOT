#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

class Servomotor {
public:
    Servomotor(int pin, bool isActOpen);
    bool isOpen();
    bool isClose();
    void open();
    void close();

private:
    int pin;
    bool actOpen;
    bool actClose;
    int actGrade;
};


#endif