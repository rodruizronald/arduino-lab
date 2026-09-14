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
 *          const int PIN_RED = 8;
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
 */


// TODO: three pin constants, and a named duration


void setup() {
  // TODO: three pins to announce. No bare numbers.
}

void loop() {
  // TODO: red, then yellow, then green -- each on, pause, off, pause
}
