/*
 * WEEK 3 · EXERCISE 5 — Re-solve: the Machine Status Indicator, a
 *                       third time
 * ------------------------------------------------------------------
 * GOAL
 *   Same spec as Week 0 and Week 2's Exercise 5 -- unchanged. Same
 *   behaviour. This time, built from functions, with a loop() that
 *   reads like the spec itself.
 *
 *   ---------------------------------------------------------------
 *   BOOTING
 *     Serial: "BOOTING..."  (once, as the state begins)
 *     Red and green flash TOGETHER, 5 times, 150 ms on / 150 ms off
 *
 *   RUNNING
 *     Serial: "RUNNING"
 *     Red stays off.
 *     Green pulses slowly 3 times: 1 s on, 1 s off
 *
 *   ERROR
 *     Serial: "ERROR"
 *     Green stays off.
 *     Red: 3 quick flashes (100 ms on, 100 ms off), then a 500 ms
 *          pause. That whole group happens TWICE.
 *
 *   ...then back to BOOTING.
 *   ---------------------------------------------------------------
 *
 * WIRING
 *   Red 8, green 10.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. The last question of Week 2's Exercise 5 asked you to describe
 *      all three states as one sentence with blanks:
 *
 *          "flash ___ LEDs, ___ times, ___ ms on, ___ ms off."
 *
 *      That sentence IS a function. The blanks are its parameters.
 *      Write it.
 *
 *   2. There's a design problem hiding in it: BOOTING flashes TWO
 *      LEDs together, but RUNNING and ERROR flash ONE. How can a
 *      single function do both? There's more than one answer, and
 *      none of them needs an if. Pick one, and be able to say why.
 *
 *   3. Then three functions named for the states -- booting(),
 *      running(), error() -- each built from your flash function.
 *
 *   4. loop() should end up as three lines. Read it out loud.
 *
 *   5. Count the lines inside loop(), and inside your whole program,
 *      and compare with Week 0 and Week 2. Three numbers for loop().
 *      They go in your journal.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Rule 6, for the third time on the same problem.
 *
 *     Week 0  ->  everything written out, numbers everywhere
 *     Week 1  ->  numbers named          (you didn't redo this one)
 *     Week 2  ->  repeated blocks became loops
 *     Week 3  ->  repeated IDEAS became functions, and the top level
 *                 reads like the spec
 *
 *   Notice that error() is called once and booting() is called once.
 *   They're not functions because they're reused -- they're
 *   functions because they give a STEP a name. That's decomposition
 *   (README 1.9), and it's the reason loop() can be three lines.
 *
 * ------------------------------------------------------------------
 * AFTER IT WORKS
 *
 *   1. How many parameters does your flash function have? Count
 *      them. At what number would you stop being able to remember
 *      what each argument means at the call site?
 *
 *      Six numbers in a row -- flash(8, 10, 5, 150, 150, 0) -- is
 *      where calls stop being readable. If you're there, it's a sign
 *      the function is doing two jobs, or that some of its arguments
 *      belong together. (Bundling values that belong together is
 *      Week 17.)
 *
 *   2. Make ERROR do three groups instead of two. One edit -- and
 *      where is it?
 */

const int PIN_RED = 8;
const int PIN_GREEN = 10;
const int BOOT_COUNT = 5;
const int RUN_COUNT = 3;
const int ERROR_COUNT = 3;
const int ERROR_GROUPS = 2;
const unsigned long BOOT_MS = 150;
const unsigned long RUN_MS = 1000;
const unsigned long ERROR_MS = 100;
const unsigned long GROUP_GAP_MS = 500;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  Serial.begin(SERIAL_BAUD);
}

void loop() {
  booting();
  running();
  error();
}

// Five parameters: two pins, count, on time, off time.
// Using the same pin twice flashes one LED: writing HIGH twice keeps it HIGH.
// This avoids if and arrays. Each state makes sure the unused LED is off.
// To get three error groups, change only ERROR_GROUPS to 3.
// Five arguments need care; named constants make their meaning easier to read.
void flash(int pinA, int pinB, int times, unsigned long onMs, unsigned long offMs) {
  for (int count = 0; count < times; count++) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    delay(onMs);
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    delay(offMs);
  }
}

void booting() {
  Serial.println("BOOTING...");
  flash(PIN_RED, PIN_GREEN, BOOT_COUNT, BOOT_MS, BOOT_MS);
}

void running() {
  Serial.println("RUNNING");
  digitalWrite(PIN_RED, LOW);
  flash(PIN_GREEN, PIN_GREEN, RUN_COUNT, RUN_MS, RUN_MS);
}

void error() {
  Serial.println("ERROR");
  digitalWrite(PIN_GREEN, LOW);
  for (int group = 0; group < ERROR_GROUPS; group++) {
    flash(PIN_RED, PIN_RED, ERROR_COUNT, ERROR_MS, ERROR_MS);
    delay(GROUP_GAP_MS);
  }
}
