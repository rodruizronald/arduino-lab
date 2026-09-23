# Week 1 — Names for Numbers

> **Phase 1** · Variables, types, and constants
> **Time:** ~5 hours
> **New concepts:** variables · types (`int`, `unsigned long`, `bool`, `byte`) · `const` · assignment · naming things well · magic numbers

---

## What you need on the desk

| Item | How many | Notes |
|---|---|---|
| UNO board + USB cable | 1 | |
| 400-point breadboard | 1 | The one already built from Week 0 |
| LEDs | 3 | Red, **yellow**, green. The yellow one is new this week |
| Resistors | 3 | 200Ω or 330Ω |
| Jumper wires | ~7 | |

You are adding one LED and moving one wire. See [`wiring.md`](wiring.md).

---

# Step 1 · CONCEPT

**~35 minutes. Read this with the box closed. No computer, no board.**

## 1.1 The problem, stated honestly

Open your Week 0 challenge. Find every `150` in it.

There are ten. They all mean the same thing — "one flash of the booting light" — but the program doesn't know that. To the compiler they are ten unrelated numbers that happen to be equal. If you decide the boot flash should be 120 ms, you have to find all ten and change all ten, and if you miss one, **nothing tells you.** It compiles. It uploads. It runs. It is just slightly, invisibly wrong.

Now find every `8`. Some of them mean "the red LED". At least one is part of `9600`. The program can't tell those apart either.

Numbers written directly into code like this are called **magic numbers**, and the name is sarcastic. There is nothing magic about them — that's the complaint. They appear from nowhere, mean something only to the person who typed them, and that person forgets within a week.

This week you learn the fix, and it is the simplest tool in the entire plan: **give the number a name.**

## 1.2 What a variable actually is

A variable is **a named box in the board's memory that holds one value.**

```cpp
int onTimeMs = 500;
```

Read it in four pieces:

| Piece | Name | Meaning |
|---|---|---|
| `int` | the **type** | what shape of thing goes in the box |
| `onTimeMs` | the **name** | what you'll call it from now on |
| `= 500` | the **initialiser** | what's in the box to start with |
| `;` | | end of instruction, as always |

That line does two jobs at once, and it's worth separating them in your head:

- **Declaration** — "make a box, this shape, call it `onTimeMs`." Happens once.
- **Assignment** — "put 500 in it." Can happen as often as you like.

After that line, writing `onTimeMs` anywhere means "whatever is currently in that box."

```cpp
delay(onTimeMs);      // the board reads the box, finds 500, waits 500 ms
```

> **Why "variable"?** Because the value can *vary* — you can put something else in the box later. That's the whole difference between a variable and the literal `500`, which is stuck being 500 forever.

## 1.3 `=` does not mean "equals"

This is the single most important sentence this week:

> **`=` means "copy the value on the right into the box on the left."**

It is an instruction, not a statement of fact. It has a direction. Once you read it that way, this stops being nonsense:

```cpp
count = count + 1;
```

As maths that's a lie — no number equals itself plus one. As an instruction it's obvious: *take what's in `count`, add 1, put the result back in `count`.* Right side first, always, then the copy.

And this is the consequence that trips up everyone, forever:

```cpp
int a = 5;
int b = a;    // copies the VALUE 5 into b. b is not "linked" to a.
a = 9;        // a is now 9
              // b is still 5
```

`b` took a **copy**. The boxes have no relationship after that line. If you expected `b` to become 9, you were thinking of `=` as "is the same as" rather than "copy into." Fix that reading now and you'll save yourself months.

## 1.4 Types: why the box has a shape

The board has **2048 bytes** of memory. Total. That's not a typo — it's about one-millionth of your laptop's. Every box you make costs some of it, so the machine insists you say up front how big each one needs to be.

The type also tells it **how to interpret the bits**, which is why the same 16 bits can be a number, a letter, or a truth value depending on what you declared.

These are the four you need this week.

| Type | Size | Holds | Use it for |
|---|---|---|---|
| `int` | 2 bytes | whole numbers, **−32,768 to 32,767** | counts, pin numbers, short durations |
| `unsigned long` | 4 bytes | whole numbers, **0 to 4,294,967,295** | milliseconds, anything that adds up |
| `bool` | 1 byte | `true` or `false` | a yes/no fact |
| `byte` | 1 byte | whole numbers, **0 to 255** | small counts, and raw bits in Phase 4 |

