const int FIRST_PIN = 7;
const int LAST_PIN = 10;
const int PIN_BLUE = 7;
const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;
const unsigned long SERIAL_BAUD = 9600;
const int FIRST_FACTOR = 1;
const int LAST_FACTOR = 9;
const unsigned long TABLE_PAUSE_MS = 1000;

void setup() {
  Serial.begin(SERIAL_BAUD);
}
void loop() {
  for (int number = FIRST_FACTOR; number <= LAST_FACTOR; number++) {
    printTimesRow(number);
  }
  delay(TABLE_PAUSE_MS);
}
void printTimesRow(int n) {
  for (int factor = FIRST_FACTOR; factor <= LAST_FACTOR; factor++) {
    Serial.print(n * factor);
    Serial.print(" ");
  }
  Serial.println();
}
