#ifndef CONFIG_H
#define CONFIG_H

// =====================================================
// Hardware name
// =====================================================

#define SABER_NAME "KyberOS"

#define FIRMWARE_VERSION "v1.0.0"

// =====================================================
// PIN DEFINITIONS
// =====================================================

#define LED_PIN         5
#define BUTTON_PIN      4

#define DF_RX          16
#define DF_TX          17

#define SDA_PIN        21
#define SCL_PIN        22

#define BATTERY_PIN    34

// =====================================================
// BLADE
// =====================================================

#define NUM_LEDS       144

#define IGNITION_SPEED 2
#define RETRACT_SPEED  2

#define FRAME_TIME_MS  10

#define MAX_BRIGHTNESS 255

// =====================================================
// DEFAULT BLADE COLOR
// =====================================================

#define DEFAULT_R      186
#define DEFAULT_G      0
#define DEFAULT_B      255

// =====================================================
// AUDIO
// =====================================================

#define DEFAULT_VOLUME 25

// Sound IDs on the DFPlayer SD card
#define SOUND_IGNITE    1
#define SOUND_HUM       2
#define SOUND_RETRACT   3
#define SOUND_SWING1    4
#define SOUND_SWING2    5
#define SOUND_SWING3    6
#define SOUND_CLASH1    7
#define SOUND_CLASH2    8
#define SOUND_CLASH3    9
#define SOUND_LOCKUP   10

// =====================================================
// MOTION
// =====================================================

#define SWING_SLOW_THRESHOLD    1.0f
#define SWING_MEDIUM_THRESHOLD  2.0f
#define SWING_FAST_THRESHOLD    4.0f

#define BNO085_ADDRESS 0x4B

#define STOP_SWING_THRESHOLD    0.2f

#define CLASH_THRESHOLD        18.0f

// =====================================================
// BLUETOOTH
// =====================================================
#define BLUETOOTH_NAME "KyberOS"

// =====================================================
// WIFI
// =====================================================

#define WIFI_NAME "Lightsaber"
#define WIFI_PASS "kyber123"

// =====================================================
// BATTERY
// (Only used if you switch from the USB power bank later.)
// =====================================================

#define BATTERY_MAX 12.6f
#define BATTERY_MIN 9.0f

#define R1 100000.0f
#define R2 33000.0f

#endif
