// A pair contains one red and one blue interval: 2 * 100 ms.
// 2000 / 200 = 10 pairs. There is no separate off wait inside a pair.
// Command execution adds a small overhead to the 2000 ms delay budget.
const int PIN_BLUE = 7;
const int PIN_RED = 8;
const unsigned long FLASH_MS = 100;
const unsigned long ACTIVE_MS = 2000;
const unsigned long PAUSE_MS = 1000;
const unsigned long PAIR_MS = FLASH_MS * 2;
const unsigned long PAIR_COUNT = ACTIVE_MS / PAIR_MS;

void setup() {
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
}

void loop() {
  for (unsigned long pair = 0; pair < PAIR_COUNT; pair++) {
    for (int pin = PIN_RED; pin >= PIN_BLUE; pin--) {
      digitalWrite(pin, HIGH);
      delay(FLASH_MS);
      digitalWrite(pin, LOW);
    }
  }
  delay(PAUSE_MS);
}
