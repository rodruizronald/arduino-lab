/*
 * WEEK 2 · CHALLENGE — Scanner
 * ==================================================================
 * NO HINTS. You will get stuck. That is the exercise.
 * ==================================================================
 *
 * A single light sweeps back and forth across the LEDs, getting
 * faster with every sweep.
 *
 *   ---------------------------------------------------------------
 *   SETTINGS -- named constants, starting values:
 *
 *     FIRST_PIN   7     first LED in the row
 *     LAST_PIN    10    last LED in the row
 *     START_MS    200   how long each LED stays lit, first sweep
 *     STEP_MS     20    how much faster each sweep gets
 *     MIN_MS      40    the fastest sweep allowed
 *
 *   ---------------------------------------------------------------
 *   ONE SWEEP is there and back: out to LAST_PIN, then back towards
 *   FIRST_PIN.
 *
 *   Each sweep is faster than the last by STEP_MS. When the next
 *   sweep would be faster than MIN_MS, the whole thing starts over,
 *   slow again.
 *   ---------------------------------------------------------------
 *
 *
 * CONSTRAINTS
 *
 *   1. SPEC AND TRACE FIRST, ON PAPER. Write the pin that is lit at
 *      every step of the first two sweeps, in order, before you type
 *      anything. (Rules 2 and 3.)
 *
 *   2. ONE LED LIT AT A TIME. The instant between one turning off and
 *      the next turning on doesn't count -- two digitalWrite calls
 *      can't happen at the same moment.
 *
 *   3. NO DOUBLE FLASH AT THE ENDS. Every LED stays lit for the same
 *      time, ends included. The lit sequence must be exactly:
 *
 *          7 8 9 10 9 8 7 8 9 10 9 8 7 ...
 *
 *      Never "10 10". Never "7 7".
 *
 *   4. EACH SWEEP IS FASTER THAN THE ONE BEFORE, by STEP_MS, from
 *      START_MS down to MIN_MS. Then it starts over.
 *
 *   5. SERIAL ANNOUNCES EACH SWEEP: its number -- starting from 1
 *      again every time the scanner restarts -- and its step time,
 *      read from the variable.
 *
 *   6. NAMED CONSTANTS for every pin and every duration. No bare
 *      numbers below the constants block, apart from the counting
 *      idiom (README section 1.4).
 *
 *   7. USE ONLY WHAT YOU KNOW: the Week 0 commands, Week 1's
 *      variables and types, and for / while.
 *      No if. No functions of your own. No arrays.
 *
 *
 * ==================================================================
 * THE ACCEPTANCE TESTS
 * ==================================================================
 *
 *   A.  Change FIRST_PIN to 8. The scanner now runs across three
 *       LEDs, still with no double flash at either end -- and you
 *       changed NOTHING else.
 *
 *   B.  Change FIRST_PIN to 9. Two LEDs: 9 10 9 10 ..., each lit for
 *       the same time.
 *
 *   C.  FIRST_PIN back to 7. Set STEP_MS to 150. The scanner does two
 *       sweeps -- 200 ms, then 50 ms -- and starts over.
 *       If it hangs instead, you've met Exercise 4's bug again. Find
 *       a way round it without if. There's more than one.
 *
 *   D.  THINK, DON'T FIX. Set FIRST_PIN and LAST_PIN both to 10.
 *       What does your scanner do? Write down why. Is it acceptable?
 *
 *   If A or B takes more than the one edit, you're not finished.
 *   Something about the number of LEDs is still hard-coded.
 *
 *
 * ==================================================================
 * AND THEN -- THE ACTUAL LESSON
 * ==================================================================
 *
 * Count the lines in your loop(). Then count the lines in your Week 0
 * challenge's loop(). Write both in your journal.
 *
 * Now look at your two sweep loops -- out, and back. Same body. Same
 * idea. Different direction. You wrote the same THOUGHT twice, and no
 * loop can fold them into one.
 *
 *      Week 1  ->  variables       killed magic numbers      <-- done
 *      Week 2  ->  loops           killed repeated blocks    <-- done
 *      Week 3  ->  functions       kill repeated ideas
 *      Week 4  ->  arrays          kill repeated data
 *
 * And notice the scanner can only ever reach LEDs whose pins are
 * consecutive numbers. A fifth LED on pin 12 can't be described by
 * FIRST_PIN and LAST_PIN without dragging pin 11 along too. The SET
 * of LEDs is baked into arithmetic on pin numbers. That's Week 4.
 *
 * Keep this file. In Week 3 you will fold the two sweeps into one.
 */


// TODO: the five settings


void setup() {
  // TODO
}

void loop() {
  // TODO
}
