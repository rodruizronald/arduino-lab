# Mistakes

Every bug that cost you more than **20 minutes**, plus every compiler error you meet for the first time.

Two reasons this file exists:

1. **You will hit the same bug again.** Six weeks from now, a missing ground wire will look like a totally new problem. It won't be.
2. **Reading error messages is a learned skill.** Compiler errors are written for people who already know what they mean. The only way through is to build a personal translation table — which is exactly this file.

**Format:** what I saw → what it actually meant → how I found it.

---

## Compiler errors

### Week 1 · Exercise 1 · Break it 1 — Variable inside setup()

**What I changed:** I moved `int onTimeMs = 200;` inside `setup()` and left `delay(onTimeMs);` in `loop()`. Then I clicked Verify.

**Exact error:**

```text
error: 'onTimeMs' was not declared in this scope
```

**What it means:** I put the variable inside `setup()`, so only that function can use it. `loop()` cannot use that name from there, even though `setup()` runs first.

**How I found it:** the error pointed to `delay(onTimeMs);` inside `loop()`.

**How to fix it:** move `int onTimeMs = 200;` back above `setup()`, outside both functions, and click Verify again.

**Final review:** the declaration is outside both functions in the working sketch. During the final naming review, onTimeMs became redOnMs and offTimeMs became redOffMs; the original error messages are kept unchanged.

---

### Week 1 · Exercise 1 · Break it 2 — Uppercase and lowercase letters

**What I changed:** I changed the variable name in the declaration to `onTimems`, with a lowercase `m`, but left `delay(onTimeMs);` with an uppercase `M`.

**Exact error:**

```text
error: 'onTimeMs' was not declared in this scope
```

**What it means:** C++ treats `onTimems` and `onTimeMs` as different names. The variable is now above `setup()`, but the names do not match. This time the problem is spelling, not where I put the variable.

**How I found it:** the error pointed to `delay(onTimeMs);` and suggested `onTimems`. I compared the two names and found the different letter.

**How to fix it:** change the declaration back to `int onTimeMs = 200;` so the name matches the one in `delay()`.

**Final review:** the declarations and uses now have matching names. The spelling error was corrected before the later tests.

---

### Week 1 · Exercise 1 · Break it 3 — Missing int

**What I changed:** I removed `int` from the line above `setup()`, leaving `onTimeMs = 200;`.

**Exact errors:**

```text
error: 'onTimeMs' does not name a type
error: 'onTimeMs' was not declared in this scope
```

**What it means:** the line above `setup()` needs to declare the variable with a type, such as `int`. Without it, this is not a valid declaration. The second error appears because `loop()` tries to use the variable, but its declaration failed.

**How I found it:** the first error pointed to `onTimeMs = 200;` on line 59. The second pointed to `delay(onTimeMs);` on line 69. Both came from removing `int`.

**How to fix it:** put `int` back so the line reads `int onTimeMs = 200;`, then click Verify.

**Final review:** int is restored on both declarations. The later LED test ran after this correction.

---

### `expected ';' before '}' token`

**What it actually means:** a missing semicolon — but look at the line *above* the one it points to. The compiler notices the problem when it reaches the next thing, so it reports the location one step too late.

**How to find it:** start at the reported line, read upward until you find a statement with no `;`.

---

<!--
    Week 0, Exercise 1 "Break it" — fill these in yourself.
    Copy the EXACT message, don't paraphrase it.
-->

### `expected '}' at end of input`

**What it actually means:** A closing brace `}` is missing.

**How I found it:** The compiler reached the end of the program expecting a `}`, so I checked the braces and found the missing final `}`.

---

### `'Delay' was not declared in this scope`

**What it actually means:** C++ is case-sensitive. `Delay` and `delay` are different names.

**How I found it:** The compiler suggested `delay`, so I changed `Delay` back to `delay`. 

---

### `'digitalwrite' was not declared in this scope`

**What it actually means:** C++ is case-sensitive. `digitalwrite` is not the same function as `digitalWrite`.

**How I found it:** I compared the function name with the correct spelling and noticed the uppercase `W`.

---

> **Reading long errors:** when the output is 40 lines, **read the first error only.** Everything below it is usually wreckage caused by the first one. Fix the top one, recompile, look again.

---

## Wiring mistakes

### LED doesn't light, code is definitely correct

**Cause, in order of likelihood:**
1. LED is backwards — long leg toward the resistor/pin, short leg toward GND. *(Backwards is not damaged, just silent.)*
2. No wire from the breadboard `−` rail to an Arduino `GND` pin
3. A leg is in the wrong column — same column = connected, adjacent column = not

