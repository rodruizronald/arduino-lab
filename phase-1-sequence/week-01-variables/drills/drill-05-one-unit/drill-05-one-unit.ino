/*
 * drill-05-one-unit
 * Expected: Red 1 second, yellow 2 seconds, green 3 seconds. All three durations come from UNIT_MS.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long UNIT_MS = 1000;
const unsigned long RED_MS = UNIT_MS;
const unsigned long YELLOW_MS = UNIT_MS * 2;
const unsigned long GREEN_MS = UNIT_MS * 3;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  digitalWrite(PIN_GREEN, LOW);
  digitalWrite(PIN_RED, HIGH);
  delay(RED_MS);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, HIGH);
  delay(YELLOW_MS);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, HIGH);
  delay(GREEN_MS);
}

