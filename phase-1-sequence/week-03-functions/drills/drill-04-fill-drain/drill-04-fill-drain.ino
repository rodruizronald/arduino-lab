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
  fill(250);
  drain(250);
}
void fill(unsigned long stepMs) {
  changeRow(HIGH, stepMs);
}
void drain(unsigned long stepMs) {
  changeRow(LOW, stepMs);
}
void changeRow(int state, unsigned long stepMs) {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    digitalWrite(pin, state);
    delay(stepMs);
  }
}
