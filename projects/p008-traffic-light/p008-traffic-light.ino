// Project 8: Traffic Light
// Green, then yellow, then red, over and over.
// Parts: red, yellow, green LEDs, 3 resistors (220 ohm),
// breadboard, 7 wires.

const int RED = 11;
const int YELLOW = 10;
const int GREEN = 9;

// Set all three lights in one line. true = on, false = off.
void setLights(bool red, bool yellow, bool green) {
  digitalWrite(RED, red);
  digitalWrite(YELLOW, yellow);
  digitalWrite(GREEN, green);
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  setLights(false, false, true);    // GO
  delay(4000);

  setLights(false, true, false);    // CAUTION
  delay(1000);

  setLights(true, false, false);    // STOP
  delay(4000);
}
