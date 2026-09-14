# Week 1 — Wiring

**Circuit:** three LEDs — red, yellow, green — on pins **8**, **9** and **10**.

You will keep this circuit for the **whole of Phase 1**. Weeks 2–4 add LEDs to it; nothing gets torn down.

> ⚠️ **Unplug the USB cable before you touch the wiring.** Every time.

---

## 1. What changes from Week 0

Almost nothing. You already have red on pin 8 and green on pin 9. Two edits:

| | Week 0 | Week 1 |
|---|---|---|
| Pin 8 | Red | Red — **unchanged** |
| Pin 9 | Green | **Yellow** |
| Pin 10 | — | **Green** (moved from pin 9) |

So: **move the green LED's jumper from pin 9 to pin 10**, then add a yellow LED on pin 9 between the two.

Arrange them physically **top to bottom: red, yellow, green** — like a real traffic light. You'll be grateful for that in the challenge.

> **Why bother rearranging?** Because from this week on, your code refers to `PIN_YELLOW`, not `9`. Once a wire has a name in the program, moving it costs one line. Proving that to yourself is Exercise 2.

---

## 2. Build it

Each LED is the same three-part hop you already know: **pin → resistor → LED long leg → LED short leg → `−` rail**.

Column numbers are a suggestion. Use whatever columns you like, as long as things that must connect share one.

### Red LED → pin 8 *(already built — leave it alone)*

| Step | Part | From | To |
|---|---|---|---|
| 1 | Red LED | **long** leg → `E10` | **short** leg → `E11` |
| 2 | Resistor (200Ω/330Ω) | `A10` | `A6` |
| 3 | Jumper wire | Arduino pin **8** | `B6` |
| 4 | Jumper wire (black) | `A11` | `−` rail |

### Yellow LED → pin 9 *(new)*

| Step | Part | From | To |
|---|---|---|---|
| 5 | Yellow LED | **long** leg → `E20` | **short** leg → `E21` |
| 6 | Resistor (200Ω/330Ω) | `A20` | `A16` |
| 7 | Jumper wire | Arduino pin **9** | `B16` |
| 8 | Jumper wire (black) | `A21` | `−` rail |

### Green LED → pin 10 *(moved)*

| Step | Part | From | To |
|---|---|---|---|
| 9 | Green LED | **long** leg → `E30` | **short** leg → `E31` |
| 10 | Resistor (200Ω/330Ω) | `A30` | `A26` |
| 11 | Jumper wire | Arduino pin **10** | `B26` |
| 12 | Jumper wire (black) | `A31` | `−` rail |

### The one that everybody forgets

| Step | Part | From | To |
|---|---|---|---|
| 13 | Jumper wire (black) | `−` rail | Arduino **`GND`** |

You already have this from Week 0. Check it's still there anyway — it is the single most common reason a circuit that "worked yesterday" stops working.

---

## 3. Trace the path

Before you plug in, follow one LED with your finger, all the way round:

```
  Arduino pin 9 ──► resistor ──► YELLOW long leg
                                      │
                                 (light comes out here)
                                      │
                                 YELLOW short leg ──► − rail ──► Arduino GND
```

Three unbroken loops, one per LED, all returning to the same `−` rail. If you can trace all three, it will work.

---

## 4. Before you plug in

- [ ] All three LEDs: **long** leg toward the resistor, **short** leg toward the `−` rail
- [ ] All three resistors bridge **two different columns** (both legs in one column does nothing)
- [ ] A wire runs from the `−` rail to an Arduino `GND` pin
- [ ] The old green jumper is on pin **10** now, not pin 9
- [ ] Nothing is plugged into pins **0** or **1**
- [ ] No bare leg touching another bare leg

Plug in the USB. **Nothing should light** — the program still on the board from Week 0 drives pins 8 and 9, so you may see the red and the *yellow* LED blinking. That's correct and it's a useful thing to notice: the board doesn't know you changed the colour. The pin number is all it ever knew.

---

## 5. If one LED doesn't light

Work down this list. It's the same list as Week 0, in the same order, because these are still the answers.

1. **The LED is backwards.** Long leg toward the resistor. Backwards is silent, not broken — just flip it.
2. **No ground.** `−` rail → `GND`.
3. **A leg is in the wrong column.** Same column = connected. One column over = not connected, no matter how close it looks. Count the holes.
4. **You're driving the wrong pin.** Now that you have three LEDs, this is a new and very likely failure. Check the jumper goes to the pin your code names.

If *two* LEDs light when only one should, you have two jumpers in the same breadboard column.

---

## 6. Add this to your reference

Once it works, copy the pin assignments into [`reference/cheatsheet-wiring.md`](../../reference/cheatsheet-wiring.md).
