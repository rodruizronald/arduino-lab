# C++ Cheatsheet

Grown one week at a time. **Only add something after you've used it and understood it** — a reference full of things you copied but never grasped is worse than no reference at all.

Rule of thumb: if you can't explain an entry out loud without reading it, it doesn't belong here yet.

---

## Week 0 — First Contact

### Program shape

```cpp
void setup() {
  // runs ONCE, when the board powers on or resets
}

void loop() {
  // runs top to bottom, then immediately again. Forever.
}
```

Both are required. `void` means "hands nothing back when it finishes" — properly unpacked in Week 3.

### Statements

```cpp
digitalWrite(8, HIGH);
```

| Piece | Name | Meaning |
|---|---|---|
| `digitalWrite` | function name | what to do |
| `(8, HIGH)` | arguments | the details |
| `;` | semicolon | end of instruction |

Every statement ends with `;`. Braces `{ }` group statements into a block; every `{` needs a matching `}`.

### Comments

```cpp
// ignored to the end of this line

/* ignored
   across lines */
```

Comment **why**, not **what**. `delay(1000); // wait 1 second` is worthless. `delay(1000); // let the sensor settle` earns its place.

### Commands

| Command | Effect |
|---|---|
| `pinMode(pin, OUTPUT)` | This pin will send signals out. Once, in `setup()`. |
| `digitalWrite(pin, HIGH)` | Pin on — 5V. |
| `digitalWrite(pin, LOW)` | Pin off — 0V. |
| `delay(ms)` | Total freeze for this many milliseconds. `1000` = 1 second. |
| `Serial.begin(9600)` | Open the text channel to the computer. Once, in `setup()`. |
| `Serial.println("text")` | Send a line of text up the cable. |
| `Serial.print("text")` | Same, but no line break — several land on one line. |

### Names that already exist

| Name | Is really | Notes |
|---|---|---|
| `LED_BUILTIN` | `13` | The LED soldered to the board |
| `OUTPUT` / `INPUT` | pin directions | |
| `HIGH` / `LOW` | on / off | |

### Things that bite

- **C++ is case-sensitive.** `delay` ≠ `Delay` ≠ `DELAY`. Only one exists. Roughly 1 in 5 beginner errors is a capital letter.
- **`delay()` freezes everything.** It is not "waiting while doing other things." Nothing else can happen during it. Replaced permanently in Week 7.
- **Syntax error** = broken grammar; the compiler catches it for free. **Logic error** = perfect grammar, wrong behaviour; only you can catch it. The second kind is the actual job.
- Indentation is for humans only — the compiler ignores it entirely. Do it anyway.

---

## Week 1 — Variables, types, and constants

### Declaring a variable

```cpp
int onTimeMs = 500;
```

| Piece | Name | Meaning |
|---|---|---|
| `int` | type | what shape of value goes in the box |
| `onTimeMs` | name | what you call it from here on |
| `= 500` | initialiser | what's in it to start with |

Two jobs in one line: **declaration** (make the box — once) and **assignment** (put a value in — as often as you like).

### `=` is a copy, not an equals

`=` means **"copy the value on the right into the box on the left."** It has a direction.

```cpp
count = count + 1;   // read count, add 1, put the result back. Not a claim about maths.
```

```cpp
int a = 5;
int b = a;    // copies the VALUE. b is not linked to a.
a = 9;        // a is 9, b is still 5
```

### Types

| Type | Size | Range | Use for |
|---|---|---|---|
| `int` | 2 bytes | **−32,768 … 32,767** | counts, pin numbers, short durations |
| `unsigned long` | 4 bytes | 0 … 4,294,967,295 | milliseconds, anything that adds up |
| `bool` | 1 byte | `true` / `false` | a yes/no fact |
| `byte` | 1 byte | 0 … 255 | small counts; raw bits from Phase 4 |

`unsigned` = no negatives, so the whole range is spent going upward.

> **`int` dies at 32,767 on this board** — that's only 33 seconds in milliseconds. Past it, the value **wraps silently to negative**. No error, no warning, no crash: a confident wrong answer. The compiler will never catch this for you.
>
> **Rule: any value in milliseconds that might be added to another one is an `unsigned long`.**

A negative `int` passed to `delay()` (which takes an `unsigned long`) is reinterpreted as a huge positive one — `-25536` becomes about **50 days**. The board appears to hang. Press reset and go find the overflow.

