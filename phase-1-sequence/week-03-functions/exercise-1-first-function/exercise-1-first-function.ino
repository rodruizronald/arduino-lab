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


// TODO: pin constants and a blink duration


void setup() {
  // TODO: pins
}

void loop() {
  // TODO: calls only
}

// TODO: your blink function(s), here, below loop()
