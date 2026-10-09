const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const unsigned long STEP_MS = 250;

void setup() {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    digitalWrite(pin, HIGH);
    delay(STEP_MS);
    digitalWrite(pin, LOW);
  }
}
