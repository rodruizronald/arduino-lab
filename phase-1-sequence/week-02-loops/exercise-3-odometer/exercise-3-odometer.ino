/*
 * WEEK 2 · EXERCISE 3 — The odometer
 * ------------------------------------------------------------------
 * GOAL
 *   The four LEDs count from 0 to 15 in binary, one step at a time,
 *   then start again at 0. Built from four loops, nested inside each
 *   other.
 *
 * WIRING
 *   Blue 7, red 8, yellow 9, green 10.
 *
 * ------------------------------------------------------------------
 * ALL THE BINARY YOU NEED
 *
 *   Picture a car's odometer, but each wheel only has two numbers on
 *   it: 0 and 1. The rightmost wheel ticks every step. When it rolls
 *   over from 1 back to 0, the wheel to its left ticks once. That's
 *   all binary counting is:
 *
 *       0000   0001   0010   0011   0100   0101  ...  1111
 *
 *   Each LED is one wheel. Off = 0, on = 1. Reading the row left to
 *   right -- blue, red, yellow, green -- gives the number as written.
 *
 *   The wheels are worth 8, 4, 2 and 1, left to right, so 0101 is
 *   4 + 1 = 5. You'll go properly deep on this in Week 15. For now,
 *   that paragraph is enough.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Name the pins for what they MEAN, not their colour. (Week 1.)
 *
 *          const int PIN_EIGHTS = 7;   // leftmost wheel
 *          const int PIN_FOURS  = 8;
 *          const int PIN_TWOS   = 9;
 *          const int PIN_ONES   = 10;  // rightmost -- spins fastest
 *
 *      And the highest digit a wheel can show:
 *
 *          const int HIGHEST_DIGIT = 1;
 *
 *   2. Four nested loops, one per wheel, each counting from 0 up to
 *      HIGHEST_DIGIT. The OUTERMOST loop is the leftmost wheel. The
 *      INNERMOST is the ones -- the fastest.
 *
 *   3. Each wheel shows its own digit: right after its loop header,
 *      pass the loop counter straight to digitalWrite. A counter of 0
 *      is LOW, 1 is HIGH -- you proved that with a bool in Week 1,
 *      drill 4.
 *
 *   4. The innermost body is one step of the count: pause, and print
 *      the number in decimal next to its four digits, e.g.
 *
 *          5 = 0101
 *
 *      For the decimal number, keep a separate counter, starting at
 *      0 each time loop() begins, that goes up by one every step.
 *      Where must it be declared so that it does exactly that?
 *
 *   5. Pick a few numbers off the Monitor and check the LEDs match.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Nested loops ARE an odometer. The inner loop runs all the way
 *   through for every single lap of the one outside it. Total steps:
 *   2 x 2 x 2 x 2 = 16.
 *
 *   You will never write a binary counter this way again after
 *   Week 15. That's fine. The point is the nesting, and this is the
 *   clearest picture of nesting there is -- you can SEE every loop
 *   spin, at its own speed.
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *
 *   1. Swap which pins the outermost and innermost loops drive, so
 *      blue becomes the fast wheel. Is it still counting? Read the
 *      row right to left and decide.
 *
 *   2. Put it back. Set HIGHEST_DIGIT to 2 -- one edit. Now each
 *      wheel counts 0, 1, 2.
 *        - How many steps before it repeats? Predict, then count
 *          with Serial.
 *        - A digit of 2 looks exactly like a 1 on the LED. Why?
 *          (What does digitalWrite do with a value that isn't 0?)
 *        - You're counting in a different number system now. Which
 *          one? You did it by changing one named value.
 *
 *   3. Put it back. Move all four digitalWrite calls into the
 *      innermost loop, just before the pause. Does it still work?
 *      Which version is easier to read? There isn't a single right
 *      answer -- have a reason for yours.
 */

// Prediction: 0 = 0000 through 15 = 1111, then restart at zero.
// HIGHEST_DIGIT = 2 gives 3*3*3*3 = 81 steps, decimal counter 0..80.
// Digits then describe base three, but digitalWrite shows both 1 and 2 as on.
// Swapping the outside/inside pin writes reverses the visible bit order.
// Moving all four writes inside the innermost loop also works; this version
// keeps each write beside its own counter to show which wheel changes.
const int PIN_EIGHTS = 7;
const int PIN_FOURS = 8;
const int PIN_TWOS = 9;
const int PIN_ONES = 10;
const int HIGHEST_DIGIT = 1;
const unsigned long STEP_MS = 500;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  for (int pin = PIN_EIGHTS; pin <= PIN_ONES; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  int number = 0;
  for (int eights = 0; eights <= HIGHEST_DIGIT; eights++) {
    digitalWrite(PIN_EIGHTS, eights);
    for (int fours = 0; fours <= HIGHEST_DIGIT; fours++) {
      digitalWrite(PIN_FOURS, fours);
      for (int twos = 0; twos <= HIGHEST_DIGIT; twos++) {
        digitalWrite(PIN_TWOS, twos);
        for (int ones = 0; ones <= HIGHEST_DIGIT; ones++) {
          digitalWrite(PIN_ONES, ones);
          Serial.print(number);
          Serial.print(" = ");
          Serial.print(eights);
          Serial.print(fours);
          Serial.print(twos);
          Serial.println(ones);
          delay(STEP_MS);
          number++;
        }
      }
    }
  }
}
