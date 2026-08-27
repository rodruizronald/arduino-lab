/*
 * WEEK 0 · EXERCISE 1 — Prove the chain works
 * ------------------------------------------------------------------
 * GOAL
 *   Make the LED that is soldered onto the Arduino board blink,
 *   one second on, one second off.
 *
 * WIRING
 *   None. Pin 13 already has an LED attached to the board itself,
 *   and it has a name you can use: LED_BUILTIN
 *
 * WHY THIS ONE FIRST
 *   No wiring means no wiring mistakes. If this doesn't work, the
 *   problem is your computer, the cable, or the IDE settings -- never
 *   the circuit. That certainty is worth a lot right now.
 *
 * WHAT TO DO
 *   The full program is in the week README, section "Exercise 1".
 *   TYPE IT OUT below. Do not copy-paste. (Rule 1.)
 *
 * ------------------------------------------------------------------
 * BREAK IT -- do these ONE AT A TIME, hit Verify, and write down the
 * EXACT error message in reference/mistakes.md before undoing it:
 *
 *   1. Delete the ';' after the first delay(1000)
 *   2. Delete the final '}'
 *   3. Change 'delay' to 'Delay'
 *   4. Change 'digitalWrite' to 'digitalwrite'
 *   5. Delete the whole pinMode line
 *
 *      <-- Number 5 is the interesting one. It COMPILES. Upload it
 *          and watch. Which of the two kinds of wrong is that?
 *          (See README section 1.6.)
 *
 * ------------------------------------------------------------------
 * AFTER THIS: go back and check your Dry Run answers for snippets
 * A, B and C. Run them if you're unsure -- it costs nothing.
 */


void setup() {
  // TODO: announce that LED_BUILTIN will send signals out
}

void loop() {
  // TODO: on, wait a second, off, wait a second
}
