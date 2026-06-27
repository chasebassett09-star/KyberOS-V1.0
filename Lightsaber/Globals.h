#ifndef GLOBALS_H
#define GLOBALS_H

#include <Adafruit_NeoPixel.h>
#include <Adafruit_BNO08x.h>
#include <DFRobotDFPlayerMini.h>
#include <BluetoothSerial.h>
#include <HardwareSerial.h>
#include <WebServer.h>

#include "Blade.h"

// =====================================================
// Hardware Objects
// =====================================================

extern Adafruit_NeoPixel strip;

extern Adafruit_BNO08x bno08x;
extern sh2_SensorValue_t sensorValue;

extern BluetoothSerial SerialBT;

extern HardwareSerial DFSerial;
extern DFRobotDFPlayerMini dfplayer;

extern WebServer server;

// =====================================================
// Blade
// =====================================================

extern BladeSettings blade;

// =====================================================
// Hardware Status
// =====================================================

extern bool bnoReady;
extern bool dfReady;
extern bool bluetoothReady;
extern bool wifiReady;

#endif
