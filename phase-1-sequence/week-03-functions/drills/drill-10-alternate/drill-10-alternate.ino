const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const int PIN_BLUE = 7;
const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
}
void loop() {
  alternate(PIN_RED, PIN_BLUE, 10, 100);
  alternate(PIN_YELLOW, PIN_GREEN, 3, 500);
}
void pulse(int pin, unsigned long flashMs) {
  digitalWrite(pin, HIGH);
  delay(flashMs);
  digitalWrite(pin, LOW);
}
void alternate(int pinA, int pinB, int times, unsigned long flashMs) {
  for (int pair = 0; pair < times; pair++) {
    pulse(pinA, flashMs);
    pulse(pinB, flashMs);
  }
}
