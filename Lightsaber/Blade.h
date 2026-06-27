#ifndef BLADE_H
#define BLADE_H
#include <Arduino.h>
#include "BladeTypes.h"
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
