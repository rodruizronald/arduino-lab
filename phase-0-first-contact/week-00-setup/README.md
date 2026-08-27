# Week 0 — First Contact

> **Phase 0** · Setup, first blink, first Serial print
> **Time:** ~5 hours of work, plus however long the install takes
> **New concepts:** the compile→upload→run cycle · statements · function calls · comments · syntax vs logic errors

---

## What you need on the desk

| Item | How many | Notes |
|---|---|---|
| UNO board + USB cable | 1 | |
| 400-point breadboard | 1 | The big one |
| LEDs | 2 | Pick two different colours — red and green are easiest to tell apart |
| Resistors | 2 | 200Ω or 330Ω. Either works. See [`wiring.md`](wiring.md) if you can't tell them apart |
| Jumper wires | ~5 | |

Leave the rest of the kit in the box. You won't need it for weeks, and an open box of 40 components is a distraction, not a resource.

---

# Step 1 · CONCEPT

**~30 minutes. Read this with the box closed. No computer, no board.**

## 1.1 What a program actually is

A program is a list of instructions. The computer reads them **one at a time, top to bottom**, and does **exactly** what each one says.

That's it. That's the whole model. There is no intelligence in there. No interpretation. No guessing what you meant.

This sounds obvious and it is the source of nearly every bug you will ever write. When your program misbehaves, the useful question is never *"why is it broken?"* — it's **"what did I actually tell it to do?"** Those are different questions and only the second one has an answer.

You are not going to argue with the machine. You are going to read your own instructions back, honestly, until you find the one that doesn't say what you thought it said.

## 1.2 The Arduino's mandatory shape

Every Arduino program contains exactly two functions. They are not optional and they are not negotiable.

```
   power on / reset / upload finishes
              │
              ▼
        ┌───────────┐
        │  setup()  │   runs exactly ONCE
        └─────┬─────┘
              │
              ▼
    ┌──►┌───────────┐
    │   │  loop()   │   runs top to bottom...
    │   └─────┬─────┘
    │         │
    └─────────┘        ...then immediately starts again. Forever.
                       Until you cut the power.
```

**`setup()`** is for things that happen once: announcing which pins you'll use, opening the connection to your computer. Housekeeping.

**`loop()`** is the actual behaviour. It runs, ends, and instantly runs again — thousands of times per second if you let it. There is no "end" to an Arduino program. It stops when the electricity stops.

> **Why two?** Because "do this once" and "do this forever" are genuinely different jobs, and separating them is the first piece of program *structure* you'll meet. You'll see this pattern — initialise, then repeat — for the rest of your life as a programmer.

## 1.3 Anatomy of a statement

A **statement** is one instruction. Here's one:

```cpp
digitalWrite(8, HIGH);
```

Read it in three pieces:

| Piece | Name | Meaning |
|---|---|---|
| `digitalWrite` | the **function name** | *what to do* |
| `(8, HIGH)` | the **arguments** | *the details* — which pin, and what to do to it |
| `;` | the **semicolon** | *end of instruction* — the full stop |

Compare to English: **`pour`**`(`**`coffee`**`,` **`200ml`**`)`**`;`** — verb, details, period.

Calling a function means: *"somebody already wrote the code to do this thing. Do it, with these details."* You don't need to know how `digitalWrite` works internally. You need to know what it does and what to hand it. That's not laziness — that's the entire foundation of how software gets built.

### Braces group things

```cpp
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}
```

The `{` and `}` mark **a block** — "all of these statements belong to `setup`." Every `{` must have a matching `}`. The indentation inside is purely for humans; the computer ignores it completely. Do it anyway, always. Code you can't visually scan is code you can't debug.

> `void` in `void setup()` means "this function hands nothing back when it's finished." You'll unpack that properly in **Week 3**. For now, read it as noise that has to be there.

### Comments are for you

```cpp
// Everything after two slashes on this line is ignored by the computer.

/* This form
   spans multiple lines. */
```

Comments are invisible to the machine. They exist for one reader: **you, in three months, with no memory of writing this.** Write them for that person.

