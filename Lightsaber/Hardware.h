#ifndef HARDWARE_H
#define HARDWARE_H

void initHardware();
void updateHardware();

// Individual initialization functions
void initLED();
void initButton();
void initI2C();
void initBNO();
void initDFPlayer();
void initBluetooth();
void initWiFi();

#endif
