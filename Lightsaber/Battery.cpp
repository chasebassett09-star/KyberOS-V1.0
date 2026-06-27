#include "Battery.h"
#include "Config.h"

static float voltage = 0;

static int percent = 100;

static bool lowBattery = false;

void batteryBegin() {

    analogReadResolution(12);

}

void batteryUpdate() {

    static unsigned long lastUpdate = 0;

    if (millis() - lastUpdate < 500)
        return;

    lastUpdate = millis();

    int raw = analogRead(BATTERY_PIN);

    float adc = raw * (3.3 / 4095.0);

    voltage = adc * ((R1 + R2) / R2);

    percent = map(
        voltage * 100,
        BATTERY_MIN * 100,
        BATTERY_MAX * 100,
        0,
        100
    );

    percent = constrain(percent, 0, 100);

    lowBattery = percent < 15;
}

float batteryVoltage() {

    return voltage;

}

int batteryPercent() {

    return percent;

}

bool batteryLow() {

    return lowBattery;

}
