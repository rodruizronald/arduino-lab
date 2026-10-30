/*
 * WEEK 3 · EXERCISE 1 — Your first function
 * ------------------------------------------------------------------
 * GOAL
 *   One blink, written once, with a name. Called on every LED.
 *
 * WIRING
 *   Blue 7, red 8, yellow 9, green 10 -- unchanged from Week 2.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Write a function that blinks the red LED once -- on, wait,
 *      off, wait -- and nothing else:
 *
 *          void blinkRed() {
 *            // one blink of PIN_RED
 *          }
 *
 *      It goes BELOW loop(), at the top level of the file -- not
 *      inside setup() or loop(). (README section 1.11.)
 *
 *   2. Call it from loop():   blinkRed();
 *      Upload. One red blink, forever.
 *
 *   3. Call it three times in a row. Then call it from setup() too,
 *      once, before loop() ever starts. PREDICT the pattern you'll see
 *      right after a reset before you upload.
 *
 *   4. Now write blinkBlue(), blinkYellow(), blinkGreen() the same
 *      way, and call all four in order.
 *
 *      Look at those four functions side by side. They are identical
 *      except for ONE value. Remember that feeling -- it's what
 *      Exercise 2 is for.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Defining a function does nothing. The board reads past it. Only a
 *   CALL makes it run -- and every call comes back to the line after
 *   it (README section 1.4).
 *
 *   And notice what you already knew: setup() and loop() are
 *   functions too. You've been writing their bodies since Week 0.
 *   The only difference is that something else calls them.
 *
 * ------------------------------------------------------------------
 * BREAK IT -- one at a time. Record compiler messages, EXACTLY, in
 * reference/mistakes.md.
 *
 *   1. Call  blinkred();  (lowercase r). Verify. The error is an old
 *      friend -- functions follow the same naming rules as variables.
 *
 *   2. Move the whole definition of blinkRed() INSIDE loop()'s
 *      braces. Verify. What does the compiler say? Where are function
 *      definitions allowed to live?
 *
 *   3. Put it back. Now write the call without parentheses:
 *
 *          blinkRed;
 *
 *      Verify. It compiles. Upload. Nothing blinks. With compiler
 *      warnings on All (you set that in Week 2), what does the
 *      compiler say about that line? The parentheses ARE the call.
 *
 *   4. Delete every call, but keep the definition. Upload. Does an
 *      unused function cost anything? Does it do anything?
 */

const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const int PIN_BLUE = 7;
const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;
const unsigned long BLINK_MS = 200;

void setup() {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
  blinkRed();
}

void loop() {
  blinkBlue();
  blinkRed();
  blinkYellow();
  blinkGreen();
}

// The first red blink runs once after reset; the four-color sequence repeats.
// Earlier stage: three blinkRed() calls in loop() repeat three red blinks.
// Together with setup(), that starts with four blinks, with no special gap.
void blinkBlue() {
  digitalWrite(PIN_BLUE, HIGH);
  delay(BLINK_MS);
  digitalWrite(PIN_BLUE, LOW);
  delay(BLINK_MS);
}

void blinkRed() {
  digitalWrite(PIN_RED, HIGH);
  delay(BLINK_MS);
  digitalWrite(PIN_RED, LOW);
  delay(BLINK_MS);
}

void blinkYellow() {
  digitalWrite(PIN_YELLOW, HIGH);
  delay(BLINK_MS);
  digitalWrite(PIN_YELLOW, LOW);
  delay(BLINK_MS);
}

void blinkGreen() {
  digitalWrite(PIN_GREEN, HIGH);
  delay(BLINK_MS);
  digitalWrite(PIN_GREEN, LOW);
  delay(BLINK_MS);
}
