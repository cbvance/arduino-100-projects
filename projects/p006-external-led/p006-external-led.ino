// Project 6: External LED
// Blinks an LED you wired yourself on pin 9.
// Parts: 1 LED, 1 resistor (220 ohm), breadboard, 3 wires.

const int LED = 9;            // the pin your LED is wired to

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);    // current flows: LED on
  delay(500);
  digitalWrite(LED, LOW);     // no current: LED off
  delay(500);
}
