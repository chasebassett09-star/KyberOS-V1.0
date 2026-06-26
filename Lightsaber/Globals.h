#ifndef GLOBALS_H
#define GLOBALS_H
#include <Adafruit_NeoPixel.h>
#include <Adafruit_BNO08x.h>
#include <DFRobotDFPlayerMini.h>
#include <BluetoothSerial.h>
#include <HardwareSerial.h>
#include <WebServer.h>
#include "Blade.h"

extern Adafruit_NeoPixel strip;
extern Adafruit_BNO08x bno08x;
extern sh2_SensorValue_t sensorValue;
extern BluetoothSerial SerialBT;
extern HardwareSerial DFSerial;
extern DFRobotDFPlayerMini dfplayer;
extern WebServer server;
extern BladeSettings blade;
#endif
