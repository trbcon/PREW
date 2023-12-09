#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const byte size = 3;

const char* MenuEn[size] = {"Read", "Cards", "Settings"};

byte PosX = 40;
byte PosY = 16;
// byte PosX = 0;
// byte PosY = 0;
byte pos = 0;

// byte CF = 0;

void setup() {
  Serial.begin(9600);
  if(!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  oled.setTextColor(SSD1306_WHITE);
  PREWMenu();
}

void loop() {
  PREWMenu();
  MenuDown();
  delay(500);
 
}

// void CheckCF() {
//   switch (CF) {
//     case 0:
//       PREWMenu();
//       break;
//     case 1:
//       ReadAndSaveToFile();
//       break;
//     case 2:
//       PrintCardsArray();
//       break;
//     case 3:
//       Settings();
//       break;
//   }
// }

void PREWMenu() {
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setCursor(40,2);
  oled.println("PREW");
  oled.setTextSize(1);
  for (int i; i < size; i++) {
    if (pos == i) {
      oled.setCursor(0 + PosX, (i + 1) * 8 + PosY);
      // oled.setCursor(0 + PosX, i + PosY);
      oled.println(">");
    } 
    oled.setCursor(6 + PosX, (i + 1) * 8 + PosY);
    oled.println(MenuEn[i]);
  }
  oled.display();
}

void MenuDown(){
  pos++;
  if (pos == size) {
    pos = 0;
  }
  PREWMenu();
}

void MenuUp(){
  pos--;
  if (pos < 0) {
    pos = size - 1;
  }
  PREWMenu();
}

// void MenuOk(){

// }

// void PrintCardsArray() {

// }