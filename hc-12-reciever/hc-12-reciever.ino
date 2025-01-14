#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

#define RX_PIN 2 // => TXD
#define TX_PIN 3 // => RXD

SoftwareSerial HC12(RX_PIN, TX_PIN);

// SDA A4
// SCL A5
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  Serial.println("Start...");

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
  }

  display.display();
  delay(500);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("HC-12 Receiver Ready"));
  display.display();
  delay(500);
}

// String message = "";
void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Received Data:"));
  display.setTextSize(2);
  display.setCursor(0, 16);
  if (HC12.available()) {
    int a = HC12.read();
    display.println(a);
  } else {
    display.println("Not Work");
  }
  
  display.display();
  delay(100);
}
