#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3);
const int threshold = 100;

void setup() {
  HC12.begin(9600);
}

void loop() {
  int x = analogRead(A6) - 512;
  int y = analogRead(A7) - 512;
  if (y > threshold && x > threshold) {
    HC12.write(1);
  } else if (y > threshold && x < -threshold) {
    HC12.write(2);
  } else if (y < -threshold && x > threshold) {
    HC12.write(3);
  } else if (y < -threshold && x < -threshold) {
    HC12.write(4);
  } else if (y > threshold) {
    HC12.write(5);
  } else if (y < -threshold) {
    HC12.write(6);
  } else if (x > threshold) {
    HC12.write(7);
  } else if (x < -threshold) {
    HC12.write(8);
  } else {
    HC12.write(9);
  }
  delay(10);
}
