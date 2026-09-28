# Week 2 — Say It Once

> **Phase 1** · Loops
> **Time:** ~5 hours
> **New concepts:** `for` · `while` · loop counters · `++` `--` `+=` · comparison operators (as loop conditions) · nested loops · off-by-one errors · infinite loops

---

## What you need on the desk

| Item | How many | Notes |
|---|---|---|
| UNO board + USB cable | 1 | |
| Breadboard | 1 | The Week 1 circuit, still standing |
| LEDs | 4 | Red, yellow, green — plus one **blue**, new this week |
| Resistors | 4 | 200Ω or 330Ω |
| Jumper wires | ~9 | |

You are adding one LED at the free end of the row. Nothing else moves. See [`wiring.md`](wiring.md).

## Where your work goes

Your work goes in the sketches, in [`dry-run.md`](dry-run.md), in the journal, and in `reference/`. **Don't edit this README** — it's the assignment, and you'll want it intact when you come back to it.

---

# Step 1 · CONCEPT

**~35 minutes. Read this with the box closed. No computer, no board.**

## 1.1 You've been inside a loop since Week 0

`loop()` is a loop. It runs top to bottom, then starts again, forever. You've been writing inside one for two weeks.

What you haven't had is a loop **you control** — one that repeats something a set number of times and then *stops*, so the program can move on to the next thing.

That's the missing piece. Open your Week 0 challenge and look at the BOOTING state: the same six lines, typed five times, identical except for nothing at all. Week 1 gave those numbers names. It didn't stop you typing the block five times. This week does: you write the block **once**, and say how many times.

## 1.2 Anatomy of a `for` loop

```cpp
for (int flash = 0; flash < FLASH_COUNT; flash++) {
  digitalWrite(PIN_RED, HIGH);
  delay(FLASH_MS);
  digitalWrite(PIN_RED, LOW);
  delay(FLASH_MS);
}
```

The header has three parts, separated by semicolons:

| Piece | Name | When it runs |
|---|---|---|
| `int flash = 0` | **init** | **once**, before anything else |
| `flash < FLASH_COUNT` | **condition** | **before every lap**. True → run the body. False → the loop is over |
| `flash++` | **update** | **after every lap** |
| `{ … }` | **body** | once per lap |

In order:

```
   init
    │
    ▼
 condition? ──false──► loop is over; carry on with the next line
    │
   true
    ▼
   body
    │
    ▼
  update ──► back to condition?
```

**`flash++` means `flash = flash + 1`.** It's so common it got its own shorthand. Its relatives:

| Shorthand | Means |
|---|---|
| `i++` | `i = i + 1` |
| `i--` | `i = i - 1` |
| `i += 3` | `i = i + 3` |
| `i -= 3` | `i = i - 3` |

The condition uses a **comparison operator**. You need these six:

| `<` | `<=` | `>` | `>=` | `==` | `!=` |
|---|---|---|---|---|---|
| less than | less or equal | greater than | greater or equal | equal | not equal |

This week they only appear as loop conditions. In **Week 5** they start making decisions. Note that `==` ("are these equal?") and `=` ("copy right into left") are completely different operators that look almost the same. Mixing them up is a Week 5 horror story; for now, just notice the difference.

## 1.3 Trace it — the skill of the week

You can't *watch* a loop run — it's over in microseconds. So you trace it: on paper, one row per lap, before you ever upload.

```cpp
for (int i = 0; i < 3; i++) {
  Serial.println(i);
}
```

| Lap | `i` at the check | `i < 3`? | Body prints | `i` after update |
|---|---|---|---|---|
| 1 | 0 | yes | `0` | 1 |
| 2 | 1 | yes | `1` | 2 |
| 3 | 2 | yes | `2` | 3 |
| — | 3 | **no** | — | loop is over |

Read the table and notice two things:

1. The body ran **three** times, with `i` equal to `0`, `1`, `2`. It never ran with `i` equal to `3`.
2. The condition was checked **four** times — one more than the body ran. The last check is the one that fails.

That second point is the seed of nearly every loop bug you'll write this week.

> **The shortcut:** you almost never need the whole table. **Trace the first lap and the last lap.** The middle laps are nearly never where the bug is. The edges are.

