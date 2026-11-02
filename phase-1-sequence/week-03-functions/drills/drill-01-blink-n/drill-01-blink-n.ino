const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const int PIN_BLUE = 7;
const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;
const unsigned long BLINK_MS = 200;

void setup() {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
}
void loop() {
  blinkN(PIN_BLUE, 1);
  blinkN(PIN_RED, 2);
  blinkN(PIN_YELLOW, 3);
  blinkN(PIN_GREEN, 4);
}
void blinkOnce(int pin) {
  digitalWrite(pin, HIGH);
  delay(BLINK_MS);
  digitalWrite(pin, LOW);
  delay(BLINK_MS);
}

void blinkN(int pin, int times) {
  for (int flash = 0; flash < times; flash++) {
    blinkOnce(pin);
  }
}
