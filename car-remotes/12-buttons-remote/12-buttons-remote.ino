#include <Keypad.h>
#include <SoftwareSerial.h>

#define HC12_TX_PIN 2
#define HC12_RX_PIN 3
SoftwareSerial hc12Serial(HC12_TX_PIN, HC12_RX_PIN);

#define VRX_PIN A7
#define VRY_PIN A6
#define SW_PIN 13

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 10, 11, 12}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6, 5};     // connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int x = 0;
int y = 0;
bool on = false;

void setup() {
  pinMode(SW_PIN, INPUT);
  hc12Serial.begin(9600);
  Serial.begin(9600);
  hc12Serial.println("F");
}

void loop() {
  return;
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    hc12Serial.println(key);
  }
  // int sw = digitalRead(SW_PIN);
  // Serial.println(sw);
  // if (sw == 1) {
  //   on = !on;
  // }
  // if (!on) return;
  // int nx = analogRead(VRX_PIN);
  // int ny = analogRead(VRY_PIN);
  // if (x != nx || y != ny) {
  //   x = nx;
  //   y = ny;
  //   Serial.print("x: ");
  //   Serial.println(x);
  //   Serial.print("y: ");
  //   Serial.println(y);
  // }
  delay(200);
}
