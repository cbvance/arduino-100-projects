// Project 16: Fade
// An LED brightens smoothly, then dims smoothly, forever.
// The LED must be on a PWM pin (marked ~ on the board).

const int LED = 9;
const int STEP_TIME = 8;      // ms spent at each level

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // Ramp up: 0 is off, 255 is full brightness.
  for (int level = 0; level <= 255; level++) {
    analogWrite(LED, level);
    delay(STEP_TIME);
  }

  // Ramp down.
  for (int level = 255; level >= 0; level--) {
    analogWrite(LED, level);
    delay(STEP_TIME);
  }
}
