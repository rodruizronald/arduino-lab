/*
 * WEEK 4 · EXERCISE 5 — Re-solve: the Week 1 traffic light, as a table
 * ------------------------------------------------------------------
 * GOAL
 *   Week 1's challenge ended with a promise:
 *
 *     "In Week 4 you will rebuild this exact traffic light, one more
 *      time, as a table of phases -- and adding a pedestrian light
 *      will mean adding a row to that table instead of rewriting
 *      loop()."
 *
 *   This is that. Same spec as Week 1:
 *
 *     GO        green only    GREEN_MS
 *     CAUTION   yellow only   YELLOW_MS  (derived from GREEN_MS)
 *     STOP      red only      RED_MS     (derived from GREEN_MS)
 *
 *   ...forever, with Serial announcing each phase and its duration.
 *
 * WIRING
 *   Red 8, yellow 9, green 10.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. The phase table, as three parallel arrays:
 *
 *          const char*         PHASE_NAME[] = { "GO", ... };
 *          const byte          PHASE_PIN[]  = { ... };
 *          const unsigned long PHASE_MS[]   = { GREEN_MS, ... };
 *
 *      PHASE_MS is filled FROM the named constants -- and YELLOW_MS
 *      and RED_MS are still derived from GREEN_MS, exactly as in
 *      Week 1. (const char* is "a piece of fixed text" -- README
 *      section 1.8.)
 *
 *   2. A count for each column. Print all three in setup(); they
 *      must match.
 *
 *   3. The engine: playPhase(phase), and a loop in loop() over every
 *      phase. Count the lines of engine. A handful.
 *
 *   4. Week 1's acceptance test still applies: the whole light runs
 *      twice as fast with ONE edit. Check it.
 *
 *   5. Now ADD a phase: an all-red safety pause between STOP and GO
 *      (both directions stopped, briefly) -- "CLEARANCE", red, short.
 *      How many lines of the ENGINE did you change? How many rows of
 *      DATA?
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Rule 6, on the Week 1 challenge. In Week 1 a new phase meant new
 *   digitalWrite lines. Now it means a new row. The engine doesn't
 *   know there's a "CLEARANCE" phase at all -- it just plays rows.
 *
 * ------------------------------------------------------------------
 * AFTER IT WORKS -- the step toward the checkpoint
 *
 *   Some countries show RED + YELLOW together just before green.
 *   Try to add that phase to your table.
 *
 *   You can't: PHASE_PIN holds ONE pin per row. The table's shape
 *   can't say "two lights at once".
 *
 *   Rebuild it the Exercise 4 way: a list of the car pins, and a
 *   flat frame table with one on/off value per car LED for each
 *   phase -- plus PHASE_NAME and PHASE_MS beside it. Now "red +
 *   yellow" is just a row:  1, 1, 0.
 *
 *   That is exactly the shape the Phase 1 checkpoint needs, where
 *   the pedestrian lights join the table.
 */


// TODO: GREEN_MS and the derived durations; the phase table; counts


void setup() {
  // TODO: pins; Serial; print every column's count
}

void loop() {
  // TODO: play every phase
}

// TODO: playPhase(phase)
