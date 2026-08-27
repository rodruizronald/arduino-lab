/*
 * WEEK 0 · EXERCISE 4 — Two LEDs, alternating
 * ------------------------------------------------------------------
 * GOAL
 *   Red and green alternate, one second each.
 *
 *   HARD REQUIREMENT: they must NEVER both be on at the same time,
 *   and NEVER both off. At every instant, exactly one is lit.
 *
 * WIRING
 *   Red on pin 8, green on pin 9. Both already wired.
 *
 * WHAT TO DO
 *   WRITE THE SEQUENCE ON PAPER FIRST. Every line, in order, before
 *   you type anything. (Rule 2.) It should take four lines of code
 *   inside loop(). If you need more than six, stop and re-plan.
 *
 * THE POINT
 *   The individual statements here are trivial -- you already know
 *   all of them. The entire exercise is WHAT ORDER TO PUT THEM IN.
 *
 *   That is a real and permanent part of programming: the vocabulary
 *   is small, the arrangement is everything.
 *
 * ------------------------------------------------------------------
 * THE TEMPTING WRONG ANSWER
 *   Many people write this:
 *
 *       red ON
 *       delay
 *       red OFF
 *       green ON
 *       delay
 *       green OFF
 *
 *   It looks symmetrical and reasonable. Trace it by hand, one line
 *   at a time, and find the instant where the requirement is broken.
 *   (Hint: what is true immediately after "red OFF"?)
 *
 *   Then find an arrangement with no such instant.
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *   Swap two ADJACENT lines. Try several different pairs.
 *   Some swaps change the behaviour completely. Some change nothing
 *   at all. Before each upload, predict which kind it is -- and be
 *   able to say WHY.
 */


void setup() {
  // TODO: two pins to announce this time
}

void loop() {
  // TODO: four lines. Plan them on paper first.
}
