#include <LiquidCrystal_I2C.h>
#include <Wire.h>
int seconds = 0;

LiquidCrystal_I2C lcd_1(0x27, 20, 4);

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  lcd_1.
  lcd_1.print("hello world");
}

void loop() {
  int button = digitalRead(2);
  Serial.println(button);
  delay(100);
  // lcd_1.setCursor(0, 1);
  // lcd_1.print(seconds);
  // lcd_1.setBacklight(1);
  // delay(500); // Wait for 500 millisecond(s)
  // lcd_1.setBacklight(0);
  // delay(500); // Wait for 500 millisecond(s)
  // seconds += 1;
}