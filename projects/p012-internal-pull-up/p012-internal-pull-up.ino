// Project 12: Internal Pull-up
// Same job as Project 11 with two fewer parts.
// The chip's own pull-up resistor replaces the 10 k one.

const int BUTTON = 2;
const int LED = 9;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);   // HIGH until pressed
  pinMode(LED, OUTPUT);
}

void loop() {
  // With a pull-up, a pressed button reads LOW.
  bool pressed = (digitalRead(BUTTON) == LOW);

  digitalWrite(LED, pressed);
}
