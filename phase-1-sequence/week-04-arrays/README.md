# Week 4 — Data, Not Code

> **Phase 1** · Arrays
> **Time:** ~5–6 hours
> **New concepts:** arrays · indexing from zero · `sizeof` to count · iterating a collection · reading past the end · arrays and functions · parallel arrays as tables · a grid in one list · data-driven design · memory

---

## What you need on the desk

| Item | How many | Notes |
|---|---|---|
| UNO board + USB cable | 1 | |
| Breadboard | 1 | The Week 2 row, still standing |
| LEDs | 5 | Blue, red, yellow, green — plus one **white**, new this week |
| Resistors | 5 | 200Ω or 330Ω |
| Jumper wires | ~12 | Two of them black, for ground |

One new LED, on **pin 12**, on the *other* half of the breadboard. See [`wiring.md`](wiring.md).

## Where your work goes

Your work goes in the sketches, in [`dry-run.md`](dry-run.md), in the journal, and in `reference/`. **Don't edit this README** — it's the assignment.

Predictions, break-it observations and the journal must be **in your own words, from your own runs.** If a tool helped you understand something, say what it helped with. A wrong prediction you made yourself is worth more than a correct one you didn't.

---

# Step 1 · CONCEPT

**~40 minutes. Read this with the box closed. No computer, no board.**

## 1.1 The problem: lists pretending to be code

Look at what Week 3 left behind:

- **The row of LEDs** is described by `FIRST_PIN` and `LAST_PIN`, and found by arithmetic: `FIRST_PIN + i`. That only works for consecutive pins, in physical order. An LED on pin 12 can't join without dragging pin 11 along.
- **The show** in `loop()` is a list of calls — `scan(2, 150); chase(FORWARD, 2, 100); …` — which is really a list of *data* (which pattern, how many times, how fast) written as code.
- **Your Week 1 traffic light** is three copies of the same "this LED, for this long" block, one per phase.

Each of these is a **list**. The language has had a way to say "a list" all along, and this week you use it.

## 1.2 What an array is

An array is **a row of numbered boxes, all the same type, under one name.**

```cpp
const byte LED_PINS[] = {7, 8, 9, 10, 12};
```

| Piece | Meaning |
|---|---|
| `const` | the contents never change (Week 1 — same reason as always) |
| `byte` | the type of **every** box. Pin numbers fit in 0–255, so `byte` — one byte each instead of `int`'s two |
| `LED_PINS` | the name of the whole row |
| `[]` | "this is an array". Empty brackets: count the values for me |
| `{7, 8, 9, 10, 12}` | the values, in order |

That's five boxes. Their order is the order you wrote them in — not the order on the breadboard, not numeric order. **The list decides.**

An array's size is fixed when it's declared. You can't add a sixth box while the program runs. (To add one, you edit the list and re-upload — which is the whole point of this week.)

## 1.3 Indexing — and why it starts at zero

You reach one box with its **index** in square brackets:

```cpp
LED_PINS[0]    // 7  — the first
LED_PINS[1]    // 8
LED_PINS[4]    // 12 — the last
```

**The first box is number 0.** The index means *"how many steps from the start"* — the first box is zero steps from the start. So with five boxes, the indexes are **0 to 4**. There is no `LED_PINS[5]`.

This is the promise from Week 2, kept: *start at `0`, use `<`, and the body runs exactly `N` times* — with the counter taking exactly the values `0` to `N − 1`. Those are exactly an array's indexes:

```cpp
for (int i = 0; i < 5; i++) {
  digitalWrite(LED_PINS[i], HIGH);   // i = 0, 1, 2, 3, 4 — every box, none past the end
}
```

The idiom you've typed a hundred times was built for this.

## 1.4 Let the compiler count

That `5` in the loop is a magic number, and a dangerous one: add a sixth LED to the list and forget the `5`, and the new LED is silently ignored.

Let the compiler count instead:

```cpp
const int LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
```

`sizeof` gives a size in **bytes** — you printed it in Week 1, Exercise 3. `sizeof(LED_PINS)` is the whole array; `sizeof(LED_PINS[0])` is one box. Divide, and you get the number of boxes. It's worked out when the program is compiled, so it costs nothing at run time, and it's always right.

> **Rule for this plan:** every array's count comes from `sizeof`. Never type it.

## 1.5 Walking the list