The rule that matters: comment **why**, not **what**. `delay(1000); // wait 1000ms` is worthless — the code already says that. `delay(1000); // give the sensor time to settle` earns its place.

## 1.4 The five commands you learn this week

That's all of them. Five.

| Command | What it does |
|---|---|
| `pinMode(pin, OUTPUT)` | Announce that this pin will **send** signals out, rather than read them in. Do this once, in `setup()`. |
| `digitalWrite(pin, HIGH)` | Turn the pin **on** (5 volts). Current flows. The LED lights. |
| `digitalWrite(pin, LOW)` | Turn the pin **off** (0 volts). Dark. |
| `delay(ms)` | Freeze. Do **nothing at all** for this many milliseconds. `1000` = one second. |
| `Serial.begin(9600)` + `Serial.println("...")` | Open a text channel to your computer over the USB cable, then send it a line of text. |

Two notes you should absorb now rather than later:

> **`delay()` is not "waiting while doing other things."** It is a total freeze of the entire program. Nothing else can happen. It's the right tool for exactly one week — this one — and by **Week 7** you'll replace it permanently. Enjoy it while it lasts.

> **`Serial.println` is your only debugger.** Professional programmers have step-through debuggers, breakpoints, watch windows. You have a text channel and a cable. It is enough — printing values to see what your program actually believes is a technique you will still be using twenty years from now. Start the habit today.

The `.` in `Serial.println` means "`Serial` is a *thing*, and `println` is something that thing can do." That's an object. **Week 19** is where you build your own. Ignore it for now.

## 1.5 The cycle: compile → upload → run

```
   you type text            ✓ Verify button          → Upload button
        │                         │                         │
        ▼                         ▼                         ▼
  ┌───────────┐   compile   ┌───────────┐   upload   ┌────────────┐
  │  .ino     │ ──────────► │  machine  │ ──────────►│  the chip  │
  │  (text)   │             │   code    │  over USB  │  runs it   │
  └───────────┘             └───────────┘            └────────────┘
        ▲                         │
        │      grammar broken?    │
        └─────────────────────────┘
              error printed, nothing reaches the board
```

1. **You write text.** A `.ino` file is just text. Nothing more.
2. **Compile.** The IDE translates your text into instructions the chip physically understands. If your text breaks the grammar rules, it **refuses**, prints an error, and nothing reaches the board.
3. **Upload.** Compile, then push the result down the cable onto the chip.
4. **Run.** The board starts immediately and never stops. Unplug it from your laptop, plug it into a battery — **it still runs**. Your program lives on the chip now, not on your computer. That's worth pausing on: you just moved software into an object.

## 1.6 Two kinds of wrong

This distinction will save you months.

| | **Syntax error** | **Logic error** |
|---|---|---|
| What happened | You broke the grammar | Your grammar is perfect, the program does the wrong thing |
| Examples | Missing `;`, unmatched `{`, `Delay` instead of `delay` | LED blinks twice as fast as you wanted |
| Who catches it | The compiler, instantly, for free | Only you |
| Cost | Seconds | Hours |

Beginners fear syntax errors. **Invert that.** A syntax error is the machine doing free work for you — it found a mistake and told you roughly where. A logic error is the machine cheerfully executing your misunderstanding. The second kind is the actual job of programming.

> **C++ is case-sensitive.** `delay`, `Delay`, and `DELAY` are three different words, and only one of them exists. Roughly one in five beginner errors is a capital letter.

---

# Step 2 · DRY RUN

**~20 minutes. Paper and pen. No computer. Do not skip this.**

For each snippet: write down **what you think the LED does**, in a full sentence, before reading the next one. You'll check your answers after Exercise 1.

### Snippet A

```cpp
void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
}
```
> **Q:** What does the LED do? And what is `loop()` doing here — is it running at all?

### Snippet B

```cpp
void loop() {
  digitalWrite(8, HIGH);
  digitalWrite(8, LOW);
  delay(1000);
}
```
> **Q:** What will you actually *see*? Be careful — this one is a trap, and the trap is the lesson.

### Snippet C

