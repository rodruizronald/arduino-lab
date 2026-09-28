/*
 * drill-04-bool-output
 * Expected: Red is on for 1 second using true, then off for 1 second using false. The bool is passed directly to digitalWrite.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long HOLD_MS = 1000;
bool isOn = true;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  isOn = true;
  digitalWrite(PIN_RED, isOn);
  delay(HOLD_MS);
  isOn = false;
  digitalWrite(PIN_RED, isOn);
  delay(HOLD_MS);
}

