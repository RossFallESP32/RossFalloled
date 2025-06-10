#include "RF24.h"
#include <SPI.h>
#include <ezButton.h>
#include <Adafruit_NeoPixel.h>
#include "esp_bt.h"
#include "esp_wifi.h"

constexpr int BUTTON_PIN = 3;
constexpr int RED_PIN = 2;  // ขา LED สีแดง
constexpr int GREEN_PIN = 1; // ขา LED สีเขียว
constexpr int NUM_PIXELS = 1;

SPIClass hspi(HSPI);
SPIClass spiBus(FSPI);
RF24 radio(20, 21, 16000000);
RF24 radio2(7, 10, 16000000);


int bluetooth_channels[] = {32, 34, 46, 48, 50, 52, 0, 1, 2, 4, 6, 8, 22, 24, 26, 28, 30, 74, 76, 78, 80};
int ble_channels[] = {2, 26, 80};

int currentMode = 0;

ezButton modeButton(BUTTON_PIN);

void configureRadio(RF24 &radio, int channel, SPIClass *spi);
void handleModeChange();
void executeMode();
void updateNeoPixel();
void jamBLE();
void jamBluetooth();
void jamAll();


void setup() {
    Serial.begin(115200);
     
    esp_bt_controller_deinit();
    esp_wifi_stop();
    esp_wifi_deinit();
    esp_wifi_disconnect();
    
    modeButton.setDebounceTime(100);

    // กำหนดขา LED เป็น OUTPUT
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);

    // ปิด LED ทั้งสองสีเมื่อเริ่มต้น
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    
   spiBus.begin(4, 5, 6);

   if (radio.begin(&spiBus)) {
    Serial.println("Radio 1 Started");
    
    radio.setAutoAck(false);
    radio.stopListening();
    radio.setRetries(0, 0);
    radio.setPALevel(RF24_PA_MAX, true);
    radio.setDataRate(RF24_2MBPS);
    radio.setCRCLength(RF24_CRC_DISABLED);
    radio.printPrettyDetails();
    radio.startConstCarrier(RF24_PA_MAX, 45);
  } else {
    Serial.println("Radio 1 Failed to Start");
    
  }

   if (radio2.begin(&spiBus)) {
    Serial.println("Radio 2 Started");
    
    radio2.setAutoAck(false);
    radio2.stopListening();
    radio2.setRetries(0, 0);
    radio2.setPALevel(RF24_PA_MAX, true);
    radio2.setDataRate(RF24_2MBPS);
    radio2.setCRCLength(RF24_CRC_DISABLED);
    radio2.printPrettyDetails();
    radio2.startConstCarrier(RF24_PA_MAX, 45);
  } else {
    Serial.println("Radio 2 Failed to Start");
    // Display failure message
  }

 
}



void configureRadio(RF24 &radio, int channel, SPIClass *spi) {
    if (radio.begin(&spiBus)) {
        radio.setAutoAck(false);
        radio.stopListening();
        radio.setRetries(0, 0);
        radio.setPALevel(RF24_PA_MAX, true);
        radio.setDataRate(RF24_2MBPS);
        radio.setCRCLength(RF24_CRC_DISABLED);
        radio.startConstCarrier(RF24_PA_HIGH, channel);
    }
}
void loop() {
    modeButton.loop();
    if (modeButton.isPressed()) {
        handleModeChange();
    }
    executeMode();
}

void handleModeChange() {
    currentMode = (currentMode + 1) % 4;
    Serial.print("Mode changed to: ");
    Serial.println(currentMode);
    updateBiColorLED(); // เปลี่ยนจาก updateNeoPixel() เป็น updateBiColorLED()
}


//constexpr int RED_PIN = 4;  // ขา LED สีแดง
//constexpr int GREEN_PIN = 5; // ขา LED สีเขียว

void updateBiColorLED() {
    switch (currentMode) {
        case 0:
            digitalWrite(RED_PIN, LOW);
            digitalWrite(GREEN_PIN, LOW);
            break;
        case 1:
            digitalWrite(RED_PIN, HIGH); // เปิดสีแดง
            digitalWrite(GREEN_PIN, LOW);
            break;
        case 2:
            digitalWrite(RED_PIN, LOW);
            digitalWrite(GREEN_PIN, HIGH); // เปิดสีเขียว
            break;
        case 3:
            digitalWrite(RED_PIN, HIGH);
            digitalWrite(GREEN_PIN, HIGH); // เปิดทั้งสองสี
            break;
    }
}


void executeMode() {
    switch (currentMode) {
        case 0:
            delay(100);
            break;
        case 1:
            jamBLE();
            break;
        case 2:
            jamBluetooth();
            break;
        case 3:
            jamAll();
            break;
    }
}


void jamBLE() {
    int randomIndex = random(0, sizeof(ble_channels) / sizeof(ble_channels[0]));
    int channel = ble_channels[randomIndex];
  
}

void jamBluetooth() {
    int randomIndex = random(0, sizeof(bluetooth_channels) / sizeof(bluetooth_channels[0]));
    int channel = bluetooth_channels[randomIndex];
    
}

void jamAll() {
    if (random(0, 2)) {
        jamBluetooth();        
    } else {
        jamBLE();
    }
    //delayMicroseconds(20);
}
