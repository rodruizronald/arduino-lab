/*
 * drill-09-small-type
 * Test confirmed by the student: int holding 40000 gave -25536;
 * unsigned long holding 40000 gave 40000. No warning text was supplied.
 * Final version keeps the working unsigned long value below.
 */

const unsigned long SERIAL_BAUD = 9600;
unsigned long correctValue = 40000;

void setup() {
  Serial.begin(SERIAL_BAUD);
  Serial.print("unsigned long: ");
  Serial.println(correctValue);
}

void loop() {
}