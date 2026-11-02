/*
 * WEEK 4 · CHALLENGE — The Show, as Data
 * ==================================================================
 * NO HINTS. You will get stuck. That is the exercise.
 * ==================================================================
 *
 * Week 3's Light Show again -- but now EVERY PATTERN IS DATA, AND SO
 * IS THE SHOW.
 *
 *   ---------------------------------------------------------------
 *   THE LEDS        a list: all five, including pin 12.
 *
 *   THE PATTERNS    scan, chase, blink all, fill -- each one a run of
 *                   FRAMES inside one big frame table.
 *
 *   THE SHOW        a table: each row says WHICH PATTERN, HOW MANY
 *                   TIMES, and HOW FAST.
 *
 *   THE ENGINE      plays the show. It never mentions a specific pin,
 *                   pattern, or show row.
 *   ---------------------------------------------------------------
 *
 *
 * CONSTRAINTS
 *
 *   1. DESIGN THE DATA FIRST, ON PAPER. Draw the frame table -- every
 *      frame of every pattern, as rows of 1s and 0s -- and the show
 *      table, before you type anything. (Rule 2.)
 *
 *   2. THE SCAN HAS NO DOUBLED ENDS. Same rule as Week 2. It's just
 *      frames now.
 *
 *   3. loop() IS AT MOST 5 LINES.
 *
 *   4. NO GLOBAL VARIABLES. Constants and const arrays only.
 *
 *   5. EVERY COUNT COMES FROM sizeof -- LEDs, frames, show rows. Not
 *      one typed by hand.
 *
 *   6. THE ENGINE NEVER MENTIONS A PIN NUMBER, A PATTERN, OR A SHOW
 *      ROW BY VALUE. It only ever works with "the current row" and
 *      "the current frame".
 *
 *   7. SERIAL ANNOUNCES EACH SHOW ROW: the pattern's NAME and how
 *      long it will take, in milliseconds -- from a calculator, as in
 *      Week 3.
 *
 *   8. USE ONLY WHAT YOU KNOW: Weeks 0-3, plus arrays.
 *      No if. No switch.
 *
 *
 * ==================================================================
 * THE ACCEPTANCE TESTS
 * ==================================================================
 *
 *   A.  Add a brand-new pattern -- say, two lights moving in from
 *       both ends and meeting in the middle -- and put it in the
 *       show. ONLY DATA CHANGES. No function is edited, and no new
 *       function is written.
 *
 *   B.  Change the order of the show, and play one pattern three
 *       times in a row at different speeds. ONLY THE SHOW TABLE
 *       CHANGES.
 *
 *   C.  Move the white LED's jumper from pin 12 to pin 11.
 *       ONE EDIT.
 *
 *   D.  THINK, DON'T FIX. To add a SIXTH LED, what has to change?
 *       Count the edits. Every frame needs one more value -- write
 *       down why, and what that suggests about this way of storing
 *       frames. (Weeks 15 and 16.)
 *
 *   E.  THINK, DON'T FIX. A show row that names a pattern that
 *       doesn't exist -- pattern 9 when there are 5. What does your
 *       engine do? Why can't you stop it yet? (Week 5.)
 *
 *
 * ==================================================================
 * AND THEN -- THE ACTUAL LESSON
 * ==================================================================
 *
 * Count the lines of ENGINE -- every function. Then count the lines
 * of DATA. The engine should be small, and you should never need to
 * touch it again. Everything that makes the show THIS show is in the
 * tables.
 *
 * In Week 3, a new pattern meant a new function. Now it means new
 * rows. In Week 0, it meant forty more lines of digitalWrite.
 *
 *      Week 1  ->  variables       killed magic numbers      <-- done
 *      Week 2  ->  loops           killed repeated blocks    <-- done
 *      Week 3  ->  functions       killed repeated ideas     <-- done
 *      Week 4  ->  arrays          killed repeated data      <-- done
 *
 * That's Phase 1. Next: the checkpoint -- a traffic light with a
 * pedestrian phase, where adding a phase means adding a row.
 */


// TODO: the data -- LED list, frame table, pattern table, show table


void setup() {
  // TODO
}

void loop() {
  // TODO: play the show -- at most 5 lines
}

// TODO: the engine, and its calculator
