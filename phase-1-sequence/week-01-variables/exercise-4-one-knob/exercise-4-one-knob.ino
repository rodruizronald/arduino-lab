/*
 * WEEK 1 · EXERCISE 4 — One knob
 * ------------------------------------------------------------------
 * GOAL
 *   A three-LED sequence in which EVERY duration is derived from a
 *   single constant. Change that one number, and the whole pattern
 *   speeds up or slows down in proportion, keeping its shape.
 *
 * WIRING
 *   Red 8, yellow 9, green 10.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Declare ONE knob:
 *
 *          const int UNIT_MS = 200;
 *
 *   2. Derive everything else FROM it. Not typed independently --
 *      derived, with arithmetic:
 *
 *          const int SHORT_MS = UNIT_MS;
 *          const int LONG_MS  = UNIT_MS * 3;
 *          const int GAP_MS   = UNIT_MS / 2;
 *
 *   3. Write a sequence with a recognisable shape, using those.
 *      Something like:
 *
 *          red   short
 *          gap
 *          yellow short
 *          gap
 *          green long
 *          gap
 *
 *   4. Get it working at UNIT_MS = 200.
 *
 *   5. Change UNIT_MS to 400. Upload. The whole thing runs at half
 *      speed and the rhythm is unmistakably the same rhythm.
 *
 *   6. Change it to 60. Then to 1000. One edit each time.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   This is the exercise of the week.
 *
 *   You have just built a CONTROL SURFACE. Someone who has never read
 *   a line of your code can now change how the program behaves, in a
 *   way that cannot break it, by editing one number you chose to
 *   expose. Everything else stays locked down.
 *
 *   Deciding what to expose and what to keep derived is a design
 *   decision, and it is the same decision -- at a larger and larger
 *   scale -- as designing a function's parameters (Week 3), a class's
 *   interface (Week 19), and a settings menu (Week 22).
 *
 *   The question is always: what should someone be allowed to change
 *   without understanding the rest?
 *
 * ------------------------------------------------------------------
 * WATCH FOR
 *   With UNIT_MS = 60, is GAP_MS still doing anything you can see?
 *   Integer division throws away remainders -- 60 / 2 is 30, but
 *   61 / 2 is also 30, not 30.5. Nothing warns you. That trap gets
 *   its own treatment in Week 10; for now just notice it exists.
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *
 *   1. Set UNIT_MS to 20000 and look at LONG_MS. 20000 * 3 is 60000,
 *      which does not fit in an int. PREDICT what the LED does, then
 *      run it. (Exercise 3 armed you for this.) Fix it by choosing a
 *      better type -- and check whether you need to change just
 *      LONG_MS, or UNIT_MS too. Why?
 *
 *   2. Replace ONE derived constant with a typed-in literal of the
 *      same value. It still works -- identical behaviour. Now change
 *      UNIT_MS and watch that one duration refuse to move with the
 *      others. This is exactly the bug from README section 1.1,
 *      recreated on purpose in code you understand completely.
 */


// TODO: one knob, then everything else derived from it


void setup() {
  // TODO
}

void loop() {
  // TODO: your sequence. No bare durations -- all derived from UNIT_MS.
}
