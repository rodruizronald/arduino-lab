# Week 3 — Dry run

These are worked answers prepared with assistance after Exercise 3 had already been written. They are not a record of my own predictions before coding. No first prediction commit is claimed. The final programs have now been confirmed working on the UNO. This confirmation does not supply the separate dry-run outputs or stopwatch measurements.

## A — Call order

**Worked answer**

```text
setup
  sayB
    print B
    sayA
      print A
  sayA
    print A
  sayB
    print B
    sayA
      print A
```

The Monitor should show B, A, A, B, A, each on its own line.
sayA runs three times. After a function ends, execution returns to the call that started it.

**What actually happened:** Not yet run on my UNO.

## B — Copies

**Worked answer**

The numbers should be 15 and 5, in that order.
addTen gets a copy of n. It changes its own x, so n stays 5.
This is Week 1 snippet B in another form: assigning one variable to another makes a copy, not a connection between them.

**What actually happened:** Not yet run on my UNO.

## C — Return values

**Worked answer**

```text
8
7
8
```

- doubled(plusOne(3)): plusOne runs first and returns 4. doubled then returns 8.
- plusOne(doubled(3)): doubled runs first and returns 6. plusOne then returns 7.
- a gets 8 from doubled(4). doubled(a) calculates 16, but nobody saves or prints it. a stays 8.

The inner call must finish first because its result is the argument for the outer call.

**What actually happened:** Not yet run on my UNO.

## D — Four problems

**Worked answer**

| Problem | Compiler response | Meaning and correction |
|---|---|---|
| delay(onMs) in blinkN | Error | onMs only exists inside loop(). Pass the duration as a parameter, or use BLINK_MS if the time is fixed. |
| totalBlinks has no return | Warning with warnings enabled | It promises an int but does not return total. Add return total;. There is no reliable value to predict for the broken version. |
| blinkN(3, PIN_RED) | Silent | The arguments are reversed: pin becomes 3 and times becomes 8. Use blinkN(PIN_RED, 3). Both types fit, so the compiler cannot know the intended order. |
| blinkN(PIN_RED) | Error | The second argument is missing. Supply a count. |

**What actually happened:** Isolated AVR compiler checks confirmed the error/warning categories for these kinds of mistakes. Exact diagnostics are filed by category in reference/mistakes.md. The complete snippet has not been uploaded; its errors must be fixed before it can run.

## Exercise explanations

### Exercise 1

A definition tells the program what a function does; a call makes it run.
Three calls to blinkRed() in loop() repeat three red blinks. An extra call in setup() adds one blink after reset. There is no special pause between groups, so the grouping is not obvious just by watching.
The final sketch flashes red once in setup(), then blue, red, yellow, green repeatedly.
The four functions differ only in their pin. Exercise 2 makes that pin a parameter.

### Exercise 2

Expected setup output: 3, 2, 1, then flashes after countDown: 3.
times is a copy of flashes, so counting down times does not change flashes.
The final loop works out each count as pin - FIRST_PIN + 1, giving 1, 2, 3, 4.
The negative-count and wrong-order cases are explained under Logic errors.

### Exercise 3

| Setting | LED count | Steps per sweep | 200 ms per step | 100 ms per step | 40 ms per step |
|---|---:|---:|---:|---:|---:|
| Pins 7 through 10 | 4 | 6 | 1200 | 600 | 240 |
| Pins 8 through 10 | 3 | 4 | 800 | 400 | 160 |

Both sum functions should give 55 for 10, 5050 for 100, and 500500 for 1000.
The loop adds each number. The formula calculates the same result another way.
A return type of long does not fix multiplication already done using int.

### Exercise 4

In the original program, the first three red blinks use 200 ms. blinkSlowly changes the global waitMs to 1000. The next round's red blinks then use 1000 too.
Printing waitMs at the start of blinkQuickly would show 200 three times in round one, then 1000 three times in round two.
Resetting the global to 200 inside blinkQuickly hides the problem, but other functions still depend on which function changed it last.
Declaring int waitMs = 1000 inside blinkSlowly creates a second variable with the same name. It hides the global only inside that function. This can look correct while making it harder to tell which value a line uses.
The final version passes a time into blinkFor. Each call uses its own value, so the slow blink cannot change the next fast blink.

### Exercise 5

flash has five parameters: two pins, a count, an on time, and an off time.
For one LED, both pin arguments name that LED. Writing HIGH twice still means HIGH; writing LOW twice still means LOW.
The state functions make sure the unused LED is off. No if is needed.
Changing ERROR_GROUPS from 2 to 3 adds a group with one edit.
Five arguments already need careful reading. Named constants make the calls easier to understand.
The three calls in loop() describe the states. Functions help even when the whole program is not shorter.

## Physical check status

All 16 final sketches compiled and linked with AVR GCC for the UNO. Software trace checks are separate from physical observations. The student confirmed that the physical tests worked. The table below keeps the expected behavior for reference. Stopwatch measurements and separate dry-run observations have not been supplied.

Use the unchanged circuit: blue 7, red 8, yellow 9, green 10. Serial is 9600 baud.

| Sketch | Expected result |
|---|---|
| Exercise 1 | Red once after reset, then blue/red/yellow/green in order |
| Exercise 2 | Setup prints 3,2,1,3; LEDs blink 1,2,3,4 times |
| Exercise 3 | Values in the table above; both sums agree |
| Exercise 4 | Three fast red blinks then one slow green blink; repeat for at least two rounds |
| Exercise 5 | BOOTING: both flash 5 times; RUNNING: green pulses 3 times; ERROR: two groups of 3 red flashes |
| Drill 1 | Blue once, red twice, yellow three times, green four |
| Drill 2 | Two forward chases at 150 ms per LED, one at 400 ms |
| Drill 3 | All four flash 3 times |
| Drill 4 | Fill the row, then turn it off in the same order |
| Drill 5 | Print 4; changing FIRST_PIN to 8 should print 3 |
| Drill 6 | 55/55, 5050/5050, 500500/500500 |
| Drill 7 | Nine rows of the multiplication table, then repeat |
| Drill 8 | Three short, three long, three short; longer word gap |
| Drill 9 | Predicted chase: 10000 ms; measure START to END with a stopwatch |
| Drill 10 | Fast red/blue, then slow yellow/green |
| Challenge | scan, forward chase, blink all, fill, reverse chase, slower scan |

Challenge A: change only FIRST_PIN to 8; all patterns use three LEDs.
Challenge B: the reverse chase and slower scan are already included as extra calls.
Challenge C: measure a complete show, from its first scan announcement to the next cycle's first scan. Expected delay budget is 8400 ms with four LEDs, 6300 ms with three; small instruction overhead is additional. The measured time must be within one second of the announced sum.
Challenge D is answered in challenge.ino. Restore FIRST_PIN to 7 after A.

The compiler errors and warnings have been checked in separate AVR test snippets and recorded in reference/mistakes.md, with their exact messages and explanations. Logic-error outcomes are explained separately; no unreported board output is claimed. Tests that deliberately remove return have undefined behavior, so no exact printed result is promised.
