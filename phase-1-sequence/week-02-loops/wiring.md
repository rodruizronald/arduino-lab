# Week 2 — Wiring

**Circuit:** the Week 1 traffic light, plus one **blue** LED on pin **7**.

| Pin | LED | |
|---|---|---|
| 7 | Blue | **new** |
| 8 | Red | unchanged |
| 9 | Yellow | unchanged |
| 10 | Green | unchanged |

> ⚠️ **Unplug the USB cable before you touch the wiring.** Every time.

---

## 1. Why pin 7, and why at that end

This week's loops step through pin numbers: 7, 8, 9, 10. For a light to *look* like it's travelling, the LEDs need to sit on the breadboard **in pin order**.

Your three LEDs already run red → yellow → green along the row, on pins 8 → 9 → 10. The space that's free is at the **red end** — columns 1 to 5, before red's resistor starts at column 6. So the new LED goes there, and it gets the pin that comes *before* 8.

The row, end to end:

```
  column:   1 ─── 5     6 ────── 11    16 ───── 21    ~26 ──── 30
            ┌─────┐     ┌────────┐     ┌────────┐     ┌────────┐
            │BLUE │     │  RED   │     │ YELLOW │     │ GREEN  │
            │pin 7│     │ pin 8  │     │ pin 9  │     │ pin 10 │
            └─────┘     └────────┘     └────────┘     └────────┘
```

Your Week 1 programs still run exactly as before. They never mention pin 7, so they ignore it.

> A 400-point breadboard has **30 columns**. If you built green in the Week 1 layout and found there's no column 31, you've already shifted it left a little — that's fine. Columns 1–5 are free either way.

---

## 2. Build it

The same three hops as every other LED: **pin → resistor → LED long leg → LED short leg → `−` rail**.

### Blue LED → pin 7

| Step | Part | From | To |
|---|---|---|---|
| 1 | Blue LED | **long** leg → `E4` | **short** leg → `E5` |
| 2 | Resistor (200Ω/330Ω) | `A1` | `A4` |
| 3 | Jumper wire | Arduino pin **7** | `B1` |
| 4 | Jumper wire (black) | `A5` | `−` rail |

The resistor spans only three holes here, so bend its legs close to the body. If it won't sit, move the whole group — any columns work, as long as the three hops connect and the blue LED ends up **beside red, at the end of the row**.

Check column 5 and column 6 carefully. They're neighbours, and they must stay separate: column 5 is blue's ground, column 6 is red's resistor. Adjacent columns are never connected, however close they look.

---

## 3. Trace the path

```
  Arduino pin 7 ──► resistor (A1→A4) ──► BLUE long leg (E4)
                                              │
                                         (light comes out here)
                                              │
                                         BLUE short leg (E5) ──► A5 ──► − rail ──► GND
```

Four unbroken loops now, one per LED, all sharing the one `−` rail and the one wire to `GND`.

---

## 4. Before you plug in

- [ ] Blue: **long** leg toward the resistor, **short** leg toward the `−` rail
- [ ] The resistor bridges **two different columns** (1 and 4)
- [ ] Nothing in column 5 touches anything in column 6
- [ ] The `−` rail still has its wire to an Arduino `GND` pin
- [ ] Nothing is plugged into pins **0** or **1**

Plug in the USB. Whatever program is on the board from Week 1 carries on — and **blue stays dark**, because nothing drives pin 7 yet. That's the correct result, not a fault.

---

## 5. Test it before Exercise 1

Don't wait until the chase to find out blue is backwards. Take any Week 1 blink, change its pin constant to `7`, and upload. One edit. If blue blinks, you're done; set the constant back.

If it doesn't:

1. **Backwards.** Flip it. Backwards is silent, not broken.
2. **Wrong column.** Count the holes — especially columns 4 and 5.
3. **Wrong pin.** Is the jumper really in **7**, not 6 or 8?

---

## 6. Add this to your reference

Once it works, add the four-LED row to [`reference/cheatsheet-wiring.md`](../../reference/cheatsheet-wiring.md).
