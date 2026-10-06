# Week 2 — Dry run

## A

**Prediction** — every line printed, in order; how many times `i < 4` is checked:

I think it will print 0, 1, 2, 3, and then "done".
I think `i < 4` is checked 4 times because the loop runs 4 times.

**What actually happened:**

It printed 0, 1, 2, 3, and then "done".
`i < 4` was checked 5 times, not 4. The last check happens when `i` is 4, and that false condition stops the loop.

---

## B

**Prediction** — number of `a`s, number of `b`s, the numbers from the third loop:

I think it will print 4 `a`s and 6 `b`s.
I think the third loop will print 10, 7, 4, 1 because it subtracts 3 each time.

**What actually happened:**

It printed 4 `a`s and 6 `b`s.
The third loop printed 10, 7, 4, 1.
My prediction was correct.

---

## C

**Prediction** — draw the output; total `*`; what's unusual about the inner condition:

I think the output will be:

*
**
***

There will be 6 stars in total.
The unusual part is that the inner loop condition depends on `row`.

**What actually happened:**

It printed:

*
**
***

There were 6 stars in total.
The inner loop ran a different number of times depending on the value of `row`, as I expected.

---

## D1

**Prediction** — how many flashes, and why:

I think the LED will not flash because there is a semicolon after the `for` loop.

**What actually happened:**

The LED flashed 1 time.
The semicolon made the `for` loop have an empty body. After the loop finished, the LED block ran only once.

---

## D2

**Prediction** — does `finished` print? Why or why not:

I think it will count up to 255 and then "finished" will print because 255 is the maximum value of a `byte`.

**What actually happened:**

"finished" did not print.
After `i` reached 255, it went back to 0 and started counting again. Because of this, the loop never ended.

---

## D3

**Prediction** — does `liftoff` print? The fifth number on screen:

I think it will print 3, 2, 1, 0, and then "liftoff".
I think there will not be a fifth number because the loop will stop after 0.

**What actually happened:**

"liftoff" did not print.
The fifth number was 4294967295.

After `n` reached 0, it could not become -1 because it is unsigned. Instead, it wrapped to its maximum value, so the loop continued.

**With compiler warnings on "All"** — which of D1, D2, D3 did the compiler warn about?

All three produced warnings in the separate AVR compiler checks with `-Wall -Wextra`. These were warnings, not errors, so the snippets still compiled.

- D1: `warning: this 'for' clause does not guard... [-Wmisleading-indentation]`. The semicolon ends the loop body. The block below runs once. This warning can depend on the indentation.
- D2: `warning: comparison is always true due to limited range of data type [-Wtype-limits]`. A byte stays between 0 and 255, so it is always less than 256.
- D3: `warning: comparison of unsigned expression >= 0 is always true [-Wtype-limits]`. An unsigned number cannot be negative, so this condition never stops the loop.

The wording above comes from the separate compiler checks, rather than a copied IDE message. The board results for the Week 2 tests were confirmed by me after testing.