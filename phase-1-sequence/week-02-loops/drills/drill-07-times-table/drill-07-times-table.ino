const int FIRST_FACTOR = 1;
const int LAST_FACTOR = 9;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  Serial.begin(SERIAL_BAUD);
  for (int row = FIRST_FACTOR; row <= LAST_FACTOR; row++) {
    for (int column = FIRST_FACTOR; column <= LAST_FACTOR; column++) {
      Serial.print(row * column);
      Serial.print(" ");
    }
    Serial.println();
  }
}

void loop() {
}
