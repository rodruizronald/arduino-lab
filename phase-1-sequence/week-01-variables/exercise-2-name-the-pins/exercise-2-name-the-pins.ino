/*
 * WEEK 1 · EXERCISE 2 — Name the pins
 * ------------------------------------------------------------------
 * GOAL
 *   Blink each of the three LEDs in turn -- red, then yellow, then
 *   green -- with NO bare pin number anywhere below the declarations.
 *
 * WIRING
 *   Red 8, yellow 9, green 10.
 *
 * WHAT TO DO
 *   1. Declare three constants above setup():
 *
 *          /*
 * SWAP TEST
 * Prediction: changing only two pin declarations should keep the same
 * visible order after swapping the red and green LEDs.
 * Result: red was changed to pin 10 and green to pin 8. The student
 * confirmed the order was still red, yellow, green.
 * Final pin declarations are restored below: red 8, yellow 9, green 10.
 *
 * BREADBOARD (30 rows)
 * Red: anode E10, cathode E11. Yellow: anode E20, cathode E21.
 * Green: anode E29, cathode E30; resistor A27-A29;
 * signal jumper B27-pin 10; ground jumper A30-negative rail.
 * The negative rail connects to Arduino GND.
 *
 * The compiler error and both other Break it results are recorded in
 * reference/mistakes.md. All three experiments were confirmed by the student.
 * WEEK 0 COMPARISON
 * Reviewed the finished challenge on branch feature/week-00-setup without
 * switching branches. It has 40 digitalWrite calls and 2 pinMode calls:
 * 24 references to red pin 8 and 18 references to green pin 9.
 * Swapping those two LED connections would require 42 pin edits there.
 * In this exercise, only 2 constant declarations needed to change.
 * Week 0 used pins 8/9; Week 1 uses 8/10 for red/green. The comparison
 * counts each program's actual red and green pin references.
 */
 /*
 * const int PIN_RED = 8;
 *const int PIN_YELLOW = 9;
 *const int PIN_GREEN = 10;

 *
 *      ...and the other two. Note the naming convention: constants
 *      are SHOUTY_SNAKE_CASE, things that change are camelCase. The
 *      compiler does not care. Every human reading your code does.
 *
 *   2. Use them in pinMode() and in every digitalWrite(). If you can
 *      find an 8, 9 or 10 below your declarations, you are not done.
 *
 *   3. One named duration for all three, as in Exercise 1.
 *
 * THE POINT
 *   A name is an INDIRECTION. The program no longer says "pin 8", it
 *   says "whatever PIN_RED currently refers to" -- and that means the
 *   answer lives in exactly one place.
 *
 *   Indirection is how software gets changed without being rewritten.
 *   You will meet this idea again as functions (Week 3), as arrays
 *   (Week 4), and eventually as entire interfaces (Week 19). It is
 *   the same idea every time, and it starts here.
 *
 * ------------------------------------------------------------------
 * THE PAYOFF -- do this one, it is the exercise
 *   Unplug the USB. Physically swap the red and green LEDs on the
 *   breadboard, so red is now on pin 10 and green on pin 8.
 *
 *   PREDICT IN WRITING: how many lines do you have to change to make
 *   the program run the same visible sequence again?
 *
 *   Then do it. Count the edits.
 *
 *   Now open your Week 0 challenge and honestly count how many edits
 *   the same swap would have cost you there.
 *
 * ------------------------------------------------------------------
 * BREAK IT -- one at a time, record the EXACT message:
 *
 *   1. Add "PIN_RED = 9;" as the first line of setup(). The compiler
 *      refuses. Read the message carefully -- it names both the
 *      problem and the variable. This refusal is the entire reason
 *      const exists.
 *
 *   2. Remove "const" from that declaration and try again. It now
 *      compiles. Upload it and watch. Which of the two kinds of wrong
 *      did you just create? Which version would you rather have
 *      written at 1am?
 *
 *   3. Change PIN_YELLOW to 13 and upload. Two LEDs respond. Why
 *      does the board's built-in light join in? (Week 0, section 1.4.)
 *
 */



/*
 * SWAP TEST
 * Prediction: changing only two pin declarations should keep the same
 * visible order after swapping the red and green LEDs.
 * Result: red was changed to pin 10 and green to pin 8. The student
 * confirmed the order was still red, yellow, green.
 * Final pin declarations are restored below: red 8, yellow 9, green 10.
 *
 * BREADBOARD (30 rows)
 * Red: anode E10, cathode E11. Yellow: anode E20, cathode E21.
 * Green: anode E29, cathode E30; resistor A27-A29;
 * signal jumper B27-pin 10; ground jumper A30-negative rail.
 * The negative rail connects to Arduino GND.
 *
 * The compiler error and both other Break it results are recorded in
 * reference/mistakes.md. All three experiments were confirmed by the student.
 * WEEK 0 COMPARISON
 * Reviewed the finished challenge on branch feature/week-00-setup without
 * switching branches. It has 40 digitalWrite calls and 2 pinMode calls:
 * 24 references to red pin 8 and 18 references to green pin 9.
 * Swapping those two LED connections would require 42 pin edits there.
 * In this exercise, only 2 constant declarations needed to change.
 * Week 0 used pins 8/9; Week 1 uses 8/10 for red/green. The comparison
 * counts each program's actual red and green pin references.
 */

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;


const int BLINK_TIME_MS = 500;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {

  digitalWrite(PIN_RED, HIGH);
  delay(BLINK_TIME_MS);
  digitalWrite(PIN_RED, LOW);
  delay(BLINK_TIME_MS);


  digitalWrite(PIN_YELLOW, HIGH);
  delay(BLINK_TIME_MS);
  digitalWrite(PIN_YELLOW, LOW);
  delay(BLINK_TIME_MS);


  digitalWrite(PIN_GREEN, HIGH);
  delay(BLINK_TIME_MS);
  digitalWrite(PIN_GREEN, LOW);
  delay(BLINK_TIME_MS);
}