```cpp
for (int i = 0; i < LED_COUNT; i++) {
  digitalWrite(LED_PINS[i], HIGH);
  delay(STEP_MS);
  digitalWrite(LED_PINS[i], LOW);
}
```

Compare with Week 2's chase. The counter is **no longer the pin** — it's the *position in the list*. The pin is whatever's in that box. So:

- Pins can be any numbers: 7, 8, 9, 10, **12**.
- In any order: `{12, 10, 9, 8, 7}` is a backwards chase, with **no code changed**.
- In any quantity: add a pin to the list, and every loop over it includes it automatically.

Naming: the counter is an **index**, so `i` is the conventional name. If you call it something more specific, call it what it is — `led`, `step`, `phase` — not `pin`. The pin is `LED_PINS[led]`.

## 1.6 Off the end — the most dangerous bug in C++

What happens if you read `LED_PINS[5]`?

**Nothing stops you.** C++ doesn't check. There's no error, and usually no warning. The board reads whatever bytes happen to sit in memory just after the array, and hands you that as if it were a pin number.

**Writing** past the end is worse. If an array isn't `const` and you write to `values[5]`, you overwrite whatever lives next door — another variable, possibly one in a completely different part of your program. The symptom shows up somewhere else entirely, later, and looks impossible.

This is Week 2's off-by-one, now with teeth. `i <= LED_COUNT` used to mean one flash too many. Now it means **reading memory that isn't yours.** It has a name in the wider world — a *buffer overflow* — and it's behind a large share of real security holes. You'll meet it by accident this week, on purpose, in a safe place.

> **Defence:** the `i = 0; i < COUNT; i++` idiom, with `COUNT` from `sizeof`, every single time. Trace the **last** lap. Ask: what's the biggest index this loop can produce?

## 1.7 Arrays and functions

You can pass an array to a function — but the function doesn't receive a copy, and it doesn't know the size.

```cpp
void chase(const byte pins[], int count, unsigned long stepMs) {
  for (int i = 0; i < count; i++) {
    // …
  }
}

chase(LED_PINS, LED_COUNT, 150);
chase(CAR_PINS, CAR_COUNT, 400);   // same function, a different list
```

Two surprises, both important:

1. **The function gets the original, not a copy.** That breaks Week 3's rule that parameters are copies. Passing an array hands over *where the array lives*, not its contents. If the parameter weren't `const`, the function could change the caller's array. Put `const` on array parameters unless the function's job is to change the array.
2. **The function can't tell how long the array is.** Inside the function, `sizeof(pins)` is the size of that "where it lives" — **2 bytes** on this board — not the array. So you **always pass the count** as a separate parameter. With warnings on All, the compiler warns if you try `sizeof` on an array parameter. Listen to it.

Why it works like this is Week 17's story. For now: **pass the array and its count, together, every time.**

## 1.8 Parallel arrays: a table

One array is a list. Several arrays **with the same length, read at the same index**, are a table:

```cpp
const byte          STEP_PIN[] = {8,   9,   10,   9};
const unsigned long STEP_MS[]  = {300, 150, 600, 150};
```

Read them by **row**: step 0 is "pin 8 for 300 ms", step 1 is "pin 9 for 150 ms". Each array is a column. The index ties a row together.

| `i` | `STEP_PIN[i]` | `STEP_MS[i]` |
|---|---|---|
| 0 | 8 | 300 |
| 1 | 9 | 150 |
| 2 | 10 | 600 |
| 3 | 9 | 150 |

The danger: **nothing makes the columns stay the same length.** Add a pin and forget its duration, and the last row reads `STEP_MS` past its end (§1.6). Two lists that must stay in step, and nothing to enforce it. Bundling a row's values into one thing is exactly what **Week 17** is for. Until then: count each array with `sizeof`, and **print both counts** in `setup()` so a mismatch is visible.

Text works too, as a recipe for now:

```cpp
const char* STEP_NAME[] = {"red", "yellow", "green", "yellow"};
Serial.println(STEP_NAME[i]);
```

`const char*` is how you write "a piece of fixed text" in C++. The full story of text — and why it's more complicated than it looks — is Week 21.

## 1.9 Data-driven design

Here's the idea the whole phase has been heading toward:

> **Split the program into an *engine* and *data*.** The engine is small and general, and almost never changes. The data says what actually happens, and changes all the time.

