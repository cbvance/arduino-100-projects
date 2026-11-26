// Project 22: Dimmer
// The knob sets the brightness of the LED on pin 9.
// map() turns the 0 to 1023 reading into a 0 to 255 level.

const int KNOB = A0;
const int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the input.
  int raw = analogRead(KNOB);

  // Solve: scale 0-1023 down to 0-255.
  int level = map(raw, 0, 1023, 0, 255);

  // Write the outputs.
  analogWrite(LED, level);
  Serial.print(raw);
  Serial.print(" -> ");
  Serial.println(level);
  delay(50);
}
