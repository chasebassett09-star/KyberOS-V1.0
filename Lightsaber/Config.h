#ifndef CONFIG_H
#define CONFIG_H
#define LED_PIN 5
#define BUTTON_PIN 4
#define DF_RX 16
#define DF_TX 17
#define SDA_PIN 21
#define SCL_PIN 22
#define NUM_LEDS 144
#define BATTERY_PIN 34
#define BATTERY_MAX 12.6
#define BATTERY_MIN 9.0
#define R1 100000.0
#define R2 33000.0
const uint8_t ignitionSpeed = 2;
const uint16_t frameTime = 10;
const char* WIFI_NAME="Lightsaber";
const char* WIFI_PASS="kyber123";
const int DEFAULT_R=186;
const int DEFAULT_G=0;
const int DEFAULT_B=255;
const int DEFAULT_VOLUME=25;
#endif
