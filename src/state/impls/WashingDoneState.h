#include "./state/State.h"
#include "components/led/Led.h"

class WashingDoneState : public State {

public:

    void ledManage(Led led);
    StateName changeState();  

private:

};