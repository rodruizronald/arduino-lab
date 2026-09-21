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
 *   - How many lines are in your loop()?  R/ There are 73 lines of executable code in my loop().
 *   - How many times did you type digitalWrite? R/ I typed digitalWrite 40 times.
 *   - How did you feel around the third time you typed the same
 *     four lines over again? R/ I think repeating the same lines was helpful because it helped me memorize the commands and understand them better.
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
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {


  //BOOTING (5 flashes)
  Serial.println("BOOTING...");

  //Flash 1
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(150);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(150);

  //Flash 2
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);  
  delay(150);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(150);

  //Flash 3
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(150);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(150);

  //Flash 4
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(150);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(150);
  
  //Flash 5
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(150);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(150);

  //RUNNING (verde 3 veces)
  Serial.println("RUNNING");
  digitalWrite(8, LOW);
  
  //Pulse 1
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);

  //Pulse 2
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);

  //Pulse 3
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);

  //ERROR (rojo 3 veces)

  Serial.println("ERROR");
  digitalWrite(9, LOW);
  //Flash 1.1
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);

  //Flash 1.2
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);

  //Flash 1.3
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);

  //Pause after first group 
  delay(500);

  //Flash 2.1
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);
  
  //Flash 2.2
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);

  //Flash 2.3
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);

    // Pause after second group
  delay(500);

}
