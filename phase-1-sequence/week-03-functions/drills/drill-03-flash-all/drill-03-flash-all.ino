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
  flashAll(3, 200, 200);
}
void flashAll(int times, unsigned long onMs, unsigned long offMs) {
  for (int flash = 0; flash < times; flash++) {
    setAll(HIGH);
    delay(onMs);
    setAll(LOW);
    delay(offMs);
  }
}
void setAll(int state) {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    digitalWrite(pin, state);
  }
}
