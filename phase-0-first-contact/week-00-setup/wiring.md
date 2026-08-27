# Week 0 — Wiring

**Circuit:** two LEDs, on pins 8 and 9. You'll use this same circuit for every exercise, drill, and the challenge.

> ⚠️ **Unplug the USB cable before you touch the wiring.** Every time, for the rest of this plan.

---

## 1. How a breadboard works

This is the only thing you need to understand, and it takes thirty seconds.

```
        1   2   3   4   5   6   7   8   9  10  11  12 ...
      ┌──────────────────────────────────────────────────┐
   +  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ ← power rail: ALL connected
   −  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ ← ground rail: ALL connected
      │                                                  │
   J  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ ┐
   I  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ │  these five holes
   H  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ ├─ are one connection
   G  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ │
   F  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ ┘
      ╞════════════════ CENTRE CHANNEL ══════════════════╡ ← nothing crosses this
   E  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ ┐
   D  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ │  and these five are
   C  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ ├─ a SEPARATE connection
   B  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ │
   A  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │ ┘
      │                                                  │
   +  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │
   −  │ ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·   ·    │
      └──────────────────────────────────────────────────┘
```

**Two rules, and that's the whole device:**

1. **Same column, same side of the channel = electrically the same point.** `A7`, `B7`, `C7`, `D7`, `E7` are one wire as far as electricity is concerned. Anything plugged into any of them is connected to everything in the others.
2. **The long `+` and `−` rails run the full length.** Every hole in the `−` rail is the same point.

`E7` and `F7` look adjacent but are **not** connected — the centre channel separates them. That channel exists so chips can straddle it with their legs in two separate groups; you'll use that in Phase 4.

> Your board's letters may be printed on one edge only, or not at all. Doesn't matter — the physical grouping is always five-in-a-column, split by the channel.

---

## 2. Identifying your parts

### The LED

```
        ╭───╮
        │   │        LONG leg  = ANODE   = "+"  → goes toward the resistor and the pin
        │   │        SHORT leg = CATHODE = "−"  → goes toward GND
        ╰┬─┬╯
         │ │         Also: the plastic rim has a FLAT SPOT on the
         │ │         short-leg (cathode) side, in case the legs got trimmed.
         │ │
      long short
```

An LED only works one way round. Backwards, it just sits there silently — **it is not damaged**, so if nothing lights, flip it before you panic.

### The resistor

Use **200Ω** or **330Ω**. Either one is fine for an LED; there's no meaningful difference you'll be able to see.

| Value | Colour bands |
|---|---|
| 200Ω | red · black · brown |
| 330Ω | orange · orange · brown |

The fourth band (usually gold) is a tolerance marking — ignore it. If you genuinely can't tell the colours apart, any resistor between 200Ω and 1kΩ will work; a bigger value just gives a dimmer LED. Do **not** use the 10Ω or 100Ω ones, and do not skip the resistor entirely.

Resistors have no direction. Either way round is fine.

> **Why it's there:** an LED has no self-control. Given the chance it will draw current until it destroys itself, and possibly damages the pin driving it. The resistor caps how much can flow. That's the entire explanation, and you don't need more of it for this plan.

---

## 3. Build it

Column numbers below are just a suggestion — use any columns you like, as long as things that need to connect share a column. If you shift one part, shift the whole group with it.

### Red LED → pin 8

| Step | Part | From | To |
|---|---|---|---|
| 1 | Red LED | **long** leg → `E10` | **short** leg → `E11` |
| 2 | Resistor (200Ω/330Ω) | `A10` | `A6` |
| 3 | Jumper wire | Arduino pin **8** | `B6` |
| 4 | Jumper wire (black) | `A11` | breadboard `−` rail |

### Green LED → pin 9

| Step | Part | From | To |
|---|---|---|---|
| 5 | Green LED | **long** leg → `E20` | **short** leg → `E21` |
| 6 | Resistor (200Ω/330Ω) | `A20` | `A16` |
| 7 | Jumper wire | Arduino pin **9** | `B16` |
| 8 | Jumper wire (black) | `A21` | breadboard `−` rail |

### The one that everybody forgets

| Step | Part | From | To |
|---|---|---|---|
| 9 | Jumper wire (black) | breadboard `−` rail | Arduino **`GND`** |

**Without step 9, nothing works.** The circuit has no return path. The UNO has three `GND` pins; any of them will do.

---

## 4. Trace the path

Follow it with your finger before you plug in the USB. Electricity leaves the pin, goes through the resistor, through the LED, and back to ground:

```
  Arduino pin 8 ──► resistor ──► LED long leg
                                     │
                                  (through the LED — light comes out here)
                                     │
                                LED short leg ──► − rail ──► Arduino GND
```

If you can trace that unbroken loop with your finger, it will work. If you can't find one of those hops, that's your bug — and you found it before powering anything on, which is exactly the habit to build.

---

## 5. Before you plug in

- [ ] Both LEDs: long leg toward the resistor, short leg toward the `−` rail
- [ ] Both resistors actually bridge **two different columns** (a resistor with both legs in the same column does nothing)
- [ ] A wire runs from the `−` rail to an Arduino `GND` pin
- [ ] Nothing at all is plugged into pins **0** or **1** (those are the USB pins — using them breaks uploads)
- [ ] No bare leg is touching another bare leg

Now plug in the USB.

**Nothing will light yet.** You haven't uploaded a program that drives pins 8 and 9. That's Exercise 3. If something *is* lit, you've got a wire in the `+` rail that shouldn't be there.

---

## 6. Add this to your reference

Once it works, copy the pin assignments into [`reference/cheatsheet-wiring.md`](../../reference/cheatsheet-wiring.md). By Phase 4 you'll have a dozen circuits and no memory of any of them.
