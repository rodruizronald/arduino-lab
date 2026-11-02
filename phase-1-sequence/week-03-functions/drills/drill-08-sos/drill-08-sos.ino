const int PIN_RED = 8;
const int SYMBOL_COUNT = 3;
const unsigned long DOT_MS = 200;
const unsigned long DASH_MS = DOT_MS * 3;
const unsigned long SYMBOL_GAP_MS = DOT_MS;
const unsigned long LETTER_GAP_MS = DOT_MS * 3;
const unsigned long WORD_GAP_MS = DOT_MS * 7;

void setup() {
  pinMode(PIN_RED, OUTPUT);
}
void loop() {
  letterS();
  letterO();
  letterS();
  delay(WORD_GAP_MS - LETTER_GAP_MS);
}
void symbol(unsigned long onMs) {
  digitalWrite(PIN_RED, HIGH);
  delay(onMs);
  digitalWrite(PIN_RED, LOW);
  delay(SYMBOL_GAP_MS);
}
void dot() {
  symbol(DOT_MS);
}
void dash() {
  symbol(DASH_MS);
}
void letterS() {
  for (int count = 0; count < SYMBOL_COUNT; count++) {
    dot();
  }
  delay(LETTER_GAP_MS - SYMBOL_GAP_MS);
}
void letterO() {
  for (int count = 0; count < SYMBOL_COUNT; count++) {
    dash();
  }
  delay(LETTER_GAP_MS - SYMBOL_GAP_MS);
}
// Each symbol already supplies 200 ms of the gap; each letter supplies 600 ms.
// Add only the missing gap, so words have 1400 ms of darkness in total.
// Week 0 approach: literal times with each flash written out.
// Week 1: named times, 18 written digitalWrite calls.
// Week 2: a loop per letter, 6 digitalWrite calls.
// Week 3: named symbols and letters, 2 digitalWrite calls.
// This compares approaches, not four saved files: no Week 0 SOS file was found.
