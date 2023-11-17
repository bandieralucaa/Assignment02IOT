#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "./components/pir/PIR.h"
#include "./components/led/Led.h"

#include "./task/Task.h"
#include "./state/State.h"

#include "configs.h"


class Controller{
public:
    void execute();
};
#endif