### `const`

```cpp
const int PIN_RED = 8;
PIN_RED = 9;    // error: assignment of read-only variable 'PIN_RED'
```

A promise you ask the compiler to enforce. That refusal is the point: a mistake becomes a free compile error instead of an afternoon.

**Habit:** make everything `const` first. Remove it only when you find you genuinely need the value to change.

### Naming

```cpp
const int PIN_RED    = 8;      // SHOUTY_SNAKE_CASE — never changes
int       flashCount = 0;      // camelCase — varies as the program runs
```

The compiler ignores the convention. Every human reading your code uses it.

| ✗ | ✓ | Why |
|---|---|---|
| `x`, `t`, `p` | `onTimeMs`, `PIN_YELLOW` | Saves six keystrokes, costs every future read |
| `time` | `redOnMs` | Which time? For what? In what unit? |
| `delay1`, `delay2` | `flashMs`, `gapMs` | Numbered names mean you gave up |

1. **Put the unit in the name** — `Ms`, `Sec`. Units that live only in the author's head become bugs.
2. **Name it for what it means**, not what it is.

### Scope

```cpp
const int PIN_RED = 8;      // global — setup() and loop() both see it

void setup() {
  int attempts = 0;         // local — exists only inside setup()'s { }
}
```

A variable exists only inside the `{ }` it was declared in. Reaching outside that gives `'attempts' was not declared in this scope`. Full treatment in Week 3; for now, put constants at the top of the file.

### Printing values

```cpp
Serial.print("red on for ");   // no line break
Serial.print(redOnMs);         // no quotes -> prints the VALUE
Serial.println(" ms");         // ends the line
```

`"redOnMs"` prints the letters. `redOnMs` prints what's in the box. Both compile.

Useful habit — a marker in `setup()` so you can see where the board last reset:

```cpp
Serial.println("--- boot ---");
```

### Things that bite

- **`int` overflow is silent.** See above. This is the week's main trap.
- **Integer division throws away the remainder.** `61 / 2` is `30`, not `30.5`. Nothing warns you. Properly covered in Week 10.
- **Arithmetic happens in the operands' type, before the assignment.** `unsigned long total = someInt * 10;` can still overflow — the multiplication is done as `int` first, and the wrapped result is what gets stored.
- **Declaration order matters.** The compiler reads top to bottom; a name must exist before it's mentioned.
- **A magic number is a number with no name.** Ten `150`s that all mean the same thing are ten separate numbers as far as the compiler is concerned. Change nine of them and nothing tells you about the tenth.

### What this week does *not* fix

Variables kill magic numbers. They do **not** kill repetition — you still type the same block over and over, just with better names in it. That's Week 2.

---

## Week 2 — Loops

### `for` — do this N times

```cpp
for (int i = 0; i < N; i++) {
  // runs N times, with i = 0, 1, … N-1
}
```

| Piece | Runs |
|---|---|
| `int i = 0` | **once**, first |
| `i < N` | **before every lap** — false ends the loop |
| `i++` | **after every lap** |
| `{ … }` | once per lap |

Order: init → check → body → update → check → body → … → check fails → carry on after the loop.

**The condition is checked one more time than the body runs.** The last check is the one that fails.

### The two shapes

| Shape | Runs | Use when you have… |
|---|---|---|
| `for (int i = 0; i < N; i++)` | N times | a **count** — end excluded |
| `for (int pin = FIRST; pin <= LAST; pin++)` | LAST − FIRST + 1 times | the **actual first and last values** — end included |

Start at `0` with `<`, or use the real bounds with `<=`. **Mixing them** — `0` with `<=`, or `1` with `<` — is how off-by-one happens.

The `0` a loop starts from and the `1` inside `++` are the counting idiom, not magic numbers. Everything else gets a name.

### Counting shorthand

| | Means |
|---|---|
| `i++` | `i = i + 1` |
| `i--` | `i = i - 1` |
| `i += 3` | `i = i + 3` |
| `i -= 3` | `i = i - 3` |

### Comparisons

`<` `<=` `>` `>=` `==` `!=` — loop conditions this week; decisions from Week 5.

`==` **asks** "are these equal?". `=` **copies** right into left. Different operators that look almost the same.

