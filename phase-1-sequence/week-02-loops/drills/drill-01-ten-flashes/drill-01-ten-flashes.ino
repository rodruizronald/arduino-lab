const int PIN_RED = 8;
const int FLASH_COUNT = 10;
const unsigned long FLASH_MS = 150;
const unsigned long PAUSE_MS = 1000;
const unsigned long SERIAL_BAUD = 9600;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  Serial.begin(SERIAL_BAUD);
}

void loop() {
  for (int flash = 0; flash < FLASH_COUNT; flash++) {
    Serial.println(flash);
    digitalWrite(PIN_RED, HIGH);
    delay(FLASH_MS);
    digitalWrite(PIN_RED, LOW);
    delay(FLASH_MS);
  }
  delay(PAUSE_MS);
}
