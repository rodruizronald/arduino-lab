/*
 * drill-01-blink-together
 * Expected: All three LEDs blink together: 500 ms on, 500 ms off. Change BLINK_MS to 250 and upload again to check the shared rate.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const int BLINK_MS = 500;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_YELLOW, HIGH);
  digitalWrite(PIN_GREEN, HIGH);
  delay(BLINK_MS);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, LOW);
  delay(BLINK_MS);
}

