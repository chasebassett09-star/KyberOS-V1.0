#ifndef BLADE_H
#define BLADE_H
#include <Arduino.h>
#include "BladeTypes.h"
enum BladeState{BLADE_OFF,BLADE_IGNITING,BLADE_ON,BLADE_RETRACTING};
enum BladeMode{MODE_STABLE,MODE_UNSTABLE,MODE_RAINBOW};
struct BladeSettings{
 uint8_t r,g,b;
 uint8_t brightness;
 BladeMode mode;
 uint16_t litPixels;
};
extern BladeSettings blade;
void bladeBegin();
void bladeUpdate();
void bladeOn();
void bladeOff();
void bladeSetColor(uint8_t,uint8_t,uint8_t);
void bladeSetBrightness(uint8_t);
void bladeSetMode(BladeMode);
BladeState bladeGetState();
#endif
