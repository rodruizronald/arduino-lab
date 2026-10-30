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

const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const int FORWARD = 1;
const int BACKWARD = -1;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  scan(2, 150);
  chase(FORWARD, 2, 100);
  blinkAll(3, 200, 200);
  fill(250);
  chase(BACKWARD, 2, 100);
  scan(1, 300);
}

int ledCount() {
  return LAST_PIN - FIRST_PIN + 1;
}

unsigned long scanMs(int times, unsigned long stepMs) {
  return 2 * (ledCount() - 1) * stepMs * times;
}

unsigned long chaseMs(int times, unsigned long stepMs) {
  return ledCount() * stepMs * times;
}

unsigned long blinkAllMs(int times, unsigned long onMs, unsigned long offMs) {
  return (onMs + offMs) * times;
}

unsigned long fillMs(unsigned long stepMs) {
  return 2 * stepMs * ledCount();
}

void announceMs(unsigned long durationMs) {
  Serial.print(durationMs);
  Serial.println(" ms");
}

void pulse(int pin, unsigned long stepMs) {
  digitalWrite(pin, HIGH);
  delay(stepMs);
  digitalWrite(pin, LOW);
}

void walk(int startPin, int direction, int steps, unsigned long stepMs) {
  for (int step = 0; step < steps; step++) {
    pulse(startPin + direction * step, stepMs);
  }
}

void scan(int times, unsigned long stepMs) {
  Serial.print("scan: ");
  announceMs(scanMs(times, stepMs));
  for (int sweep = 0; sweep < times; sweep++) {
    walk(FIRST_PIN, FORWARD, ledCount(), stepMs);
    walk(LAST_PIN - 1, BACKWARD, ledCount() - 2, stepMs);
  }
}

void chase(int direction, int times, unsigned long stepMs) {
  Serial.print("chase: ");
  announceMs(chaseMs(times, stepMs));
  int startPin = FIRST_PIN + (1 - direction) * (ledCount() - 1) / 2;
  for (int round = 0; round < times; round++) {
    walk(startPin, direction, ledCount(), stepMs);
  }
}

void setAll(int state) {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    digitalWrite(pin, state);
  }
}

void blinkAll(int times, unsigned long onMs, unsigned long offMs) {
  Serial.print("blink all: ");
  announceMs(blinkAllMs(times, onMs, offMs));
  for (int flash = 0; flash < times; flash++) {
    setAll(HIGH);
    delay(onMs);
    setAll(LOW);
    delay(offMs);
  }
}

void changeRow(int state, unsigned long stepMs) {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    digitalWrite(pin, state);
    delay(stepMs);
  }
}

void fill(unsigned long stepMs) {
  Serial.print("fill: ");
  announceMs(fillMs(stepMs));
  changeRow(HIGH, stepMs);
  changeRow(LOW, stepMs);
}

/*
Function guide (prepared with the code; not claimed as a prior paper plan):
setup(): prepares the pins.
loop(): plays the show.
ledCount(): returns the number of LEDs.
scanMs(times, stepMs): returns the scan's delay total.
chaseMs(times, stepMs): returns the chase's delay total.
blinkAllMs(times, onMs, offMs): returns the blink pattern's delay total.
fillMs(stepMs): returns the fill pattern's delay total.
announceMs(durationMs): prints a duration.
pulse(pin, stepMs): lights one pin briefly.
walk(startPin, direction, steps, stepMs): moves a light through a set of positions.
scan(times, stepMs): repeats a bouncing light.
chase(direction, times, stepMs): repeats a one-way light.
setAll(state): sets every LED to the same state.
blinkAll(times, onMs, offMs): flashes the whole row.
changeRow(state, stepMs): changes the row one pin at a time.
fill(stepMs): plays the fill pattern.

A: FIRST_PIN=8 changes only the constant. Expected durations in ms:
1200,600,1200,1500,600,1200; total 6300.
Default FIRST_PIN=7: 1800,800,1200,2000,800,1800; total 8400.
B: The last two calls add a reverse chase and a slower scan, with no new loops.
C: Time from the first scan announcement to the next cycle's first scan.
The delay budget is 8.4 seconds; command/Serial overhead is additional.
The required physical stopwatch check is not yet confirmed.
D: walk(7,0,4,150) pulses pin 7 four times; it never moves.
walk(7,2,4,150) visits 7,9,11,13, skipping LEDs and leaving our row.
The loop still ends because it counts steps, not the pin's value.
An int accepts both invalid directions. Checking and rejecting them needs
a decision, such as if, which this assignment has not introduced.
These are explanations, not directions to upload invalid-pin tests.

Supported settings: FIRST_PIN <= LAST_PIN, at least two LEDs for scan,
direction +1/-1, nonnegative counts, and times whose totals fit unsigned long.
*/