A traffic light's engine is three lines: *"for each phase in the table, light that phase's LED, for that phase's time."* The data is the table. Want an all-red safety phase? Add a row. Longer green? Edit one number. A pedestrian phase? Add rows. **The engine never changes.**

That's what *"change behaviour by editing data, not code"* means — and it's the Phase 1 checkpoint's real test. The signs you've got it right:

- Adding a step, a phase, or an LED is an edit to the **data**, not to any function.
- The engine never mentions a specific pin, phase, or pattern — only "the current row".

## 1.10 A grid in one list

Some data is naturally a grid. A **frame** says which LEDs are on at one moment — one value per LED:

```
          blue  red  yellow green white
frame 0:   1     0     0      0     0
frame 1:   0     1     0      0     0
frame 2:   1     1     1      1     1
```

Arrays are one-dimensional, but a grid fits in one by **writing the rows one after another**:

```cpp
const byte FRAMES[] = {
  1, 0, 0, 0, 0,     // frame 0
  0, 1, 0, 0, 0,     // frame 1
  1, 1, 1, 1, 1,     // frame 2
};
```

Then the value for frame `f`, LED `led` is at:

```cpp
FRAMES[f * LED_COUNT + led]
```

Skip `f` whole rows of `LED_COUNT` values, then step `led` along. The number of frames is the total count divided by the row length:

```cpp
const int FRAME_COUNT = sizeof(FRAMES) / sizeof(FRAMES[0]) / LED_COUNT;
```

> **Trace one by hand before you trust it.** Frame 2, LED 3: `2 × 5 + 3 = 13`. Count thirteen boxes in from the start — counting the first as 0 — and check you land on the right one.

A row with a missing value doesn't cause an error — it **shifts everything after it** by one, and every later frame comes out wrong. In **Week 16**, two-dimensional arrays give grids a real shape. Doing it by hand first is how you'll understand what those do.

## 1.11 Memory

The board has **2048 bytes** of memory for variables. Arrays are where that starts to matter:

| | Bytes |
|---|---|
| `byte` array, 100 entries | 100 |
| `int` array, 100 entries | 200 |
| `unsigned long` array, 100 entries | 400 — a fifth of everything |

After every **Verify**, the IDE prints a line like *"Global variables use 412 bytes (20%) of dynamic memory."* **Start reading it.** Pick the smallest type that fits each column: a pin, an on/off value or a small count fits in a `byte`. Durations still need `unsigned long`.

## 1.12 What this week does *not* fix

This is the last week of Phase 1, so here's the whole list.

- **Nothing reacts.** Every program in Phase 1 does the same thing every time. Buttons arrive in **Week 5** — and so does `if`.
- **The parallel arrays can drift apart.** Bundling a row into one thing is **Week 17**.
- **The flat grid can shift.** Real two-dimensional arrays are **Week 16**.
- **`delay()` still freezes everything.** **Week 7** ends it.
- **Bad data can't be rejected.** A show row pointing at a pattern that doesn't exist reads past the end, and nothing can check for it without `if`. **Week 5.**

---

# Step 2 · DRY RUN

**~25 minutes. Paper and pen. No computer.**

Write your predictions in [`dry-run.md`](dry-run.md), in your own words, **before** you open the IDE. Then commit that file on its own:

```bash
git add phase-1-sequence/week-04-arrays/dry-run.md
git commit -m "Week 4: dry run predictions"
```

> **How this is checked:** your PR's **first commit contains only `dry-run.md`**, with predictions in your own words. Worked answers written afterwards, or with help, count as not done. A wrong prediction you made yourself counts in full.

After Exercise 1, run each snippet on the board and fill in "what actually happened." For every array, draw the boxes with their indexes underneath — `[0] [1] [2] …` — and point at them as you trace.

### Snippet A — indexing

```cpp
const int NUMS[] = {4, 8, 15, 16, 23, 42};

void setup() {
  Serial.begin(9600);
  Serial.println(NUMS[0]);
  Serial.println(NUMS[3]);
  Serial.println(NUMS[5]);

  int i = 2;
  Serial.println(NUMS[i + 1]);
  Serial.println(NUMS[NUMS[0]]);
}

void loop() {
}
```
> **Q:** All five numbers. The last one is an index inside an index — work from the inside out.

### Snippet B — counting

