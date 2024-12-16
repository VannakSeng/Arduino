const int waterSensorPin = A0;

void setup() {
  pinMode(waterSensorPin, INPUT);
}

void loop() {
  Serial.begin(9600);
  Serial.print("Water Level: ");
  int waterLevel = analogRead(waterSensorPin);
  Serial.println(waterLevel);
  delay(1000);
}
