/*
 * WEEK 2 · EXERCISE 4 — While
 * ------------------------------------------------------------------
 * GOAL
 *   The red LED blinks, starting slow and getting faster with every
 *   blink, until it reaches a minimum. Then it starts over, slow.
 *
 * WIRING
 *   Red on pin 8.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Three constants:
 *
 *          const unsigned long START_MS = 500;
 *          const unsigned long STEP_MS  = 50;
 *          const unsigned long MIN_MS   = 50;
 *
 *   2. At the top of loop(), a variable that really does change:
 *
 *          unsigned long waitMs = START_MS;
 *
 *      Not const. Week 1 said "start everything as const, and remove
 *      it only when you genuinely need the value to change." This is
 *      that moment -- and because it's declared inside loop(), it
 *      goes back to START_MS every time loop() begins.
 *
 *   3. A while loop:
 *
 *          while (waitMs >= MIN_MS) {
 *            // one blink, on for waitMs, off for waitMs
 *            // then make waitMs smaller by STEP_MS
 *          }
 *
 *   4. Print waitMs on every lap.
 *
 *   5. BEFORE UPLOADING: with 500 / 50 / 50, how many blinks before
 *      it starts over? Write the number down. Then count them on the
 *      Monitor.
 *
 *   6. Now rewrite it as a for loop. All three parts of the while --
 *      the starting value, the condition, and the line that changes
 *      waitMs -- fit into a for loop's header. Same behaviour.
 *
 *      Which version reads better, and why? README section 1.8 has a
 *      rule of thumb. Decide whether you agree.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   A while loop's header changes nothing. It only asks a question.
 *   If the body doesn't move the answer toward "no", the loop never
 *   ends. That is the whole difference between while and for, and
 *   it's why while reads as "until".
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *
 *   1. Delete the line that makes waitMs smaller. Upload.
 *      What does it look like? Can you tell it apart from an ordinary
 *      Week 0 blink? What does the Monitor show? Record it under
 *      LOGIC ERRORS in reference/mistakes.md.
 *
 *   2. Put it back. Set MIN_MS to 0. PREDICT, in writing, what
 *      happens when waitMs gets down to 0 and the loop subtracts 50
 *      one more time. Then upload, and watch the Monitor.
 *
 *      This is Week 1's overflow, coming from the other direction.
 *      An unsigned number can't go below zero -- so it wraps to the
 *      TOP. Press reset when you've seen enough.
 *
 *      Now fix it without changing MIN_MS. Hint: which Week 1 type
 *      CAN go below zero? Try switching waitMs to that type...
 *      and watch it still fail. Then work out why: in a comparison
 *      that mixes a signed value with an unsigned one, the compiler
 *      quietly treats BOTH as unsigned. For the fix to work, the
 *      constants it's compared and combined with must be signed too.
 *
 *      Rule to take away: if a value can dip below zero part-way
 *      through a calculation, give it a signed type -- and give that
 *      same type to everything it meets in that calculation.
 *
 *      Record the bug and the fix under LOGIC ERRORS.
 *
 *   3. Put everything back to 500 / 50 / 50, unsigned. Now move the
 *      subtraction to the TOP of the loop body, before the blink.
 *      Which blink disappeared? Which new one appeared at the end?
 *      Off-by-one isn't only about < and <=.
 */

// Prediction for each version: 500,450,400,350,300,250,200,150,100,50.
// Both versions run here, one after the other, so they can be compared.
// Signed int is deliberate: 0 - 50 becomes -50 and fails the next check.
// All related constants are signed too. The chosen times fit an UNO int.
// MIN_MS can be changed to 0 to verify the fix without an unsigned wrap.
// for keeps start/check/update together; while makes the separate update clear.
const int PIN_RED = 8;
const int START_MS = 500;
const int STEP_MS = 50;
const int MIN_MS = 50;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  Serial.begin(SERIAL_BAUD);
}

void loop() {
  Serial.println("WHILE");
  int waitMs = START_MS;
  while (waitMs >= MIN_MS) {
    Serial.println(waitMs);
    digitalWrite(PIN_RED, HIGH);
    delay(waitMs);
    digitalWrite(PIN_RED, LOW);
    delay(waitMs);
    waitMs -= STEP_MS;
  }

  Serial.println("FOR");
  for (int waitMs = START_MS; waitMs >= MIN_MS; waitMs -= STEP_MS) {
    Serial.println(waitMs);
    digitalWrite(PIN_RED, HIGH);
    delay(waitMs);
    digitalWrite(PIN_RED, LOW);
    delay(waitMs);
  }
}
