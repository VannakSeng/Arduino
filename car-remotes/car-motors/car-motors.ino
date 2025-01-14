#include <SoftwareSerial.h>

// HC-12 Serial communication (pins on Arduino Nano)
#define HC12_TX_PIN 2
#define HC12_RX_PIN 3
SoftwareSerial hc12Serial(HC12_TX_PIN, HC12_RX_PIN);

// Motor control pins
#define LEFT_FRONT_FORWARD 9
#define LEFT_FRONT_BACKWARD 10
#define LEFT_REAR_FORWARD 6 
#define LEFT_REAR_BACKWARD 5
#define RIGHT_FRONT_FORWARD 11
#define RIGHT_FRONT_BACKWARD 12
#define RIGHT_REAR_FORWARD 8
#define RIGHT_REAR_BACKWARD 7

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

    if (command == "S") {
      stopCar();
    } else if (command == "F") {
      moveForward();
    } else if (command == "TL") {
      moveTopLeft();
    } else if (command == "TR") {
      moveTopRight();
    } else if (command == "L") {
      strafeLeft();
    } else if (command == "R") {
      strafeRight();
    } else if (command == "BL") {
      moveBottomLeft();
    } else if (command == "B") {
      moveBackward();
    } else if (command == "BR") {
      moveBottomRight();
    } else {
      Serial.println("Unknown command: " + command);
    }
  } else {
    Serial.println("HC-12 not working");
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
  digitalWrite(LEFT_FRONT_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void strafeRight() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH);
}

void moveTopLeft() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void moveTopRight() {
  digitalWrite(LEFT_FRONT_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void moveBottomLeft() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH);
}

void moveBottomRight() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH);
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
