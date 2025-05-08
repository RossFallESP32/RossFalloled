# RossFalloled
Jammer-ESP32

## REQUIRED DEVICE AND MODULE:

* 1 Esp32 wroom 30 pin
* 1 or 2 Nrf24l01 PA LNA
* 14 Jummper wire female to female


 
 ## STEP 1 WIRING VIDEO INSTRUCTION

![316725930-ba7c2991-1542-4296-8b8c-8011c2bc8e77](https://github.com/user-attachments/assets/2eda5c3c-843f-427f-8967-ff948f7b31f0)


![nrf](https://github.com/user-attachments/assets/0925bcad-5da9-4b5b-8263-1537b2578b7c)

---

Oled

SDA 21
SCK 22
Vcc 3.3
GND GND
1. FOR DUAL/TWO NRF24L01
 * HSPI PINS 
 * 3.3V=VCC
 *  GND=GROUND
 * HSPI SCK = 14
 * HSPI MISO = 12
 * HSPI MOSI = 13
 *  HSPI HCS = 15
 *  HSPI CE = 16
 *  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
 *    VSPI PINS
 * 3.3V=VCC
 * GND=GROUND
 * VSPI SCK = 18
 *  VSPI MISO =19
 *  VSPI MOSI = 23
 *  VSPI CS =21
 *  VSPI CE = 22
2. FOR SINGLE/ONE NRF24L01 YOU CAN CHOOSE BETWEEN HSPI OR VSPI

Link Projetc
https://app.cirkitdesigner.com/project/6b42841d-01df-4a47-88ff-2cdbf93b908e