> ### ⚠️ The one that will bite you
>
> **On this board, `int` stops at 32,767.** Not two billion. Thirty-two thousand.
>
> On your laptop `int` is 32 bits and you'd never notice. Here it's 16, and 32,767 milliseconds is **33 seconds**. That is well inside the range of things you will actually want to measure.
>
> When an `int` goes past its maximum it doesn't error, warn, or stop. It **wraps around to the most negative value** and keeps going, cheerfully. You get a wrong answer with no indication that anything happened. This is a logic error the compiler will never catch for you, and it is the reason `unsigned long` exists in your vocabulary from week one.
>
> **Rule for this plan: any value measured in milliseconds that might be added to another one is an `unsigned long`.**

`unsigned` means "no negatives, so spend the whole range going upward." Half the range of a signed type is spent on negative numbers you'll never use for a duration.

## 1.5 `const` — a box you promise not to change

```cpp
const int PIN_RED = 8;
```

`const` says: *this box is set once and never written to again.* Try to assign to it and the **compiler refuses to build**:

```cpp
PIN_RED = 9;    // error: assignment of read-only variable 'PIN_RED'
```

That refusal is the entire point. You are asking the machine to enforce a promise you made to yourself, so that a mistake three months from now becomes a free instant compile error instead of an afternoon of debugging.

**When to use it:** the moment you know a value should never change while the program runs. Pin numbers. Fixed durations. Thresholds. In practice, most of the named values in a small Arduino program are `const`.

> **The habit worth forming:** start every variable as `const`. Remove it only when you hit a case where you genuinely need to change the value. That way "this can change" is a decision you made, not an accident.

### The convention

`const` values are conventionally named in `SHOUTY_SNAKE_CASE`, and things that vary in `camelCase`:

```cpp
const int PIN_RED  = 8;       // never changes
int       flashCount = 0;     // changes as the program runs
```

The compiler does not care. Every human reading your code does — the shape of the name tells them whether to expect it to move.

## 1.6 Where you put it decides who can see it

```cpp
const int PIN_RED = 8;        // OUTSIDE any function: "global".
                              // setup() and loop() can both see it.

void setup() {
  int attempts = 0;           // INSIDE setup(): "local".
  pinMode(PIN_RED, OUTPUT);   // loop() cannot see 'attempts' at all.
}
```

That's called **scope**, and a variable exists only inside the `{ }` block it was declared in. Use `attempts` inside `loop()` and you get:

```
error: 'attempts' was not declared in this scope
```

— which is the compiler telling you, precisely, that you're reaching for something that doesn't exist where you're standing.

For this week the practical rule is simple: **put your `const` declarations at the top of the file, above `setup()`.** Full treatment of scope is Week 3, where it becomes a design decision rather than a rule.

## 1.7 Naming things well

This is not decoration. It is the highest-leverage skill in this entire week, and it has almost nothing to do with C++.

A good name answers the question *"what is this, and what unit is it in?"* without you having to read another line.

| ✗ | ✓ | Why |
|---|---|---|
| `x` | `onTimeMs` | `x` tells the reader nothing at all |
| `time` | `redOnMs` | *Which* time? For what? In what unit? |
| `delay1` | `flashMs` | Numbered names mean you gave up |
| `p` | `PIN_YELLOW` | Saving six keystrokes, costing every future read |
| `t` | `cycleTotalMs` | |

Two rules that do most of the work:

1. **Put the unit in the name.** `Ms` for milliseconds, `Sec` for seconds. Every bug where someone waited a thousand times too long was a unit that lived in the author's head instead of in the name.
2. **Name it for what it *means*, not what it *is*.** `PIN_RED` is a pin number, but nobody needs telling that — what they need is which LED it drives.

> **You will rename things.** Writing the code teaches you what it actually does, and the first name is often a guess made before you knew. Renaming as you understand better is a sign the process is working, not a sign you did it wrong. Your journal prompt this week asks about exactly this.

## 1.8 What this week does *not* fix

Be clear-eyed about the limits, because it sets up next week.

Variables kill **magic numbers**. They do not kill **repetition**. When you finish the challenge you will still have typed the same three-line block three times over — it'll just be three lines of well-named code instead of three lines of mystery numbers.

That is genuine progress and it is not enough. Loops are Week 2.

---

# Step 2 · DRY RUN

**~20 minutes. Paper and pen. No computer. Do not skip this.**

Write your answer to each in full before reading the next.

### Snippet A

```cpp
int onTimeMs  = 500;
int offTimeMs = 250;

void setup() {
  Serial.begin(9600);
  Serial.println(onTimeMs + offTimeMs);
}

void loop() {
}
```
> **Q:** What number appears in the Serial Monitor? How many times does it appear, and why that many?

### Snippet B — the important one

