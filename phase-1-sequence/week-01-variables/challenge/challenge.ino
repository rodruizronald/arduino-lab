/*
 * WEEK 1 · CHALLENGE — Traffic Light
 * ==================================================================
 * NO HINTS. You will get stuck. That is the exercise.
 * ==================================================================
 *
 * A traffic light on your three LEDs, cycling forever:
 *
 *   ---------------------------------------------------------------
 *   GO
 *     Green on. Red and yellow off.
 *     Lasts GREEN_MS.
 *     Serial: which phase it is, and how long it lasts.
 *
 *   ---------------------------------------------------------------
 *   CAUTION
 *     Yellow on. Red and green off.
 *     Lasts YELLOW_MS.
 *     Serial: same.
 *
 *   ---------------------------------------------------------------
 *   STOP
 *     Red on. Yellow and green off.
 *     Lasts RED_MS.
 *     Serial: same.
 *
 *   ---------------------------------------------------------------
 *   ...then back to GO.
 *
 *
 * CONSTRAINTS
 *
 *   1. WRITE THE SPEC ON PAPER FIRST, in plain language. Every phase,
 *      every duration, in order, before you touch the keyboard.
 *      (Rule 2.)
 *
 *   2. EXACTLY ONE LED IS LIT AT ANY INSTANT. Never two. Never zero.
 *      Not even for a few microseconds between phases. Trace your
 *      sequence by hand and find the gaps before you upload.
 *
 *   3. NOT ONE BARE NUMBER below the constants block. Every pin and
 *      every duration is a name. (HIGH, LOW and OUTPUT are already
 *      names, so those are fine.)
 *
 *   4. YELLOW_MS AND RED_MS ARE DERIVED FROM GREEN_MS. Not typed
 *      independently -- derived, with arithmetic. Pick ratios that
 *      look like a real traffic light.
 *
 *   5. SERIAL ANNOUNCES EACH PHASE AND PRINTS ITS DURATION, reading
 *      the number from the variable. The printout has to be evidence
 *      that the constant really drives the delay -- if you type the
 *      number into the string by hand, the two can disagree, and a
 *      printout that can lie is worse than none.
 *
 *   6. ONCE PER CYCLE, PRINT HOW LONG TEN FULL CYCLES WOULD TAKE.
 *      Think about the type before you write it. Then check the
 *      number is actually right -- a plausible-looking wrong answer
 *      is the failure mode here, and you met it in Exercise 3.
 *
 *   7. USE ONLY WHAT YOU KNOW: the five Week 0 commands, plus
 *      variables, const, types, and arithmetic.
 *      No loops. No if. No functions of your own. Not yet.
 *
 *
 * ==================================================================
 * THE ACCEPTANCE TEST
 * ==================================================================
 *
 *   MAKE THE ENTIRE LIGHT RUN TWICE AS FAST BY CHANGING ONE NUMBER.
 *
 *   One edit. Every duration halves, every printed number updates,
 *   the ratios between the phases stay exactly as they were.
 *
 *   If it takes more than one edit, you are not finished. You have
 *   written Week 0 code with better spelling. Go back and find what
 *   is still hard-coded -- it will be somewhere you were sure was
 *   fine.
 *
 *
 * ==================================================================
 * AND THEN -- THE ACTUAL LESSON
 * ==================================================================
 *
 * Look at what you built. Every magic number is gone. The file says
 * what it means. One constant re-times the entire system. That is
 * real, and it is a bigger improvement than it looks.
 *
 * Now count your digitalWrite calls. Still nine.
 *
 * You wrote the same three-line shape three times, changing only
 * which pin was HIGH. Variables killed the mystery numbers and did
 * absolutely nothing about the repetition.
 *
 * WRITE THAT DOWN IN YOUR JOURNAL.
 *
 * That is the correct outcome, not a failure. Each tool kills exactly
 * one kind of misery:
 *
 *      Week 1  ->  variables       killed magic numbers      <-- done
 *      Week 2  ->  for loops       kill repeated blocks
 *      Week 3  ->  functions       kill repeated ideas
 *      Week 4  ->  arrays          kill repeated data
 *
 * In Week 4 you will rebuild this exact traffic light, one more time,
 * as a table of phases -- and adding a pedestrian light will mean
 * adding a row to that table instead of rewriting loop().
 *
 * Keep this file. You are going to want to compare.
 */


// TODO: pins, then GREEN_MS, then everything derived from it


void setup() {
  // TODO
}

void loop() {
  // TODO
}
