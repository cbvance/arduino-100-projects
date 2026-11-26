// Project 19: Mood Lamp
// Drifts slowly around the color wheel. Press the button to
// hold the color you like. Press again to let it drift.

const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;
const int BUTTON = 2;
const int STEP_TIME = 10;     // ms per step: bigger is slower

int red = 255;                // the color showing right now
int green = 0;
int blue = 0;

bool holding = false;         // true while frozen
bool wasPressed = false;

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

// Move one step from now toward target. Gives the new value.
int stepToward(int now, int target) {
  if (now < target) {
    return now + 1;
  }
  if (now > target) {
    return now - 1;
  }
  return now;
}

// Each new press flips holding on or off.
void checkButton() {
  bool pressed = (digitalRead(BUTTON) == LOW);
  if (pressed && !wasPressed) {
    holding = !holding;
  }
  wasPressed = pressed;
}

// Glide from the current color to a new one.
void fadeTo(int r, int g, int b) {
  while (red != r || green != g || blue != b) {
    checkButton();
    if (!holding) {
      red = stepToward(red, r);
      green = stepToward(green, g);
      blue = stepToward(blue, b);
      setColor(red, green, blue);
    }
    delay(STEP_TIME);
  }
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  setColor(red, green, blue);
}

void loop() {
  fadeTo(255, 255, 0);        // to yellow
  fadeTo(0, 255, 0);          // to green
  fadeTo(0, 255, 255);        // to cyan
  fadeTo(0, 0, 255);          // to blue
  fadeTo(255, 0, 255);        // to magenta
  fadeTo(255, 0, 0);          // back to red
}