```cpp
void setup() {
  Serial.begin(9600);

  int a = 5;
  int b = a;
  a = 9;

  Serial.println(a);
  Serial.println(b);
}
```
> **Q:** Write down both numbers, in order. Then write one sentence explaining what `int b = a;` actually did. If you have to hesitate, reread §1.3 — this is the snippet that matters most this week.

### Snippet C — the trap

```cpp
void setup() {
  Serial.begin(9600);

  int waitMs = 20000;
  waitMs = waitMs + 20000;

  Serial.println(waitMs);
}

void loop() {
}
```
> **Q:** What prints? (It is not 40000, and §1.4 tells you why.) Then the follow-up: if the next line were `delay(waitMs);`, roughly how long would the board sit there? Guess an order of magnitude — seconds, minutes, days?

### Snippet D — find the errors

There are **four** things wrong here. Find all four, and for each one say **what the compiler will print**.

```cpp
const int PIN_RED = 8;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  PIN_RED = 9;
}

void loop() {
  digitalWrite(pin_red, HIGH);
  delay(onTimeMs);
  digitalWrite(PIN_RED, LOW)
  delay(onTimeMs);
}
```

> **Q:** Unlike Week 0's snippet D, **every one of these is caught at compile time.** None of them can reach the board. Notice how that feels compared to the `pinMode` bug in Week 0 that compiled fine and silently did nothing — that contrast is the real lesson of this snippet.

---

## Answers A–D — Reviewed after the guided exercises

These answers were reviewed after doing the exercises. They are not a record of predictions made before running them.

**A:** 750 appears once each time the board starts or resets. The sum is 500 + 250, and the print is inside setup(), which runs once.

**B:** 9 prints first, then 5. `int b = a;` copies the value 5 into b. Changing a later does not change b.

**C:** In the exercise 3 test on this UNO, the output was -25536. The sum 40000 is too large for int on this board. Passing that negative value to delay() converted it to 4294941760 ms, about 49.7 days. This is the observed result of that experiment, not a safe general rule for signed overflow.

**D:** Four problems:

- `PIN_RED = 9;` tries to change a constant. Expected diagnostic: `assignment of read-only variable 'PIN_RED'`.
- `pin_red` does not match `PIN_RED`. Expected diagnostic: `'pin_red' was not declared in this scope`.
- `onTimeMs` was never declared. Expected diagnostic: `'onTimeMs' was not declared in this scope`. Both delay calls use that missing name.
- `digitalWrite(PIN_RED, LOW)` is missing its final semicolon. Expected diagnostic: `expected ';' before 'delay'`.

The D messages are expected diagnostic wording, not a captured compilation of this snippet. A compiler may report them in a different order or use slightly different wording. Fix the first error and compile again.

---

# Step 3 · WIRE

**~15 minutes.**

→ **Full instructions: [`wiring.md`](wiring.md)**

Three LEDs — red on **8**, yellow on **9**, green on **10** — stacked top to bottom like a traffic light. You keep this circuit for all of Phase 1.

> ⚠️ **Unplug the USB cable before you change any wiring.** Every time.

---

# Step 4 · GUIDED EXERCISES

**~90 minutes. Five exercises. Each builds on the last.**

Open each folder's `.ino` file in the Arduino IDE — the spec and hints are in the comments at the top.

> **Rule 1 still applies: type every line.** Yes, even the parts you're copying from your own Week 0 files.

### Exercise 1 — Your first variable
📁 [`exercise-1-first-variable/`](exercise-1-first-variable/)

Take the Week 0 blink and replace the two `1000`s with a named variable. The board does exactly the same thing; the file reads completely differently.

**The point:** you've changed nothing about the behaviour and everything about the code. That distinction — *the program is not the same thing as what the program does* — is most of software engineering.

---

### Exercise 2 — Name the pins
📁 [`exercise-2-name-the-pins/`](exercise-2-name-the-pins/)

Introduce `const int PIN_RED`, `PIN_YELLOW`, `PIN_GREEN`. No bare pin number anywhere below the declarations.

Then the payoff: **move the program to a different LED by editing one line.**

**The point:** a name is an indirection, and indirection is what lets you change one thing in one place. This is the first time you'll feel it.

---

### Exercise 3 — Types, and where they break
📁 [`exercise-3-types/`](exercise-3-types/)

A short tour: `int`, `unsigned long`, `bool`, `byte`. Then you overflow an `int` deliberately, watch it produce a confident wrong answer, and fix it with the right type.

**The point:** types are not bureaucracy. Picking the wrong one is a bug that compiles cleanly and lies to you.

---

