/*
 * drill-08-cycle-total
 * Expected: Serial prints Cycle delays: 6000 ms once per cycle. Time from one red turn-on to the next with a stopwatch: about 6 seconds, plus small command overhead.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long UNIT_MS = 1000;
const unsigned long SERIAL_BAUD = 9600;
const unsigned long RED_MS = UNIT_MS;
const unsigned long YELLOW_MS = UNIT_MS * 2;
const unsigned long GREEN_MS = UNIT_MS * 3;

const unsigned long CYCLE_MS = RED_MS + YELLOW_MS + GREEN_MS;

void setup() {
  Serial.begin(SERIAL_BAUD);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  Serial.print("Cycle delays: ");
  Serial.print(CYCLE_MS);
  Serial.println(" ms");
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

