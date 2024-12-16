#include <SoftwareSerial.h>

// HC-12 Serial communication (pins on Arduino Nano)
#define HC12_TX_PIN 2
#define HC12_RX_PIN 3
SoftwareSerial hc12Serial(HC12_TX_PIN, HC12_RX_PIN);

// Motor control pins
#define LEFT_FRONT_FORWARD 5
#define LEFT_FRONT_BACKWARD 6
#define LEFT_REAR_FORWARD 9
#define LEFT_REAR_BACKWARD 10
#define RIGHT_FRONT_FORWARD 3
#define RIGHT_FRONT_BACKWARD 4
#define RIGHT_REAR_FORWARD 7
#define RIGHT_REAR_BACKWARD 8

void setup() {
  hc12Serial.begin(9600);

  pinMode(LEFT_FRONT_FORWARD, OUTPUT);
  pinMode(LEFT_FRONT_BACKWARD, OUTPUT);
  pinMode(LEFT_REAR_FORWARD, OUTPUT);
  pinMode(LEFT_REAR_BACKWARD, OUTPUT);
  pinMode(RIGHT_FRONT_FORWARD, OUTPUT);
  pinMode(RIGHT_FRONT_BACKWARD, OUTPUT);
  pinMode(RIGHT_REAR_FORWARD, OUTPUT);
  pinMode(RIGHT_REAR_BACKWARD, OUTPUT);
}

void loop() {
  if (hc12Serial.available()) {
    String command = hc12Serial.readStringUntil('\n');
    Serial.println("Received: " + command);

    if (command == "5") {
      stopCar();
    } else if (command == "2") {
      moveForward();
    } else if (command == "1") {
      moveTopLeft();
    } else if (command == "3") {
      moveTopRight();
    } else if (command == "4") {
      strafeLeft();
    } else if (command == "6") {
      strafeRight();
    } else if (command == "7") {
      moveBottomLeft();
    } else if (command == "8") {
      moveBackward();
    } else if (command == "9") {
      moveBottomRight();
    } else {
      Serial.println("Unknown command: " + command);
    }
  }

  delay(50);
}

void moveForward() {
  digitalWrite(LEFT_FRONT_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void moveBackward() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH);
}

void strafeLeft() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH);
}

void strafeRight() {
  digitalWrite(LEFT_FRONT_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void moveTopLeft() {
  digitalWrite(LEFT_FRONT_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH);
}

void moveTopRight() {
  digitalWrite(LEFT_FRONT_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void moveBottomLeft() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH);
}

void moveBottomRight() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void stopCar() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}
