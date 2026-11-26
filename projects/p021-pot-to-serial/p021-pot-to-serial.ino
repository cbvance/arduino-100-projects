// Project 21: Pot to Serial
// Reads the knob on pin A0 ten times a second and prints the
// raw number. Fully one way is 0. Fully the other is 1023.

const int KNOB = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(KNOB);   // 0 to 1023
  Serial.println(raw);
  delay(100);
}
