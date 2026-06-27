/*
===========================================================
 KyberOS v1.0
 ESP32 Lightsaber Firmware
 Hardware:
   • ESP32-D0WD-V3
   • BNO085
   • DFPlayer Mini
   • WS2812B Blade
===========================================================
*/

#include "Config.h"

#include "Globals.h"

#include "Hardware.h"

#include "Blade.h"

#include "Motion.h"

#include "Audio.h"

#include "Web.h"

#include "Battery.h"

void setup() {

    Serial.begin(115200);

    Serial.println();
    Serial.println("===============================");
    Serial.println("      KYBER OS v1.0");
    Serial.println("===============================");
    Serial.println();

    initHardware();

    bladeBegin();

    motionBegin();

    audioBegin();

    webBegin();

    batteryBegin();

    Serial.println("System Ready");

}

void loop() {

    //----------------------------------------------------
    // Update every subsystem
    //----------------------------------------------------

    bladeUpdate();

    motionUpdate();

    audioUpdate();

    webUpdate();

    batteryUpdate();

}