```cpp
const int NUMS[] = {4, 8, 15, 16, 23, 42};

void setup() {
  Serial.begin(9600);
  Serial.println(sizeof(NUMS));
  Serial.println(sizeof(NUMS[0]));
  Serial.println(sizeof(NUMS) / sizeof(NUMS[0]));
}
```
> **Q:** All three numbers, *on this board*. (Week 1: how many bytes is an `int` here?) Which of the three would change if `NUMS` were a `long` array — and which wouldn't?

### Snippet C — backwards

```cpp
const int NUMS[] = {4, 8, 15, 16, 23, 42};
const int COUNT = sizeof(NUMS) / sizeof(NUMS[0]);

void setup() {
  Serial.begin(9600);
  for (int i = COUNT - 1; i >= 0; i--) {
    Serial.print(NUMS[i]);
    Serial.print(" ");
  }
  Serial.println();
}
```
> **Q:** What's printed? Then: change `i >= 0` to `i > 0`. Which number disappears, and why that one?

### Snippet D — four problems

```cpp
const int VALUES[] = {10, 20, 30};
const int COUNT = sizeof(VALUES) / sizeof(VALUES[0]);

const byte          STEP_PIN[] = {8, 9, 10};
const unsigned long STEP_MS[]  = {300, 300};

int totals[3] = {0, 0, 0, 0};

void printAll(const int values[]) {
  int count = sizeof(values) / sizeof(values[0]);
  for (int i = 0; i < count; i++) {
    Serial.println(values[i]);
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 1; i <= COUNT; i++) {
    Serial.println(VALUES[i]);
  }
  printAll(VALUES);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(STEP_PIN[i], HIGH);
    delay(STEP_MS[i]);
    digitalWrite(STEP_PIN[i], LOW);
  }
}
```
> **Q:** Find all four. For each one: **compiler error**, **warning** (on All), or **silent**? For the silent ones — what might actually happen on the board?

---

# Step 3 · WIRE

**~15 minutes.**

→ **Full instructions: [`wiring.md`](wiring.md)**

A **white** LED on **pin 12** — deliberately *not* pin 11, and deliberately on the *other* half of the breadboard, out of line with the row. Plus one wire joining the two ground rails.

> ⚠️ **Unplug the USB cable before you change any wiring.** Every time.

---

# Step 4 · GUIDED EXERCISES

**~110 minutes. Five exercises. Each builds on the last.**

### Exercise 1 — Your first array
📁 [`exercise-1-first-array/`](exercise-1-first-array/)

All five LEDs — including pin 12 — in one list, chased with one loop. Then reverse the chase without touching the code.

**The point:** the list decides which LEDs and in what order. Not the breadboard, not arithmetic.

---

### Exercise 2 — Arrays and functions
📁 [`exercise-2-arrays-and-functions/`](exercise-2-arrays-and-functions/)

One `chase(pins, count, stepMs)` function, used with several different lists. Then the two surprises: the function gets the original, not a copy — and it can't tell how long the array is.

**The point:** pass the array and its count together. Every time.

---

### Exercise 3 — Tables
📁 [`exercise-3-tables/`](exercise-3-tables/)

A rhythm as a table — pin and duration for each step, in parallel arrays — and a three-line engine that plays any table you give it.

**The point:** your first engine-and-data split. And your first look at what happens when two columns drift out of step.

---

### Exercise 4 — Frames
📁 [`exercise-4-frames/`](exercise-4-frames/)

A grid in one list: each frame says which of the five LEDs are on. Now two LEDs can be on at once — something a one-pin-per-step table can't say.

**The point:** `f * LED_COUNT + led`. Trace it by hand until it's boring.

---

### Exercise 5 — Re-solve: the Week 1 traffic light, as a table
📁 [`exercise-5-traffic-light-table/`](exercise-5-traffic-light-table/)

Week 1's challenge promised this: *"In Week 4 you will rebuild this exact traffic light, one more time, as a table of phases."* The engine is a few lines. Adding a phase is adding a row.

**The point:** Rule 6 — and a direct rehearsal for the Phase 1 checkpoint.

---

# Step 5 · DRILLS

**~60 minutes. Ten short specs.**

Save each in `drills/drill-NN-name/drill-NN-name.ino`.

**House rules:** every array's count comes from `sizeof`. Every loop over an array is `i = 0; i < COUNT; i++` — or the exact reverse. Arrays go to functions with their count.

