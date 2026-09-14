/*
 * WEEK 1 · EXERCISE 3 — Types, and where they break
 * ------------------------------------------------------------------
 * GOAL
 *   Meet the four types you need, then deliberately destroy one of
 *   them and watch the board lie to you with total confidence.
 *
 * WIRING
 *   Red 8, yellow 9, green 10. Barely used -- this one is mostly
 *   Serial output.
 *
 * ------------------------------------------------------------------
 * PART 1 -- THE TOUR
 *
 *   Declare one of each, above setup(), and print all four in setup():
 *
 *       int           flashCount   = 3;
 *       unsigned long cycleMs      = 9000;
 *       bool          isRunning    = true;
 *       byte          brightness   = 200;
 *
 *   Predict what bool prints BEFORE you upload. It is not the word
 *   "true". Write down your guess, then look.
 *
 *   Optional, and worth ten seconds: print sizeof(int) and
 *   sizeof(unsigned long). Those are the number of BYTES each box
 *   takes. The board has 2048 of them in total.
 *
 * ------------------------------------------------------------------
 * PART 2 -- THE OVERFLOW
 *
 *   This is the part that matters.
 *
 *       int waitMs = 20000;
 *       waitMs = waitMs + 20000;
 *       Serial.println(waitMs);
 *
 *   PREDICT IN WRITING FIRST. Then upload.
 *
 *   You did not get 40000. You got a negative number, the compiler
 *   said nothing, and no error was reported at any point. The board
 *   is entirely satisfied with its answer.
 *
 *   Record what you saw in reference/mistakes.md, under LOGIC ERRORS
 *   -- not compiler errors. There was no compiler error. That is the
 *   whole point, and it is why that section of the file exists.
 *
 *   NOW FIX IT: change the type to unsigned long and run it again.
 *
 *   Then answer, in writing: an int on this board stops at 32767.
 *   Expressed in seconds, how long is 32767 milliseconds? Is that a
 *   duration you might plausibly have wanted to use?
 *
 * ------------------------------------------------------------------
 * PART 3 -- THE CONSEQUENCE
 *
 *   Take the BROKEN version back (int, holding the negative number)
 *   and pass it to delay():
 *
 *       digitalWrite(PIN_RED, HIGH);
 *       delay(waitMs);
 *
 *   Upload and watch. The LED comes on and stays on.
 *
 *   delay() takes an unsigned long -- a type with no negatives. Your
 *   negative int gets reinterpreted, bit for bit, as an enormous
 *   positive one. Roughly 50 days.
 *
 *   Press the reset button. Nothing is damaged.
 *
 *   This is what a type error looks like in practice: not a crash,
 *   not a message. A program that sits there, apparently working,
 *   doing something insane for a reason you cannot see.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Types are not bureaucracy the language imposes on you. They are a
 *   statement about what values are possible, and picking the wrong
 *   one produces bugs that compile cleanly, run happily, and lie.
 *
 *   Rule for the rest of this plan: any value in milliseconds that
 *   might be added to another one is an unsigned long.
 */


// TODO: one variable of each type


void setup() {
  // TODO: Serial.begin, then print all four. Predict bool first.
}

void loop() {
  // TODO: Part 3 only -- the overflow, then delay() on it. Then reset.
}
