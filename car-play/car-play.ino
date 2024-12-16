// Define motor control pins
#define LEFT_FRONT_FORWARD 5
#define LEFT_FRONT_BACKWARD 6
#define LEFT_REAR_FORWARD 9
#define LEFT_REAR_BACKWARD 10
#define RIGHT_FRONT_FORWARD 3
#define RIGHT_FRONT_BACKWARD 4
#define RIGHT_REAR_FORWARD 7
#define RIGHT_REAR_BACKWARD 8

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
}

// Function to move forward
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

// Function to move backward
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

// Function to turn left
void turnLeft() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(LEFT_FRONT_FORWARD, HIGH);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH);
}

// Function to strafe left
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

// Function to strafe right
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

// Function to move to top-left
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

// Function to move to top-right
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

// Function to move to bottom-left
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

// Function to move to bottom-right
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

// Function to stop the robot
void stopRobot() {
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD, LOW);
  digitalWrite(RIGHT_FRONT_FORWARD, LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD, LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW);
}

void loop() {
  // Example: Move forward for 2 seconds
  moveForward();
  delay(2000);
  stopRobot();
  delay(1000);

  // Example: Strafe left for 2 seconds
  strafeLeft();
  delay(2000);
  stopRobot();
  delay(1000);

  // Example: Strafe right for 2 seconds
  strafeRight();
  delay(2000);
  stopRobot();
  delay(1000);

  // Example: Move to top-left for 2 seconds
  moveTopLeft();
  delay(2000);
  stopRobot();
  delay(1000);

  // Example: Move to top-right for 2 seconds
  moveTopRight();
  delay(2000);
  stopRobot();
  delay(1000);

  // Example: Move backward for 2 seconds
  moveBackward();
  delay(2000);
  stopRobot();
  delay(1000);

  // Example: Move to bottom-left for 2 seconds
  moveBottomLeft();
  delay(2000);
  stopRobot();
  delay(1000);

  // Example: Move to bottom-right for 2 seconds
  moveBottomRight();
  delay(2000);
  stopRobot();
  delay(1000);
}
