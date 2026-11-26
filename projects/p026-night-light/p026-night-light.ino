// Project 26: Night Light
// The darker the room, the brighter the LED. Measure your
// own DARK and BRIGHT readings and type them in below.

const int LIGHT_SENSOR = A0;
const int LED = 9;

const int DARK = 200;     // reading with the sensor covered
const int BRIGHT = 700;   // reading in normal room light

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the input.
  int light = analogRead(LIGHT_SENSOR);

  // Solve: dark gives 255, bright gives 0, nothing outside.
  int level = map(light, DARK, BRIGHT, 255, 0);
  level = constrain(level, 0, 255);

  // Write the outputs.
  analogWrite(LED, level);
  Serial.print(light);
  Serial.print(" -> ");
  Serial.println(level);
  delay(100);
}
