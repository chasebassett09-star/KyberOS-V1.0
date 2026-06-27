#ifndef BLADE_H
#define BLADE_H

#include "BladeTypes.h"

// =====================================================
// Initialization
// =====================================================

void bladeBegin();
void bladeUpdate();

// =====================================================
// Power
// =====================================================

void bladeOn();
void bladeOff();
void bladeToggle();

// =====================================================
// Blade Settings
// =====================================================

void bladeSetColor(uint8_t r, uint8_t g, uint8_t b);
void bladeSetBrightness(uint8_t brightness);
void bladeSetLength(uint16_t length);

void bladeSetMode(BladeMode mode);
void bladeSetProfile(BladeProfile profile);

// =====================================================
// Blade State
// =====================================================

BladeState bladeGetState();

bool bladeIsOn();

void bladeSetIgnitionStyle(IgnitionStyle style);

void bladeSetRetractionStyle(RetractionStyle style);

// =====================================================
// Blade Effects
// =====================================================

void bladeIgnition();
void bladeRetraction();

void bladeFlash();

void bladeLockup(bool enable);

void bladeMelt(bool enable);

void bladeDrag(bool enable);

void bladeBlaster();

void bladeRainbow(bool enable);

void bladeUnstable(bool enable);

// =====================================================
// Effect Management
// =====================================================

void bladeEnableEffect(BladeEffect effect);

void bladeDisableEffect(BladeEffect effect);

bool bladeHasEffect(BladeEffect effect);

// =====================================================
// Utility
// =====================================================

void bladeRefresh();

void bladeClear();

#endif
