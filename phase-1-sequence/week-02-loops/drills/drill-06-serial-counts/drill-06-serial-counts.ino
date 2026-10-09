const int FIRST_NUMBER = 1;
const int LAST_NUMBER = 20;
const int FIRST_EVEN = 2;
const int EVEN_STEP = 2;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  for (int number = FIRST_NUMBER; number <= LAST_NUMBER; number++) {
    Serial.print(number);
    Serial.print(" ");
  }
  Serial.println();
  for (int number = LAST_NUMBER; number >= FIRST_NUMBER; number--) {
    Serial.print(number);
    Serial.print(" ");
  }
  Serial.println();
  for (int number = FIRST_EVEN; number <= LAST_NUMBER; number += EVEN_STEP) {
    Serial.print(number);
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {
}
