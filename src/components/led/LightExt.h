#ifndef __LIGHT_EXT_H__
#define __LIGHT_EXT_H__

#include "Light.h"

class LightExt : public Light {

public:
   virtual void setIntensity(int intensity) = 0;
};

#endif