```cpp
void loop() {
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(900);
}
```
> **Q:** How long is one full cycle? What fraction of the time is the LED lit? Describe the visual effect in words.

### Snippet D — find the errors

There are **three** things wrong here. Two are syntax, one is a capital letter. Circle them.

```cpp
void setup() {
  pinMode(8, OUTPUT)
}

void loop{
  digitalWrite(8, HIGH);
  Delay(500);
  digitalWrite(8, LOW);
  delay(500);
}
```

> **Q:** For each one — will the compiler catch it, or will it slip through?

---

# Step 3 · WIRE

**~15 minutes.**

→ **Full instructions: [`wiring.md`](wiring.md)**

You'll build one circuit and use it for the whole week: **two LEDs, on pins 8 and 9.**

> ⚠️ **Unplug the USB cable before you change any wiring.** Every single time. Build the habit now, while nothing is at stake.

---

# Step 4 · GUIDED EXERCISES

**~90 minutes. Five exercises. Each builds on the last.**

Open each folder's `.ino` file in the Arduino IDE — the spec and hints are in the comments at the top.

> **Rule 1 applies: type every line.** Do not copy-paste, not even from this file. Your fingers are part of your memory, and the muscle memory for `void setup() {` is worth more right now than understanding it.

### Exercise 1 — Prove the chain works
📁 [`exercise-1-blink-builtin/`](exercise-1-blink-builtin/)

No wiring at all. The board has an LED soldered onto it, wired to pin 13, and it has a name: `LED_BUILTIN`. Use it to prove your computer can reach the board before you introduce any wiring you could have got wrong.

Here is the reference program. **Type it. Don't paste it.**

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

Line by line:

| Line | What it's doing |
|---|---|
| `void setup() {` | Start of the run-once block |
| `pinMode(LED_BUILTIN, OUTPUT);` | "Pin 13 is going to send signals out" |
| `}` | End of the run-once block |
| `void loop() {` | Start of the run-forever block |
| `digitalWrite(LED_BUILTIN, HIGH);` | Light on |
| `delay(1000);` | Freeze for one second |
| `digitalWrite(LED_BUILTIN, LOW);` | Light off |
| `delay(1000);` | Freeze for one second |
| `}` | End of the block — and straight back to the top |

**Then go check your Dry Run answers for snippets A, B and C.** Run them if you're not sure. Being wrong here costs nothing and teaches a lot.

**🔨 Break it — the full tour.** This is the most valuable 15 minutes of the week. Make each of these changes **one at a time**, hit Verify, and write down **the exact error message** in [`reference/mistakes.md`](../../reference/mistakes.md):

1. Delete the `;` after the first `delay(1000)`
2. Delete the final `}`
3. Change `delay` to `Delay`
4. Change `digitalWrite` to `digitalwrite`
5. Delete the whole `pinMode` line — **this one compiles fine.** Upload it. What happens? Which of the two kinds of wrong is this?

Number 5 is the point of the exercise.

---

### Exercise 2 — Change the rhythm
📁 [`exercise-2-rhythm/`](exercise-2-rhythm/)

Same built-in LED, three different rhythms. Only the numbers change.

1. A fast blink — on and off ten times per second
2. A slow blink — two seconds on, two seconds off
3. Asymmetric — a short flash, then a long dark pause (like a smoke detector)

**The point:** you're proving to yourself that the numbers in the code map directly onto something you can see. This is the feedback loop that makes the next nine months work.

---

### Exercise 3 — Your own LED
📁 [`exercise-3-your-own-led/`](exercise-3-your-own-led/)

Move the program off the board's built-in LED and onto the red LED you wired to **pin 8**.

Exactly two things change. Find them yourself before you look at the hint in the file.

**The point:** `LED_BUILTIN` was training wheels — it's just the number 13 with a friendly name. Pins are numbers, and you choose them.

**🔨 Break it:** change `pinMode(8, OUTPUT)` to `pinMode(9, OUTPUT)` but leave the `digitalWrite` calls on pin 8. Predict the result *before* uploading.

---

