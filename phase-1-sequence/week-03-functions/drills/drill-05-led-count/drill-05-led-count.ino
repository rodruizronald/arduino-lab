const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const int PIN_BLUE = 7;
const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.println(ledCount());
}
void loop() {
}
int ledCount() {
  return LAST_PIN - FIRST_PIN + 1;
}
// Expected 4. Change FIRST_PIN to 8, upload again: expected 3.
