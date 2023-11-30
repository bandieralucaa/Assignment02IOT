#include "./state/State.h"
#include "./components/button/Button.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/OutSender.h"

class WaitConfirmState : public State {
public:
    WaitConfirmState(Button* b, LcdMonitor* lcd, OutSender* out);
    void init();
    StateName changeState();
    
private:
    Button* button;
    LcdMonitor* lcd;
    OutSender* out;
};