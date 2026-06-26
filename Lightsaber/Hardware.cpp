#include "Hardware.h"
#include "Config.h"
#include "Globals.h"
#include <Wire.h>
#include <WiFi.h>
Adafruit_NeoPixel strip(NUM_LEDS,LED_PIN,NEO_GRB+NEO_KHZ800);
Adafruit_BNO08x bno08x;
sh2_SensorValue_t sensorValue;
BluetoothSerial SerialBT;
HardwareSerial DFSerial(2);
DFRobotDFPlayerMini dfplayer;
WebServer server(80);
void initHardware(){
 Serial.begin(115200);
 pinMode(BUTTON_PIN,INPUT_PULLUP);
 strip.begin();strip.show();
 Wire.begin(SDA_PIN,SCL_PIN);
 SerialBT.begin("Lightsaber");
 WiFi.softAP(WIFI_NAME,WIFI_PASS);
}
void updateHardware(){server.handleClient();}