And on the board, the same trace comes from Rule 9: put `Serial.println(i);` inside the loop, and the Monitor *is* your trace table.

## 1.4 Counting from zero

Memorise this shape. It's the most-typed line in all of programming:

```cpp
for (int i = 0; i < N; i++)
```

**Start at `0`, use `<`, and the body runs exactly `N` times.** `i` takes the values `0` to `N − 1`.

You *could* start at `1` and use `<=` — that also runs `N` times. But the `0` and `<` version is the one everybody uses, and in Week 4 you'll see why: arrays number their slots from zero, and this loop fits them exactly.

What you must not do is **mix the two**: start at `0` with `<=`, or start at `1` with `<`. That's how you get a loop that runs `N + 1` times or `N − 1` times — and it compiles and runs without a word of complaint.

> **Not magic numbers:** the `0` a loop starts from and the `1` hidden inside `++` are part of the counting idiom, and they don't need names. Everything else still does — the `N` is a named constant, same as Week 1.

## 1.5 Off-by-one

The old joke: *there are two hard problems in computer science — cache invalidation, naming things, and off-by-one errors.*

It's funny because it's the most common bug there is, and it has a very old form. **You're building a 10-metre fence with a post every metre. How many posts?** Not ten — **eleven**. Ten gaps need eleven posts. Count the gaps when you meant to count the posts, or vice versa, and you're off by one.

You'll meet it this week as:

- A chase where the **last LED never lights**
- A blink that fires **one time too many**
- A bouncing light that **flashes twice at each end** — the classic, and the challenge is built around it

Every one of these compiles, runs, and looks *almost* right. Which is exactly why it survives. Trace the first and last lap.

## 1.6 When the counter means something

In §1.2 the counter was just a count. It doesn't have to be:

```cpp
const int FIRST_PIN = 7;
const int LAST_PIN  = 10;

for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
  digitalWrite(pin, HIGH);
  delay(STEP_MS);
  digitalWrite(pin, LOW);
}
```

Now the counter **is the pin number**. This lights 7, 8, 9, 10 in turn. The colours are gone — the loop doesn't know or care which LED is red. It sees positions.

Notice the `<=`. That breaks the §1.4 idiom on purpose, and the rule behind it is the one that actually matters:

> **Know whether your end is included.**
> - You have a **count** ("do it 5 times") → start at `0`, use `<`. The end is *excluded*.
> - You have the **actual first and last values** ("pins 7 to 10") → use `<=`. The end is *included*.

**Naming the counter.** `i` is fine when it's a pure count and means nothing else — that's a convention every programmer reads instantly. The moment the counter *means* something, name it for what it means: `pin`, `flash`, `sweep`. Week 1's rules still apply.

**The counter only exists inside its loop.** `for (int pin = …)` creates `pin` for that loop alone. After the closing `}` it's gone, and using it gives the Week 1 error you already know: `'pin' was not declared in this scope`. The upside: two loops can each have their own `pin` without interfering.

> **Hold on to this one:** `pin <= LAST_PIN` only works because pins 7, 8, 9, 10 happen to be consecutive numbers. Put an LED on pin 12 and this loop can't reach it without also driving pin 11. That limitation is real, and **Week 4** is where it goes away.

## 1.7 Loops inside loops

A loop's body can contain another loop:

```cpp
for (int row = 0; row < 3; row++) {
  for (int col = 0; col < 4; col++) {
    // runs 3 × 4 = 12 times in total
  }
}
```

The rule: **the inner loop runs all the way through, from scratch, for every single lap of the outer one.** Total laps = outer × inner.

The best picture is a car's odometer. The rightmost wheel spins fastest. Each time it rolls over, the wheel to its left ticks once. That wheel rolls over far less often, and ticks the next one along. **The innermost loop is the rightmost wheel.** In Exercise 3 you'll build one out of LEDs.

## 1.8 `while` — when you know the stop, not the count

```cpp
while (waitMs >= MIN_MS) {
  // blink using waitMs
  waitMs = waitMs - STEP_MS;
}
```

`while` has only a condition. It's checked before every lap, exactly like `for`'s, and the loop ends when it's false.

