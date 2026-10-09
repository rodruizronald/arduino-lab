/*
 * WEEK 3 · EXERCISE 3 — Return values
 * ------------------------------------------------------------------
 * GOAL
 *   Calculators: functions that work out a value and hand it back.
 *   No LEDs, no delays. You check every one of them by printing what
 *   it returns, in setup(), for a few different inputs.
 *
 * WIRING
 *   Not used. This one lives on the Serial Monitor.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. With the Week 2 row described by FIRST_PIN and LAST_PIN:
 *
 *          int ledCount()       // how many LEDs in the row
 *          int stepsPerSweep()  // how many lit steps in one scanner
 *                               // sweep, out and back, no doubled
 *                               // ends -- Week 2's challenge
 *
 *      PREDICT both on paper for 7..10. Then print them. Then change
 *      FIRST_PIN to 8 and PREDICT again.
 *
 *   2. A calculator with parameters:
 *
 *          unsigned long sweepMs(unsigned long stepMs)
 *
 *      How long one full sweep takes at that step time. Build it FROM
 *      stepsPerSweep() -- a calculator calling a calculator. Print it
 *      for 200, 100 and 40.
 *
 *   3. Two ways of answering the same question:
 *
 *          long sumByLoop(long n)      // 1 + 2 + ... + n, with a loop
 *          long sumByFormula(long n)   // n * (n + 1) / 2
 *
 *      Print both, side by side, for n = 10, 100, 1000.
 *      They must agree.
 *
 *      When two INDEPENDENT methods give the same answer, you can
 *      trust it far more than either one alone. That's not a trick;
 *      it's the foundation of testing, and it comes back in Week 32.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   A calculator that touches nothing -- no LEDs, no Serial, no
 *   delays, no globals that change -- gives the same answer for the
 *   same inputs, every time. That makes it the easiest code there is
 *   to check: call it, print it, compare with what you expected.
 *
 *   Keep calculating out of doing wherever you can. (README 1.7.)
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *
 *   1. Delete the 'return' line from stepsPerSweep(), leaving the
 *      calculation. Verify with warnings on All -- what does the
 *      compiler say? It still uploads. What gets printed? (Don't
 *      expect it to be consistent.) Record under LOGIC ERRORS.
 *
 *   2. Put it back. Call  stepsPerSweep();  on a line by itself, and
 *      print nothing. What happened to the answer?
 *
 *   3. Change sumByFormula's PARAMETER to int, keep the long return
 *      type, and print it for 1000 again. PREDICT first. The return
 *      type is long -- so why is the answer wrong?
 *      (Week 1: arithmetic happens in the operands' type, BEFORE the
 *      result goes anywhere.) Now look how quickly sumByLoop caught
 *      it. That's what a second method is for.
 */


// TODO: FIRST_PIN, LAST_PIN


void setup() {
  // TODO: Serial, then print every calculator for several inputs
}

void loop() {
  // Nothing. Calculators are checked once, in setup().
}

// TODO: the calculators
