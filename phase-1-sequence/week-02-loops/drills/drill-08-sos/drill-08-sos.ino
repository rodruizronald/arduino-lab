/*
 * Week 1 comparison: 18 written digitalWrite calls become 6 here.
 * Each letter's three symbols use one loop; the rhythm is unchanged.
 * With Week 0 tools, I would write each flash with literal numbers.
 * Week 1 names the times; Week 2 also removes repeated flash blocks.
 * This is a comparison of approaches; see JOURNAL.md for the details.
 * The final letter/word gap adds only the part not already provided by
 * the last symbol gap, so a letter gap is 600 ms, not 800 ms.
 */
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
  for (int symbol = 0; symbol < SYMBOL_COUNT; symbol++) {
    digitalWrite(PIN_RED, HIGH);
    delay(DOT_MS);
    digitalWrite(PIN_RED, LOW);
    delay(SYMBOL_GAP_MS);
  }
  delay(LETTER_GAP_MS - SYMBOL_GAP_MS);
  for (int symbol = 0; symbol < SYMBOL_COUNT; symbol++) {
    digitalWrite(PIN_RED, HIGH);
    delay(DASH_MS);
    digitalWrite(PIN_RED, LOW);
    delay(SYMBOL_GAP_MS);
  }
  delay(LETTER_GAP_MS - SYMBOL_GAP_MS);
  for (int symbol = 0; symbol < SYMBOL_COUNT; symbol++) {
    digitalWrite(PIN_RED, HIGH);
    delay(DOT_MS);
    digitalWrite(PIN_RED, LOW);
    delay(SYMBOL_GAP_MS);
  }
  delay(WORD_GAP_MS - SYMBOL_GAP_MS);
}
