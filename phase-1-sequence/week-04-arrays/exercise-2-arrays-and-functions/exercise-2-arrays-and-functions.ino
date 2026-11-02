/*
 * WEEK 4 · EXERCISE 2 — Arrays and functions
 * ------------------------------------------------------------------
 * GOAL
 *   One chase function that works on ANY list of pins. Then two
 *   surprises about what a function actually receives when you hand
 *   it an array.
 *
 * WIRING
 *   Blue 7, red 8, yellow 9, green 10, white 12.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Three lists, each with its count from sizeof:
 *
 *          LED_PINS   all five
 *          CAR_PINS   red, yellow, green
 *          ENDS_PINS  blue and white
 *
 *   2. One function -- array AND count, always together:
 *
 *          void chase(const byte pins[], int count, unsigned long stepMs)
 *
 *   3. loop() calls it three times, once per list, at different
 *      speeds. One function, three different jobs -- the list is the
 *      only thing that changes.
 *
 * ------------------------------------------------------------------
 * SURPRISE 1: THE FUNCTION GETS THE ORIGINAL
 *
 *   Week 3: parameters are copies. Arrays break that rule.
 *
 *   Make a non-const array -- 'int scores[] = {1, 2, 3};' -- and a
 *   function that doubles every value in it:
 *
 *       void doubleAll(int values[], int count)
 *
 *   PREDICT, in writing: after calling doubleAll(scores, 3), what
 *   does scores[0] hold back in setup()? Then print it.
 *
 *   Then put 'const' on the parameter -- 'const int values[]' --
 *   and Verify. What does the compiler say now? That error is the
 *   protection: const on an array parameter is a promise not to
 *   touch the caller's data, and the compiler holds you to it.
 *
 * ------------------------------------------------------------------
 * SURPRISE 2: THE FUNCTION CAN'T TELL HOW LONG IT IS
 *
 *   Inside chase(), add these two lines and print the result:
 *
 *       int guess = sizeof(pins) / sizeof(pins[0]);
 *       Serial.println(guess);
 *
 *   PREDICT first: you passed a list of 5. What does 'guess' say?
 *   With warnings on All, what does the compiler warn about that
 *   line? Read the warning slowly -- it says exactly what's
 *   happening.
 *
 *   Then delete those lines. The count comes in as a parameter, or
 *   not at all.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Pass the array and its count, together, every time. Put const on
 *   the array parameter unless changing the caller's array is the
 *   function's whole job. (README section 1.7.)
 *
 * ------------------------------------------------------------------
 * BREAK IT -- on the board; record what you see
 *
 *   1. Call  chase(CAR_PINS, LED_COUNT, 200);  -- the right list,
 *      the WRONG count. PRINT, don't drive, any index past the end
 *      (comment out the digitalWrite). What does it read after
 *      green? Where do those numbers come from?
 *
 *   2. Call  chase(LED_PINS, LED_COUNT - 1, 200);  -- a count one
 *      too SMALL. Which LED is left out? Why that one, and not the
 *      first? A short count is safe -- it just stops early. A long
 *      count reads memory that isn't yours. Which of the two would
 *      you rather get wrong?
 */


// TODO: three lists of pins, each with its count


void setup() {
  // TODO: pins; Serial; the two surprises
}

void loop() {
  // TODO: chase each list
}

// TODO: chase(pins, count, stepMs), doubleAll(values, count)
