/*
 * drill-10-three-constants
 * Expected: A two-flash heartbeat on red, followed by a longer pause. Exactly three named constants in the whole sketch.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const unsigned long PULSE_MS = 150;
const unsigned long PAUSE_MS = 900;

void setup() {
  pinMode(PIN_RED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_RED, HIGH);
  delay(PULSE_MS);
  digitalWrite(PIN_RED, LOW);
  delay(PULSE_MS);
  digitalWrite(PIN_RED, HIGH);
  delay(PULSE_MS);
  digitalWrite(PIN_RED, LOW);
  delay(PAUSE_MS);
}
