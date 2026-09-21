/*
 * WEEK 0 · EXERCISE 3 — Your own LED
 * ------------------------------------------------------------------
 * GOAL
 *   Take a working blink program and move it off the board's
 *   built-in LED onto the RED LED you wired to pin 8.
 *
 * WIRING
 *   See wiring.md. Red LED on pin 8, green on pin 9.
 *   Unplug the USB before wiring. Plug it back in after.
 *
 * WHAT TO DO
 *   Start from your Exercise 1 program. Exactly TWO things need to
 *   change. Work out which two before reading the hint below.
 * 
 * THE POINT
 *   LED_BUILTIN was training wheels -- it is just the number 13 with
 *   a friendly name attached. Pins are numbers, and which pin you use
 *   is your choice, not the board's.
 *
 * ------------------------------------------------------------------
 * HINT (only after you've tried)
 *   .
 *   .
 *   .
 *   Every place the old program named LED_BUILTIN, it now needs to
 *   name pin 8 instead. There are two such places: one in setup(),
 *   one... no, TWO in loop(). So three total. If you said two, you
 *   forgot that digitalWrite appears twice.
 *
 *   Noticing that you have to change the same thing in three separate
 *   places is worth remembering. Week 1 gives you the fix.
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *   Change the pinMode line to pin 9, but leave both digitalWrite
 *   calls on pin 8.
 *
 *   PREDICT FIRST, in writing: does the red LED blink? Does green?
 *   Does neither? Does it even compile? 
 *
 *   Then run it. Were you right? If not -- why did you expect what
 *   you expected? That gap is the useful part.
 *   What happened: The red LED still blinked one second on and one second off.
*    (My prediction: I think it will not work).
 */


void setup() {
pinMode(8, OUTPUT);

}

void loop() {
  digitalWrite(8, HIGH);
  delay(1000);

  digitalWrite(8, LOW);
  delay(1000);
  
}