### `while` — keep going until…

```cpp
while (waitMs >= MIN_MS) {
  // …
  waitMs = waitMs - STEP_MS;   // the BODY must move toward the exit
}
```

The header only asks a question — nothing in it changes anything. If the body doesn't move the variable toward "false", the loop never ends.

| | Use when you know… |
|---|---|
| `for` | how many times, or the range to step through |
| `while` | the condition to stop on |

Any `for` can be rewritten as a `while`, and back. Pick the one that says what you mean.

### Nested loops

```cpp
for (int row = 0; row < 3; row++) {
  for (int col = 0; col < 4; col++) {
    // 3 × 4 = 12 laps in total
  }
}
```

The inner loop runs all the way through, from scratch, for **every** lap of the outer one. The innermost spins fastest — an odometer.

### The counter's scope

`for (int pin = …)` creates `pin` for that loop only. After the closing `}` it's gone — `'pin' was not declared in this scope`. Two loops can each have their own `pin`.

### Naming the counter

`i` is fine for a pure count. When the counter means something, name it for what it means: `pin`, `flash`, `sweep`.

### Tracing

A trace table: one row per lap, one column per variable, plus the condition. **Check the first lap and the last lap** — the middle is almost never where the bug is.

On the board, the Serial Monitor is the trace table: `Serial.println(i);` inside the loop.

### Printing

```cpp
Serial.println();    // nothing in the brackets — just ends the line
```

Useful after a loop of `Serial.print`s that built up one line.

### Things that bite

- **A semicolon after the header.** `for (…);` — that `;` *is* the body, an empty one. The block underneath isn't in the loop; it runs once, afterwards. Compiles silently.
- **Off-by-one.** `<` vs `<=`; starting at `0` vs `1`. Fence posts: 10 metres of fence with a post every metre needs **11** posts.
- **Doubled ends in a bounce.** If the "out" loop and the "back" loop both include the end pins, the end LEDs light twice.
- **A counter whose type can't reach the end.** `for (byte i = 0; i < 256; i++)` never ends — a `byte` stops at 255 and wraps back to 0.
- **Counting an unsigned down to zero.** `for (unsigned long n = 3; n >= 0; n--)` never ends — an unsigned value is *always* `>= 0`.
- **Unsigned subtraction below zero** wraps to about 4.29 billion. If a value can dip below zero part-way through a calculation, give it a signed type (`long`) — **and give that type to everything it's compared or combined with.** Mix signed and unsigned in one comparison and the compiler quietly treats both as unsigned.
- **Sums grow fast.** `1 + 2 + … + 1000` is 500,500 — far past an `int`. Strictly, signed overflow is *undefined behaviour* in C++; on this board it happens to wrap. The rule isn't "know what it wraps to" — it's "pick a type big enough that it never happens."
- **An infinite loop isn't a crash.** A frozen-looking board is a chip running flat out, doing what you said. Print the counter.
- **Loop bounds that escape the LED range** can drive pins that don't exist, or pins 0 and 1. Nothing gets damaged; the board may act strangely until reset.
- **Turn on compiler warnings:** File → Preferences → Compiler warnings → **All**. It catches some never-ending loops. Warnings don't stop the upload — they're the compiler asking "are you sure?"

### What this week does *not* fix

Loops kill **repeated blocks**. They don't kill **repeated ideas** — the sweep out and the sweep back are the same thought written twice. That's Week 3.

And `for (int pin = FIRST; pin <= LAST; pin++)` only reaches LEDs on **consecutive** pins. The set of LEDs is baked into arithmetic. That's Week 4.

---

## Week 3 — Functions

### Defining and calling

```cpp
void blinkN(int pin, int times) {    // DEFINITION — says what the idea is
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(BLINK_MS);
    digitalWrite(pin, LOW);
    delay(BLINK_MS);
  }
}

blinkN(PIN_RED, 3);                  // CALL — makes it happen
```

| Piece | Name | Meaning |
|---|---|---|
| `void` | return type | what comes back. `void` = nothing |
| `blinkN` | name | a verb — it *does* something |
| `int pin, int times` | **parameters** | the blanks, each with a type |
| `PIN_RED, 3` | **arguments** | what fills the blanks, at this call |

A definition does nothing until it's called. A call jumps in, runs the body, and **comes back to the line after it.** `blinkOnce;` without `()` is not a call — it compiles and does nothing.

