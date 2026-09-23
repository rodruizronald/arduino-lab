/*
 * drill-07-countdown
 * Expected: Serial counts 5, 4, 3, 2, 1 one second apart, then all LEDs flash for one second. Repeats.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;
const unsigned long SECOND_MS = 1000;
const int START_COUNT = 5;
const int STEP = 1;
int count = START_COUNT;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  Serial.begin(SERIAL_BAUD);
}

void loop() {
  count = START_COUNT;
  Serial.println(count);
  delay(SECOND_MS);
  count = count - STEP;
  Serial.println(count);
  delay(SECOND_MS);
  count = count - STEP;
  Serial.println(count);
  delay(SECOND_MS);
  count = count - STEP;
  Serial.println(count);
  delay(SECOND_MS);
  count = count - STEP;
  Serial.println(count);
  delay(SECOND_MS);
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_YELLOW, HIGH);
  digitalWrite(PIN_GREEN, HIGH);
  delay(SECOND_MS);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, LOW);
  delay(SECOND_MS);
}