| # | Spec |
|---|---|
| 1 | Print every value of an array on one line, then the same values backwards on the next |
| 2 | `unsigned long totalMs(const unsigned long durations[], int count)` — add up a list of durations and return the total |
| 3 | Chase all five LEDs — including pin 12 — with one loop and no arithmetic on pin numbers |
| 4 | Make drill 3's chase run backwards, then in a zig-zag order (for example `7, 10, 8, 12, 9`), **by editing only the array** |
| 5 | Two lists, one function: `blinkAll(pins, count, times)` called once with `WARM_PINS` (red, yellow) and once with `COOL_PINS` (blue, green, white) |
| 6 | Running total: for a list of durations, print each one next to the total so far — `300 300`, `150 450`, `600 1050`… |
| 7 | Copy an array into a second, non-`const` array **in reverse order**, element by element. Print both. Both arrays' sizes must come from the same constant |
| 8 | **SOS, for the fifth and last time — as data.** Two arrays: how long the LED is on for each symbol, and how long it's off after it. A short engine plays them. Then change the message to your initials **by editing only the arrays**. Line up all five versions, Weeks 0–4 |
| 9 | **Frames:** a pattern of your own design, at least 8 frames, where at least one frame lights two or more LEDs at once |
| 10 | **Memory:** a non-`const` array of 100 `unsigned long`s, filled with a loop and summed (so the compiler keeps it). Verify, and write down the "global variables use…" number. Change the type to `int`, then `byte`, and record both again. Do the numbers match §1.11? |

Drill 8 closes the story that started in Week 0's drill 5. Five versions of the same message: written out, named, looped, decomposed, and finally *data*. Keep all five.

Drill 10 is the one most people skip. Don't — after this week, you'll read that memory line after every Verify.

---

# Step 6 · CHALLENGE

**~90 minutes. No hints. You will get stuck. That is the exercise.**

📁 [`challenge/`](challenge/)

## The Show, as Data

Week 3's Light Show again — but now **every pattern is data, and so is the show.**

- **The LEDs** are a list: all five, including pin 12.
- **Every pattern** — scan, chase, blink all, fill — is a run of **frames** in one big frame table (§1.10).
- **The show** is a table: each row says which pattern, how many times, and how fast.
- **The engine** plays the show. It never mentions a specific pin, pattern, or step.

### Constraints

1. **Design the data first, on paper.** Draw the frame table — every frame of every pattern, as rows of 1s and 0s — and the show table, before you type anything. *(Rule 2.)*
2. **The scan has no doubled ends** — same rule as Week 2. It's just frames now.
3. **`loop()` is at most 5 lines.**
4. **No global variables.** Constants and `const` arrays only.
5. **Every count comes from `sizeof`** — LEDs, frames, show rows. Not one typed by hand.
6. **The engine never mentions a pin number, a pattern, or a show row by value.** It only ever works with "the current row" and "the current frame".
7. **Serial announces each show row:** the pattern's **name** and how long it will take, in milliseconds — from a calculator, as in Week 3.
8. **Use only what you know:** Weeks 0–3, plus arrays. **No `if`. No `switch`.**

### The acceptance tests

> **A.** Add a brand-new pattern — say, two lights moving in from both ends and meeting in the middle — and put it in the show. **Only data changes.** No function is edited, and no new function is written.
>
> **B.** Change the order of the show, and play one pattern three times in a row at different speeds. **Only the show table changes.**
>
> **C.** Move the white LED's jumper from pin 12 to pin 11. **One edit.**
>
> **D.** *Think, don't fix:* to add a **sixth** LED, what has to change? Count the edits. Every frame needs one more value — write down why, and what that suggests about this way of storing frames. *(Weeks 15 and 16.)*
>
> **E.** *Think, don't fix:* a show row that names a pattern that doesn't exist — say, pattern 9 when there are 5. What does your engine do? Why can't you stop it yet? *(Week 5.)*

### And then, the actual lesson

Count the lines in your engine — every function that isn't data. Then count the lines of data.

The engine should be small, and you should never need to touch it again. **Everything that makes the show *this* show is in the tables.** That's data-driven design: the behaviour lives in the data, and the code just plays it.

Now look at your Week 3 Light Show. In Week 3, a new pattern meant a new function. Now it means new rows. And look back further — your Week 0 challenge, 73 lines of `digitalWrite` and `delay`. Four weeks, four tools:

