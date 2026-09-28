/*
 * drill-02-derived-times
 * Expected: Red lasts 2 seconds, green 1 second. Yellow stays off. GREEN_MS is derived from RED_MS.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long RED_MS = 2000;
const unsigned long GREEN_MS = RED_MS / 2;

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
  digitalWrite(PIN_GREEN, HIGH);
  delay(GREEN_MS);
}

