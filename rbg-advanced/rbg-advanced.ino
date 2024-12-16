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
  // Fading effect
  fadeColors();
  
  // Color chasing effect
  colorChase();

  // Rainbow cycle effect
  rainbowCycle();
}

// Function to set the color of the RGB strip
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);    // Set red channel
  analogWrite(greenPin, green);// Set green channel
  analogWrite(bluePin, blue);  // Set blue channel
}

// Function for fading effect
void fadeColors() {
  for (int i = 0; i <= 255; i++) {
    setColor(i, 0, 255 - i);   // Fade from blue to red
    delay(10);
  }
  for (int i = 0; i <= 255; i++) {
    setColor(255 - i, i, 0);   // Fade from red to green
    delay(10);
  }
  for (int i = 0; i <= 255; i++) {
    setColor(0, 255 - i, i);   // Fade from green to blue
    delay(10);
  }
}

// Function for color chasing effect
void colorChase() {
  for (int i = 0; i <= 255; i += 15) {
    setColor(255, 255, 255);   // White
    delay(100);
    setColor(0, 0, 0);         // Off
    delay(100);
    setColor(i, 0, 255 - i);   // Red to blue
    delay(100);
    setColor(0, i, 255 - i);   // Green to blue
    delay(100);
  }
}

// Function for rainbow cycle effect
void rainbowCycle() {
  int rainbowColors[7][3] = {
    {255, 0, 0},    // Red
    {255, 127, 0},  // Orange
    {255, 255, 0},  // Yellow
    {0, 255, 0},    // Green
    {0, 0, 255},    // Blue
    {75, 0, 130},   // Indigo
    {143, 0, 255}   // Violet
  };

  for (int i = 0; i < 7; i++) {
    setColor(rainbowColors[i][0], rainbowColors[i][1], rainbowColors[i][2]);
    delay(500);
  }
}