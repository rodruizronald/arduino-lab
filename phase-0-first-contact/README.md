# Phase 0 — First Contact

**Units:** Week 0 (one session, ~5 hours + install time)
**Hardware:** the board, a USB cable, 2 LEDs, 2 resistors, a breadboard, 5 jumper wires

---

## Why this phase exists

Before you can learn to program, three things have to be true, and none of them are about programming:

1. **The toolchain works.** Your computer can see the board, compile a program, and push it over the cable. Until this is true, every bug you hit is ambiguous — is my code wrong, or is my setup wrong? That ambiguity is poison for a beginner. We remove it on day one.
2. **You've seen what a program looks like.** Not "understood" — *seen*. The shape of it. Braces, semicolons, indentation. The visual grammar has to stop looking like noise.
3. **You trust the feedback loop.** Change a number → upload → the physical world changes. Once your body believes that loop is real and fast, experimenting stops feeling risky and starts feeling like play. That is the engine the next 36 weeks run on.

This phase is short on concepts and long on friction. That is intentional. Get the friction out of the way now.

---

## What you'll be able to do when it's done

- Write, compile, and upload a program without looking anything up
- Read a compiler error and know roughly where to look
- Explain, out loud, what `setup()` and `loop()` do and why there are two of them
- Wire an LED to any pin, correctly, from memory
- Print a message from the board to your screen — your first and most important debugging tool
- Tell the difference between "the computer refused my code" and "the computer ran my code and it was wrong"

---

## Contents

| Week | Folder | Target |
|---|---|---|
| 0 | [`week-00-setup/`](week-00-setup/) | Setup, first blink, first Serial print |

---

## Checkpoint — how you know Phase 0 is done

You've passed when **all four** are true:

- [ ] An LED **you wired yourself** (not the one soldered to the board) blinks a rhythm **you designed**, and you can explain every line of the program that drives it.
- [ ] The Serial Monitor shows a message you wrote, updating live as the program runs.
- [ ] You have deliberately caused at least **four different compiler errors**, and recorded what each one said in [`reference/mistakes.md`](../reference/mistakes.md).
- [ ] You completed the challenge, and you found it **tedious**. (If it wasn't tedious, you took a shortcut you haven't learned yet. Go back.)

That last one is not a joke. The challenge is designed to make you feel the absence of loops. Week 2 will feel like a gift.

---

**Next:** [Week 0 →](week-00-setup/)
