#include "./state/State.h"
#include "./components/servomotor/Servomotor.h"

class EnteringState : public State {
public:
    EnteringState();
    void init();
    StateName changeState(); 
private:
    Servomotor* myMotor;
};