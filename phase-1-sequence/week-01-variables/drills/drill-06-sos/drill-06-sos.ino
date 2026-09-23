/*
 * drill-06-sos
 * Expected: Red: three short flashes, three long, three short, then a longer pause.
 * Status: expected result confirmed by the student on the UNO.
 */

const int PIN_RED = 8;
const unsigned long DOT_MS = 200;
const unsigned long DASH_MS = DOT_MS * 3;
const unsigned long SYMBOL_GAP_MS = DOT_MS;
const unsigned long LETTER_GAP_MS = DOT_MS * 3;
const unsigned long WORD_GAP_MS = DOT_MS * 7;

void setup() {
  pinMode(PIN_RED, OUTPUT);
}

void loop() {
  // S
  digitalWrite(PIN_RED, HIGH);
  delay(DOT_MS);
  digitalWrite(PIN_RED, LOW);
  delay(SYMBOL_GAP_MS);
  digitalWrite(PIN_RED, HIGH);
  delay(DOT_MS);
  digitalWrite(PIN_RED, LOW);
  delay(SYMBOL_GAP_MS);
  digitalWrite(PIN_RED, HIGH);
  delay(DOT_MS);
  digitalWrite(PIN_RED, LOW);
  delay(LETTER_GAP_MS);

  // O
  digitalWrite(PIN_RED, HIGH);
  delay(DASH_MS);
  digitalWrite(PIN_RED, LOW);
  delay(SYMBOL_GAP_MS);
  digitalWrite(PIN_RED, HIGH);
  delay(DASH_MS);
  digitalWrite(PIN_RED, LOW);
  delay(SYMBOL_GAP_MS);
  digitalWrite(PIN_RED, HIGH);
  delay(DASH_MS);
  digitalWrite(PIN_RED, LOW);
  delay(LETTER_GAP_MS);

  // S
  digitalWrite(PIN_RED, HIGH);
  delay(DOT_MS);
  digitalWrite(PIN_RED, LOW);
  delay(SYMBOL_GAP_MS);
  digitalWrite(PIN_RED, HIGH);
  delay(DOT_MS);
  digitalWrite(PIN_RED, LOW);
  delay(SYMBOL_GAP_MS);
  digitalWrite(PIN_RED, HIGH);
  delay(DOT_MS);
  digitalWrite(PIN_RED, LOW);
  delay(WORD_GAP_MS);

}

