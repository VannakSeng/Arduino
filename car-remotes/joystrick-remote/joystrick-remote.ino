#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3);
Adafruit_SSD1306 display(128, 64, &Wire, -1);
const int threshold = 100;

void setup() {
  HC12.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
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

void loop() {
  int x = analogRead(A6) - 512;
  int y = analogRead(A7) - 512;
  if (y > threshold && x > threshold) {
    show("W");
    HC12.write(1);
  } else if (y > threshold && x < -threshold) {
    show("X");
    HC12.write(2);
  } else if (y < -threshold && x > threshold) {
    show("Y");
    HC12.write(3);
  } else if (y < -threshold && x < -threshold) {
    show("Z");
    HC12.write(4);
  } else if (y > threshold) {
    show("F");
    HC12.write(5);
  } else if (y < -threshold) {
    show("B");
    HC12.write(6);
  } else if (x > threshold) {
    show("R");
    HC12.write(7);
  } else if (x < -threshold) {
    show("L");
    HC12.write(8);
  } else {
    show("S");
    HC12.write(9);
  }
  delay(10);
}

void show(String message) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Received Data:"));
  display.setTextSize(2);
  display.setCursor(0, 16);
  display.println(message);
  display.display();
  // HC12.println(message);
}
