// Define pin connections for RGB channels
const int redPin = 9;    // Pin connected to the red channel of the RGB strip
const int greenPin = 10; // Pin connected to the green channel of the RGB strip
const int bluePin = 11;  // Pin connected to the blue channel of the RGB strip

// Define RGB color values
int redValue = 0;        // Initial red value
int greenValue = 0;      // Initial green value
int blueValue = 0;       // Initial blue value

void setup() {
  // Set RGB pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Cycle through various colors
  
  // Red
  setColor(255, 0, 0);
  delay(1000);

  // Green
  setColor(0, 255, 0);
  delay(1000);

  // Blue
  setColor(0, 0, 255);
  delay(1000);

  // Yellow
  setColor(255, 255, 0);
  delay(1000);

  // Cyan
  setColor(0, 255, 255);
  delay(1000);

  // Magenta
  setColor(255, 0, 255);
  delay(1000);

  // White
  setColor(255, 255, 255);
  delay(1000);

  // Off
  setColor(0, 0, 0);
  delay(1000);
}

// Function to set the color of the RGB strip
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);    // Set red channel
  analogWrite(greenPin, green);// Set green channel
  analogWrite(bluePin, blue);  // Set blue channel
}