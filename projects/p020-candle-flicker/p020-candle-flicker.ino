// Project 20: Candle Flicker
// A flame that never repeats. Press the button to blow it
// out. Press again to light it.
// Uses the same circuit as Project 19.

const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;
const int BUTTON = 2;

bool lit = true;
bool wasPressed = false;

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  // A0 must have nothing plugged in for this to work.
  randomSeed(analogRead(A0));
}

void loop() {
  // 1. Read the input.
  bool pressed = (digitalRead(BUTTON) == LOW);

  // 2. Solve the logic: each new press flips the flame.
  if (pressed && !wasPressed) {
    lit = !lit;
  }
  wasPressed = pressed;

  // 3. Write the output.
  if (lit) {
    int glow = random(120, 256);          // how bright
    setColor(glow, glow / 4, 0);          // warm orange
    delay(random(30, 120));               // how long
  } else {
    setColor(0, 0, 0);
    delay(30);
  }
}
