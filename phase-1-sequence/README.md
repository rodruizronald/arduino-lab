# Phase 1 — Sequence, Repetition, Decomposition

**Units:** Weeks 1–4 (~4–6 focused hours each)
**Hardware:** the board, a breadboard, up to 5 LEDs, 5 resistors, jumper wires. **No input devices at all.**

---

## Why this phase exists

Phase 0 proved the machine obeys you. This phase is about **the shape of the code you give it**.

Nothing here reacts to the outside world. There are no buttons, no sensors, no decisions. Every program in these four weeks is a fixed script that runs the same way every time. That constraint is deliberate: it means the *only* thing that can vary between a bad program and a good one is how it's written.

You already built a working program in Week 0. It was ~190 lines, it was correct, and it was miserable. Every one of the next four weeks removes one specific kind of misery:

| Week | The misery it kills | The tool |
|---|---|---|
| 1 | Numbers scattered through the code with no names | **Variables and constants** |
| 2 | The same block of lines, typed again and again | **Loops** |
| 3 | The same *idea* expressed in several places | **Functions** |
| 4 | Behaviour welded into logic, so changing it means rewriting | **Arrays and data-driven design** |

Each will feel like relief. It only feels like relief because you did it the hard way in Week 0.

> **A warning about Week 4.** The last week of this phase asks you to *rewrite* something that already works. Rule 6 exists because of weeks like it. Re-solving a solved problem with better tools is the single highest-value activity in this plan, and it is the one your brain will most want to skip. Don't.

---

## What you'll be able to do when it's done

- Declare a variable, pick the right type for it, and explain what the type actually buys you
- Know why an `int` on this board dies at 32767, and what to use instead
- Name things so that a stranger — including you in three months — can read your code without a decoder ring
- Write a `for` loop, reason about its bounds, and spot an off-by-one before uploading
- Break a program into functions with parameters, and say what each one is responsible for
- Store behaviour as **data** rather than code, so that changing what the program does means editing a table, not rewriting logic
- Look at your own Week 0 challenge and see exactly what's wrong with it

---

## Contents

| Week | Folder | Target | Concept |
|---|---|---|---|
| 1 | [`week-01-variables/`](week-01-variables/) | Blink patterns driven by named values | Variables · types · constants · naming · sequential execution |
| 2 | ⬜ `week-02-loops/` | LED chase, bounce, binary counter | `for` / `while` · counters · nesting · off-by-one |
| 3 | ⬜ `week-03-functions/` | Reusable pattern generators | Functions · parameters · return values · DRY · scope |
| 4 | ⬜ `week-04-arrays/` | Pattern *tables* | Arrays · indexing · iteration · data-driven design |

Weeks 2–4 get written as you reach them. Finish Week 1 first — the plan is deliberately not written ahead, so it can adapt to what actually confuses you.

---

## The hardware, once

You build the circuit in Week 1 and **leave it standing for the whole phase**. Weeks 2–4 add LEDs to it but never tear it down.

That's not laziness. Rule 4: one new concept at a time. If the wiring changed every week, half your debugging time would go on circuits instead of code — and the point of these four weeks is entirely code.

---

## Checkpoint — how you know Phase 1 is done

The checkpoint project is a **traffic light with a pedestrian phase, purely timed** — no button yet, the pedestrian phase just happens on schedule.

You've passed when **all five** are true:

- [ ] The traffic light runs a correct, readable cycle including a pedestrian phase.
- [ ] **Adding a sixth LED, or a new phase in the sequence, requires editing one array — not rewriting logic.** This is the real test. If a new phase means new `digitalWrite` lines, you have written Week 0 code with better spelling.
- [ ] There is not a single unexplained number in the file. Every duration and every pin has a name.
- [ ] `loop()` is short enough to read in one screen and describes *what happens*, not *how*.
- [ ] You can open your Week 0 challenge, and list out loud the four specific things wrong with it.

That last one is the actual graduation requirement. Being able to write good code matters less, right now, than being able to *see* why the old code was bad.

---

**Next:** [Week 1 →](week-01-variables/)
