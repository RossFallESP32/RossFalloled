//  Changeable parameters  
RF24 radio(16, 15, 16000000);
RF24 radio1(4, 5, 16000000);
GButton butt1(32);
GButton buttNext(26);
GButton buttPrevious(33);
const char *default_ssid = "RossFall";
const char *default_password = "RossFall";

//  Unchangeable parameters
#define SDA_PIN 21
#define SCL_PIN 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define EEPROM_SIZE 512
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
SPIClass *sp = nullptr;
SPIClass *hp = nullptr;
int menu_number = 0;
int bluetooth_jam_method;
int drone_jam_method;
int ble_jam_method;
int wifi_jam_method;
int zigbee_jam_method;
int Separate_or_together;
int misc_jam_method;
int logo;
int access_point;
int buttons;
int channel1 = 0;
int channel2 = 0;
int flag = 0;

byte bluetooth_channels[] = {32, 34, 46, 48, 50, 52, 0, 1, 2, 4, 6, 8, 22, 24, 26, 28, 30, 74, 76, 78, 80};
byte bluetooth_channels_reversed[] = {80, 78, 76, 74, 30, 28, 26, 24, 22, 8, 6, 4, 2, 1, 0, 52, 50, 48, 46, 34, 32};
byte ble_channels[] = {2, 26, 80};
byte ble_channels_reversed[] = {80, 26, 2};
const char jam_text[] = "xxxxxxxxxxxxxxxx";
WebServer server(80); 