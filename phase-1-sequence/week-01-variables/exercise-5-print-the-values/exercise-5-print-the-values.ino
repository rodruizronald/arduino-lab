/*
 * WEEK 1 · EXERCISE 5 — Print the values
 * ------------------------------------------------------------------
 * GOAL
 *   Serial output that reports what your variables actually HOLD,
 *   not just fixed text you typed.
 *
 * WIRING
 *   Red 8, yellow 9, green 10.
 *
 * ------------------------------------------------------------------
 * THE NEW SKILL
 *
 *   In Week 0 you printed literals:
 *
 *       Serial.println("RED ON");
 *
 *   Now you print values:
 *
 *       Serial.print("red on for ");     // no line break yet
 *       Serial.print(redOnMs);           // no quotes -- the VALUE
 *       Serial.println(" ms");           // ends the line
 *
 *   Two things to get straight:
 *
 *     - print() vs println(): println ends the line. print does not,
 *       so several of them land side by side. That is how you build
 *       one readable line out of several pieces.
 *
 *     - "redOnMs" in quotes prints the eleven letters. redOnMs with
 *       no quotes prints what is in the box. Confusing those two is
 *       a rite of passage; do it once here deliberately so you
 *       recognise it later.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. Take your Exercise 4 sequence.
 *   2. Before each LED lights, print which one and for how long,
 *      reading the duration from the constant.
 *   3. Open Tools -> Serial Monitor, 9600 baud.
 *   4. Now change UNIT_MS and upload again. The printed numbers move
 *      with it -- because they are the same numbers, not a second
 *      copy you typed into the strings.
 *
 *      That last point is the whole exercise. If your printout can
 *      disagree with your program, it is worse than useless.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   Rule 9 begins here: "from Week 1 onward, when something is wrong
 *   you print values -- you do not guess."
 *
 *   Right now this feels redundant. The LEDs are visible; you can see
 *   what the program is doing. Enjoy that, because it ends soon. From
 *   Phase 2 the interesting state lives in variables you cannot see,
 *   and a printed value is the only difference between debugging and
 *   staring at code hoping to feel something.
 *
 *   Professional programmers have step-through debuggers. You have a
 *   cable and println(). It is genuinely enough.
 *
 * ------------------------------------------------------------------
 * BREAK IT
 *
 *   1. Put redOnMs in quotes: Serial.println("redOnMs");
 *      It compiles. It is wrong. Why did nothing complain?
 *
 *   2. Change every println to print. Read the Serial Monitor. Now
 *      you know what println was actually doing for you.
 *
 *   3. Print an unsigned long that you have overflowed (Exercise 3).
 *      The Serial Monitor reports the wrong value with complete
 *      confidence. Printing shows you what the program BELIEVES --
 *      which is what you want, but it is not the same as the truth.
 *
 * ------------------------------------------------------------------
 * ONE HABIT TO STEAL
 *   Print a marker line in setup(), before anything else runs:
 *
 *       Serial.println("--- boot ---");
 *
 *   When the Monitor fills up, that line tells you exactly where the
 *   board last reset. You will use this for the next nine months.
 */


// TODO: your constants from Exercise 4


void setup() {
  // TODO: pins, Serial.begin, and a boot marker
}

void loop() {
  // TODO: each phase announces itself AND its duration, from the variable
}
