/*
 * WEEK 0 · EXERCISE 5 — Make it talk
 * ------------------------------------------------------------------
 * GOAL
 *   Take your Exercise 4 program and make it narrate itself over the
 *   USB cable, in step with the LEDs.
 *
 *   Expected output in the Serial Monitor:
 *
 *       RED ON
 *       GREEN ON
 *       RED ON
 *       GREEN ON
 *       ...
 *
 * TWO NEW COMMANDS
 *
 *   Serial.begin(9600);          <- once, in setup(). Opens the channel.
 *   Serial.println("RED ON");    <- anywhere. Sends one line of text.
 *
 *   The quotes matter. Text in quotes is sent literally.
 *
 * HOW TO SEE IT
 *   Tools -> Serial Monitor (or the magnifying-glass icon, top right).
 *   Set the baud dropdown at the BOTTOM RIGHT to 9600.
 *   Gibberish like  ?????x?  means that dropdown is wrong. It is
 *   always that dropdown.
 *
 * THE POINT
 *   Right now this feels redundant -- the LEDs already show you what
 *   is happening, so the text adds nothing.
 *
 *   That changes permanently in Week 5. From then on, most of what
 *   your program knows lives in variables you cannot see, and this
 *   text channel is the ONLY thing standing between you and guessing.
 *
 *   Professionals have step-through debuggers, breakpoints and watch
 *   windows. You have a cable and println(). It is genuinely enough,
 *   and you will still be using this technique in twenty years.
 *
 * ------------------------------------------------------------------
 * GOING FURTHER (optional, 10 min)
 *   Serial.print()  is the same as println() but with no line break,
 *   so several prints land on one line. Try:
 *
 *       Serial.print("Red is ");
 *       Serial.println("ON");
 *
 *   Also: you can print numbers without quotes -> Serial.println(8);
 *   What happens if you print 8 WITH quotes instead? Is it the same?
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *   Delete the Serial.begin(9600) line but keep all the println calls.
 *   It compiles cleanly. It uploads. The LEDs still work.
 *
 *   What does the Serial Monitor show? Why?
 *   Which of the two kinds of wrong is this?
 */


void setup() {
  // TODO: pins, plus open the serial channel
}

void loop() {
  // TODO: exercise 4's sequence, plus an announcement per LED
}
