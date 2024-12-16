#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10
// pin 12 => MISO
// pin 11 => MOSI
// pin 13 => SCK
// pin 10 => SS
// pin 9 => RST 

#define SP_PIN 1

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Read personal data on a MIFARE PICC:");
  pinMode(SP_PIN, OUTPUT);
  digitalWrite(SP_PIN, HIGH);
  delay(1000);
  digitalWrite(SP_PIN, LOW);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  // Print card UID
  Serial.print("Card UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  digitalWrite(SP_PIN, HIGH);
  delay(1000);
  digitalWrite(SP_PIN, LOW);
  Serial.println();

  // Halt PICC
  mfrc522.PICC_HaltA();

  // Stop encryption on PCD
  mfrc522.PCD_StopCrypto1();
}
