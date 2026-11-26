// Project 24: Bar Graph
// Five LEDs show the knob position as a bar, the way a level
// indicator shows how full a tank is.

const int KNOB = A0;
const int LED1 = 12;          // bottom of the bar
const int LED2 = 11;
const int LED3 = 10;
const int LED4 = 9;
const int LED5 = 8;           // top of the bar

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  // Read the input.
  int raw = analogRead(KNOB);

  // Solve: scale to percent.
  int percent = map(raw, 0, 1023, 0, 100);

  // Write the outputs. Each LED has its own switch-on point.
  digitalWrite(LED1, percent >= 10);
  digitalWrite(LED2, percent >= 30);
  digitalWrite(LED3, percent >= 50);
  digitalWrite(LED4, percent >= 70);
  digitalWrite(LED5, percent >= 90);
  delay(20);
}
