// Project 14: Press Counter
// Counts button presses and reports the total.
// The LED is on for odd counts and off for even ones.
// Uses the same circuit as Project 12.

const int BUTTON = 2;
const int LED = 9;
const int DEBOUNCE = 20;      // ms to let the contacts settle

int count = 0;
bool wasPressed = false;      // the button last time round

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Press the button");
}

void loop() {
  bool pressed = (digitalRead(BUTTON) == LOW);

  // An edge: not pressed last time, pressed now.
  if (pressed && !wasPressed) {
    count = count + 1;
    Serial.print("Presses: ");
    Serial.println(count);
    digitalWrite(LED, count % 2);   // remainder after / 2
  }

  wasPressed = pressed;       // remember for next time
  delay(DEBOUNCE);
}
