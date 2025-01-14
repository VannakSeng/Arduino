#include <SoftwareSerial.h>;
#define RX_PIN 2 // => TXD
#define TX_PIN 3 // => RXD

SoftwareSerial HC12(RX_PIN, TX_PIN);

void setup() {
  HC12.begin(9600);
}

void loop() {
  int i = 1;
  for (; i < 100; i++) {
    HC12.write(i);
    delay(100);
  }
  for (int j = i; j > 0; j--) {
    HC12.write(j);
    delay(100);
  }
  
}