### Exercise 4 — Two LEDs, alternating
📁 [`exercise-4-two-leds/`](exercise-4-two-leds/)

Both LEDs. They alternate — when red is on, green is off, and vice versa. **They must never both be on at the same time, and never both off.**

Write the sequence on paper first. There is more than one correct answer and at least one very tempting wrong one.

**The point:** this is your first taste of *ordering as a design decision*. The statements are trivial; which order you put them in is the whole exercise.

**🔨 Break it:** swap two adjacent lines. Which swaps change the behaviour, and which don't? Why?

---

### Exercise 5 — Make it talk
📁 [`exercise-5-make-it-talk/`](exercise-5-make-it-talk/)

Add Serial output so the program narrates itself. You'll need two new things:

```cpp
Serial.begin(9600);          // in setup(), once
Serial.println("RED ON");    // wherever you want to announce something
```

Then open **Tools → Serial Monitor** and set the dropdown at the bottom right to **9600 baud**. (If you see gibberish like `⸮⸮x⸮`, that dropdown is wrong. It's always that dropdown.)

Make the program print what it's doing, in step with the LEDs.

**The point:** you now have a window into your program's mind. Right now the LEDs already tell you what's happening, so this feels redundant — that's fine. From **Week 5** onward, when the state lives in variables you can't see, this is the *only* thing standing between you and guessing.

**🔨 Break it:** delete the `Serial.begin(9600)` line but keep the `println` calls. It compiles. What do you get? Why?

---

# Step 5 · DRILLS

**~60 minutes. Ten short specs, ~5 minutes each. Same circuit throughout.**

Speed reps. Don't polish, don't over-think — get it working, watch it, move on. The goal is fluency: `void loop() {` should stop requiring thought by the end of this.

| # | Spec |
|---|---|
| 1 | Both LEDs on, solid, forever |
| 2 | Both blink together, half a second on, half a second off |
| 3 | Alternating at 250 ms |
| 4 | Red blinks twice, then green blinks once, repeat |
| 5 | **Morse SOS on the red LED:** `· · ·` `— — —` `· · ·` then a long pause. Short = 200 ms, long = 600 ms, gap between symbols = 200 ms, gap between letters = 600 ms |
| 6 | Heartbeat — two quick flashes, then a long pause |
| 7 | Police lights — rapid alternation for 2 seconds, then 1 second of darkness |
| 8 | Red on → both on → green on → both off, one second each |
| 9 | Count down `5 4 3 2 1` on the Serial Monitor, one second apart, then flash both LEDs three times |
| 10 | A rhythm from a song you like. Yes, really. Get it close enough to recognise |

Drill 5 is the real one. Do it on paper first — write out the full sequence of on/off/duration before you type anything. It is the first genuinely *logical* problem in this plan.

---

# Step 6 · CHALLENGE

**~60 minutes. No hints. You will get stuck. That is the exercise.**

📁 [`challenge/`](challenge/)

## Machine Status Indicator

Build the status light for an imaginary machine. It cycles endlessly through three states:

| State | Red LED | Green LED | Serial announces |
|---|---|---|---|
| **BOOTING** | flashes together with green, 5 times, 150 ms on / 150 ms off | ″ | `BOOTING...` when it starts |
| **RUNNING** | off | 3 slow pulses — 1 s on, 1 s off | `RUNNING` when it starts |
| **ERROR** | 3 quick flashes (100 ms), pause 500 ms — the whole group twice | off | `ERROR` when it starts |

Then back to BOOTING. Forever.

### Constraints

1. **Write the full spec on paper first**, in plain language, before touching the keyboard. Every state, every duration, in order. *(Rule 2.)*
2. Use **only** what this week introduced. No loops, no variables, no functions of your own — you haven't learned them. Five commands and that's it.
3. It must be readable. Blank lines between states, a comment naming each state.

### And then, the actual lesson

Count the lines in your `loop()`. Count how many times you typed `digitalWrite`. Notice how you felt around the third time you typed the same four lines again.

**Write that feeling down in your journal.**

That feeling has a name — it's the thing every language feature you'll learn for the next two months exists to kill. `for` loops in **Week 2**. Functions in **Week 3**. Arrays in **Week 4**. Each one will feel like relief, and it'll only feel like relief because you did this the hard way first.

If the challenge wasn't tedious, you cheated. Go back.

---

# Step 7 · JOURNAL

**~15 minutes. Non-negotiable.**

Open [`JOURNAL.md`](../../JOURNAL.md) and write the Week 0 entry. The template is there. Four things:

- **What I built** — one or two sentences
- **What confused me** — be specific and be honest; "everything" is not an answer, "I don't understand why `void` is there" is
- **What broke, and why** — the actual cause, not "it didn't work"
- **What I understand now that I didn't on Monday** — this is the important one

Then commit everything:

```bash
git add -A
git commit -m "Week 0: first contact — blink, two LEDs, serial output"
```

Yes, including the broken sketches. *(Rule: everything gets committed.)*

---

# Troubleshooting

Work down the list. Roughly ordered by how often it's the answer.

### The board doesn't appear under Tools → Port

- **You have a cheap "generic" UNO,** which almost certainly uses a **CH340** USB chip instead of the official one. Recent macOS versions usually include the driver, but not always. Check the Port menu: if the only entries are Bluetooth-related, you need it — search **"CH340 driver macOS"** and install, then reboot.
- **The cable is charge-only.** Very common with spare micro/USB cables. Try a different one. If the board's power LED lights but no port appears, this is a strong suspect.
- Quit and reopen the Arduino IDE after plugging the board in.

### Upload fails with `avrdude: stk500_recv(): programmer is not responding`

- Wrong port selected — **Tools → Port**, pick the one that isn't Bluetooth
- Wrong board selected — **Tools → Board → Arduino AVR Boards → Arduino Uno**
- The **Serial Monitor is holding the port open** — close it and retry
- Something is plugged into pins **0 or 1**. Those are the USB pins. Never use them. (You won't in this plan.)

### It compiles and uploads, but the LED doesn't light

Nine times out of ten it's one of these three:

1. **The LED is backwards.** Long leg (anode) toward the resistor and the pin; short leg (cathode) toward GND. Flip it and try again — an LED wired backwards is not damaged, just silent.
2. **No ground connection.** The `−` rail of the breadboard must have a wire running to a `GND` pin on the Arduino. This is the single most common wiring mistake in existence.
3. **The legs aren't in the columns you think.** Same column = connected. Different column = not connected, no matter how close together they look. Count the holes.

Also check: the resistor is actually in the circuit (not bridging the same column to itself), and you're driving the pin you wired.

### The Serial Monitor shows garbage like `⸮⸮x⸮`

The baud rate dropdown at the bottom right doesn't match your `Serial.begin(9600)`. Set it to **9600**. It is always this.

### The Serial Monitor is blank

- No `Serial.begin(9600)` in `setup()`
- Using `Serial.print` (no newline) instead of `Serial.println`
- Everything is in `setup()` and already finished — press the reset button on the board

### The error message is 40 lines of nonsense

Read **the first error only**. Everything after it is usually wreckage caused by the first one. Fix the top one, recompile, look again. Repeat.

---

# Done checklist

- [ ] IDE installed, board appears under Tools → Port
- [ ] Dry run: snippets A–D answered on paper *before* running them
- [ ] Exercise 1 — built-in LED blinks; all five deliberate breakages recorded in `reference/mistakes.md`
- [ ] Exercise 2 — three rhythms
- [ ] Exercise 3 — your own LED on pin 8
- [ ] Exercise 4 — two LEDs alternating, never both on
- [ ] Exercise 5 — Serial Monitor narrating the program
- [ ] Drills 1–10 (drill 5 planned on paper first)
- [ ] Challenge complete, spec written on paper before any code
- [ ] `reference/cheatsheet-cpp.md` reviewed — you can explain every entry
- [ ] Journal entry written
- [ ] Everything committed to git

---

**Next:** Phase 1, Week 1 — Variables, types, and constants. Where the numbers you've been typing by hand get names.
