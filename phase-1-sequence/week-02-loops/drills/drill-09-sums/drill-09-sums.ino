// n is unsigned long, so the product n*(n+1) is calculated in that type.
// Expected: 100 -> 5050; 1000 -> 500500. An UNO int cannot hold the latter.
const unsigned long FIRST_LIMIT = 100;
const unsigned long LAST_LIMIT = 1000;
const unsigned long SCALE = 10;
const unsigned long DIVISOR = 2;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  for (unsigned long n = FIRST_LIMIT; n <= LAST_LIMIT; n *= SCALE) {
    unsigned long total = 0;
    for (unsigned long number = 1; number <= n; number++) {
      total += number;
    }
    const unsigned long formula = n * (n + 1) / DIVISOR;
    Serial.print("n=");
    Serial.print(n);
    Serial.print(" sum=");
    Serial.print(total);
    Serial.print(" formula=");
    Serial.println(formula);
  }
}

void loop() {
}
