#include "Hardware.h"
#include "Config.h"
#include "Globals.h"

#include <Wire.h>
#include <WiFi.h>

// ----------------------------------------------------
// Global Hardware Objects
// ----------------------------------------------------

Adafruit_NeoPixel strip(
    NUM_LEDS,
    LED_PIN,
    NEO_GRB + NEO_KHZ800
);

Adafruit_BNO08x bno08x;

sh2_SensorValue_t sensorValue;

BluetoothSerial SerialBT;

HardwareSerial DFSerial(2);

DFRobotDFPlayerMini dfplayer;

WebServer server(80);

// ----------------------------------------------------
// Hardware Status
// ----------------------------------------------------

bool bnoReady = false;

bool dfReady = false;

bool wifiReady = false;

bool bluetoothReady = false;

// ----------------------------------------------------
// Initialize Everything
// ----------------------------------------------------

void initHardware() {

    Serial.println();
    Serial.println("Initializing Hardware...");
initLED();

initButton();

initBNO();

initDFPlayer();

initBluetooth();

initWiFi();

     Serial.println();

    Serial.println(
        "==========="
    );

    Serial.print(
        "Blade: "
    );

    Serial.println("OK");

    Serial.print(
        "BNO085: "
    );

    Serial.println(
        bnoReady ?
        "OK":"FAIL"
    );

    Serial.print(
        "DFPlayer: "
    );

    Serial.println(
        dfReady ?
        "OK":"FAIL"
    );

    Serial.print(
        "Bluetooth: "
    );

    Serial.println(
        bluetoothReady ?
        "OK":"FAIL"
    );

    Serial.print(
        "WiFi: "
    );

    Serial.println(
        wifiReady ?
        "OK":"FAIL"
    );

    Serial.println(
        "==========="
    );
}

void initLED(){
    strip.begin();

    strip.clear();

    strip.show();

    Serial.println("Blade OK");
 
}

void initButton(){
    pinMode(
        BUTTON_PIN,
        INPUT_PULLUP
    );

    Serial.println("Button OK");
}

void initBNO(){
    Wire.begin(
        SDA_PIN,
        SCL_PIN
    );

    Serial.println("I2C OK");

    if(
        bno08x.begin_I2C(0x4B)
    ){

        bnoReady=true;

        bno08x.enableReport(
            SH2_GYROSCOPE_CALIBRATED,
            5000
        );

        bno08x.enableReport(
            SH2_LINEAR_ACCELERATION,
            5000
        );

        Serial.println("BNO085 OK");

    }
    else{

        Serial.println("BNO085 FAILED");

    }
}

void initDFPlayer(){
    DFSerial.begin(
        9600,
        SERIAL_8N1,
        DF_RX,
        DF_TX
    );

    delay(1500);

    if(
        dfplayer.begin(
            DFSerial
        )
    ){

        dfReady=true;

        dfplayer.volume(
            DEFAULT_VOLUME
        );

        Serial.println("DFPlayer OK");

    }
    else{

        Serial.println("DFPlayer FAILED");

    }
}

void initBluetooth(){
    if(
        SerialBT.begin(
            "KyberOS"
        )
    ){

        bluetoothReady=true;

        Serial.println(
            "Bluetooth OK"
        );

    }
}

void initWiFi(){
    WiFi.softAP(
        WIFI_NAME,
        WIFI_PASS
    );

    wifiReady=true;

    Serial.println(
        "WiFi OK"
    );

    Serial.print(
        "IP: "
    );

    Serial.println(
        WiFi.softAPIP()
    );
}

void updateHardware() {

    server.handleClient();

}
