/*
 * WEEK 1 · EXERCISE 1 — Your first variable
 * ------------------------------------------------------------------
 * GOAL
 *   Blink the red LED, one second on, one second off -- exactly what
 *   Week 0 did. The difference is entirely in how it is written:
 *   the two 1000s become a named variable.
 *
 * WIRING
 *   Red LED on pin 8. (Yellow on 9, green on 10, unused this time.)
 *
 * WHAT TO DO
 *   1. Above setup(), declare an int called onTimeMs, holding 1000.
 *   2. Use it in BOTH delay() calls instead of the literal number.
 *   3. Upload. Confirm it behaves identically to Week 0.
 *   4. Now change the ONE declaration to 200 and upload again.
 *      Both delays changed. You edited one line.
 *
 * THE POINT
 *   The board cannot tell the difference between this program and
 *   your Week 0 one. The compiled result is the same. Nothing about
 *   the behaviour improved.
 *
 *   What improved is that the program now SAYS what the number means,
 *   and there is exactly one place to change it. That distinction --
 *   the program is not the same thing as what the program does -- is
 *   most of software engineering, and this is the smallest possible
 *   example of it.
 *
 * ------------------------------------------------------------------
 * THEN: SPLIT IT
 *   Add a second variable, offTimeMs, and give the two different
 *   values so the blink is asymmetric. Now the two delays can move
 *   independently -- which they could not when they were both the
 *   literal 1000.
 *
 *   Ask yourself: was one variable used twice the right design, or
 *   two variables? The answer depends entirely on whether those two
 *   durations MEAN the same thing. That question comes up forever.
 *
 * ------------------------------------------------------------------
 * BREAK IT -- one at a time, hit Verify, record the EXACT message in
 * reference/mistakes.md:
 *
 *   1. Move the declaration of onTimeMs INSIDE setup(), leaving the
 *      uses in loop(). It compiled a second ago. Why not now?
 *
 *   2. Put the declaration back, then change ONE use to onTimems
 *      (lowercase m). Same error, different cause -- note both.
 *
 *   3. Delete "int" from the declaration, leaving "onTimeMs = 1000;"
 *      above setup(). What does the compiler say it needs?
 *
 *   4. Set onTimeMs to 0. Look at the LED closely. You saw this in
 *      Week 0 Exercise 2 -- does the explanation still hold?
 */


// TODO: declare your named duration(s) here, above setup()


void setup() {
  // TODO: announce the red pin
}

void loop() {
  // TODO: on, wait, off, wait -- but no bare numbers in the delays
}
