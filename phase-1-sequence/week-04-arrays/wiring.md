# Week 4 — Wiring

**Circuit:** the Week 2 row, plus one **white** LED on pin **12**, on the other half of the breadboard.

| Pin | LED | |
|---|---|---|
| 7 | Blue | unchanged |
| 8 | Red | unchanged |
| 9 | Yellow | unchanged |
| 10 | Green | unchanged |
| 12 | White | **new** — other half of the board |

> ⚠️ **Unplug the USB cable before you touch the wiring.** Every time.

---

## 1. Why pin 12, and why over there

Both choices are deliberate.

- **Pin 12, not 11.** Skipping a pin means no loop of the form `FIRST_PIN … LAST_PIN` can reach it. Only a list can.
- **The other half of the board, out of line.** In Week 2 the LEDs had to sit in pin order for a chase to *look* like a chase. That's over. From now on, **the array decides the order**, not the breadboard. The white LED sits wherever it fits.

And practically: a 400-point board has 30 columns, and the row of four already fills the bottom half.

---

## 2. The second ground rail

So far everything has used the **bottom** `−` rail, next to row A. The white LED sits on the **top** half, next to the **top** rails.

**The top and bottom rails are not connected to each other.** Each side's `+` and `−` run the full length of the board, but nothing joins the top pair to the bottom pair. So the top `−` rail is floating until you wire it — and an LED grounded to it will stay dark.

One black jumper fixes that for good:

| Step | Part | From | To |
|---|---|---|---|
| 1 | Jumper wire (black) | top `−` rail | bottom `−` rail |

Now both `−` rails are ground. Use any free hole at either end of the board.

---

## 3. Build it

The same three hops as every other LED, mirrored onto the top half. Columns are a suggestion.

```
   top + rail
   top − rail  ◄──────────────────────────── J25 (ground jumper)
         J   J20 ──resistor── J24
         I   I20 ◄── pin 12
         H
         G
         F                    F24 (long)  F25 (short)
   ═══════════ centre channel ═══════════
         E   … the Week 2 row, unchanged …
```

### White LED → pin 12

| Step | Part | From | To |
|---|---|---|---|
| 2 | White LED | **long** leg → `F24` | **short** leg → `F25` |
| 3 | Resistor (200Ω/330Ω) | `J20` | `J24` |
| 4 | Jumper wire | Arduino pin **12** | `I20` |
| 5 | Jumper wire (black) | `J25` | **top** `−` rail |

Check it: column 20 on the top half joins pin 12 to the resistor. Column 24 joins the resistor to the LED's long leg. Column 25 joins the short leg to the top `−` rail — which, after step 1, is ground.

Nothing on the top half (rows F–J) is connected to anything on the bottom half (rows A–E). The centre channel separates them, so the new LED can't interfere with the row.

---

## 4. Before you plug in

- [ ] White: **long** leg toward the resistor, **short** leg toward the top `−` rail
- [ ] The resistor bridges two different columns (20 and 24)
- [ ] The jumper is in pin **12** — not 11, not 13
- [ ] The **top** `−` rail is joined to the **bottom** `−` rail
- [ ] The bottom `−` rail still goes to an Arduino `GND` pin
- [ ] Nothing in pins **0** or **1**

---

## 5. Test it before Exercise 1

Take any one-LED blink from an earlier week, change its pin to `12`, and upload. One edit.

If white doesn't light:

1. **The rail bridge.** This is the new failure — check step 1 first.
2. **Backwards.** Flip it.
3. **Wrong pin.** Pin 13 has its own LED on the board, so a jumper in 13 by mistake makes the *board's* light blink instead. Pin 11 does nothing.

---

## 6. Add this to your reference

Add the white LED and the rail bridge to [`reference/cheatsheet-wiring.md`](../../reference/cheatsheet-wiring.md). The rail fact — **top and bottom rails are separate until you join them** — is worth its own line. You'll need it again every time a circuit spreads across both halves.
