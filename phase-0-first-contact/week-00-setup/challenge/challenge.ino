/*
 * WEEK 0 · CHALLENGE — Machine Status Indicator
 * ==================================================================
 * NO HINTS. You will get stuck. That is the exercise.
 * ==================================================================
 *
 * Build the status light for an imaginary machine. It cycles through
 * three states, forever, in this order:
 *
 *   ---------------------------------------------------------------
 *   BOOTING
 *     Serial: "BOOTING..."  (once, as the state begins)
 *     Both LEDs flash TOGETHER, 5 times, 150 ms on / 150 ms off
 *
 *   ---------------------------------------------------------------
 *   RUNNING
 *     Serial: "RUNNING"
 *     Red stays off.
 *     Green pulses slowly 3 times: 1 s on, 1 s off
 *
 *   ---------------------------------------------------------------
 *   ERROR
 *     Serial: "ERROR"
 *     Green stays off.
 *     Red: 3 quick flashes (100 ms on, 100 ms off), then a 500 ms
 *          pause. That whole group happens TWICE.
 *
 *   ---------------------------------------------------------------
 *   ...then back to BOOTING.
 *
 *
 * CONSTRAINTS
 *
 *   1. WRITE THE FULL SPEC ON PAPER FIRST, in plain language, before
 *      touching the keyboard. Every state, every duration, in order.
 *      (Rule 2. This is not optional and you will feel the difference.)
 *
 *   2. Use ONLY what Week 0 introduced:
 *          pinMode, digitalWrite, delay, Serial.begin, Serial.println
 *      No loops. No variables. No functions of your own. You have not
 *      learned them, and reaching for them now skips the lesson.
 *
 *   3. It must be readable. A blank line between states, and a comment
 *      naming each state.
 *
 *
 * ==================================================================
 * AND THEN -- THE ACTUAL LESSON
 * ==================================================================
 *
 * When it works, stop and count:
 *
 *   - How many lines are in your loop()?
 *   - How many times did you type digitalWrite?
 *   - How did you feel around the third time you typed the same
 *     four lines over again?
 *
 * WRITE THAT FEELING DOWN IN YOUR JOURNAL.
 *
 * It has a name, and it is the thing that every language feature you
 * will learn over the next two months exists to kill:
 *
 *      Week 2  ->  for loops        kill repeated blocks
 *      Week 3  ->  functions        kill repeated ideas
 *      Week 4  ->  arrays           kill repeated data
 *
 * Each will feel like relief. It will only feel like relief because
 * you did it the hard way first, today.
 *
 * If this challenge was not tedious, you took a shortcut. Go back.
 */


void setup() {
  // TODO
}

void loop() {
  // TODO
}
