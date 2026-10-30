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

Before these exercises, I didn't know how to properly connect the wires, resistors, and LEDs, and I didn't really understand concepts like anode and cathode. During the exercises, I learned how to make these connections and make the LEDs work by following the instructions in the code. The exercises also helped me develop my logical thinking because, before running the code, I had to try to predict what would happen based on the instructions I wrote.

**What confused me**

At first, I didn't understand what would happen when we wrote text in the code, for example "BOOTING...", "RUNNING", and "ERROR" in the challenge. Later, I understood that this text is sent and displayed in the Serial Monitor.

**What broke, and why**

During the "Break It" exercises, we intentionally caused several errors to understand what would happen. For example, when we removed a } or a ;, the code could not compile correctly. We also removed Serial.begin(9600); and saw that the LEDs still worked, but the messages no longer appeared in the Serial Monitor. This helped me understand that different mistakes can affect the program in different ways.

**What I understand now that I didn't at the start of the week**

Now I understand better how the code controls what physically happens with the LEDs. I also understand what instructions like pinMode, digitalWrite, delay, Serial.begin, and Serial.println are used for. Before, I would just see code, but now I can read some instructions and try to predict what the Arduino will do before running them.

**The challenge — how tedious was it, honestly?**

The challenge was tedious because I had to repeat the same instructions many times. However, I think doing it this way is useful because it helps me memorize the commands and understand how they work. It also helped me understand why tools like loops and functions exist to simplify code and avoid so much repetition. In total, I typed digitalWrite 40 times.

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


## Week 3 — Names for Ideas

*Written with assistance using my reflection and my confirmation that the physical tests worked.*

**What I built**

This week I worked with programs that use functions to name small jobs. blinkN can blink different LEDs with different counts. Other functions calculate values, like the number of LEDs or the time a pattern needs. The Light Show combines scans, chases, flashes, and a fill pattern through function calls.

**What confused me**

I learned a lot this week, but I got confused in some parts at first. Sometimes I could see that the program worked, but I did not understand why it worked that way. After going through the explanations, things started to make more sense. I still need practice, but I understand the examples better now.

**What broke, and why**

The separate compiler tests showed that a misspelled name, a missing argument, or a parameter used outside its function stops compilation. Missing parentheses can compile without calling anything. A missing return gets a warning, but its result cannot be trusted.

In the original scope exercise, a function changed a global time. That made the red LED slow after the first round. The fixed version passes the time into the function, so one call does not change another call's time.

**What I understand now that I didn't at the start of the week**

Now the idea of giving a small job its own name makes more sense to me. A function lets the program use that job again without writing all its instructions again. The examples helped me connect the code with what happens when it runs. I learned quite a lot, even though I needed help with some parts. I want to keep practicing so I can explain each step more easily.

**The one-sentence test**

The design separates the idea "announce the duration and play the pattern" into announceMs(durationMs), which prints a duration, and pattern functions such as scan(times, stepMs), which repeats a bouncing light. Both scan directions use walk(startPin, direction, steps, stepMs).

This describes the prepared design, not a remembered first sentence from a paper exercise.

**Three versions**

| Version | Lines inside loop() | Whole program code lines |
|---|---:|---:|
| Week 0 Machine Status Indicator | 73 | 78 |
| Week 2 Exercise 5 | 24 | 40 |
| Week 3 Exercise 5 | 3 | 40 |

Counting rule: exclude comments, blank lines, and lines containing only braces. Count loop headers and function headers in the whole-program total; exclude the loop() header from its body count. Week 2 is taken from the saved week-02-loops commit 7bfebc8, since this branch still contains its starter file.

The whole Week 3 program is not shorter by this count, but loop() is much easier to read: booting(), running(), error(). The helper function has one home for the flashing idea.

**SOS comparison**

With Week 0's tools, each flash is written out with numbers. Week 1 gives the times names. Week 2 uses a loop for each letter. Week 3 gives the symbols and letters names: dot(), dash(), letterS(), letterO(). The loop reads S, O, S, then waits for the next message.

The saved Week 1, Week 2, and Week 3 versions have 18, 6, and 2 written digitalWrite calls. The Week 0 part is a comparison of the approach: a saved Week 0 SOS file was not found, so this is not a claim that four files were compared.

