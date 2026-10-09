const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const unsigned long FLASH_MS = 150;
const unsigned long PAUSE_MS = 500;

void setup() {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    const int flashCount = pin - FIRST_PIN + 1;
    for (int flash = 0; flash < flashCount; flash++) {
      digitalWrite(pin, HIGH);
      delay(FLASH_MS);
      digitalWrite(pin, LOW);
      delay(FLASH_MS);
    }
    delay(PAUSE_MS);
  }
}
