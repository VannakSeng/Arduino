#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3);
// Define motor control pins

#define LEFT_FRONT_FORWARD 9
#define LEFT_FRONT_BACKWARD 10
#define LEFT_REAR_FORWARD 6 
#define LEFT_REAR_BACKWARD 5
#define RIGHT_FRONT_FORWARD 12
#define RIGHT_FRONT_BACKWARD 11
#define RIGHT_REAR_FORWARD 8
#define RIGHT_REAR_BACKWARD 7

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  // Set motor control pins as output
  pinMode(LEFT_FRONT_FORWARD, OUTPUT);
  pinMode(LEFT_FRONT_BACKWARD, OUTPUT);
  pinMode(LEFT_REAR_FORWARD, OUTPUT);
  pinMode(LEFT_REAR_BACKWARD, OUTPUT);
  pinMode(RIGHT_FRONT_FORWARD, OUTPUT);
  pinMode(RIGHT_FRONT_BACKWARD, OUTPUT);
  pinMode(RIGHT_REAR_FORWARD, OUTPUT);
  pinMode(RIGHT_REAR_BACKWARD, OUTPUT);
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
  digitalWrite(LEFT_FRONT_FORWARD, 0);
  digitalWrite(LEFT_FRONT_BACKWARD, 1);
  digitalWrite(LEFT_REAR_FORWARD, 1);
  digitalWrite(LEFT_REAR_BACKWARD, 0);
  digitalWrite(RIGHT_FRONT_FORWARD, 1);
  digitalWrite(RIGHT_FRONT_BACKWARD, 0);
  digitalWrite(RIGHT_REAR_FORWARD, 0);
  digitalWrite(RIGHT_REAR_BACKWARD, 1);
}

void strafeRight() {
  digitalWrite(LEFT_FRONT_FORWARD, 1);
  digitalWrite(LEFT_FRONT_BACKWARD, 0);
  digitalWrite(LEFT_REAR_FORWARD, 0);
  digitalWrite(LEFT_REAR_BACKWARD, 1);
  digitalWrite(RIGHT_FRONT_FORWARD, 0);
  digitalWrite(RIGHT_FRONT_BACKWARD, 1);
  digitalWrite(RIGHT_REAR_FORWARD, 1);
  digitalWrite(RIGHT_REAR_BACKWARD, 0);
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
  digitalWrite(LEFT_FRONT_BACKWARD, 1);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, 0);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, 0);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, 1);
}

void moveBottomRight() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, 0);
  digitalWrite(LEFT_REAR_BACKWARD, 1);
  digitalWrite(RIGHT_FRONT_FORWARD, 0);
  digitalWrite(RIGHT_FRONT_BACKWARD, 1);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
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

void carRound() {
  digitalWrite(LEFT_FRONT_FORWARD, 1);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, 1);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void carCircle() {
  digitalWrite(LEFT_FRONT_FORWARD, 1);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, 1);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, 1);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, 1);
}

void loop() {
  int cmd = HC12.read();
  if (cmd < 1) return;
  Serial.println(cmd);

  if (cmd == 5) {
    moveForward();
  } else if (cmd == 6) {
    moveBackward();
  } else if (cmd == 8) {
    strafeLeft();
  } else if (cmd == 7) {
    strafeRight();
  } else if (cmd == 1) {
    moveTopRight();
  } else if (cmd == 2) {
    moveTopLeft();
  } else if (cmd == 3) {
    moveBottomRight();
  } else if (cmd == 4) {
    moveBottomLeft();
  } else {
    stopCar();
  }
  delay(10);
}