**Verification status**

All 16 final sketches compiled and linked for the UNO with no diagnostics. Software trace checks covered the patterns, sums, repeated scope exercise, SOS gaps, and the challenge's four-LED and three-LED settings. I also tested the programs on my UNO and confirmed that the physical tests worked. The separate compiler checks are recorded in reference/mistakes.md. The calculated time is 10 seconds for drill 9 and 8.4 seconds for the full light show.

The dry-run answers are labeled as worked explanations, because no original predictions or first prediction commit were supplied. No earlier paper plan or test result has been invented.
## Week 2 — Loops

### What I built

This week I learned how to use loops to repeat instructions without writing the same code many times. I used `for` loops to flash LEDs, move a light across different pins, and create a binary counter. I also used a `while` loop to make an LED blink faster each time.

I also rewrote the Week 0 Machine Status Indicator using loops. The behavior was the same, but the code was much shorter and easier to change.

### What confused me

At first, it was a little confusing to know when to use `<` and when to use `<=`. I also had to pay attention to where the counter starts and how it changes.

Nested loops were also a little confusing at first because one loop runs inside another loop. The binary counter helped me understand this better because I could see how each LED changed at a different speed.

### What broke, and why

One important error was adding a semicolon after a `for` loop. In the version without the counter print inside the following block, the program could still compile, but the loop did not control the block of code I expected.

I also saw how a loop can run one time too many or one time too few depending on its starting value and condition.

Another important problem happened with unsigned values. When an unsigned value tried to go below zero, it wrapped around to a very large positive value instead of becoming negative. I learned that the type of a variable can affect how a loop behaves.

### What I understand now that I didn't before

Now I understand that a loop is useful when I need to repeat the same instructions. Instead of copying the same code many times, I can write it once and control how many times it repeats.

I also understand the three important parts of a `for` loop: where the counter starts, the condition that decides if the loop continues, and how the counter changes.

I understand better why small changes such as `<` instead of `<=`, starting at 0 instead of 1, or putting an update in a different place can change the number of repetitions.

### Off-by-one error

An off-by-one error happens when a loop runs one time too many or one time too few.

For example, changing `flash < FLASH_COUNT` to `flash <= FLASH_COUNT` makes the loop run one extra time because the last value is included. With FLASH_COUNT set to 5, I expected 0 through 4, but including the limit gives 0 through 5. The extra `=` was responsible.

I learned that I should check the starting value, the condition, and the update when a loop repeats the wrong number of times.

### Week 0 challenge compared with Week 2

In Week 0, I had to write the same `digitalWrite` and `delay` instructions many times because I did not know how to use loops yet.

In Week 2, I could write one flash inside a loop and tell the program how many times to repeat it.

The behavior of the Machine Status Indicator did not change, but the Week 2 version has less repeated code and is easier to read and modify. The green LED uses pin 10 in the current circuit instead of Week 0's pin 9.

- Week 0 loop() lines: 73.
- Week 2 Exercise 5 loop() lines: 24.
- Week 2 scanner challenge loop() lines: 18.
- Week 0 digitalWrite calls written in loop(): 40.
- Week 2 Exercise 5 digitalWrite calls written in loop(): 10.

These counts include lines of code and loop headers, but exclude comments, blank lines, the loop() header, and lines containing only braces. They count written instructions, not how often each instruction runs.

### SOS comparison

With the Week 0 tools, SOS needs the instructions for each flash written out, with numbers directly in the code. In Week 1, the times have names, so changing the rhythm is easier, but the flashes are still written one by one. In Week 2, each letter uses a loop to repeat its three flashes.

The Week 1 file has 18 digitalWrite calls, and the Week 2 file has 6. The message is still three short flashes, three long flashes, and three short flashes. The main difference is how much code I need to repeat.

This compares the Week 0 approach with the saved Week 1 and Week 2 SOS files; it is not a comparison of three saved SOS files.

### Board checks

I confirmed that the Week 2 physical tests, changes, and error experiments gave the expected results on my UNO. This includes the exercises, drills, and scanner tests A, B, and C. The explanation for scanner test D is in challenge.ino. The final sketches have the normal settings restored.
