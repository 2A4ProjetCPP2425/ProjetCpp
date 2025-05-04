#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN1 5  // First LED on pin 5
#define LED_PIN2 6  // Second LED on pin 6

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(LED_PIN1, OUTPUT);  // Set both LED pins
  pinMode(LED_PIN2, OUTPUT);  // as outputs
  Serial.println("Scan a card to see its UID...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Print UID to Serial Monitor
  Serial.print("UID : ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(i < rfid.uid.size - 1 ? ":" : "");
  }
  Serial.println();

  rfid.PICC_HaltA();

  // Turn both LEDs on for 3 seconds
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  delay(3000);
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
}