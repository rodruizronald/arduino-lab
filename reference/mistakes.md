# Mistakes

Every bug that cost you more than **20 minutes**, plus every compiler error you meet for the first time.

Two reasons this file exists:

1. **You will hit the same bug again.** Six weeks from now, a missing ground wire will look like a totally new problem. It won't be.
2. **Reading error messages is a learned skill.** Compiler errors are written for people who already know what they mean. The only way through is to build a personal translation table — which is exactly this file.

**Format:** what I saw → what it actually meant → how I found it.

---

## Compiler errors

### `expected ';' before '}' token`

**What it actually means:** a missing semicolon — but look at the line *above* the one it points to. The compiler notices the problem when it reaches the next thing, so it reports the location one step too late.

**How to find it:** start at the reported line, read upward until you find a statement with no `;`.

---

<!--
    Week 0, Exercise 1 "Break it" — fill these in yourself.
    Copy the EXACT message, don't paraphrase it.

### <paste the error from deleting the final '}'>

**What it actually means:**
**How I found it:**

---

### <paste the error from changing delay to Delay>

**What it actually means:**
**How I found it:**

---

### <paste the error from changing digitalWrite to digitalwrite>

**What it actually means:**
**How I found it:**

---
-->

> **Reading long errors:** when the output is 40 lines, **read the first error only.** Everything below it is usually wreckage caused by the first one. Fix the top one, recompile, look again.

---

## Wiring mistakes

### LED doesn't light, code is definitely correct

**Cause, in order of likelihood:**
1. LED is backwards — long leg toward the resistor/pin, short leg toward GND. *(Backwards is not damaged, just silent.)*
2. No wire from the breadboard `−` rail to an Arduino `GND` pin
3. A leg is in the wrong column — same column = connected, adjacent column = not

---

## Logic errors

The expensive ones. These compile cleanly and do the wrong thing. No error message will ever point at them — the only way one gets recorded is if you notice and write it down.

### A duration that goes negative — `int` overflow

**What I saw:** an `int` holding milliseconds went past 32,767 and came back as a negative number. Then `delay()` sat there for what looked like forever.

**What it actually means:** `int` on this board is 16 bits and stops at 32,767 — about 33 seconds in milliseconds. Past that it wraps silently to the most negative value and keeps going. `delay()` takes an `unsigned long`, so a negative `int` is reinterpreted as an enormous positive one: `-25536` becomes roughly 50 days.

**Why it's here and not in Compiler errors:** the grammar was perfect. Nothing was reported, at any point. The program ran and produced a confident wrong answer.

**How to find it:** print the value. A duration that is negative, or far smaller than it should be, has overflowed. Check the intermediate steps too — `int + int` wraps *before* the result is stored, even if you store it in an `unsigned long`.

**The fix:** `unsigned long` for any value in milliseconds that gets added to another one.

*(Week 1, Exercise 3.)*

---

<!--
    Add yours as you find them. From Week 5 onward this section grows
    fast, and by Week 12 it will be the longest in the file.
-->
