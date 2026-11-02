/*
 * WEEK 4 · EXERCISE 4 — Frames
 * ------------------------------------------------------------------
 * GOAL
 *   A pattern as a list of FRAMES. Each frame says, for every LED,
 *   on or off. Now two or more LEDs can be lit at once -- something
 *   Exercise 3's one-pin-per-row table can't say.
 *
 * WIRING
 *   Blue 7, red 8, yellow 9, green 10, white 12.
 *
 * ------------------------------------------------------------------
 * WHAT TO DO
 *
 *   1. LED_PINS and LED_COUNT, as in Exercise 1.
 *
 *   2. The frames, as a grid written into ONE list -- one row per
 *      frame, one value per LED, in LED_PINS order (README 1.10):
 *
 *          const byte FRAMES[] = {
 *            1, 0, 0, 0, 1,     // frame 0: both ends
 *            0, 1, 0, 1, 0,     // frame 1: one step in
 *            ...
 *          };
 *          const int FRAME_COUNT = sizeof(FRAMES) / sizeof(FRAMES[0]) / LED_COUNT;
 *
 *      Write each frame on its own line, with a comment. It's the
 *      only thing that keeps the grid readable.
 *
 *      Design your own pattern: at least 6 frames, and at least two
 *      frames where two or more LEDs are lit together.
 *
 *   3. BY HAND, FIRST: frame 3, LED 4. Work out the index with
 *      f * LED_COUNT + led, then count that many boxes into your
 *      list -- the first box is 0 -- and check you land on the right
 *      value. Write the working in dry-run.md, under the dry run.
 *
 *   4. The engine:
 *
 *          void showFrame(int frame)   // sets EVERY LED for that frame
 *
 *      and loop() shows every frame in turn, with a pause after each.
 *
 *   5. Print each frame on Serial as a row of 1s and 0s as it's shown.
 *      Compare the Monitor with the LEDs.
 *
 * ------------------------------------------------------------------
 * THE POINT
 *   f * LED_COUNT + led: skip f whole rows, then step along. A grid
 *   in a list. Trace it until it's boring -- that's when you can
 *   trust it.
 *
 *   And notice what showFrame() doesn't need: no "turn off the
 *   previous LED". Every frame sets every LED, so no frame can be
 *   polluted by the one before it.
 *
 * ------------------------------------------------------------------
 * BREAK IT -- on the board; record what you actually see
 *
 *   1. Delete ONE value from a frame in the MIDDLE of the list.
 *      Upload. Which frames still look right, and from which frame
 *      does everything go wrong? Print FRAME_COUNT, and the total
 *      sizeof(FRAMES) / sizeof(FRAMES[0]). Is the total still a whole
 *      multiple of LED_COUNT? Did the compiler notice anything?
 *      Record under LOGIC ERRORS.
 *
 *   2. Put it back. Swap the formula to  led * LED_COUNT + frame.
 *      It compiles. What comes out? (Safe to run: every pin still
 *      comes from LED_PINS, so only the on/off values are wrong.)
 *      Rows and columns are easy to swap and impossible for the
 *      compiler to catch. Week 16 gives grids a real shape.
 */


// TODO: LED_PINS and LED_COUNT; FRAMES and FRAME_COUNT; a step time


void setup() {
  // TODO: every pin an output; Serial
}

void loop() {
  // TODO: show every frame in turn
}

// TODO: showFrame(frame)
