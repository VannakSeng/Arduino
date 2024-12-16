#define LED_BUILTIN 13

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println(sensorValue);
  delay(sensorValue);
  digitalWrite(LED_BUILTIN, LOW);
  delay(sensorValue);
}