What `while` does **not** have is an update step. **Nothing in the header changes anything.** If the body doesn't move the variable toward the exit, the condition never becomes false and the loop never ends.

When to use which:

| Use | When you know… | Reads as |
|---|---|---|
| `for` | how many times, or the range to step through | "for each pin from 7 to 10" |
| `while` | the condition to stop on | "keep going as long as the delay is above the minimum" |

Any `for` can be rewritten as a `while` and vice versa — they're the same machine with the parts arranged differently. You'll prove that in Exercise 4. Pick whichever says what you mean.

## 1.9 Loops that never end

A loop whose condition never becomes false runs forever. On this board that looks like:

- An LED stuck on, or stuck blinking at one speed
- The Serial Monitor silent — or scrolling the same thing endlessly
- The rest of the program apparently frozen

**It hasn't crashed.** The chip is running flat out, doing exactly what you told it, over and over. There's no error because nothing went wrong — from the machine's point of view.

The fix is always the same, and it's Rule 9: **print the counter inside the loop.** Within seconds you'll see it stuck, or going the wrong way, or wrapping around.

> **Turn on compiler warnings.** In the Arduino IDE: **File → Preferences → Compiler warnings → All.** The compiler can spot some loops that can never end — but by default the IDE tells it to keep quiet. Warnings aren't errors: the code still compiles and uploads. They're the compiler saying *"this is legal, but are you sure?"* — and in loops, you usually aren't.

`loop()` itself, by the way, is an infinite loop — on purpose. The difference between that and a bug is only whether you meant it.

## 1.10 What this week does *not* fix

Be clear about the limits again, because they set up the next two weeks.

Loops kill **repeated blocks**. When you finish the challenge, you'll notice that the light's journey *out* and its journey *back* are two loops that look almost the same — same body, different direction. That's not a repeated block, it's a **repeated idea**, and loops can't touch it. That's **Week 3**.

And every loop over the LEDs this week leans on the pins being consecutive numbers. That's the set of LEDs baked into arithmetic. **Week 4** takes it out.

---

# Step 2 · DRY RUN

**~25 minutes. Paper and pen. No computer.**

Write your answers in [`dry-run.md`](dry-run.md) — **before** you open the IDE. Then commit that file on its own:

```bash
git add phase-1-sequence/week-02-loops/dry-run.md
git commit -m "Week 2: dry run predictions"
```

The commit's timestamp is the proof you predicted before you ran. *(Rule 3.)* After Exercise 1, come back, run the snippets, and fill in the "what actually happened" half of the file.

For each snippet, draw the trace table (§1.3) if you're not sure.

### Snippet A

```cpp
void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    Serial.println(i);
  }
  Serial.println("done");
}

void loop() {
}
```
> **Q:** Write every line the Serial Monitor shows, in order. How many times is `i < 4` checked?

### Snippet B

```cpp
void setup() {
  Serial.begin(9600);

  for (int i = 1; i < 5; i++) {
    Serial.print("a");
  }
  Serial.println();

  for (int i = 0; i <= 5; i++) {
    Serial.print("b");
  }
  Serial.println();

  for (int i = 10; i > 0; i -= 3) {
    Serial.print(i);
    Serial.print(" ");
  }
  Serial.println();
}
```
> **Q:** How many `a`s? How many `b`s? Which numbers does the third loop print? (`Serial.println()` with nothing in the brackets just ends the line.)

### Snippet C

```cpp
void setup() {
  Serial.begin(9600);

  for (int row = 1; row <= 3; row++) {
    for (int col = 1; col <= row; col++) {
      Serial.print("*");
    }
    Serial.println();
  }
}
```
> **Q:** Draw exactly what appears. How many `*` in total? Look carefully at the inner loop's condition — what's unusual about it?

### Snippet D — three bugs that compile

Week 0's snippet D mixed syntax and logic errors. Week 1's was all compiler errors. This one is the opposite: **every one of these compiles without complaint, and every one is wrong.** Welcome to the expensive kind.

