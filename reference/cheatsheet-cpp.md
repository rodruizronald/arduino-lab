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

<!-- next -->
