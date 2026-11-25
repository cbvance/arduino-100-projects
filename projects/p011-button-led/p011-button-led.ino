// Project 11: Button LED
// The LED is on while the button is held down.
// The button has an external 10 k pull-down resistor.

const int BUTTON = 2;
const int LED = 9;

void setup() {
  pinMode(BUTTON, INPUT);     // this pin listens
  pinMode(LED, OUTPUT);       // this pin drives the LED
}

void loop() {
  int state = digitalRead(BUTTON);   // HIGH while pressed

  if (state == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
