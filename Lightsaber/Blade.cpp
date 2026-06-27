#include "Blade.h"
#include "Globals.h"
#include "Config.h"

#include <Adafruit_NeoPixel.h>

BladeSettings blade = {
    DEFAULT_R,
    DEFAULT_G,
    DEFAULT_B,
    255,
    MODE_STABLE,
    0
};

static unsigned long effectTimer = 0;

static uint16_t rainbowHue = 0;

static float noiseOffset = 0;

static BladeState bladeState = BLADE_OFF;

static unsigned long lastFrame = 0;

const uint8_t ignitionSpeed = 2;      // LEDs per frame
const uint16_t frameTime = 10;        // ms between frames

static bool redraw = true;

void bladeBegin() {

    strip.clear();
    strip.show();

    blade.litPixels = 0;

    bladeState = BLADE_OFF;

}

void bladeOn() {

    if (bladeState == BLADE_OFF) {

        blade.litPixels = 0;

        bladeState = BLADE_IGNITING;

    }

}

void bladeOff() {

    if (bladeState == BLADE_ON) {

        bladeState = BLADE_RETRACTING;

    }

}

BladeState bladeGetState() {

    return bladeState;

}

void bladeSetColor(uint8_t r,
                   uint8_t g,
                   uint8_t b) {

    blade.r = r;
    blade.g = g;
    blade.b = b;

    redraw = true;

}

void bladeSetBrightness(uint8_t value) {

    blade.brightness = value;

    redraw = true;

}

void bladeSetMode(BladeMode mode) {

for(int i=0;i<NUM_LEDS;i++){

    if(i>=blade.litPixels){

        strip.setPixelColor(i,0);

        continue;

    }

    switch(blade.mode){

        case MODE_STABLE:{

            float b=stableBrightness();

            strip.setPixelColor(

                i,

                blade.r*b,

                blade.g*b,

                blade.b*b

            );

            break;
        }

        case MODE_UNSTABLE:{

            float b=

            unstableBrightness(i);

            strip.setPixelColor(

                i,

                blade.r*b,

                blade.g*b,

                blade.b*b

            );

            break;
        }

        case MODE_RAINBOW:{

            strip.setPixelColor(

                i,

                rainbowColor(i)

            );

            break;
        }

    }

}

    strip.show();

}

void bladeUpdate() {

    if (millis() - lastFrame < frameTime)
        return;

    lastFrame = millis();

    switch (bladeState) {

        case BLADE_OFF:
            break;

        case BLADE_IGNITING:

            blade.litPixels += ignitionSpeed;

            if (blade.litPixels >= NUM_LEDS) {

                blade.litPixels = NUM_LEDS;

                bladeState = BLADE_ON;

            }

            redraw = true;

            break;

        case BLADE_RETRACTING:

            if (blade.litPixels > ignitionSpeed)
                blade.litPixels -= ignitionSpeed;
            else {

                blade.litPixels = 0;

                bladeState = BLADE_OFF;

            }

            redraw = true;

            break;

case BLADE_ON:

    if(millis()-effectTimer>20){

        effectTimer=millis();

        redraw=true;

        rainbowHue+=350;

    }

    break;

    }

    if (redraw) {

        drawBlade();

        redraw = false;

    }

}

static float unstableBrightness(int pixel) {

    noiseOffset += 0.04;

    float wave =
        sin(pixel*0.20 + noiseOffset);

    float chaos =
        random(-30,30)/100.0;

    float value =
        0.70 +
        wave*0.15 +
        chaos;

    return constrain(value,
                     0.40,
                     1.10);

}

uint32_t rainbowColor(int pixel){

    return strip.gamma32(

        strip.ColorHSV(

            rainbowHue +

            pixel *

            (65535/NUM_LEDS),

            255,

            blade.brightness

        )

    );

}
