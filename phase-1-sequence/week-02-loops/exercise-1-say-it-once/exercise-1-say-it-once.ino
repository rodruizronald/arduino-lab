/*
 * WEEK 2 · EXERCISE 1 — Say it once
 * ------------------------------------------------------------------
 * GOAL
 *   The red LED flashes five times, quickly, then stays dark for a
 *   second. Then again, forever.
 *
 *   Five flashes. One copy of the flash.
 *
 * WIRING
 *   Red on pin 8. (Blue 7, yellow 9, green 10 unused this time.)
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Open your Week 0 challenge and look at the BOOTING state.
 *      Five copies of the same six lines. That is what you are
 *      replacing.
 *
 *   2. Name everything first, Week 1 style:
 *
 *          const int PIN_RED = 8;
 *          const int FLASH_COUNT = 5;
 *
 *      ...plus a flash duration and a pause duration.
 *
 *   3. Write ONE flash -- on, wait, off, wait -- inside a for loop:
 *
 *          for (int flash = 0; flash < FLASH_COUNT; flash++) {
 *            // one flash here
 *          }
 *
 *      Then the long pause, AFTER the loop's closing brace.
 *
 *   4. Inside the loop, add:  Serial.println(flash);
 *      BEFORE UPLOADING, write down the numbers you expect to see.
 *      All of them, in order. Then upload and compare.
 *
 *   5. Change FLASH_COUNT to 10. Then 1. Then 0.
 *      One edit each time. What happens at 0, and why is that
 *      exactly right?
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   The block is written once. The count is data -- a named constant
 *   you can change without touching the code that does the work.
 *
 *   Week 1 separated WHAT a number means from WHERE it is used.
 *   This week separates WHAT you do from HOW MANY TIMES you do it.
 *
 * ------------------------------------------------------------------
 * BREAK IT -- one at a time. Predict first, then check with the
 * Serial Monitor. Record anything that surprised you in
 * reference/mistakes.md.
 *
 *   1. Change  flash < FLASH_COUNT  to  flash <= FLASH_COUNT.
 *      Count the flashes. What number does Serial print last?
 *
 *   2. Put it back, then start the counter at 1 instead of 0.
 *      Count again. Which is it now -- one too many, or one short?
 *
 *   3. Put it back, then add a semicolon straight after the closing
 *      bracket of the header:   for (...);
 *      Verify. It compiles. Upload. How many flashes? Why?
 *      (This is dry run snippet D1, on real hardware.)
 *
 *   4. Put it back, then add  Serial.println(flash);  on the line
 *      AFTER the loop's closing brace. Verify. Read the error -- you
 *      met it in Week 1. Where does 'flash' exist, and where doesn't
 *      it?
 */


// TODO: pin, count, and durations


void setup() {
  // TODO: pin, and Serial for the counter
}

void loop() {
  // TODO: one flash, inside a for loop -- then the long pause
}