`setup()` and `loop()` are functions. A hidden `main()` calls `setup()` once, then `loop()` inside a `for (;;)` that never ends.

### Parameters are copies

```cpp
void countDown(int times) {
  times = times - 1;        // changes the function's own copy only
}
```

Passing an argument is an assignment — `times = flashes` — and `=` copies (Week 1). The caller's variable is untouched. That's **pass by value**.

**Arguments match parameters by position, not by name.** `blinkN(3, PIN_RED)` compiles — both are `int`s — and blinks pin 3.

An argument is converted to the parameter's type, silently. `-2` passed to an `unsigned int` parameter arrives as 65,534.

### Return values

```cpp
int stepsPerSweep() {
  return 2 * (LAST_PIN - FIRST_PIN);   // hands the value back AND ends the function
}

int steps = stepsPerSweep();           // the call becomes the value
```

- `stepsPerSweep();` alone works out the answer and **throws it away**.
- A non-`void` function must `return` a value. Forget, and it still compiles — with warnings on All, the compiler mentions it — and the caller gets garbage.
- The return type is a type like any other: an `int` can't return 500,500. And a `long` return type doesn't help if the arithmetic inside was done in `int`.

### Doers and calculators

| Doers | Calculators |
|---|---|
| make something happen — LEDs, Serial, time | work out a value and `return` it |
| usually `void` | the answer's type |
| check by watching | check by **printing their answers** for a few inputs |

A good calculator touches nothing: same inputs → same answer, always. Keep calculating out of doing. Two independent calculators that agree are far more trustworthy than one.

### Scope

| Declared… | Visible… | Lives… |
|---|---|---|
| inside a function, or as a parameter | only inside that function | while the function runs |
| inside a `for` header or `{ }` block | only inside that block | while the block runs |
| at the top of the file (global) | everywhere | the whole time |

**Global constants: fine. Global variables: almost never.** A global any function can change gives you bugs that only appear the second time round. Pass values in; `return` results out.

**Shadowing:** a local with the same name as a global hides the global inside that function. Legal, and confusing — two boxes, one name. Use different names.

### Naming and size

- **Verbs** for doers: `blinkN`, `walk`, `announce`. What-it-returns for calculators: `stepsPerSweep`, `scanMs`.
- **The one-sentence test:** if describing the function needs the word "and", it's two functions.
- **Short:** under ~15 lines. If it doesn't fit on screen, split it.

### DRY and decomposition

**DRY — Don't Repeat Yourself:** every idea has one home, so changing it is one edit.

**Decomposition:** a function can earn its place by naming a step, even if it's called once. `booting(); running(); error();` — the top level reads like a summary.

**Nested loops:** a loop inside a loop is often clearer as a loop that *calls a function*. The inner loop gets a name.

### Refactoring — turning repeated code into a function

1. Find two pieces with the same idea.
2. **Make them the same shape** — identical except for values. Often the real work.
3. The values that still differ become parameters.
4. Write the function once; replace both pieces with calls.
5. **Run it. Same behaviour?** If not, it wasn't a refactor.

Decide `<` vs `<=` **once, inside the function** — have it take a count of steps — so no caller ever has to think about the boundary again.

### Layout

```cpp
// constants
void setup() { … }
void loop()  { … }      // the summary, read first
// your functions below
```

The Arduino IDE writes the declarations that let you define functions below where they're used. In plain C++ you do it yourself (Week 18). A function **can't be defined inside another function**.

### Things that bite

- **Missing `()`** — `blinkOnce;` compiles and calls nothing.
- **Arguments in the wrong order** — compiles if the types match. The compiler can't read your intentions.
- **Missing `return`** — compiles; garbage comes back. Warnings on All catch it.
- **A calculator's answer thrown away** — called on a line by itself.
- **"It worked the first time"** — a global variable changed by one function and relied on by another.
- **Overflow inside the function** — the return type being big enough doesn't protect the arithmetic inside.

### What this week does *not* fix

The show in `loop()` — which pattern, how many times, how fast — is a **list of data written as code**. And every pattern still finds its LEDs with `FIRST_PIN + i` — consecutive pins only. Both are lists pretending to be code. That's Week 4.

---

## Week 4 — Arrays

<!-- next -->
