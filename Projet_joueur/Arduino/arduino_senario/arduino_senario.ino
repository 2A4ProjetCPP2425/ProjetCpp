#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10    // RFID SS pin
#define RST_PIN 9    // RFID RST pin
#define LED_GREEN 6  // Green LED pin
#define LED_RED 5    // Red LED pin
#define BUZZER_PIN 7 // Buzzer pin

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Scan a card to see its UID...");
}

void playOkMelody() {
    // Simpler and better "hello" melody: G4, C5, E5
    tone(BUZZER_PIN, 392, 200); // G4
    delay(200 + 10); // Slight pause between notes
    tone(BUZZER_PIN, 523, 200); // C5
    delay(200 + 10);
    tone(BUZZER_PIN, 659, 300); // E5, longer for a gentle finish
    delay(300 + 10);
    noTone(BUZZER_PIN);
}

void playNokMelody() {
    // "denied" melody (unchanged): E3, D3, E3, C3
    tone(BUZZER_PIN, 165, 300); // E3
    delay(300 + 10);
    tone(BUZZER_PIN, 147, 300); // D3
    delay(300 + 10);
    tone(BUZZER_PIN, 165, 300); // E3
    delay(300 + 10);
    tone(BUZZER_PIN, 131, 500); // C3, longer for emphasis
    delay(500 + 10);
    
    noTone(BUZZER_PIN);
}


void loop() {
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
        return;
    }

    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
        if (rfid.uid.uidByte[i] < 0x10) {
            uid += "0";
        }
        uid += String(rfid.uid.uidByte[i], HEX);
        if (i < rfid.uid.size - 1) {
            uid += ":";
        }
    }
    uid.toUpperCase();
    Serial.println(uid);

    unsigned long startTime = millis();
    String response = "";
    while (millis() - startTime < 5000) {
        if (Serial.available() > 0) {
            response = Serial.readStringUntil('\n');
            response.trim();
            break;
        }
        delay(10);
    }

    if (response == "OK") {
        digitalWrite(LED_GREEN, HIGH);
        playOkMelody(); // Play new "hello" melody
        delay(3000);
        digitalWrite(LED_GREEN, LOW);
    } else if (response == "NOK") {
        digitalWrite(LED_RED, HIGH);
        playNokMelody(); // Play "denied" melody
        delay(3000);
        digitalWrite(LED_RED, LOW);
    }

    rfid.PICC_HaltA();
}