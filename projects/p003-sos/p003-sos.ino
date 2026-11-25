// Project 3: SOS
// Flashes the Morse code distress signal: ... --- ...
// Board: Arduino Uno R3. No extra parts.

const int LED = LED_BUILTIN;
const int DOT = 200;          // length of one dot in ms

// Turn the LED on for a while, then off for one dot.
void flash(int onTime) {
  digitalWrite(LED, HIGH);
  delay(onTime);
  digitalWrite(LED, LOW);
  delay(DOT);                 // gap inside a letter
}

void dot() {
  flash(DOT);
}

void dash() {
  flash(3 * DOT);
}

void letterGap() {
  delay(2 * DOT);             // 1 dot already waited + 2 = 3
}

void wordGap() {
  delay(6 * DOT);             // 1 dot already waited + 6 = 7
}

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {   // S
    dot();
  }
  letterGap();

  for (int i = 0; i < 3; i++) {   // O
    dash();
  }
  letterGap();

  for (int i = 0; i < 3; i++) {   // S
    dot();
  }
  wordGap();
}
