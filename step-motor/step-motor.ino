#include <Stepper.h>

// Define the number of steps per revolution
const int stepsPerRevolution = 2048; // 28BYJ-48 stepper motor

// Create a Stepper object with the defined steps per revolution
// Pins: IN1, IN2, IN3, IN4
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set the speed of the stepper motor
  myStepper.setSpeed(10); // Speed in RPM

  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Stepper Motor Test");
}

void loop() {
  // Rotate the stepper motor clockwise
  Serial.println("Clockwise rotation");
  myStepper.step(stepsPerRevolution); // Move one full revolution

  delay(1000); // Wait for a second

  // Rotate the stepper motor counterclockwise
  Serial.println("Counterclockwise rotation");
  myStepper.step(-stepsPerRevolution); // Move one full revolution in the opposite direction

  delay(1000); // Wait for a second
}