/*
 * WEEK 2 · EXERCISE 2 — The pin is the counter
 * ------------------------------------------------------------------
 * GOAL
 *   A single light runs along all four LEDs -- blue, red, yellow,
 *   green -- then starts again from blue. Then make it run the other
 *   way.
 *
 * WIRING
 *   Blue 7, red 8, yellow 9, green 10.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Two constants describe the whole row:
 *
 *          const int FIRST_PIN = 7;
 *          const int LAST_PIN  = 10;
 *
 *      ...plus one duration for how long each LED stays lit.
 *
 *   2. setup() first. Four pinMode lines become one, inside a loop
 *      whose counter IS the pin number:
 *
 *          for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
 *            pinMode(pin, OUTPUT);
 *          }
 *
 *   3. loop(): the same kind of loop. Each lap turns 'pin' on,
 *      waits, and turns it off.
 *
 *   4. Print the pin number on every lap. Check the Monitor against
 *      the LEDs -- does 7 really mean blue?
 *
 *   5. Now make the light run BACKWARDS, green to blue. Three things
 *      in the header change. Work out which three on paper before you
 *      touch the code.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   The colours are gone. PIN_RED, PIN_YELLOW -- none of them appear.
 *   The loop doesn't know which LED is which colour; it sees
 *   positions, one after another.
 *
 *   And look at the condition: <=, not <. In Exercise 1 you had a
 *   COUNT, so the end was excluded. Here you have the actual FIRST
 *   and LAST pins, so the end is included. Be able to say that out
 *   loud. (README section 1.6.)
 *
 *   One more thing, and hold on to it: this only works because 7, 8,
 *   9 and 10 are consecutive numbers. An LED on pin 12 would be out
 *   of this loop's reach. Week 4 fixes that.
 *
 * ------------------------------------------------------------------
 * BREAK IT -- one at a time, predict first:
 *
 *   1. In loop(), change <= to <. Which LED goes dark -- and why that
 *      one and not another?
 *
 *   2. Put it back, then start the loop() counter at FIRST_PIN + 1.
 *      Which one now?
 *
 *   3. Put it back. Now break ONLY the setup() loop: make it
 *      pin < LAST_PIN. The chase loop is still correct. Upload.
 *      One LED misbehaves -- not dark, but not right either. You have
 *      seen this exact symptom before, in Week 0 Exercise 3's
 *      break-it. What is the LED missing?
 *
 *   4. Swap the 7 and the 10: FIRST_PIN = 10, LAST_PIN = 7, forward
 *      loop unchanged. PREDICT before uploading. How many laps does
 *      the loop run? Trace the very first condition check.
 *
 *   If a loop bug ever sends the counter somewhere strange, the board
 *   may try to drive pins that don't exist. Nothing is damaged --
 *   press reset.
 */

// Forward prediction: 7 8 9 10. Backward: 10 9 8 7.
// Backward changes the start to LAST_PIN, the condition to >= FIRST_PIN,
// and the update to pin--. Both directions are kept here to compare them.
// Ends repeat between these two full chases; the scanner challenge removes that.
const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const unsigned long STEP_MS = 250;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  Serial.println("Forward");
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    Serial.println(pin);
    digitalWrite(pin, HIGH);
    delay(STEP_MS);
    digitalWrite(pin, LOW);
  }
  Serial.println("Backward");
  for (int pin = LAST_PIN; pin >= FIRST_PIN; pin--) {
    Serial.println(pin);
    digitalWrite(pin, HIGH);
    delay(STEP_MS);
    digitalWrite(pin, LOW);
  }
}
