# Arduino Lab — A Programming Curriculum Disguised as an Electronics Kit

**Goal:** learn to program and to think logically, from zero.
**Method:** an Arduino kit, because blinking a real light beats printing `Hello World` to a black rectangle.

---

## 1. The Deal

| | |
|---|---|
| **What this plan is** | A structured path to programming fundamentals, data structures, algorithms, and software design — taught through hardware that reacts instantly to your code. |
| **What this plan is not** | An electronics course. There is no circuit theory, no Ohm's-law problem sets, no transistor biasing math. |
| **The language** | C++ (Arduino's language *is* C++, not a toy dialect). Everything you learn here — loops, functions, arrays, structs, classes, pointers, scope — transfers directly to real software work. |
| **The electronics rule** | Hardware is a *display device* for your logic. When a circuit is needed, this plan tells you exactly what to plug where and gives a one-paragraph "why", and nothing more. Curiosity beyond that is optional and encouraged, never required. |
| **The honest bit** | You will not build "impressive gadgets" for the first two months. You will build increasingly *well-written* versions of small things. That is the point. A blinking LED written five different ways teaches more than five different gadgets copy-pasted from YouTube. |

### Pacing

A "week" here is a **unit of work (~4–6 focused hours)**, not a calendar week. Take two calendar weeks per unit if you need to. The sequence matters; the speed does not. Full plan ≈ **37 units**.

---

## 2. The Rules

These are the difference between finishing this plan able to program, and finishing it able to *paste*.

1. **Type every line. Never copy-paste code.** Not from this repo, not from the internet. Your fingers are part of your memory.
2. **Write the spec before the code.** Before touching the keyboard, write in plain English (or Spanish) what the program should do, step by step. If you can't describe it, you can't code it.
3. **Predict, then run.** Before uploading, write down what you *expect* to happen. Being wrong is the lesson; being surprised without a prediction is nothing.
4. **One new concept at a time.** A week introduces one programming idea. Hardware may be reused for several weeks in a row — that is deliberate.
5. **Break it on purpose.** Every exercise ends with: change a number, delete a line, swap two lines. Watch it break. Explain *why* it broke.
6. **Re-solve old problems with new tools.** Several weeks are pure rewrites of earlier projects using better structure. These are the highest-value weeks in the plan. Do not skip them because "it already works".
7. **Journal every session.** One entry per week: what I built, what confused me, what broke, what I now understand that I didn't before. Non-negotiable.
8. **Rubber-duck it.** Explain your code out loud, line by line, to nobody. Where you go vague is where you don't understand it.
9. **The Serial Monitor is your debugger.** From Week 1 onward, when something is wrong, you print values — you don't guess.

---

## 3. How a Week Works

Every week's folder follows the same shape:

```
1. CONCEPT      (~30 min)  Read the week's programming idea. Text only, no hardware.
2. DRY RUN      (~20 min)  Trace 2–3 short code snippets on paper. Predict the output. No computer.
3. WIRE         (~15 min)  Build the circuit from the diagram. Explanation included, memorization not required.
4. GUIDED       (~90 min)  3–5 exercises that build on each other, with hints but not solutions.
5. DRILLS       (~60 min)  Same circuit, different behaviours. Speed reps for fluency.
6. CHALLENGE    (~60 min)  One problem with no hints. You will get stuck. That is the exercise.
7. JOURNAL      (~15 min)  Write the entry.
```

---

## 4. The Map

| Phase | Units | Theme | Core programming payload | Hardware in play |
|---|---|---|---|---|
| **0** | Week 0 | First Contact | Toolchain, compile/upload loop, what a program *is* | Board, 1 LED |
| **1** | Weeks 1–4 | Sequence, Repetition, Decomposition | Variables, types, loops, functions, arrays | LEDs, resistors, breadboard |
| **2** | Weeks 5–9 | Decisions, Input, and State | Conditionals, boolean logic, event vs state, `millis()`, state machines | Buttons, switches |
| **3** | Weeks 10–14 | Data and Algorithms | Analog input, scaling, buffers, moving averages, hysteresis, calibration | Potentiometer, LDR, thermistor, ultrasonic, joystick |
| **4** | Weeks 15–20 | Structuring Bigger Programs | Binary & bitwise ops, 2D arrays, structs, multi-file projects, your first class | Shift register, 8×8 matrix + MAX7219, buzzer, RGB LED |
| **5** | Weeks 21–25 | Text, Interfaces, Persistence | Strings & formatting, menus as nested state machines, command parsing, EEPROM | 1602 LCD, 7-seg displays, IR remote, joystick |
| **6** | Weeks 26–30 | Control Systems & Concurrency | Cooperative schedulers, function pointers, feedback loops, I²C libraries | Servo, DC motor + L293D, stepper, relay, MPU6050 |
| **7** | Weeks 31–36 | Craft & Capstone | Design-first, testing without a debugger, git, documentation, a real project | Whatever your project needs |

---

## 5. The Phases in Detail

> Each week below is a **stub**. Detailed exercises get written into `phase-N/week-NN/` as you reach them — see §9.

### Phase 0 — First Contact `[Week 0]`

Getting the machine to obey you at all.

| Week | Target | Programming concept |
|---|---|---|
| 0 | Install the IDE, upload Blink, wire one LED, print to Serial | The compile→upload→run cycle · statements · function calls · comments · what "syntax error" means |

**Checkpoint:** an LED you wired yourself blinks a rhythm you chose, and the Serial Monitor prints a message you wrote.

---

### Phase 1 — Sequence, Repetition, Decomposition `[Weeks 1–4]`

> 📁 **[`phase-1-sequence/`](phase-1-sequence/)** — phase overview written, [Week 1](phase-1-sequence/week-01-variables/) ready to start.

Four weeks, five LEDs, zero input. Everything here is about **the shape of code**.

| Week | Target | Programming concept |
|---|---|---|
| 1 | Blink patterns with named values | Variables · types (`int`, `bool`, `unsigned long`) · constants · naming things well · sequential execution |
| 2 | LED chase, bounce, binary counter on 4 LEDs | `for` and `while` loops · loop counters · nested loops · off-by-one errors |
| 3 | Reusable pattern generators: `chase(speed, times)`, `blinkN(pin, n)` | Functions · parameters · return values · DRY · decomposition · local vs global scope |
| 4 | Pattern *tables* — LEDs and sequences stored as data | Arrays · indexing · iterating a collection · **data-driven design** (change behaviour by editing data, not code) |

**Checkpoint project:** a **traffic light with a pedestrian phase**, purely timed. Requirement: adding a sixth LED or a new sequence must require editing *one array*, not rewriting logic.

---

### Phase 2 — Decisions, Input, and State `[Weeks 5–9]`

The program stops being a fixed script and starts *reacting*. This phase contains the single biggest conceptual leap in the plan (Week 7).

| Week | Target | Programming concept |
|---|---|---|
| 5 | Button controls LED, multiple buttons, combinations | `if` / `else if` / `else` · comparison operators · boolean logic `&&` `\|\|` `!` · truth tables |
| 6 | Toggle a light with a push button (press ≠ hold) | **State vs event** · edge detection (rising/falling) · remembering the previous reading · `INPUT_PULLUP` |
| 7 | Kill `delay()` forever — blink two LEDs at different rates, simultaneously | **`millis()` and non-blocking code** · time as data · cooperative multitasking · why blocking code is a dead end |
| 8 | Model behaviour explicitly: modes, transitions, guards | **Finite state machines** · `enum` · `switch` · transition tables · debouncing done properly |
| 9 | Consolidation & rewrite week | Refactoring · reading your own old code with fresh eyes |

**Checkpoint project (two parts):**
1. **Rewrite the Phase 1 traffic light** — now with a working pedestrian button, fully non-blocking, as an explicit state machine.
2. **Reaction-timer game** — random delay, LED fires, measure response in ms, track best score.

---

### Phase 3 — Data and Algorithms `[Weeks 10–14]`

The world sends you messy numbers. You learn to clean, transform, and reason about them.

| Week | Target | Programming concept |
|---|---|---|
| 10 | Potentiometer → LED brightness, → blink speed, → number of LEDs lit | `analogRead` · ranges & scaling · `map()` · integer vs float · **integer division traps** |
| 11 | Turn Serial into an instrument: print tables, watch the Plotter | Debugging methodology · print-driven development · formatting output · reading your program's mind |
| 12 | Smooth a noisy light sensor | Arrays as **circular buffers** · moving average · running min/max · algorithm over a data window |
| 13 | Thermistor → actual °C; light sensor → stable on/off threshold | Named constants over magic numbers · pure transform functions · **hysteresis** · calibration routines |
| 14 | Consolidation | Combining several sensors, one loop, no blocking |

**Checkpoint project:** a **smart night light / distance alarm** — smoothed sensor input, hysteresis so it never flickers at the threshold, live readings on Serial, thresholds set by the potentiometer.

---

### Phase 4 — Structuring Bigger Programs `[Weeks 15–20]`

Your files start getting long. This phase is about not drowning.

| Week | Target | Programming concept |
|---|---|---|
| 15 | Drive 8 LEDs from 3 pins (74HC595) | **Binary representation** · bitwise operators `&` `\|` `^` `<<` `>>` · bit masks · `bitWrite`/`bitRead` |
| 16 | Draw and animate sprites on the 8×8 matrix | **2D arrays** · nested loop mastery · frames · animation as an array of states |
| 17 | Group related data: a `Note`, a `Sprite`, an `LedChannel` | **`struct`** · custom types · arrays of structs · passing by value vs reference |
| 18 | Split one big `.ino` into `.h` / `.cpp` modules | Multi-file projects · header guards · `static` · declaration vs definition · **modularity** |
| 19 | Write your own `Button`, `Blinker`, `Debouncer` classes | Using libraries & reading APIs · **classes and objects** · encapsulation · designing an interface someone else could use |
| 20 | Consolidation | Rebuild an earlier project on top of your own library |

**Checkpoint project:** an **animated matrix display or music box** — scrolling text / sprite animation / melody player, assembled from *your own* reusable modules, where `loop()` is under 20 lines and reads like a summary.

---

### Phase 5 — Text, Interfaces, and Persistence `[Weeks 21–25]`

Programs that talk to humans and remember things.

| Week | Target | Programming concept |
|---|---|---|
| 21 | Get text onto the 1602 LCD, formatted and stable | `char` arrays vs `String` · `sprintf` · padding & alignment · why `String` is dangerous on a 2 KB machine |
| 22 | A navigable settings menu | **Nested state machines** · cursor/selection state · separating *model* from *view* |
| 23 | IR remote buttons and typed Serial commands → actions | **Lookup tables** · parsing input · mapping commands to behaviour · `switch` over data · function pointers (preview) |
| 24 | Settings and high scores that survive a power cut | **EEPROM** · serialization · memory as a resource · validation of stored data |
| 25 | Consolidation | Integration week |

**Checkpoint project:** a **menu-driven control panel** — LCD display, navigation by joystick *and* IR remote, at least three adjustable settings, all persisted across reboots.

---

### Phase 6 — Control Systems and Concurrency `[Weeks 26–30]`

Things that move, and programs that juggle.

| Week | Target | Programming concept |
|---|---|---|
| 26 | Servo, DC motor, and stepper under precise control | Abstraction over different actuators · one interface, several implementations |
| 27 | Run six behaviours at once without a single `delay()` | **Cooperative scheduler** · task tables · **function pointers / callbacks** · the event loop |
| 28 | Sensor → decision → actuator, closed loop | **Feedback control** · error terms · a simple proportional (P) controller · tuning as an empirical skill |
| 29 | Read the MPU6050 gyro/accelerometer | I²C in practice · structured sensor data · combining Phase 3 filtering with real 3-axis data |
| 30 | Consolidation | Systems thinking: what fails, and how you notice |

**Checkpoint project:** pick one — **obstacle-avoiding rover**, **gesture-controlled servo arm**, or **auto-levelling platform**. Must use the scheduler from Week 27 and the filtering from Week 12.

---

### Phase 7 — Craft and Capstone `[Weeks 31–36]`

Stop being someone who writes code. Start being someone who ships it.

| Week | Target | Programming concept |
|---|---|---|
| 31 | Design a project *before* writing it | Specs · pseudocode · flowcharts · module boundaries · estimating |
| 32 | Prove your code works without a debugger | Assertions · logging levels · test harnesses · **isolating logic so it can be tested off-hardware** |
| 33 | Version control and documentation for real | `git` beyond `commit -m "stuff"` · branches · writing a README others can follow · commenting *why*, not *what* |
| 34–36 | **Capstone** | Everything |

**Capstone candidates:** Simon Says (matrix + buzzer + buttons) · Snake on the 8×8 matrix (joystick) · a digital instrument · a weather station with logging · a home alarm system with remote arm/disarm.

**Closing session:** an explicit map of what you now know in C++ terms and where it lands in Python / JavaScript / Go, plus a recommended next step.

---

## 6. The Skills Ledger

The computer-science curriculum hiding inside the blinking lights. Tick these off — this list, not the gadgets, is the real deliverable.

**Fundamentals** — variables · primitive types · constants · operators · integer vs floating point · scope · sequential execution
**Control flow** — `if`/`else` · boolean algebra · `for` · `while` · `switch` · early return · nesting and when to stop nesting
**Decomposition** — functions · parameters · return values · pure vs side-effecting functions · DRY · single responsibility
**Data** — arrays · 2D arrays · circular buffers · `struct` · lookup tables · data-driven design · serialization
**Binary** — bits, bytes, masks, shifts, hex · why computers count the way they do
**Modelling** — finite state machines · events vs state · non-blocking time · cooperative scheduling · callbacks
**Algorithms** — search · min/max/average over a window · smoothing filters · hysteresis · debouncing · proportional control
**Architecture** — multi-file projects · headers · classes & encapsulation · designing an API · separating model from view
**Craft** — debugging by instrumentation · reading documentation · assertions & testing · version control · writing for future-you

---

## 7. Component Coverage

Not every part in the kit deserves your attention. Here is the honest split.

### Things you will *program* (the curriculum)

| Component | First appears | Used for |
|---|---|---|
| LEDs (red/green/yellow/blue/white) | Phase 0 | Loops, arrays, patterns — your primary output device for months |
| Resistor pack | Phase 0 | Always paired with LEDs and sensors; you'll be told which value |
| Breadboards (400-pt + mini) | Phase 0 | Everything |
| Switches / push buttons | Phase 2 | Conditionals, events, debouncing, state machines |
| 10k Potentiometer | Phase 3 | Analog input, scaling, live parameter tuning; also LCD contrast |
| Light sensors (LDR) ×2 | Phase 3 | Noisy data, filtering, thresholds, hysteresis |
| Thermistor | Phase 3 | Raw → real-world unit conversion |
| HC-SR04 ultrasonic | Phase 3 | Timing-based measurement, range logic |
| Joystick module | Phase 3 / 5 | Two-axis analog input, menu navigation, game control |
| 74HC595 shift register | Phase 4 | Binary and bitwise operations — 8 outputs from 3 pins |
| Piezo buzzer | Phase 4 | Arrays of notes, timing, feedback |
| RGB LED | Phase 4 | Three-channel state, colour as data |
| 8×8 LED matrix + MAX7219 | Phase 4 | 2D arrays, sprites, animation, games |
| 1-digit & 4-digit 7-seg displays | Phase 4 / 5 | Digit decomposition, multiplexing, number formatting |
| 1602 LCD | Phase 5 | Strings, formatting, menus, model/view separation |
| IR receiver + mini remote | Phase 5 | Command lookup tables, input parsing |
| SG90 servo | Phase 6 | Precise actuation, abstraction over actuators |
| DC motor + L293D | Phase 6 | Direction & speed control, closed-loop feedback |
| Stepper motor + driver | Phase 6 | Step sequencing, position vs speed control |
| 1-channel relay | Phase 6 | Switching logic, safe isolation of loads |
| MPU6050 gyro/accelerometer | Phase 6 | I²C, structured multi-axis data, sensor fusion basics |

### Things you will just *wire when told* (electronics plumbing)

These exist for electrical reasons, not programming ones. Each gets one paragraph of explanation when it appears, and never a quiz.

`BC547` / `BC557` / `PN2222` transistors · `1N4007` diodes (flyback protection for motors and the relay) · `0.1µF` capacitors (decoupling — noise suppression) · `10µF` / `100µF` capacitors (power smoothing near motors) · `22pF` capacitors (crystal oscillators — you will likely never use these) · 40-pin header · expansion shield (a convenience board — optional throughout) · 9V battery clip and 9V supply (external power for motors) · jumper wires · component box.

---

## 8. Electronics Survival Kit

Six facts. That is the entire prerequisite. Everything else is looked up when needed.

1. **The breadboard.** The long rails on the edges are `+` and `−` power lines running the full length. In the middle section, **five holes in a column are one connection**, and the centre channel separates the two halves — the five on one side are *not* connected to the five on the other. Adjacent columns are never connected, however close they look. Nothing else about it matters.
2. **Every LED needs a resistor.** LEDs have no self-control and will destroy themselves drawing current. `220Ω` or `330Ω` in series, always. Long leg = `+` (anode), short leg = `−` (cathode).
3. **Everything shares a GND.** Any two things that talk to each other must have their grounds connected. Roughly 80% of "it doesn't work" is a missing ground.
4. **Buttons need a defined resting state.** A floating input pin reads random noise. Either add a 10kΩ pull-down resistor, or use `pinMode(pin, INPUT_PULLUP)` and treat the button as inverted. This plan uses `INPUT_PULLUP` — one line of code instead of a resistor.
5. **The Arduino cannot power motors.** Motors, the stepper, and the relay coil draw far more current than a pin can supply. They get the external 9V supply, with grounds tied together. Powering a motor from a digital pin is the classic way to kill a board.
6. **Analog vs digital pins.** `D0–D13` are on/off in and out (`~` marked ones can fake in-between values with PWM). `A0–A5` can read a *range* of voltages — that's how sensors report numbers instead of yes/no. `A4`/`A5` are also the I²C pins used by the MPU6050.

> ⚠️ **Safety.** The relay can switch household mains voltage. Do not connect it to anything plugged into a wall outlet during this plan. Everything here runs on 5V and 9V, which are harmless. Mains is not.
>
> ⚠️ **Habit.** Unplug the USB cable before changing wiring. Every time.

---

## 9. Repo Structure

```
arduino-lab/
├── README.md                  ← this file: the big picture, revised as we go
├── JOURNAL.md                 ← one entry per week. The most valuable file here.
├── reference/
│   ├── cheatsheet-cpp.md      ← syntax reference, grown as concepts land
│   ├── cheatsheet-wiring.md   ← the six survival facts + circuits you've built
│   └── mistakes.md            ← every bug that cost you >20 minutes, and its cause
├── phase-0-first-contact/      ← WRITTEN
│   ├── README.md
│   └── week-00-setup/
│       ├── README.md           ← concept · dry run · exercises · drills · challenge
│       ├── wiring.md
│       ├── exercise-1-blink-builtin/exercise-1-blink-builtin.ino
│       └── challenge/challenge.ino
├── phase-1-sequence/           ← Week 1 WRITTEN
│   ├── README.md              ← phase overview + what "done" means
│   ├── week-01-variables/
│   │   ├── README.md          ← concept · dry run · wiring · exercises · drills · challenge
│   │   ├── wiring.md
│   │   ├── exercise-1-first-variable/exercise-1-first-variable.ino
│   │   ├── ... (5 exercises)
│   │   └── challenge/challenge.ino
│   └── week-02-loops/          ← written when you reach it
│       └── ...
├── phase-2-state/
└── ...
```

**Rule:** every `.ino` you write is committed, including the broken ones. In six months, `git log` is the proof you can point at.

---

## 10. Progress

**Status legend:** ⬜ not written yet · 🟨 written, not started · 🟦 in progress · ✅ done

### Phase 0 — First Contact
- [ ] 🟨 [Week 0](phase-0-first-contact/week-00-setup/) — Setup, first blink, first Serial print

### Phase 1 — Sequence, Repetition, Decomposition
- [ ] 🟨 [Week 1](phase-1-sequence/week-01-variables/) — Variables, types, constants
- [ ] ⬜ Week 2 — Loops
- [ ] ⬜ Week 3 — Functions
- [ ] ⬜ Week 4 — Arrays & data-driven design
- [ ] ⬜ **Checkpoint** — Timed traffic light

### Phase 2 — Decisions, Input, and State
- [ ] ⬜ Week 5 — Conditionals & boolean logic
- [ ] ⬜ Week 6 — State vs event, edge detection
- [ ] ⬜ Week 7 — `millis()` and non-blocking code
- [ ] ⬜ Week 8 — Finite state machines & debouncing
- [ ] ⬜ Week 9 — Consolidation
- [ ] ⬜ **Checkpoint** — Pedestrian traffic light + reaction timer

### Phase 3 — Data and Algorithms
- [ ] ⬜ Week 10 — Analog input & scaling
- [ ] ⬜ Week 11 — Serial as a debugging instrument
- [ ] ⬜ Week 12 — Buffers & moving averages
- [ ] ⬜ Week 13 — Calibration & hysteresis
- [ ] ⬜ Week 14 — Consolidation
- [ ] ⬜ **Checkpoint** — Smart night light / distance alarm

### Phase 4 — Structuring Bigger Programs
- [ ] ⬜ Week 15 — Binary & bitwise operations
- [ ] ⬜ Week 16 — 2D arrays & sprites
- [ ] ⬜ Week 17 — Structs & custom types
- [ ] ⬜ Week 18 — Multi-file projects
- [ ] ⬜ Week 19 — Your first classes
- [ ] ⬜ Week 20 — Consolidation
- [ ] ⬜ **Checkpoint** — Animated matrix display / music box

### Phase 5 — Text, Interfaces, and Persistence
- [ ] ⬜ Week 21 — Strings & formatting
- [ ] ⬜ Week 22 — Menus as nested state machines
- [ ] ⬜ Week 23 — Command parsing & lookup tables
- [ ] ⬜ Week 24 — EEPROM & persistence
- [ ] ⬜ Week 25 — Consolidation
- [ ] ⬜ **Checkpoint** — Menu-driven control panel

### Phase 6 — Control Systems and Concurrency
- [ ] ⬜ Week 26 — Actuators & abstraction
- [ ] ⬜ Week 27 — Cooperative scheduler & function pointers
- [ ] ⬜ Week 28 — Feedback loops & P control
- [ ] ⬜ Week 29 — I²C and the MPU6050
- [ ] ⬜ Week 30 — Consolidation
- [ ] ⬜ **Checkpoint** — Rover / arm / levelling platform

### Phase 7 — Craft and Capstone
- [ ] ⬜ Week 31 — Design before code
- [ ] ⬜ Week 32 — Testing & assertions
- [ ] ⬜ Week 33 — Git & documentation
- [ ] ⬜ Weeks 34–36 — **Capstone**

---

## 11. Open Questions

Things to confirm before the phases that need them:

- **1602 LCD:** does yours have an I²C backpack soldered to the back (a small board with 4 pins), or is it a bare 16-pin module? Wiring and code differ substantially. Affects Week 21.
- **Stepper motor:** most kits ship a 28BYJ-48 with a ULN2003 driver board. Confirm before Week 26.
- **Expansion shield:** identify the type (sensor shield vs prototyping shield). Treated as optional either way.
- **CR2032/CR2025 battery** for the IR remote and a **9V battery** are not included — needed by Weeks 23 and 26 respectively.

---

## 12. Next Step

**[Phase 0 — First Contact](phase-0-first-contact/) is written and ready to start.** Install the IDE, wire two LEDs, and go: [Week 0 →](phase-0-first-contact/week-00-setup/)

**[Phase 1 — Week 1](phase-1-sequence/week-01-variables/) is written too.** Once Week 0's challenge has made you type `digitalWrite` forty times, Week 1 gives every one of those numbers a name.

Weeks 2–4 get written as you reach them — deliberately, so they can adapt to what actually confused you.