### Exercise 4 — One knob
📁 [`exercise-4-one-knob/`](exercise-4-one-knob/)

Build a three-LED sequence where **every duration is derived from a single constant.** Change that one number, and the whole pattern speeds up or slows down in proportion.

**The point:** this is the exercise of the week. A well-chosen constant is a control surface — you're deciding what someone is allowed to tune without understanding your code.

---

### Exercise 5 — Print the values
📁 [`exercise-5-print-the-values/`](exercise-5-print-the-values/)

Serial output that prints **variables**, not just text. `Serial.print("on: "); Serial.println(onTimeMs);`

**The point:** Rule 9 starts here. From this week on, when something is wrong you print the value and *look*. You do not guess, and you do not stare at the code hoping.

---

# Step 5 · DRILLS

**~60 minutes. Ten short specs, ~5 minutes each. Same circuit throughout.**

Speed reps. Don't polish. The goal is that declaring and naming a value stops requiring thought.

**House rule for every drill below: no bare numbers below the declarations.** Pins and durations are named, always. That constraint is the drill.

| # | Spec |
|---|---|
| 1 | All three LEDs blink together. A single `const int` sets the rate — changing it changes everything |
| 2 | Red on twice as long as green. Two constants, and the second is **derived from the first** (`GREEN_MS = RED_MS / 2`) — not typed independently |
| 3 | In `setup()`, print each LED's name and its pin number, using the constants. Then never mention a raw pin number again |
| 4 | Hold a `bool` and pass it straight to `digitalWrite(PIN_RED, isOn)`. Prove to yourself that `true`/`HIGH` and `false`/`LOW` are the same thing to the machine |
| 5 | Red → yellow → green, one after another. All three durations come from one `UNIT_MS` (×1, ×2, ×3) |
| 6 | **Morse SOS on the red LED again** — but now with `DOT_MS`, `DASH_MS`, `SYMBOL_GAP_MS`, `LETTER_GAP_MS`. Open your Week 0 version side by side and compare them |
| 7 | Count down `5 4 3 2 1` on Serial from an `int` you decrement with `count = count - 1;`. Then flash all three LEDs |
| 8 | Add up the durations of one full cycle into an `unsigned long` and print it once per cycle. Check the number against a stopwatch |
| 9 | Deliberately store `40000` in an `int` and print it. Write down what you get. Then change the type and print it again |
| 10 | Any rhythm you like — with a hard limit of **three** named constants for the entire program |

Drill 6 is the one to take seriously. It is a direct re-solve of Week 0's drill 5 with this week's tools, and the two files next to each other are the clearest evidence you'll get that the week worked. *(Rule 6.)*

---

### Drill results

The student confirmed drills 1–10 on the UNO. Drill 1 was also tested at BLINK_MS = 250 and blinked twice as fast. Drill 8 printed `Cycle delays: 6000 ms`; the student confirmed the stopwatch check of approximately six seconds. Drill 9's expected outputs were confirmed and its final sketch keeps unsigned long. No compiler warning text was supplied.


# Step 6 · CHALLENGE

**~60 minutes. No hints. You will get stuck. That is the exercise.**

📁 [`challenge/`](challenge/)

## Traffic Light

A real traffic light, on your three LEDs, cycling forever:

| Phase | Red | Yellow | Green | Duration |
|---|---|---|---|---|
| **GO** | off | off | **on** | `GREEN_MS` |
| **CAUTION** | off | **on** | off | `YELLOW_MS` |
| **STOP** | **on** | off | off | `RED_MS` |

Then back to GO.

### Constraints

1. **Write the spec on paper first.** Every phase, every duration, in order. *(Rule 2.)*
2. **Exactly one LED is lit at any instant.** Never two, never zero.
3. **Not one bare number below the constants block.** Every pin and every duration is a name. `HIGH`, `LOW` and `OUTPUT` are already names, so they're fine.
4. **`YELLOW_MS` and `RED_MS` must be derived from `GREEN_MS`**, not typed independently. Pick sensible ratios.
5. **Serial announces each phase and prints its duration** — using the variable, so the printout is evidence the constant really drives the delay.
6. **Once per cycle, print how long ten full cycles would take**, in an `unsigned long`. Think carefully about the type before you write it. *(§1.4 armed you for this.)*
7. Use only what you know: the five Week 0 commands, plus variables, `const`, types, and arithmetic. **No loops, no `if`, no functions of your own.**

### The acceptance test

> **Make the entire light run twice as fast by changing one number.**

If that takes more than a single edit, you haven't finished the challenge — you've written Week 0 code with better spelling. Go back and find what's still hard-coded.

### And then, the actual lesson

