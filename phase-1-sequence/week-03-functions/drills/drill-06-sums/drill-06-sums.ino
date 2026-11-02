const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const int PIN_BLUE = 7;
const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  for (long n = 10; n <= 1000; n *= 10) {
    Serial.print(n);
    Serial.print(" | ");
    Serial.print(sumByLoop(n));
    Serial.print(" | ");
    Serial.println(sumByFormula(n));
  }
}
void loop() {
}
long sumByLoop(long n) {
  long total = 0;
  for (long number = 1; number <= n; number++) {
    total += number;
  }
  return total;
}

long sumByFormula(long n) {
  return n * (n + 1) / 2;
}
