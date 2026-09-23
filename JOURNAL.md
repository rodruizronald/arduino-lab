# Journal

One entry per week. Written the same day you finish, not later.

This is the most valuable file in the repo. Not because anyone will read it — because writing down *what confused you* is the act that converts "I got it working" into "I understand it." Skipping this is the single fastest way to reach Week 20 able to copy code and unable to write it.

Four prompts. Two minutes each. Be honest, especially in the second one.

---

## Template

```markdown
## Week N — <title>            <!-- date -->

**What I built**
One or two sentences. What actually exists now that didn't before.

**What confused me**
Be specific. "Everything" is not an answer. "I don't understand why `void`
has to be there" is. Unresolved confusion is fine — write it down anyway
and come back to it. Some of these get answered five weeks later.

**What broke, and why**
The actual cause, not "it didn't work." If you never found the cause,
say so — that's data too.

**What I understand now that I didn't at the start of the week**
The important one. Even if it feels small.
```

---

## Week 0 — First Contact <!-- date: -->

**What I built**

<!-- TODO -->

**What confused me**

<!-- TODO -->

**What broke, and why**

<!-- TODO -->

**What I understand now that I didn't at the start of the week**

<!-- TODO -->

**The challenge — how tedious was it, honestly?**

<!-- One-off prompt for this week only. Count your digitalWrite calls.
     Describe the feeling of typing the same block for the third time.
     You'll want to reread this in Week 2. -->

---

## Week 1 — Names for Numbers <!-- date: 2026-09-22 -->

**What I built**

This week I worked with three LEDs and made a traffic light. I used names for the pins and times, and printed the values in the Serial Monitor. I also tested different rhythms and made small changes to see what happened.

**What confused me**

This week was a bit harder than the last one. It needed more tests, so it took more time. At first, I was confused about changing a variable's value and using its name inside delay(). I also needed help finding exactly which line to change during the error tests.

**What broke, and why**

Moving a variable inside setup() meant loop() could not use it. Changing an uppercase letter made the variable name different. I also saw that int could be too small for a time value, which caused a very long wait. When I put a variable name in quotes, the Serial Monitor printed the name instead of its value.

**What I understand now that I didn't at the start of the week**

I learned that variables give values a name, and const stops the program from changing a value. I learned that different types can hold different amounts of information. I can use one main time value to change a whole pattern, and the Serial Monitor helps me check the values the program is using. print() keeps writing on the same line, while println() ends the line.

In the traffic light, I still used nine digitalWrite calls. Giving values names made the code clearer, but it did not remove the repeated instructions.

**Name one variable you renamed after writing it**

I renamed onTimeMs to redOnMs and offTimeMs to redOffMs during the final review. The first names did not say which LED the times belonged to. After working with three LEDs, I understood why including the color makes the names clearer. The values and behavior stayed the same.
