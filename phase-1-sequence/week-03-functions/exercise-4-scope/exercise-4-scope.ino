/*
 * WEEK 3 · EXERCISE 4 — Scope, and the bug that waits
 * ------------------------------------------------------------------
 * GOAL
 *   Below is a short program with a bug in it. It runs perfectly the
 *   first time round loop(), and is wrong every time after that.
 *   Find the bug with Serial. Then fix it properly -- which means
 *   removing the global variable entirely.
 *
 * WIRING
 *   Red 8, green 10.
 *
 * ------------------------------------------------------------------
 * THE PROGRAM -- type it in below (Rule 1: no copy-paste, not even
 * from here). The spec: red blinks QUICKLY three times, then green
 * blinks SLOWLY once. Forever.
 *
 *     const int PIN_RED   = 8;
 *     const int PIN_GREEN = 10;
 *
 *     int waitMs = 200;
 *
 *     void setup() {
 *       pinMode(PIN_RED, OUTPUT);
 *       pinMode(PIN_GREEN, OUTPUT);
 *     }
 *
 *     void loop() {
 *       blinkQuickly(PIN_RED);
 *       blinkQuickly(PIN_RED);
 *       blinkQuickly(PIN_RED);
 *       blinkSlowly(PIN_GREEN);
 *     }
 *
 *     void blinkQuickly(int pin) {
 *       digitalWrite(pin, HIGH);
 *       delay(waitMs);
 *       digitalWrite(pin, LOW);
 *       delay(waitMs);
 *     }
 *
 *     void blinkSlowly(int pin) {
 *       waitMs = 1000;
 *       digitalWrite(pin, HIGH);
 *       delay(waitMs);
 *       digitalWrite(pin, LOW);
 *       delay(waitMs);
 *     }
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Upload it and watch for at least two full rounds. Describe in
 *      writing what goes wrong, and WHEN it starts going wrong.
 *
 *   2. Prove it with Serial: print waitMs as the first line of
 *      blinkQuickly(). Find the exact moment it changes, and the line
 *      that changed it.
 *
 *   3. The QUICK fix: add  waitMs = 200;  as the first line of
 *      blinkQuickly(). Upload. It works.
 *
 *      Now explain, in writing, why it's the WRONG fix. Think about:
 *      what happens when someone writes a third function that uses
 *      waitMs? Does the ORDER the functions are called in matter now?
 *      Can you understand blinkQuickly() by reading only blinkQuickly()?
 *
 *   4. The REAL fix: delete  int waitMs  completely. No global
 *      variable at all. One function,
 *
 *          void blinkFor(int pin, unsigned long ms)
 *
 *      and two CONSTANTS for the two speeds. Every call says, right
 *      there, how long it wants. Nothing is shared, so nothing can be
 *      changed behind anyone's back.
 *
 *   5. Record the bug under LOGIC ERRORS in reference/mistakes.md:
 *      what you saw, what caused it, why the quick fix was wrong.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   "It worked the first time" is the signature of a global variable
 *   changed by one function and relied on by another. The bug isn't
 *   in any single line -- every line is fine on its own. It's in the
 *   SHARING.
 *
 *   Global CONSTANTS are fine: nobody can change them. Global
 *   VARIABLES are a door into every function at once. Pass values in
 *   as parameters; hand results back with return. (README 1.8.)
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *
 *   1. Go back to the ORIGINAL program. Instead of the quick fix,
 *      change the first line of
 *      blinkSlowly() to declare a NEW variable:
 *
 *          int waitMs = 1000;
 *
 *      Upload. It "works". There are now two different boxes both
 *      called waitMs -- the global, and one local to blinkSlowly(),
 *      which hides the global while that function runs. That's
 *      called SHADOWING. It's legal. Why is it still a bad idea?
 *
 *   2. In your FIXED version -- no global left -- try to print
 *      blinkFor()'s 'ms' parameter from inside loop(). Record the
 *      exact error. Where does a parameter exist, and when?
 *
 *      (Why the fixed version? In the original, a global waitMs
 *      exists, so loop() would quietly print THAT one instead. One
 *      more reason shadowing is confusing.)
 */


// TODO: type the program from the comment above into this file,
//       around these two functions. Then fix it.


void setup() {
  // TODO
}

void loop() {
  // TODO
}
