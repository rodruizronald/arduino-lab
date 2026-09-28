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


/*
 * PLAN BEFORE IMPLEMENTATION
 * GO: green on, other LEDs off, for 4000 ms.
 * CAUTION: yellow on, other LEDs off, for half the green time: 2000 ms.
 * STOP: red on, other LEDs off, for the same time as green: 4000 ms.
 * Repeat. Print each phase and its duration. Once per cycle, print the
 * sum of the delays for ten cycles: 100000 ms at the initial setting.
 * Change only GREEN_MS from 4000 to 2000 for the acceptance test:
 * durations become 2000, 1000, 2000; ten cycles total 50000 ms.
 * This written plan is in the sketch; it is not a claim of a paper exercise.
 *
 * CONSTRAINT TO DISCUSS WITH THE TEACHER
 * Separate digitalWrite calls cannot switch two pins at exactly the same
 * instant. Turning the old LED off first leaves a brief all-off transition.
 * Turning the new LED on first would briefly light two LEDs. This version
 * uses the allowed commands and avoids overlap, but does not meet the
 * literal "never zero, even for microseconds" rule. Reset also starts off.
 * Printed cycle totals sum the delays; command and Serial time add overhead.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;

const unsigned long GREEN_MS = 2000;
const unsigned long YELLOW_MS = GREEN_MS / 2;
const unsigned long RED_MS = GREEN_MS;
const unsigned long CYCLE_MS = GREEN_MS + YELLOW_MS + RED_MS;
const unsigned long CYCLE_COUNT = 10;
const unsigned long TEN_CYCLES_MS = CYCLE_MS * CYCLE_COUNT;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  Serial.begin(SERIAL_BAUD);
  Serial.println("--- boot ---");
}

void loop() {

  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, HIGH);
  Serial.print("GO - green for ");
  Serial.print(GREEN_MS);
  Serial.println(" ms");
  delay(GREEN_MS);


  digitalWrite(PIN_GREEN, LOW);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, HIGH);
  Serial.print("CAUTION - yellow for ");
  Serial.print(YELLOW_MS);
  Serial.println(" ms");
  delay(YELLOW_MS);


  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, LOW);
  digitalWrite(PIN_RED, HIGH);
  Serial.print("STOP - red for ");
  Serial.print(RED_MS);
  Serial.println(" ms");
  Serial.print("Ten cycles (sum of delays): ");
  Serial.print(TEN_CYCLES_MS);
  Serial.println(" ms");
  delay(RED_MS);
}
