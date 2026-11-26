// Project 17: Breathing LED
// A fade that looks even to the eye, with a rest between
// breaths. Uses the same circuit as Project 16.

const int LED = 9;
const int STEP_TIME = 6;      // ms spent at each level
const int REST = 700;         // ms of dark between breaths

// Square the level so the dim end gets more of the steps.
// level is a long because 255 x 255 is too big for an int.
void show(long level) {
  analogWrite(LED, level * level / 255);
}

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  for (int level = 0; level <= 255; level++) {  // breathe in
    show(level);
    delay(STEP_TIME);
  }

  for (int level = 255; level >= 0; level--) {  // breathe out
    show(level);
    delay(STEP_TIME);
  }

  delay(REST);
}
