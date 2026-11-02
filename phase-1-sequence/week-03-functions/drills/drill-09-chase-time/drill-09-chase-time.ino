const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const int PIN_BLUE = 7;
const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;
const int ROUNDS = 5;
const unsigned long STEP_MS = 500;
const unsigned long PAUSE_MS = 2000;

void setup() {
  for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
  Serial.begin(SERIAL_BAUD);
}
void loop() {
  Serial.print("START chase, expected ms: ");
  Serial.println(chaseMs(ROUNDS, STEP_MS));
  chase(ROUNDS, STEP_MS);
  Serial.println("END chase");
  delay(PAUSE_MS);
}
unsigned long chaseMs(int times, unsigned long stepMs) {
  return (LAST_PIN - FIRST_PIN + 1) * stepMs * times;
}
void chase(int times, unsigned long stepMs) {
  for (int round = 0; round < times; round++) {
    for (int pin = FIRST_PIN; pin <= LAST_PIN; pin++) {
      digitalWrite(pin, HIGH);
      delay(stepMs);
      digitalWrite(pin, LOW);
    }
  }
}
// Expected 10000 ms for four LEDs; time START to END with a stopwatch.
// The pause after END is not part of the chase.
