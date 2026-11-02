/*
 * WEEK 4 · EXERCISE 3 — Tables
 * ------------------------------------------------------------------
 * GOAL
 *   A rhythm stored as a TABLE -- which LED, and for how long, at
 *   each step -- and a small ENGINE that plays any table it's given.
 *
 * WIRING
 *   Blue 7, red 8, yellow 9, green 10, white 12.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Two parallel arrays -- one column each (README section 1.8):
 *
 *          const byte          STEP_PIN[] = { ... };
 *          const unsigned long STEP_MS[]  = { ... };
 *
 *      Same length. Row i is "light STEP_PIN[i] for STEP_MS[i]".
 *      Design a rhythm you'd recognise -- at least 8 steps, using at
 *      least four different LEDs, with at least three different
 *      durations.
 *
 *   2. A count for EACH column, from sizeof. In setup(), print both
 *      counts on one line. They must match. This printout is your
 *      only protection against the columns drifting apart -- keep it.
 *
 *   3. The engine: one function that plays one row --
 *
 *          void playStep(int step)
 *
 *      -- and a loop in loop() that plays every row in order.
 *      The engine never mentions a specific pin or duration. Only
 *      "row step".
 *
 *   4. Now change the rhythm WITHOUT touching any function:
 *        - make it twice as long by adding rows
 *        - make one step much longer
 *        - move a step to a different LED
 *      Every change is in the data. Count your edits to functions:
 *      it should be zero.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   This is your first ENGINE-AND-DATA split (README section 1.9).
 *   The engine is three or four lines and should never change. The
 *   rhythm -- everything that makes it THIS rhythm -- lives in the
 *   table.
 *
 * ------------------------------------------------------------------
 * BREAK IT -- on the board; record what you actually see
 *
 *   1. Add one pin to STEP_PIN but forget to add its duration.
 *      Leave the loop using STEP_PIN's count. Upload.
 *        - What does your count printout in setup() say now?
 *        - What happens on the last step? Print STEP_MS for that row
 *          before the delay, so you can see the value it got.
 *        - Did the compiler say anything?
 *      Record under LOGIC ERRORS. This is the parallel-array hazard,
 *      and it's the reason Week 17 exists.
 *
 *   2. Put it back. Now make the loop use STEP_MS's count while
 *      STEP_PIN is the longer one. Which step goes missing?
 */


// TODO: the two columns of the table, and a count for each


void setup() {
  // TODO: every pin used is an output; Serial; print both counts
}

void loop() {
  // TODO: play every row of the table
}

// TODO: playStep(step)
