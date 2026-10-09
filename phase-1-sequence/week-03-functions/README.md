# Week 3 — Names for Ideas

> **Phase 1** · Functions
> **Time:** ~5 hours
> **New concepts:** defining and calling functions · `void` · parameters and arguments · pass by value · return values · doers and calculators · local vs global scope · DRY · decomposition · refactoring

---

## What you need on the desk

| Item | Notes |
|---|---|
| UNO board + USB cable | |
| The Week 2 circuit | Four LEDs — blue 7, red 8, yellow 9, green 10. **Nothing changes this week** |

## Where your work goes

Your work goes in the sketches, in [`dry-run.md`](dry-run.md), in the journal, and in `reference/`. **Don't edit this README** — it's the assignment.

---

# Step 1 · CONCEPT

**~40 minutes. Read this with the box closed. No computer, no board.**

## 1.1 You've been writing functions since Week 0

`setup()` and `loop()` are functions. You've written one of each in every sketch since the first blink.

So who calls them? The Arduino software adds a small hidden file to every sketch you upload. Stripped down, it says this:

```cpp
int main() {
  setup();
  for (;;) {
    loop();
  }
}
```

That's the whole secret of the "runs once / runs forever" diagram from Week 0. `setup()` is called once. Then `loop()` is called from inside a `for` loop with an empty header — no init, no condition, no update — which never stops. You've been inside a function, inside a loop, for three weeks.

This week you write your own.

## 1.2 The problem: the same idea, in different places

Loops killed repeated *blocks* — the same lines, back to back. But look at what's still repeated in your Week 2 work:

- The scanner's sweep **out** and sweep **back**. Same body, different direction.
- The three states of the Machine Status Indicator. Each one is "flash some LEDs, some number of times, for some duration."
- The three letters of SOS. Each is "three of the same symbol."

A loop can't fold these. They aren't side by side, and the details differ each time. What they share is an **idea** — and that's what a function is: **an idea with a name, and blanks for the details.**

## 1.3 Anatomy of a function

```cpp
void blinkN(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(BLINK_MS);
    digitalWrite(pin, LOW);
    delay(BLINK_MS);
  }
}
```

That's the **definition** — it says what the idea is. It does nothing on its own. This is a **call** — it makes it happen:

```cpp
blinkN(PIN_RED, 3);
```

| Piece | Name | Meaning |
|---|---|---|
| `void` | **return type** | what the function hands back when it's done. `void` = nothing |
| `blinkN` | **name** | what you call it |
| `(int pin, int times)` | **parameters** | the blanks — each with a type and a name |
| `{ … }` | **body** | what happens, using the blanks |

And at the call:

| Piece | Name | Meaning |
|---|---|---|
| `PIN_RED, 3` | **arguments** | the values that fill the blanks, *this* time |

**Parameters** are the blanks in the definition. **Arguments** are what you fill them with at the call. Every call can fill them differently — that's the point.

> **`void`, at last.** Week 0 told you to read `void setup()` as noise. Now it isn't: `void` is the return type, and it means *"this function does something, and hands nothing back."* Week 0's promise, kept.

## 1.4 What a call actually does

When the board reaches a call:

1. It notes where it is.
2. It jumps into the function, and the parameters get the arguments' values.
3. It runs the body, top to bottom.
4. It comes back to exactly where it left off, and carries on with the next line.

```
  loop()                          blinkN(pin, times)
  ──────                          ──────────────────
  blinkN(PIN_RED, 3);  ─────────►  pin = 8, times = 3
                                   for … 3 blinks …
           ◄───────────────────── end of body: go back
  blinkN(PIN_GREEN, 1); ────────►  pin = 10, times = 1
                                   …
```

Functions can call other functions, as deep as you like. The board keeps a list of where to come back to — that list is called the **call stack**, and you'll meet it by name again much later. For now: every call comes back, to the line after it.

**Tracing calls on paper** works like tracing loops: write each line as it runs, and **indent when you go into a function, out-dent when you come back.** The indentation *is* the call stack.

## 1.5 Parameters are copies

When you call `blinkN(PIN_RED, 3)`, the parameter `times` gets a **copy** of 3. Not a link to it. A copy.

