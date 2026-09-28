/*
 * drill-03-print-pins
 * Expected: At 9600 baud, print Red pin: 8, Yellow pin: 9, Green pin: 10 once after reset. This drill does not drive the LEDs.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.print("Red pin: ");
  Serial.println(PIN_RED);
  Serial.print("Yellow pin: ");
  Serial.println(PIN_YELLOW);
  Serial.print("Green pin: ");
  Serial.println(PIN_GREEN);
}

void loop() {
}
