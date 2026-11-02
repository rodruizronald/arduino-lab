/*
 * WEEK 4 · EXERCISE 1 — Your first array
 * ------------------------------------------------------------------
 * GOAL
 *   All five LEDs in one list. One loop chases through them -- pin 12
 *   included, even though it isn't next to 10 and isn't in the row.
 *
 * WIRING
 *   Blue 7, red 8, yellow 9, green 10, white 12.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. The list, and its count -- worked out by the compiler, never
 *      typed (README sections 1.2 and 1.4):
 *
 *          const byte LED_PINS[] = {7, 8, 9, 10, 12};
 *          const int  LED_COUNT  = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
 *
 *   2. setup(): every pin in the list is an OUTPUT. One loop over the
 *      INDEXES, 0 to LED_COUNT - 1. The pin is LED_PINS[i].
 *
 *   3. Print LED_COUNT in setup(). It should say 5. Check it.
 *
 *   4. loop(): the chase. On each lap, print the index AND the pin,
 *      like  "0 -> 7". Watch the light jump to the white LED at the
 *      end -- off the row, onto the other half of the board.
 *
 *   5. Now edit ONLY the array:
 *        - {12, 10, 9, 8, 7}     -- backwards
 *        - {7, 12, 8, 12, 9, 12, 10}  -- white between every other LED
 *      What changed in the code? (Nothing. That's the exercise.)
 *      What did LED_COUNT do by itself when the list got longer?
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   In Week 2 the loop counter WAS the pin, so pins had to be
 *   consecutive and in physical order. Now the counter is a POSITION
 *   IN A LIST, and the pin is whatever's in that box. Any pins, any
 *   order, any number of them.
 *
 *   The list decides. Not the breadboard, not arithmetic.
 *
 * ------------------------------------------------------------------
 * BREAK IT -- predict first, then run ON THE BOARD. Record what you
 * actually see in reference/mistakes.md, under the matching section.
 *
 *   1. Replace LED_COUNT with a typed 5. Upload: fine. Now add a sixth
 *      pin to the list -- say, 12 again. Upload. Is it chased?
 *      Put sizeof back and compare.
 *
 *   2. Change the chase condition to  i <= LED_COUNT.
 *      BEFORE uploading: COMMENT OUT the digitalWrite lines in the
 *      chase, and only PRINT the index and LED_PINS[i]. (The value
 *      past the end isn't a real pin -- don't drive it.)
 *      What does the last lap print? Run it a few times, and after
 *      adding or removing other constants. Is it always the same?
 *      Which section of mistakes.md does this belong in, and why?
 *
 *   3. Put it back. Print LED_PINS[LED_COUNT] once in setup().
 *      Same question: what lives just past the end?
 */


// TODO: the list of pins, and its count


void setup() {
  // TODO: every pin in the list is an output; Serial; print LED_COUNT
}

void loop() {
  // TODO: chase through the list by index
}