---

## Logic errors

### Week 1 · Exercise 5 · Break it 2 — No line breaks

**What was tested:** replace println with print.

**Actual output supplied by the student:**

```text
red on for 400 msyellow on for 400 msgreen on for 1200 ms
```

**What it means:** print does not end the line, so the messages join together. println adds the line ending.

**Fix applied:** restore println after each duration and for the boot marker.

### Week 1 · Exercise 5 · Break it 3 — Unsigned long overflow

**What was tested:** start an unsigned long at 4294967295UL, then add 1UL. Line breaks were added around this result so it could be read separately from the joined LED messages.

**Actual output supplied by the student:**

```text
--- boot ---
 | before overflow: 4294967295 | after overflow: 0
LED messages:
```

**What it means:** unsigned long also has a limit. On this UNO, adding 1 to its maximum wraps to 0. Serial prints the stored value; it does not check whether that value is the answer we wanted. This unsigned wrap is different from relying on signed int overflow.

**Final code:** the temporary overflow test is removed. UNIT_MS remains 400; the printed LED durations and delays both use SHORT_MS or LONG_MS. The student confirmed the restored final upload worked as expected.

### Week 1 · Exercise 5 · Break it 1 — Printing a name in quotes

**What was tested:** change the red output from `Serial.print(SHORT_MS);` to `Serial.print("SHORT_MS");`.

**Actual result confirmed by the student:** `red on for SHORT_MS ms`. Yellow and green still printed 400 and 1200 ms.

**What it means:** quotes make it text. Without quotes, the program reads the constant's value. Both are valid code, so the compiler does not reject the text.

**Fix applied:** remove the quotes. The next two experiments were confirmed; see the entries below.

**Earlier check:** the student supplied outputs showing 200, 200, 600 at UNIT_MS = 200, and 400, 400, 1200 at UNIT_MS = 400. The printed numbers followed the shared setting.

### Week 1 · Exercise 4 · Break it 2 — A fixed duration

**What was changed:** replace `LONG_MS = UNIT_MS * 3` with `LONG_MS = 600` while UNIT_MS was 200. The student reported `LONG_MS: 600` and fast lights.

**What happened next:** after changing only UNIT_MS to 1000, the monitor still printed `LONG_MS: 600`. The student could not clearly distinguish the green timing, so UNIT_MS was increased to 3000. The student then confirmed that green was shorter than the other lights.

**What it means:** SHORT_MS and GAP_MS still depended on UNIT_MS, but LONG_MS was fixed at 600. Red and yellow changed with the main setting, while green did not.

**Fix applied:** restore `LONG_MS = UNIT_MS * 3`. The final setting is UNIT_MS = 200, and all durations use unsigned long. The student confirmed the restored final sketch worked as expected on the UNO.

**Other exercise 4 checks:** the student confirmed the expected patterns at UNIT_MS = 200, 400, 60, and 1000. At 60, the dark gaps were hard to distinguish but still visible.

### Week 1 · Exercise 4 · Break it 1 — Multiplication too large for int

**What was tested:** UNIT_MS was an int set to 20000, and LONG_MS was an int set to UNIT_MS * 3.

**Actual Serial output:**

```text
LONG_MS: -5536
```

**What it means:** 60000 does not fit in int on this UNO. The printed value confirms the incorrect result. The student confirmed that the broken version stayed on green. No compiler warning text was supplied.

**Fix applied:** use unsigned long for UNIT_MS and the derived durations. This makes the multiplication use the larger type before the result is stored. Changing only LONG_MS is not enough when the multiplication still uses int operands. Another way is to use an unsigned long operand such as 3UL, but the current code changes UNIT_MS too.

**Corrected result:** the student confirmed `LONG_MS: 60000` and that the sequence now moves slowly through all three colors. Expected durations at UNIT_MS = 20000 are red and yellow 20 seconds each, gaps 10 seconds, and green 60 seconds; these exact timings were not measured.

### Week 1 · Exercise 3 — A time value too large for int

**What was tested:** add 20000 to an int that already held 20000, print it, compare it with an unsigned long sum, and pass the broken value to delay().

**What was observed:** the student supplied the Serial Monitor output: `int sum: -25536`, `unsigned long sum: 40000`, and `broken value passed to delay, in ms: 4294941760`. The student also confirmed the expected LED behavior.

**What it means:** 40000 is outside the range of int on this classic UNO. The worksheet expects a negative result in this experiment. Passing a negative value to delay(), which accepts unsigned long, can produce an extremely long wait. Signed overflow is not a reliable way to calculate a value.

