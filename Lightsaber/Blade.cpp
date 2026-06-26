#include "Blade.h"
#include "Globals.h"
BladeSettings blade={186,0,255,255,MODE_STABLE,0};
static BladeState state=BLADE_OFF;
void bladeBegin(){strip.clear();strip.show();}
void bladeUpdate(){}
void bladeOn(){state=BLADE_IGNITING;}
void bladeOff(){state=BLADE_RETRACTING;}
void bladeSetColor(uint8_t r,uint8_t g,uint8_t b){blade.r=r;blade.g=g;blade.b=b;}
void bladeSetBrightness(uint8_t v){blade.brightness=v;}
void bladeSetMode(BladeMode m){blade.mode=m;}
BladeState bladeGetState(){return state;}