Look at your `loop()`. You killed every magic number. Good — that's real.

Now count how many times you typed `digitalWrite`. Still nine. You still wrote the same three-line shape three times, changing only which pin.

**Write that down in your journal.** Naming values fixed one problem completely and the other one not at all. Week 2 is the other one.

---

# Step 7 · JOURNAL

**~15 minutes. Non-negotiable.**

Open [`JOURNAL.md`](../../JOURNAL.md) and write the Week 1 entry. Four prompts, plus one specific to this week:

> **Name one variable you renamed after writing it. What was wrong with the first name, and what did you have to learn about the program before you could see that?**

Then commit:

```bash
git add -A
git commit -m "Week 1: variables, types, constants — traffic light"
```

---

# Troubleshooting

### `'onTimeMs' was not declared in this scope`

You used a variable the compiler can't see from there. Three causes, in order:

1. **Spelling or case.** `onTimeMs` ≠ `ontimeMs` ≠ `OnTimeMs`. Still roughly one in five errors.
2. **Declared inside a different block.** A variable declared in `setup()` does not exist in `loop()`. Move the declaration above `setup()`.
3. **Declared below where you used it.** The compiler reads top to bottom; a name has to exist before it's mentioned.

### `assignment of read-only variable 'PIN_RED'`

You wrote to a `const`. Either you meant to read it and typed `=` instead of using it, or it shouldn't have been `const` in the first place. Nine times out of ten it's the first.

### The LED blinks at completely the wrong speed

Print the variable. Don't stare at the code — `Serial.println(onTimeMs);` right before the `delay()`, and look at what it actually holds. *(Rule 9. Start as you mean to go on.)*

If the printed number looks fine but the timing doesn't, check you're passing the variable you think: `delay(onTimeMs)` vs `delay(offTimeMs)` is a one-character-class mistake that reads perfectly.

### A duration prints as a negative number

You overflowed an `int`. See §1.4. Change the type to `unsigned long` — and check every intermediate step, not just the final variable: if you add two `int`s together the addition itself wraps, *before* the result is stored anywhere.

### The board freezes for what feels like forever

You almost certainly passed a negative number to `delay()`. It takes an `unsigned long`, so a negative `int` is reinterpreted as an enormous positive one — `-25536` becomes about **50 days**. Press reset, then go find the overflow.

### It compiled before I added variables and now it doesn't

Read the **first** error only. Everything after it is usually wreckage. Fix the top one, recompile, look again.

---

# Done checklist

- [ ] Original dry-run method: snippets A–D on paper before execution. Answers are recorded above, but were reviewed after the guided exercises; this requirement cannot be claimed retroactively.
- [x] Yellow LED wired on pin 9, green moved to pin 10, all three light
- [x] Exercise 1 — blink driven by a named variable
- [x] Exercise 2 — all three pins named; swapping red and green required changing two pin declarations, and the sequence was tested.
- [x] Exercise 3 — `int` overflow observed and fixed, recorded in `reference/mistakes.md`
- [x] Exercise 4 — every duration derived from one constant
- [x] Exercise 5 — Serial printing values, not just text
- [x] Drills 1–10 tested on the UNO.
- [ ] Compare drill 6 with Week 0 SOS.
- [ ] Challenge fully meets every original constraint. The sequence and speed test passed; the plan is recorded in the sketch. Paper-first completion is not verified, and separate digitalWrite calls cannot meet the literal zero-gap rule.
- [x] Challenge passes the acceptance test: twice as fast in **one** edit
- [ ] `reference/cheatsheet-cpp.md` Week 1 section reviewed — you can explain every entry out loud
- [x] `reference/cheatsheet-wiring.md` updated with the three-LED circuit
- [x] Journal entry written, including the renaming question
- [ ] Everything committed to git

---

## Final review before the PR

- Exercise 1 names were clarified to redOnMs and redOffMs without changing its durations or instructions.
- Confirmed UNO tests and supplied Serial output are recorded; intentional failures have been removed from final executable sketches. The drill 9 comparison is retained in comments, with only the corrected unsigned long version active.
- The Week 0 challenge comparison is complete: 42 numeric pin references versus 2 Week 1 constant changes. Week 0 files were not edited.
- Still required: the student's spoken review of the Week 1 C++ reference, teacher review of the exceptions above, and commit/PR creation.
- The current branch does not yet include the three Week 0 commits present in the locally known origin/main. Preserve the current work before integrating those changes. Leave PR merge to the teacher's approval.

**Next:** Week 2 — Loops. Where you stop typing the same three lines over and over, and the Week 0 challenge becomes about nine lines long.
