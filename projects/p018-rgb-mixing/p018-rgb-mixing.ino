// Project 18: RGB Mixing
// One RGB LED steps through eight colors.
// All three pins must be PWM pins.

const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;
const int HOLD = 1000;        // ms to show each color

// Each value runs from 0 (none) to 255 (full).
void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);        // red
  delay(HOLD);
  setColor(0, 255, 0);        // green
  delay(HOLD);
  setColor(0, 0, 255);        // blue
  delay(HOLD);
  setColor(255, 255, 0);      // yellow
  delay(HOLD);
  setColor(0, 255, 255);      // cyan
  delay(HOLD);
  setColor(255, 0, 255);      // magenta
  delay(HOLD);
  setColor(255, 255, 255);    // white
  delay(HOLD);
  setColor(255, 80, 0);       // orange
  delay(HOLD);
  setColor(0, 0, 0);          // off
  delay(HOLD);
}