**D1**
```cpp
for (int i = 0; i < 5; i++);
{
  digitalWrite(PIN_RED, HIGH);
  delay(FLASH_MS);
  digitalWrite(PIN_RED, LOW);
  delay(FLASH_MS);
}
```
> **Q:** How many times does the red LED flash? Look at the end of the first line.

**D2**
```cpp
for (byte i = 0; i < 256; i++) {
  Serial.println(i);
}
Serial.println("finished");
```
> **Q:** Does `finished` ever print? (Week 1, §1.4 — what's the biggest number a `byte` can hold?)

**D3**
```cpp
for (unsigned long n = 3; n >= 0; n--) {
  Serial.println(n);
}
Serial.println("liftoff");
```
> **Q:** Does `liftoff` ever print? What's the fifth number on the screen?

---

# Step 3 · WIRE

**~10 minutes.**

→ **Full instructions: [`wiring.md`](wiring.md)**

One new LED — **blue, on pin 7** — at the free end of the row, next to red. The row now reads **blue · red · yellow · green**, which is also pin order: **7 · 8 · 9 · 10**.

> ⚠️ **Unplug the USB cable before you change any wiring.** Every time.

---

# Step 4 · GUIDED EXERCISES

**~100 minutes. Five exercises. Each builds on the last.**

Open each folder's `.ino` file in the Arduino IDE — the spec and hints are in the comments at the top.

### Exercise 1 — Say it once
📁 [`exercise-1-say-it-once/`](exercise-1-say-it-once/)

The red LED flashes five times, then pauses. One `for` loop instead of five copies of the same block.

**The point:** the block is written once and the count is data. Change the count and nothing else moves.

**Then go back to your dry run** and check snippets A–D on the board.

---

### Exercise 2 — The pin is the counter
📁 [`exercise-2-chase/`](exercise-2-chase/)

A light runs along all four LEDs, then back the other way. The loop counter *is* the pin number — including in `setup()`, where four `pinMode` lines become one.

**The point:** the colours disappear. The loop sees positions. And `<=` shows up, for a reason you should be able to say out loud.

---

### Exercise 3 — The odometer
📁 [`exercise-3-odometer/`](exercise-3-odometer/)

The four LEDs count in binary from 0 to 15, using four loops nested inside each other. No knowledge of binary needed — the exercise explains the little you need.

**The point:** this is the clearest picture of nested loops there is. The innermost loop spins fastest; each outer one ticks once per full turn of the one inside it.

---

### Exercise 4 — While
📁 [`exercise-4-while/`](exercise-4-while/)

A blink that starts slow and speeds up, until it hits a minimum, then starts over. Then you rewrite it as a `for` and decide which reads better.

**The point:** `while` is for "until". And Week 1's overflow trap comes back from the other direction — an unsigned number going *below* zero.

---

### Exercise 5 — Re-solve: Week 0's challenge
📁 [`exercise-5-rewrite-week-0/`](exercise-5-rewrite-week-0/)

The Machine Status Indicator from Week 0, again: same spec, same behaviour, rewritten with Week 1's names and this week's loops.

**The point:** Rule 6. Same problem, better tools. Count the lines in `loop()` before and after — that number is the evidence the last two weeks worked.

---

# Step 5 · DRILLS

**~60 minutes. Ten short specs, ~5 minutes each. Same circuit throughout.**

Save each drill as its own sketch in `drills/drill-NN-name/drill-NN-name.ino` (the IDE insists the folder and the file share a name). They get committed with everything else.

**House rules for every drill:** anything repeated is a loop — no copied blocks. Pins, counts and durations are named constants, same as Week 1.

| # | Spec |
|---|---|
| 1 | Red flashes 10 times, fast, then 1 second dark. One `for` |
| 2 | Chase 7 → 10, with `pinMode` done by a loop in `setup()` |
| 3 | Chase 10 → 7 |
| 4 | **Fill and drain:** the LEDs light one at a time and *stay* lit until all four are on, then go dark one at a time in the same order — first on, first off. Two loops |
| 5 | Each LED blinks as many times as its position: blue once, red twice, yellow three times, green four. The inner loop's count is *calculated* from the outer counter |
| 6 | On Serial: `1` to `20` on one line, separated by spaces. Then `20` down to `1`. Then only the even numbers, `2` to `20`, using `+=` |
| 7 | A multiplication table on Serial, `1×1` up to `9×9`, one row per line. Don't bother lining the columns up |
| 8 | **Morse SOS, for the third time** — now each letter's three symbols are a loop. Put your Week 0, Week 1 and Week 2 versions side by side |
| 9 | Add up `1 + 2 + … + 100` in a loop and print the total. Then `1` to `1000`. Check both against the formula `n × (n + 1) / 2`. If they disagree, find out why before moving on |
| 10 | **Police lights:** red and blue alternate rapidly for 2 seconds, then 1 second of darkness. The number of flashes is *computed* from the durations, not typed in |

Drill 8 is the one to keep: one problem, three weeks, three tools, and the three files together show exactly what each week bought you. *(Rule 6, in miniature.)*

Drill 9 has a trap in it. You've been warned about it twice already.

---

# Step 6 · CHALLENGE

**~60–75 minutes. No hints. You will get stuck. That is the exercise.**

📁 [`challenge/`](challenge/)

## Scanner

A single light sweeps back and forth across the LEDs, getting faster with every sweep — like the scanner on the front of a certain 1980s talking car.

| Setting | Name | Start with |
|---|---|---|
| First LED's pin | `FIRST_PIN` | 7 |
| Last LED's pin | `LAST_PIN` | 10 |
| Time each LED stays lit, first sweep | `START_MS` | 200 |
| How much faster each sweep gets | `STEP_MS` | 20 |
| The fastest sweep allowed | `MIN_MS` | 40 |

One **sweep** is there and back: out to `LAST_PIN`, back towards `FIRST_PIN`. When the next sweep would be faster than `MIN_MS`, the whole thing starts over, slow again.

### Constraints

1. **Spec and trace first, on paper.** Write the pin that's lit at every step of the first two sweeps, in order, before you type anything. *(Rules 2 and 3.)*
2. **One LED lit at a time.** (The instant between one turning off and the next turning on doesn't count — you showed in Week 1 that two `digitalWrite` calls can't happen at the same moment.)
3. **No double flash at the ends.** Every LED stays lit for the same time, ends included. The lit sequence must be exactly `7 8 9 10 9 8 7 8 9 10 9 8 7 …` — never `10 10`, never `7 7`.
4. **Each sweep is faster than the one before**, by `STEP_MS`, from `START_MS` down to `MIN_MS`.
5. **Serial announces each sweep** — its number (starting at `1` again each time the scanner restarts) and its step time, read from the variable.
6. **Named constants for every pin and duration.** No bare numbers below the constants block, apart from the counting idiom (§1.4).
7. **Use only what you know:** the Week 0 commands, Week 1's variables and types, and `for` / `while`. **No `if`. No functions of your own. No arrays.**

### The acceptance tests

> **A.** Change `FIRST_PIN` to `8`. The scanner now runs across three LEDs, still with no double flash at either end, and **you changed nothing else**.
>
> **B.** Change `FIRST_PIN` to `9`. Two LEDs: `9 10 9 10 …`, each lit for the same time.
>
> **C.** Put `FIRST_PIN` back to `7` and set `STEP_MS` to `150`. The scanner does two sweeps — at 200 ms, then 50 ms — and starts over. **If it hangs instead, you've met Exercise 4's bug again.** Find a way round it without `if`. (There's more than one.)
>
> **D.** *Think, don't fix:* set `FIRST_PIN` and `LAST_PIN` both to `10`. What does your scanner do? Write down why. Is that acceptable?

If A or B takes more than the one edit, you're not finished — something about the number of LEDs is still hard-coded.

### And then, the actual lesson

Count the lines in your `loop()`. Now count the lines in your Week 0 challenge's `loop()`. Write both numbers in your journal.

Then look at the two sweep loops — out and back. Same body. Same idea. Different direction. You wrote the same *thought* twice, and no loop can fold them into one. **Week 3.**

And notice that the scanner can only ever reach LEDs whose pins are consecutive. Put a fifth LED on pin 12 and `FIRST_PIN`/`LAST_PIN` can't describe it without dragging pin 11 along too. **Week 4.**

---

# Step 7 · JOURNAL

**~15 minutes. Non-negotiable.**

Open [`JOURNAL.md`](../../JOURNAL.md) and add a **Week 2 — Say It Once** entry at the bottom, using the template at the top of the file. The four usual prompts, plus two for this week:

> **Describe your first off-by-one error this week.** What did you expect the counter to reach, what did it actually reach, and which single character was responsible?

> **The line count.** Your Week 0 challenge's `loop()` versus your Exercise 5 rewrite. Both numbers.

Then commit:

```bash
git add -A
git commit -m "Week 2: loops — chase, odometer, scanner"
```

---

# Troubleshooting

### The loop body only runs once

A semicolon straight after the header: `for (…);`. That semicolon *is* the loop's body — an empty one. The block underneath isn't part of the loop at all; it runs once, afterwards. (Dry run D1.)

### The last LED never lights

`<` where you needed `<=`. You have the actual last pin, so the end is *included*. (§1.6.)

### The first LED never lights

The loop starts one too late — often `FIRST_PIN + 1`, or `1` where you meant `0`.

### One LED is very dim, or barely lights

It never got `pinMode(pin, OUTPUT)` — your `setup()` loop stops one short. `digitalWrite(HIGH)` on a pin that isn't an output only switches on a weak internal resistor. You've seen this exact symptom before, in Week 0 Exercise 3's break-it.

### The end LEDs flash twice

Your "out" loop and your "back" loop both include the end pins. Trace the last lap of the first loop and the first lap of the second. (That's the challenge — no more hints than that.)

### The board seems frozen

An infinite loop (§1.9). Print the counter inside the loop and watch what it does. Three usual causes:

1. A `while` whose body never changes the variable in the condition
2. A counter whose type can't reach the end — a `byte` can never get to 256 (D2)
3. An `unsigned` counter counting down to zero with `>= 0` — unsigned is never below zero (D3)

### A number suddenly becomes enormous — about 4.29 billion

An `unsigned` value went below zero and wrapped to the top. See Exercise 4. If a value can dip below zero part-way through a calculation, it needs a signed type — and so does everything it's compared with.

### A total prints as negative, or much too small

The sum outgrew its type. See drill 9, and Week 1, §1.4.

### `'pin' was not declared in this scope`

You used a loop's counter after the loop ended. It only exists between that loop's `{ }`. (§1.6.)

### The board acts strangely after a loop bug, even once it's fixed

If a loop's bounds were wrong, it may have driven pins that don't exist, or pins 0 and 1 (the USB pins). **Nothing is damaged.** Press reset, or re-upload. This is part of why `FIRST_PIN` and `LAST_PIN` are named once, at the top, and not retyped.

---

# Done checklist

- [ ] Dry run: A–D answered in `dry-run.md` and **committed before Exercise 1**
- [ ] Dry run: "what actually happened" filled in after running them
- [ ] Blue LED wired on pin 7; the row is blue · red · yellow · green
- [ ] Compiler warnings set to **All** in Preferences
- [ ] Exercise 1 — five flashes from one loop; break-its recorded in `reference/mistakes.md`
- [ ] Exercise 2 — chase both directions; `pinMode` in a loop
- [ ] Exercise 3 — binary odometer counting 0–15, checked against the Serial output
- [ ] Exercise 4 — `while` version and `for` version both working; the wrap-below-zero bug recorded under **Logic errors**
- [ ] Exercise 5 — Week 0 challenge rewritten; both line counts written down
- [ ] Drills 1–10, each saved in `drills/` (drill 8 compared across three weeks)
- [ ] Challenge — spec and two-sweep trace written on paper first
- [ ] Challenge passes acceptance tests **A**, **B** and **C**, and **D** is answered in writing
- [ ] `reference/cheatsheet-cpp.md` Week 2 section reviewed — you can explain every entry out loud
- [ ] `reference/cheatsheet-wiring.md` updated with the four-LED row
- [ ] Journal entry written, including the off-by-one and the line counts
- [ ] Everything committed to git

---

**Next:** Week 3 — Functions. Where the sweep out and the sweep back become one idea with a direction, and a blink becomes something you *call*.
