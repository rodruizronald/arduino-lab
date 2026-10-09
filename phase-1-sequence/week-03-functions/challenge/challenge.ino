/*
 * WEEK 3 · CHALLENGE — Light Show
 * ==================================================================
 * NO HINTS. You will get stuck. That is the exercise.
 * ==================================================================
 *
 * Build a small LIBRARY of pattern generators -- functions that each
 * produce one kind of pattern, with parameters -- and a SHOW in
 * loop() that plays them in sequence.
 *
 *   ---------------------------------------------------------------
 *   THE PATTERNS -- at minimum, these four:
 *
 *     SCAN       the Week 2 scanner at a fixed speed: a light sweeps
 *                out and back, a given number of times. No double
 *                flash at the ends.
 *
 *     CHASE      a light runs along the row, end to end, a given
 *                number of times -- in EITHER direction.
 *
 *     BLINK ALL  all the LEDs flash together, a given number of
 *                times.
 *
 *     FILL       the LEDs light one by one until all are on, then go
 *                dark one by one.
 *
 *   How many times, how fast: those are ARGUMENTS, not constants
 *   inside the functions.
 *   ---------------------------------------------------------------
 *
 *
 * CONSTRAINTS
 *
 *   1. SPEC FIRST, ON PAPER. List every function you'll write, its
 *      parameters, and one sentence saying what it does. No sentence
 *      may need the word "and". (Rule 2.)
 *
 *   2. THE SWEEP OUT AND THE SWEEP BACK ARE THE SAME FUNCTION, called
 *      twice with different arguments. Week 2's challenge promised
 *      this. Keep the promise.
 *
 *   3. loop() CONTAINS ONLY FUNCTION CALLS. No for, no while, no
 *      digitalWrite, no delay. Just the show, as a list of calls.
 *
 *   4. NO GLOBAL VARIABLES. Global constants only. Everything a
 *      function needs comes in through its parameters.
 *
 *   5. EVERY FUNCTION BODY IS 15 LINES OR FEWER -- loop() included.
 *      Blank lines and comments don't count.
 *
 *   6. BEFORE EACH PATTERN RUNS, SERIAL ANNOUNCES ITS NAME AND HOW
 *      LONG IT WILL TAKE, in milliseconds. That duration comes from a
 *      CALCULATOR -- a function that returns it, worked out from the
 *      same arguments the pattern receives. The pattern itself never
 *      measures anything.
 *
 *   7. THE SHOW USES EVERY PATTERN AT LEAST ONCE, and at least one
 *      pattern twice with different arguments.
 *
 *   8. USE ONLY WHAT YOU KNOW: Weeks 0-2, plus functions.
 *      No if. No arrays.
 *
 *
 * ==================================================================
 * THE ACCEPTANCE TESTS
 * ==================================================================
 *
 *   A.  Change FIRST_PIN to 8. Every pattern adapts to three LEDs,
 *       every announced duration is still correct, and you changed
 *       NOTHING else.
 *
 *   B.  Add a REVERSE CHASE and a SLOWER SECOND SCAN to the show
 *       WITHOUT WRITING A NEW LOOP ANYWHERE. New calls only. If you
 *       need a new for, your generators aren't general enough yet.
 *
 *   C.  Time one full run of the show with a stopwatch. It should
 *       match the sum of the announced durations to within a second.
 *       If it doesn't, a calculator or a pattern is wrong -- find
 *       out which.
 *
 *   D.  THINK, DON'T FIX. Whichever function walks the light along
 *       the row takes some kind of direction. What happens if it's
 *       given a value you didn't intend -- 0, or 2? Write down what
 *       the LEDs would do, and why you can't prevent it yet.
 *
 *
 * ==================================================================
 * AND THEN -- THE ACTUAL LESSON
 * ==================================================================
 *
 * Read your loop() out loud. It should sound like a description of
 * the show, not like instructions to a machine. That's decomposition.
 *
 * Now look at what's left:
 *
 *   - THE SHOW is a list of calls with numbers in them: pattern,
 *     count, speed. That's a list of DATA, written as code. To change
 *     the show, you edit and re-upload the program.
 *
 *   - EVERY PATTERN finds its LEDs by arithmetic -- a start pin, plus
 *     a step. Consecutive pins only. A fifth LED on pin 12 still
 *     can't join in.
 *
 * Both of those are lists pretending to be code.
 *
 *      Week 1  ->  variables       killed magic numbers      <-- done
 *      Week 2  ->  loops           killed repeated blocks    <-- done
 *      Week 3  ->  functions       killed repeated ideas     <-- done
 *      Week 4  ->  arrays          kill repeated data
 *
 * Keep this file. In Week 4 the row of LEDs becomes a list, and so
 * does the show.
 */


// TODO: constants only -- no global variables


void setup() {
  // TODO
}

void loop() {
  // TODO: the show -- function calls only
}

// TODO: your pattern library, and its calculators
