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

<!-- next -->
