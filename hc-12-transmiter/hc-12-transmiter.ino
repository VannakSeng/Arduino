#include <SoftwareSerial.h>;
#define RX_PIN 2
#define TX_PIN 3

SoftwareSerial HC12(RX_PIN, TX_PIN);
const String deviceID = "Nano_01";

const int led = 8;

void setup() {
  pinMode(led, OUTPUT);
  HC12.begin(9600);
}

void loop() {
  int i = 1;
  for (; i < 100; i++) {
    HC12.println(i);
    delay(100);
  }
  for (int j = i; j > 0; j--) {
    HC12.println(j);
    delay(100);
  }
  
}
