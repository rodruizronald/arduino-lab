/*
 * WEEK 2 · EXERCISE 5 — Re-solve: Week 0's challenge
 * ------------------------------------------------------------------
 * GOAL
 *   The Machine Status Indicator from Week 0 -- same spec, same
 *   behaviour, rewritten with Week 1's names and this week's loops.
 *
 *   Here's the spec again, unchanged:
 *
 *   ---------------------------------------------------------------
 *   BOOTING
 *     Serial: "BOOTING..."  (once, as the state begins)
 *     Red and green flash TOGETHER, 5 times, 150 ms on / 150 ms off
 *
 *   RUNNING
 *     Serial: "RUNNING"
 *     Red stays off.
 *     Green pulses slowly 3 times: 1 s on, 1 s off
 *
 *   ERROR
 *     Serial: "ERROR"
 *     Green stays off.
 *     Red: 3 quick flashes (100 ms on, 100 ms off), then a 500 ms
 *          pause. That whole group happens TWICE.
 *
 *   ...then back to BOOTING.
 *   ---------------------------------------------------------------
 *
 * WIRING
 *   Red on 8, green on 10.
 *
 *   In Week 0, green was on pin 9. It moved in Week 1. Your Week 0
 *   code would need 18 separate edits to follow it. This version
 *   needs one -- which you get for free, because it's a named
 *   constant.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Write it FRESH, from the spec above. Don't open your Week 0
 *      file and edit it -- you'll just end up with Week 0's shape
 *      and better spelling.
 *
 *   2. Every count is a named constant: how many boot flashes, how
 *      many running pulses, how many error flashes per group, how
 *      many groups. Every duration too.
 *
 *   3. Each state is a loop. ERROR is a loop INSIDE a loop -- three
 *      flashes, then a pause, and that whole thing twice.
 *
 *   4. When it works, and only then, open your Week 0 challenge and
 *      count:
 *          - lines inside loop(), then and now
 *          - digitalWrite calls, then and now
 *      Write all four numbers in your journal.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Rule 6: re-solve old problems with new tools.
 *
 *   The spec didn't change. The board does exactly what it did in
 *   Week 0. But the program is a fraction of the size, each state
 *   reads as one idea, and every number means something.
 *
 *   Nothing about the behaviour improved. Everything about the code
 *   did. That's the same lesson as Week 1, Exercise 1, at a much
 *   bigger scale -- and this is your first real evidence that the
 *   last two weeks worked.
 *
 * ------------------------------------------------------------------
 * AFTER IT WORKS
 *
 *   1. Change the number of boot flashes from 5 to 8. One edit.
 *      What would the same change have cost in Week 0?
 *
 *   2. Make ERROR happen in three groups instead of two. One edit.
 *
 *   3. Look at your three states side by side. What do they have in
 *      common? Try to describe all three in a single sentence with
 *      blanks in it: "flash ___ LEDs, ___ times, ___ ms on,
 *      ___ ms off."
 *
 *      Three states, one idea, written three times. That sentence
 *      with blanks is what a FUNCTION is. Week 3.
 */


// TODO: pins, counts, durations -- all named


void setup() {
  // TODO
}

void loop() {
  // TODO: BOOTING, RUNNING, ERROR -- each one a loop
}
