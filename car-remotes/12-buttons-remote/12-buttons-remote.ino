#include <Keypad.h>
#include <SoftwareSerial.h>

#define HC12_TX_PIN 2
#define HC12_RX_PIN 3
SoftwareSerial hc12Serial(HC12_TX_PIN, HC12_RX_PIN);

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {10, 11, 12, 13}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {A0, A1, A2};     // connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  hc12Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    hc12Serial.println(key);
  }
  delay(50);
}