**Fix applied:** declare waitMs as unsigned long before the addition. The final code should print 40000 and keep the red LED on for 40 seconds, then off for 1 second.

**Corrected upload:** the student supplied Serial output showing `Corrected waitMs: 40000`. The four type values remained 3, 9000, 1, 200, with type sizes 2 and 4 bytes. The student also confirmed the expected final LED cycle: 40 seconds on and 1 second off. Written predictions and the answer are kept in comments in the exercise 3 sketch.


### Week 1 · Exercise 1 · Break it 4 — Zero on time

**What I tested:** `onTimeMs` set to `0`, with `offTimeMs` still set to `1000`.

**What I saw:** the LED was on for much less time than it was off. The on time was almost impossible to notice.

**What it means:** `delay(0)` does not add a wait, but the program still runs the commands that turn the LED on and off. These commands take a little time, so setting the wait to zero does not remove the brief on pulse. Then the LED stays off during `delay(offTimeMs)`.

**Final code:** the durations are 200 ms on and 1000 ms off. During the final review, the names were changed to redOnMs and redOffMs; each delay uses its matching variable.

---


The expensive ones. These compile cleanly and do the wrong thing. No error message will ever point at them — the only way one gets recorded is if you notice and write it down.

### A duration that goes negative — `int` overflow

**What I saw:** an `int` holding milliseconds went past 32,767 and came back as a negative number. Then `delay()` sat there for what looked like forever.

**What it actually means:** `int` on this board is 16 bits and stops at 32,767 — about 33 seconds in milliseconds. Past that it wraps silently to the most negative value and keeps going. `delay()` takes an `unsigned long`, so a negative `int` is reinterpreted as an enormous positive one: `-25536` becomes roughly 50 days.

**Why it's here and not in Compiler errors:** the grammar was perfect. Nothing was reported, at any point. The program ran and produced a confident wrong answer.

**How to find it:** print the value. A duration that is negative, or far smaller than it should be, has overflowed. Check the intermediate steps too — `int + int` wraps *before* the result is stored, even if you store it in an `unsigned long`.

**The fix:** `unsigned long` for any value in milliseconds that gets added to another one.

*(Week 1, Exercise 3.)*

---

<!--
    Add yours as you find them. From Week 5 onward this section grows
    fast, and by Week 12 it will be the longest in the file.
-->

## Week 1 · Exercise 2 — Recorded results

The three experiments below were confirmed by the student. Swap predictions and breadboard positions are kept in comments in the exercise 2 sketch.

### Week 1 · Exercise 2 · Break it 1 — Changing a constant

**What was tested:** with `const int PIN_RED = 10;`, add `PIN_RED = 9;` at the start of `setup()` and click Verify. The red and green LEDs were still swapped from the previous test.

**Exact error:**

```text
error: assignment of read-only variable 'PIN_RED'
```

**What it means:** `const` does not let the program change PIN_RED after its starting value is set. The line inside setup() tries to change it to 9, so the compiler stops.

**How it was found:** the compiler pointed to `PIN_RED = 9;` inside setup(), on line 75 of the tested file.

**Result:** the student confirmed this compiler error. To restore the working program, remove the assignment inside setup() and keep const.

**Next experiment:** removing const was tested afterward; see Break it 2 below.

### Week 1 · Exercise 2 · Break it 2 — Without const

**What was tested:** remove const from PIN_RED and keep `PIN_RED = 9;` at the start of setup(). The wiring was red on 10, yellow on 9, green on 8.

**What happened:** the student confirmed the expected sequence on the UNO: yellow twice, then green, with red off.

**What it means:** PIN_RED and PIN_YELLOW both held 9, so both steps controlled the yellow LED. This is a logic error: the program runs, but does the wrong thing. Keeping const would catch the unwanted assignment before uploading.

**Correction made:** put const back and remove the assignment from setup(). The next test changes only PIN_YELLOW to 13.

### Week 1 · Exercise 2 · Break it 3 — Pin 13

**What was tested:** restore const and remove the test assignment, then set PIN_YELLOW to 13. The external yellow LED stayed wired to pin 9.

**What happened:** the student confirmed red, built-in L LED, green. The external yellow LED stayed off.

**What it means:** the name PIN_YELLOW does not choose a color. Its value chooses the pin. On this UNO, pin 13 controls the built-in L LED.

**Final code restored:** PIN_RED = 8, PIN_YELLOW = 9, PIN_GREEN = 10, all const. No test assignment remains in setup(). The next exercise uses the original wiring again: red 8, yellow 9, green 10.