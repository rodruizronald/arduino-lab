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

### `expected '}' at end of input`

**What it actually means:** A closing brace `}` is missing.

**How I found it:** The compiler reached the end of the program expecting a `}`, so I checked the braces and found the missing final `}`.

---

### `'Delay' was not declared in this scope`

**What it actually means:** C++ is case-sensitive. `Delay` and `delay` are different names.

**How I found it:** The compiler suggested `delay`, so I changed `Delay` back to `delay`. 

---

### `'digitalwrite' was not declared in this scope`

**What it actually means:** C++ is case-sensitive. `digitalwrite` is not the same function as `digitalWrite`.

**How I found it:** I compared the function name with the correct spelling and noticed the uppercase `W`.

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

<!--
    The expensive ones. These compile cleanly and do the wrong thing.
    Nothing here yet — you'll start collecting them around Week 5,
    and by Week 12 this section will be the longest in the file.
-->
