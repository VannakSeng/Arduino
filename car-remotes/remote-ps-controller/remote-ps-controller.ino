#include <PS2X_lib.h>

#define LEFT_FRONT_FORWARD 9
#define LEFT_FRONT_BACKWARD 10
#define LEFT_REAR_FORWARD 6 
#define LEFT_REAR_BACKWARD 5
#define RIGHT_FRONT_FORWARD 11
#define RIGHT_FRONT_BACKWARD 12
#define RIGHT_REAR_FORWARD 8
#define RIGHT_REAR_BACKWARD 7

PS2X ps2x;
#define PS2_DAT 13
#define PS2_CMD 12
#define PS2_SEL 11
#define PS2_CLK 10

int error = -1;

void setup() {
  // Set motor control pins as output
  pinMode(LEFT_FRONT_FORWARD, OUTPUT);
  pinMode(LEFT_FRONT_BACKWARD, OUTPUT);
  pinMode(LEFT_REAR_FORWARD, OUTPUT);
  pinMode(LEFT_REAR_BACKWARD, OUTPUT);
  pinMode(RIGHT_FRONT_FORWARD, OUTPUT);
  pinMode(RIGHT_FRONT_BACKWARD, OUTPUT);
  pinMode(RIGHT_REAR_FORWARD, OUTPUT);
  pinMode(RIGHT_REAR_BACKWARD, OUTPUT);

  Serial.begin(9600);

  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);
  if (error == 0) {
    Serial.println("PS2 Connected");
  } else {
    Serial.println("PS2 error");
  }
}

void loop() {
  // Read data from the controller
  ps2x.read_gamepad(false, 0);
  return;
  // Example: Check if the "X" button is pressed
  if (ps2x.Button(PSB_CROSS)) {
    Serial.println("X button pressed!");
  }

  // Example: Read joystick values
  int leftJoystickX = ps2x.Analog(PSS_LX); // Left joystick X-axis
  int leftJoystickY = ps2x.Analog(PSS_LY); // Left joystick Y-axis
  Serial.print("Left Joystick X: ");
  Serial.print(leftJoystickX);
  Serial.print(" Y: ");
  Serial.println(leftJoystickY);

  delay(100); // Add a short delay
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
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
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
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void moveBottomRight() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
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
