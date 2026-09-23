# Wiring Cheatsheet

Circuits you've actually built, plus the minimum electronics knowledge this plan needs. Add each new circuit as you build it — by Phase 4 you'll have a dozen and no memory of any of them.

---

## The six facts

1. **Breadboard.** The long `+` / `−` rails run the full length. In the middle, **five holes in a column are one connection**, and the centre channel separates the two halves. Adjacent columns are not connected, no matter how close they look.
2. **Every LED needs a resistor.** 200Ω or 330Ω in series. Long leg = anode = `+`, short leg = cathode = `−` (also marked by a flat spot on the rim). An LED will otherwise draw current until it destroys itself.
3. **Everything shares a GND.** Any two things that interact must have their grounds connected. Roughly 80% of "it doesn't work" is a missing ground wire.
4. **Buttons need a defined resting state.** A floating input pin reads random noise. This plan uses `pinMode(pin, INPUT_PULLUP)` — one line of code instead of a resistor, with the button reading inverted. *(Week 5.)*
5. **The Arduino cannot power motors.** Motors, the stepper and the relay coil draw far more current than a pin can supply. They get the external 9V supply, grounds tied together. *(Phase 6.)*
6. **Analog vs digital pins.** `D0`–`D13` are on/off. `A0`–`A5` read a *range* of voltages — that's how sensors report numbers instead of yes/no. `A4`/`A5` double as the I²C pins used by the MPU6050.

> ⚠️ **Unplug the USB before changing any wiring.** Every time.
> ⚠️ **Never use pins 0 or 1.** They're the USB pins — anything attached breaks uploads.
> ⚠️ **Never connect the relay to mains voltage** during this plan. 5V and 9V are harmless. Mains is not.

---

## Circuits built

### Week 0 — Two LEDs

| Pin | Component | Notes |
|---|---|---|
| 8 | Red LED | via 200Ω/330Ω resistor to anode; cathode → `−` rail |
| 9 | Green LED | same |
| `GND` | → breadboard `−` rail | the one everybody forgets |

```
  pin 8 ──► resistor ──► LED long leg
                             │
                        LED short leg ──► − rail ──► GND
```

Full build instructions: [`phase-0-first-contact/week-00-setup/wiring.md`](../phase-0-first-contact/week-00-setup/wiring.md)

### Week 1 — Three LEDs (kept for all of Phase 1)

Green moves from pin 9 to pin 10; yellow takes pin 9. Stack them physically red / yellow / green, top to bottom.

| Pin | Component | Notes |
|---|---|---|
| 8 | Red LED | unchanged from Week 0 |
| 9 | Yellow LED | new |
| 10 | Green LED | moved from pin 9 |
| `GND` | → breadboard `−` rail | shared by all three cathodes |

Each LED is the same hop: `pin → resistor → long leg … short leg → − rail → GND`.

Full build instructions: [`phase-1-sequence/week-01-variables/wiring.md`](../phase-1-sequence/week-01-variables/wiring.md)

> Once the pins have names in your code (`PIN_RED`, `PIN_YELLOW`, `PIN_GREEN`), moving an LED to a different pin costs one line. That is the point of Week 1, demonstrated in hardware.

### Actual Week 1 breadboard — 30 rows

| LED | Anode | Cathode | Resistor | Signal jumper | Ground jumper |
|---|---|---|---|---|---|
| Red | E10 | E11 | A6–A10 | pin 8–B6 | A11–negative rail |
| Yellow | E20 | E21 | A16–A20 | pin 9–B16 | A21–negative rail |
| Green | E29 | E30 | A27–A29 | pin 10–B27 | A30–negative rail |

The negative rail connects to Arduino GND. The green layout replaces the suggested row 31, which this breadboard does not have. A–E with the same row number share a connection. Keep a separate series resistor for each LED and unplug USB before changing wiring.

<!-- Week 5 — buttons: add here -->

---

## Resistor colour codes

Only the ones this plan actually uses. First three bands; the gold fourth band is tolerance, ignore it.

| Value | Bands | Used for |
|---|---|---|
| 200Ω | red · black · brown | LEDs |
| 330Ω | orange · orange · brown | LEDs |
| 1kΩ | brown · black · red | general |
| 10kΩ | brown · black · orange | pull-downs, sensor dividers |

Resistors have no direction — either way round is fine.