```
Week 1  ->  variables   killed magic numbers     <-- done
Week 2  ->  loops       killed repeated blocks   <-- done
Week 3  ->  functions   killed repeated ideas    <-- done
Week 4  ->  arrays      killed repeated data     <-- done
```

That's Phase 1. Next comes the **Phase 1 checkpoint**: a traffic light with a pedestrian phase, where adding a phase means adding a row.

---

# Step 7 · JOURNAL

**~15 minutes. Non-negotiable — and in your own words.**

Add a **Week 4 — Data, Not Code** entry at the **bottom** of [`JOURNAL.md`](../../JOURNAL.md), using the four headings from the template at the top of the file. Plus two for this week:

> **Data or code?** Name one change you made this week by editing only data. What would the same change have cost in Week 3? In Week 0?

> **Phase 1, looking back.** One paragraph: which of the four weeks changed how you think about code the most, and why? Be specific — name a file, a moment, a bug.

Then commit (your dry-run commit should already be there):

```bash
git add -A
git commit -m "Week 4: arrays — tables, frames, and the show as data"
```

---

# Troubleshooting

### A loop over an array prints strange numbers at the end

You read past the end (§1.6). Check the condition is `i < COUNT`, not `i <= COUNT`, and that `COUNT` comes from `sizeof`. Trace the **last** lap: what's the biggest index it can produce?

### A new LED in the list is ignored

The count was typed by hand and not updated. Use `sizeof` (§1.4).

### A function only processes the first value or two of the array

`sizeof` was used on an array *parameter* (§1.7). Inside a function, an array parameter is just "where the array lives" — 2 bytes on this board — so the "count" comes out as 2 for a `byte` array and 1 for an `int` array, whatever the real length. Pass the count in as a parameter.

### `too many initializers` (or "excess elements")

The array was declared with an explicit size — `int totals[3]` — and given more values than that. Use empty brackets and let the compiler count, or fix the size.

### The last step of a table has a wild duration — or the board seems to hang

The parallel arrays have different lengths, and the engine read past the end of the shorter one (§1.8). Print every array's count in `setup()`. They must match.

### Frames come out wrong from some point on, but the first few are fine

A frame has a missing or extra value, and every frame after it has shifted (§1.10). Check the frame count: `sizeof(FRAMES) / sizeof(FRAMES[0])` must be a whole multiple of `LED_COUNT`. Print both numbers.

### The white LED doesn't light

It's on the other half of the board, so it uses the **other** `−` rail. Is that rail joined to the first one with a black wire? See [`wiring.md`](wiring.md), section 2.

### A function changed my array

Arrays are not copied when passed (§1.7). Put `const` on the parameter, and the compiler stops the function changing it.

### "Global variables use" is high

Look at your arrays' types (§1.11). A pin or an on/off value doesn't need more than a `byte`.

---

# Done checklist

- [ ] Dry run: A–D predicted **in my own words** in `dry-run.md`, and **committed on its own as the first commit of the week**
- [ ] Dry run: "what actually happened" filled in **from running them on my board**
- [ ] White LED wired on pin 12, on the other half, with both `−` rails joined
- [ ] Exercise 1 — five LEDs in one array; chase reversed by editing only data
- [ ] Exercise 2 — one function, several lists; the "original, not a copy" and "can't tell its size" surprises both seen on the board
- [ ] Exercise 3 — a table and its engine; a column mismatch observed **on the board** and recorded under **Logic errors**
- [ ] Exercise 4 — frames, including two LEDs lit at once; the shifted-frame bug observed on the board
- [ ] Exercise 5 — the Week 1 traffic light as a phase table; a phase added as one row
- [ ] Drills 1–10 in `drills/` (drill 8 lined up with all four earlier SOS versions)
- [ ] Challenge — frame table and show table drawn on paper first
- [ ] Challenge passes acceptance tests **A**, **B** and **C** on the board; **D** and **E** answered in writing
- [ ] Break-its done **on the board**, with what you actually saw, in `reference/mistakes.md` under the matching section
- [ ] `reference/cheatsheet-cpp.md` Week 4 section reviewed — you can explain every entry out loud
- [ ] `reference/cheatsheet-wiring.md` updated with the white LED and the rail bridge
- [ ] Journal entry, **at the bottom of the file**, in my own words
- [ ] Everything committed to git

---

**Next:** the **Phase 1 checkpoint** — a traffic light with a pedestrian phase, where the whole sequence lives in a table.