```cpp
void countDown(int times) {
  while (times > 0) {
    Serial.println(times);
    times = times - 1;      // changes the function's own copy
  }
}

void setup() {
  Serial.begin(9600);
  int flashes = 3;
  countDown(flashes);
  Serial.println(flashes);  // still 3
}
```

This is Week 1's §1.3 again — **`=` is a copy** — in a new place. Passing an argument is an assignment: `times = flashes`, done for you at the call. After that, the two boxes have nothing to do with each other.

That's called **pass by value**, and it's a safety feature: a function can't reach out and damage the caller's variables by accident. (There is a way to deliberately let it. That's Week 17.)

And one more thing the compiler won't tell you: **arguments are matched to parameters by position, not by name.** `blinkN(3, PIN_RED)` compiles perfectly — both are `int`s — and blinks pin 3 eight times. There's no LED on pin 3. Nothing happens, and nothing complains.

## 1.6 Return values

A function can hand a value back:

```cpp
int stepsPerSweep() {
  return 2 * (LAST_PIN - FIRST_PIN);
}
```

The return type — `int` here, instead of `void` — says what kind of value comes back. `return` hands it back **and ends the function on the spot.**

At the call, the whole call *becomes* that value:

```cpp
int steps = stepsPerSweep();            // steps is now 6
Serial.println(stepsPerSweep());        // prints 6
delay(stepsPerSweep() * STEP_MS);       // usable anywhere a number is
```

Two things to watch:

- **Use it or lose it.** `stepsPerSweep();` on a line by itself works out 6 and throws it away. Legal. Useless.
- **A function that promises a value must return one.** Leave out the `return` and it still compiles — with warnings on, the compiler mentions it — and the caller gets whatever garbage happens to be lying around. A logic error with a warning attached, not an error. Week 2 told you to turn warnings on. This is why.

The return type is a type like any other, and Week 1's rules apply to it. A function returning an `int` can't return 500,500.

## 1.7 Doers and calculators

You'll write two kinds of function:

| | **Doers** | **Calculators** |
|---|---|---|
| Example | `blinkN(pin, times)` | `stepsPerSweep()` |
| Job | make something happen — LEDs, Serial, time passing | work out a value and return it |
| Return type | usually `void` | the type of the answer |
| How you check it | watch it | **print what it returns, for a few inputs** |

A good calculator touches nothing: same inputs in, same answer out, every time, no LEDs, no delays, no Serial. That makes it trivially easy to check — call it in `setup()` with a few inputs and print the answers. Is `stepsPerSweep()` 6 with four LEDs? Is it 4 with three?

**Where you can, keep the calculating out of the doing.** A doer that works out its own timing *and* blinks is hard to check: the only test is a stopwatch. Split it, and the arithmetic can be checked in a printout in two seconds. *(This idea grows into all of Week 32.)*

## 1.8 Scope, properly

Week 1 introduced scope. Functions make it matter.

```cpp
const int PIN_RED = 8;       // GLOBAL constant — every function can read it

void blinkN(int pin, int times) {   // pin, times: PARAMETERS — local to blinkN
  for (int i = 0; i < times; i++) { // i: local to this loop
    …
  }
}
```

- **Parameters and variables declared inside a function are local.** They exist while the function runs, and vanish when it returns. Another function can't see them — try, and you get the error you already know: `'onMs' was not declared in this scope`.
- **Globals are visible to every function** — and that's the problem with global *variables*. Any function can change them, at any time. Exercise 4 has a program where one function quietly changes a global that another one relies on. It works perfectly the first time round `loop()`, and is wrong forever after. That's the signature of a global-variable bug: **"it worked the first time."**

The rule for this plan:

> **Global constants: fine — that's where they belong.**
> **Global variables: almost never.** If a function needs a value, pass it in as a parameter. If it produces one, return it.

A function that follows that rule can be understood from its first line alone. `void blinkN(int pin, int times)` tells you everything it uses.

## 1.9 Naming, size, and DRY

**Name a function with a verb** — it *does* something: `blinkN`, `walk`, `flashAll`, `announce`. Calculators can be named for what they return: `stepsPerSweep`, `scanMs`.

**The one-sentence test.** Describe what a function does in one sentence. If the sentence needs the word "and", it's two functions.

**Keep them short.** If a function doesn't fit on your screen, it's doing too much. Most functions in this plan should be under 15 lines.

**DRY — Don't Repeat Yourself.** Every idea gets *one* home. If the rule for how a blink works lives in one function, then changing how blinks work is one edit. If it lives in four places, it's four edits and one of them gets missed. (Week 1's ten `150`s, but for ideas.)

Functions earn their place for two different reasons, and both count:

1. **To say an idea once** — it's used in several places. That's DRY.
2. **To give a step a name** — even if it's used once. `booting(); running(); error();` reads better than forty lines, even though each is called once. That's **decomposition**: breaking a big job into named pieces, so the top level reads like a summary.

> **Nested loops, again.** If loops-inside-loops tangled you up in Week 2, here's the fix: a loop inside a loop is usually clearer as **a loop that calls a function**. The inner loop gets a name, and you can read the outer one without holding both in your head at once.

## 1.10 Making two pieces the same shape

Here's the skill that actually turns repeated code into a function, step by step:

1. **Find two pieces that do the same idea.**
2. **Make them identical, except for values.** This is often the real work. If one sweep loop includes both end pins and the other includes neither, they're the *same idea* in *different shapes* — and you can't fold them until you make them the same shape.
3. **The values that still differ become parameters.**
4. **Write the function once. Replace both pieces with calls.**
5. **Run it. Same behaviour as before?**

That process — changing the *structure* of code without changing what it *does* — is called **refactoring**. Step 5 is not optional: the whole definition of a refactor is that the behaviour didn't change, so you have to check.

A boundary tip, given what Week 2 was like: **decide `<` vs `<=` once, inside the function, and never again.** If `walk` takes a *number of steps* and uses the `i = 0; i < steps` idiom inside, every caller just says how many steps they want. The off-by-one question gets answered in one place.

## 1.11 Where functions go in the file

```cpp
// constants first

void setup() { … }
void loop()  { … }       // the summary — read first

// then the functions loop() calls, below it
void blinkN(int pin, int times) { … }
```

Put `setup()` and `loop()` near the top, and your own functions below. Someone opening the file reads the summary first and the details only if they need them.

> **Why that works at all:** C++ normally needs a function to be declared before it's used. The Arduino IDE quietly writes those declarations for you before compiling. In plain C++ — Week 18 — you'll write them yourself.

**A function can't be defined inside another function.** Every definition sits at the top level of the file, side by side.

## 1.12 What this week does *not* fix

Look ahead to the end of the challenge. `loop()` will be a list of calls:

```cpp
scan(2, 150);
chase(FORWARD, 2, 100);
blinkAll(3, 200, 200);
```

That reads beautifully. But the *show* — which patterns, in what order, with which numbers — is now **data written as code**. To change the show, you edit the program.

And underneath, every pattern still finds its LEDs by arithmetic on pin numbers: `FIRST_PIN + i`. Consecutive pins only. A fifth LED on pin 12 still can't join in.

Both of those are the same problem — **data that should be a list** — and it's **Week 4**.

---

# Step 2 · DRY RUN

**~25 minutes. Paper and pen. No computer.**

Write your answers in [`dry-run.md`](dry-run.md) **before** you open the IDE. Then commit that file on its own:

```bash
git add phase-1-sequence/week-03-functions/dry-run.md
git commit -m "Week 3: dry run predictions"
```

> **How this is checked:** your PR's **first commit contains only `dry-run.md`**. If the whole week arrives as a single commit, the dry run counts as not done — however good the answers are. The timestamp is the only evidence that you predicted *before* you ran.

After Exercise 1, run the snippets and fill in "what actually happened." Use the call-trace method from §1.4: indent going into a function, out-dent coming back.

### Snippet A — call order

```cpp
void sayA() {
  Serial.println("A");
}

void sayB() {
  Serial.println("B");
  sayA();
}

void setup() {
  Serial.begin(9600);
  sayB();
  sayA();
  sayB();
}

void loop() {
}
```
> **Q:** Every line the Monitor shows, in order. How many times does `sayA()` run in total?

### Snippet B — copies

```cpp
void addTen(int x) {
  x = x + 10;
  Serial.println(x);
}

void setup() {
  Serial.begin(9600);
  int n = 5;
  addTen(n);
  Serial.println(n);
}
```
> **Q:** Both numbers, in order. Then: which Week 1 dry-run snippet is this, in disguise?

### Snippet C — return values

```cpp
int doubled(int x) {
  return x * 2;
}

int plusOne(int x) {
  return x + 1;
}

void setup() {
  Serial.begin(9600);
  Serial.println(doubled(plusOne(3)));
  Serial.println(plusOne(doubled(3)));

  int a = doubled(4);
  doubled(a);
  Serial.println(a);
}
```
> **Q:** All three numbers. For the first two, which function runs first — and why? For the third, what happened to the value `doubled(a)` worked out?

### Snippet D — four problems

```cpp
const int PIN_RED = 8;
const int BLINK_MS = 200;

void blinkN(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(onMs);
    digitalWrite(pin, LOW);
    delay(onMs);
  }
}

int totalBlinks(int rounds, int perRound) {
  int total = rounds * perRound;
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
}

void loop() {
  int onMs = BLINK_MS;
  blinkN(3, PIN_RED);
  blinkN(PIN_RED);
  Serial.println(totalBlinks(2, 3));
}
```
> **Q:** Find all four. For each: **does the compiler stop you** (error), **warn you** (with warnings on All), or **say nothing at all**? Week 2's snippet D was all silent. This one is a mix — and the silent one is the most dangerous.

---

# Step 3 · WIRE

**Nothing to wire.** Same four LEDs as Week 2: blue 7 · red 8 · yellow 9 · green 10. [Week 2's wiring](../week-02-loops/wiring.md) if you need it.

Exercise 1 checks all four still light before anything else depends on them.

---

# Step 4 · GUIDED EXERCISES

**~100 minutes. Five exercises. Each builds on the last.**

### Exercise 1 — Your first function
📁 [`exercise-1-first-function/`](exercise-1-first-function/)

Take one blink, give it a name, and call it. Then call it on every LED.

**The point:** a function is a named idea. Defining it does nothing; calling it makes it happen.

---

### Exercise 2 — Parameters
📁 [`exercise-2-parameters/`](exercise-2-parameters/)

`blinkN(pin, times)`: one function, any LED, any count. Then prove to yourself that parameters are copies — and that the compiler can't tell when you pass arguments in the wrong order.

**The point:** parameters are the blanks. Every call fills them differently.

---

### Exercise 3 — Return values
📁 [`exercise-3-return-values/`](exercise-3-return-values/)

Calculators: functions that work something out and hand it back. You check each one by printing its answers — and you write the same calculation two different ways, and make them check each other.

**The point:** a calculator that touches nothing is the easiest code in the world to verify.

---

### Exercise 4 — Scope, and the bug that waits
📁 [`exercise-4-scope/`](exercise-4-scope/)

A short program, given to you, with a global-variable bug in it. It works perfectly once, then goes wrong forever. Find it with Serial, then fix it by removing the global entirely.

**The point:** "it worked the first time" is the signature of shared, changing state. Pass values in, return values out.

---

### Exercise 5 — Re-solve: the Machine Status Indicator, a third time
📁 [`exercise-5-rewrite-again/`](exercise-5-rewrite-again/)

Week 0 wrote it out longhand. Week 2 used loops. Now: the "sentence with blanks" from Week 2's Exercise 5 becomes an actual function, and `loop()` becomes three lines.

**The point:** Rule 6, again. The same spec for the third time — and the clearest evidence yet of what each week bought you.

---

# Step 5 · DRILLS

**~60 minutes. Ten short specs. Same circuit.**

Save each in `drills/drill-NN-name/drill-NN-name.ino`.

**House rules:** every repeated idea is a function. No global variables — only global constants. Week 1 and 2 rules still apply.

| # | Spec |
|---|---|
| 1 | `blinkN(pin, times)`. Use it to blink blue once, red twice, yellow three times, green four — four calls, no loop in `loop()` |
| 2 | `chase(times, stepMs)` — the Week 2 chase as a function. Call it with different arguments, one after another |
| 3 | `flashAll(times, onMs, offMs)` — all four LEDs together |
| 4 | `fill(stepMs)` and `drain(stepMs)` — Week 2's drill 4 as two functions. Does `loop()` read like what it does? |
| 5 | A calculator: `int ledCount()`, worked out from `FIRST_PIN` and `LAST_PIN`. Print it in `setup()`. Then change `FIRST_PIN` and print it again |
| 6 | Two calculators that answer the same question: `long sumByLoop(long n)` and `long sumByFormula(long n)`. Print both, side by side, for `n` = 10, 100 and 1000. They must agree — when two independent methods give the same answer, you can trust it |
| 7 | `printTimesRow(int n)` — prints one row of the times table. A loop in `loop()` calls it for 1 to 9 |
| 8 | **SOS, for the fourth time:** `dot()`, `dash()`, `letterS()`, `letterO()`. `loop()` should read almost exactly like the message. Line your four versions up — Weeks 0, 1, 2, 3 |
| 9 | `unsigned long chaseMs(int times, unsigned long stepMs)` — a calculator that predicts how long a call to your drill-2 `chase` will take. Print the prediction, run the chase, and check it with a stopwatch |
| 10 | `alternate(pinA, pinB, times, flashMs)`. Use the *same* function for police lights (red / blue, fast) **and** a level crossing (yellow / green, slow). One function, two jobs |

Drill 8 is the one to keep — four versions of the same message, and each one shorter and clearer than the last.

Drill 6 is the most important idea in the list, even though it's the easiest to write. Two independent ways of getting an answer, checking each other, is how you trust code you can't see inside. You'll do it properly in Week 32.

---

# Step 6 · CHALLENGE

**~75 minutes. No hints. You will get stuck. That is the exercise.**

📁 [`challenge/`](challenge/)

## Light Show

Build a small **library of pattern generators** — functions that each produce one kind of pattern, with parameters — and then a **show** in `loop()` that plays them in sequence.

### The patterns

At minimum, these four:

| Pattern | What it does |
|---|---|
| **scan** | The Week 2 scanner at a fixed speed: a light sweeps out and back, a given number of times. No double flash at the ends |
| **chase** | A light runs along the row, end to end, a given number of times — in **either** direction |
| **blink all** | All the LEDs flash together, a given number of times |
| **fill** | The LEDs light one by one until all are on, then go dark one by one |

The numbers — how many times, how fast — are **arguments**, not constants inside the function.

### Constraints

1. **Spec first, on paper:** list every function you'll write, with its parameters, and one sentence for what it does. No sentence may need the word "and". *(Rule 2.)*
2. **The sweep out and the sweep back are the same function**, called twice with different arguments. That's the promise Week 2's challenge made. Keep it.
3. **`loop()` contains only function calls.** No `for`, no `while`, no `digitalWrite`, no `delay` — just the show, as a list of calls.
4. **No global variables.** Global constants only. Everything a function needs comes in through its parameters.
5. **Every function body is 15 lines or fewer** — `loop()` included. Not counting blank lines and comments.
6. **Before each pattern runs, Serial announces its name and how long it will take**, in milliseconds. That duration comes from a **calculator** — a function that returns it, worked out from the same arguments the pattern will receive. The pattern itself never measures anything.
7. **The show uses every pattern at least once, and at least one pattern twice with different arguments.**
8. **Use only what you know:** Weeks 0–2, plus functions. **No `if`. No arrays.**

### The acceptance tests

> **A.** Change `FIRST_PIN` to `8`. Every pattern adapts to three LEDs, every announced duration is still correct, and **you changed nothing else**.
>
> **B.** Add a **reverse chase** and a **slower second scan** to the show **without writing a new loop anywhere.** Only new calls. If you need a new `for`, your generators aren't general enough yet.
>
> **C.** Time one full run of the show with a stopwatch. It should match the sum of the announced durations to within a second. If it doesn't, either a calculator or a pattern is wrong — find out which.
>
> **D.** *Think, don't fix:* whichever function walks the light along the row takes some kind of direction. What happens if you pass it a value you didn't intend — `0`, or `2`? Write down what the LEDs would do, and why you can't prevent it yet. *(Week 5.)*

### And then, the actual lesson

Read your `loop()` out loud. It should sound like a description of the show, not like instructions to a machine. That's decomposition, and it's the biggest single improvement in readability you'll make in this whole phase.

Now look at what's left:

- **The show is a list of calls with numbers in them.** It's a list of *data* — pattern, count, speed — written as code. To change the show, you edit and re-upload the program.
- **Every pattern still finds its LEDs by arithmetic:** a start pin, plus a step. Consecutive pins only.

Both of those are **lists pretending to be code**. Week 4 turns them into actual lists — and the Phase 1 checkpoint asks you to change the whole traffic-light sequence by editing one of them.

---

# Step 7 · JOURNAL

**~15 minutes. Non-negotiable.**

Add a **Week 3 — Names for Ideas** entry at the bottom of [`JOURNAL.md`](../../JOURNAL.md), using the four headings from the template at the top of the file. Plus two for this week:

> **The one-sentence test.** Pick your challenge function that was hardest to describe in one sentence without "and". What was the first sentence you wrote? What did you split it into?

> **Three versions.** `loop()` line counts for the Machine Status Indicator: Week 0, Week 2 Exercise 5, Week 3 Exercise 5.

Then commit (your dry-run commit should already be there):

```bash
git add -A
git commit -m "Week 3: functions — pattern library and light show"
```

---

# Troubleshooting

### `'blinkN' was not declared in this scope`

The same error as a misspelt variable, for the same reasons: spelling and capitals first. If the name is right, check the function isn't defined *inside* another function's braces — every definition sits at the top level of the file.

### `too few arguments to function` (or too many)

The call doesn't supply exactly one argument per parameter. Count them against the definition.

### The function is called, but nothing happens

Three suspects:

1. **No parentheses:** `blinkOnce;` instead of `blinkOnce();`. Without `()`, it's not a call. It compiles — with warnings on, the compiler says so.
2. **Arguments in the wrong order:** `blinkN(3, PIN_RED)`. Both are `int`s, so the compiler can't tell. Print the parameters at the top of the function.
3. **The count is 0** — perhaps calculated, perhaps passed by mistake. Print it.

### A calculator returns nonsense

- **No `return`** on the path that ran. Turn warnings to All; the compiler flags this.
- **The return type is too small** for the answer. Week 1, §1.4.
- **The arithmetic overflowed before it was returned.** A `long` return type doesn't help if the multiplication inside was done in `int`. Week 1's "arithmetic happens in the operands' type".

### It works the first time round `loop()`, then goes wrong

A global variable changed by one function and relied on by another. Exercise 4. Print the global at the start of each function that uses it — you'll see the moment it changes.

### Changing a parameter didn't change my variable

Correct behaviour — parameters are copies (§1.5). If the function's job is to produce a new value, `return` it, and assign the result at the call: `waitMs = faster(waitMs);`.

### A warning about an "unused" value or variable

Often the start of a bug: a calculator called on a line by itself, its answer thrown away (`stepsPerSweep();`), or a variable worked out and never used. Read it before dismissing it.

---

# Done checklist

- [ ] Dry run: A–D in `dry-run.md`, **committed on its own as the first commit of the week**
- [ ] Dry run: "what actually happened" filled in afterwards
- [ ] Exercise 1 — a named blink, called on all four LEDs
- [ ] Exercise 2 — `blinkN(pin, times)`; copies proved; wrong-order call observed
- [ ] Exercise 3 — calculators checked by printing; two methods agreeing
- [ ] Exercise 4 — the global bug found with Serial, fixed with no global variable; recorded under **Logic errors** in `reference/mistakes.md`
- [ ] Exercise 5 — Machine Status Indicator as functions; three `loop()` line counts written down
- [ ] Drills 1–10 in `drills/` (drill 8 lined up with all three earlier SOS versions)
- [ ] Challenge — function list with one-sentence descriptions written on paper first
- [ ] Challenge passes acceptance tests **A**, **B** and **C**; **D** answered in writing
- [ ] `reference/cheatsheet-cpp.md` Week 3 section reviewed — you can explain every entry out loud
- [ ] Journal entry, including the one-sentence test and the three line counts
- [ ] Everything committed to git

---

**Next:** Week 4 — Arrays. Where the row of LEDs becomes a list, the show becomes a table, and adding an LED on pin 12 stops being impossible.
