// Project 7: Alternating Pair
// Two LEDs take turns, like a railroad crossing signal.
// Parts: 2 LEDs, 2 resistors (220 ohm), breadboard, 5 wires.

const int LEFT = 10;
const int RIGHT = 9;
const int WAIT = 400;         // ms each light stays on

void setup() {
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
}

void loop() {
  digitalWrite(LEFT, HIGH);   // left on, right off
  digitalWrite(RIGHT, LOW);
  delay(WAIT);

  digitalWrite(LEFT, LOW);    // left off, right on
  digitalWrite(RIGHT, HIGH);
  delay(WAIT);
}
