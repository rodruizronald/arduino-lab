/*
 * WEEK 3 · EXERCISE 2 — Parameters
 * ------------------------------------------------------------------
 * GOAL
 *   ONE function that blinks ANY LED, ANY number of times:
 *
 *       blinkN(pin, times)
 *
 *   Then use it to replace all four functions from Exercise 1.
 *
 * WIRING
 *   Blue 7, red 8, yellow 9, green 10.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Start with one parameter. blinkOnce(int pin) blinks whichever
 *      pin it's given, once. Replace blinkRed(), blinkBlue()... with
 *      four calls to it. Four functions became one.
 *
 *      (That's README section 1.10 in miniature: four pieces that
 *      were the same shape, one value that differed, and that value
 *      became the parameter.)
 *
 *   2. Add a second parameter, and rename to match what it now does:
 *
 *          void blinkN(int pin, int times)
 *
 *      Inside, a for loop -- Week 2's "count from 0, use <" idiom.
 *      The boundary question gets answered once, in here, and never
 *      again by any caller.
 *
 *   3. In loop(): blue blinks once, red twice, yellow three times,
 *      green four. Four calls.
 *
 *   4. Now a loop in loop() that calls blinkN once per pin, with the
 *      count worked out from the pin. (Week 2's drill 5 -- but the
 *      inner loop has a name now. README section 1.9: this is the
 *      nested loop, made readable.)
 *
 * ------------------------------------------------------------------
 * PROVE IT: PARAMETERS ARE COPIES
 *
 *   Write this one, call it from setup(), and PREDICT both printouts
 *   before uploading:
 *
 *       void countDown(int times) {
 *         while (times > 0) {
 *           Serial.println(times);
 *           times = times - 1;
 *         }
 *       }
 *
 *       // in setup():
 *       int flashes = 3;
 *       countDown(flashes);
 *       Serial.println(flashes);
 *
 *   The function counted its 'times' down to zero. What's 'flashes'?
 *   Write one sentence explaining why, using the word "copy".
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Parameters are the blanks; arguments fill them. Every call can
 *   fill them differently, and the function doesn't need to know or
 *   care which LED is which colour.
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *
 *   1. Swap the arguments:  blinkN(3, PIN_RED);
 *      PREDICT, then upload. It compiles -- even with warnings on
 *      All. What happened, and why couldn't the compiler tell?
 *      Record it under LOGIC ERRORS.
 *
 *   2. Leave one out:  blinkN(PIN_RED);   Record the exact error.
 *
 *   3. Pass a negative count:  blinkN(PIN_RED, -2);
 *      PREDICT how many blinks. Trace the first condition check of
 *      the for loop inside. Is that the behaviour you'd want?
 *
 *   4. Change the 'times' parameter to unsigned int, and call
 *      blinkN(PIN_RED, -2) again. PREDICT. Then press reset when you
 *      have seen enough. Week 2's unsigned trap, coming in through a
 *      parameter -- an argument gets converted to the parameter's
 *      type, silently.
 */


// TODO: pins, and a blink duration


void setup() {
  // TODO: pins, Serial -- and the countDown proof
}

void loop() {
  // TODO: calls to blinkN
}

// TODO: blinkN(pin, times), and countDown(times)
