// Project 27: Light Meter
// Averages 16 readings, shows the light as a percentage and
// a bar, and lights the LED when the room is dark.

const int LIGHT_SENSOR = A0;
const int LED = 9;

const int DARK = 200;     // your reading with it covered
const int BRIGHT = 700;   // your reading in room light
const int SAMPLES = 16;

// Take SAMPLES readings of one pin and give the average.
int readAverage(int pin) {
  analogRead(pin);            // first reading is thrown away
  long total = 0;
  for (int i = 0; i < SAMPLES; i++) {
    total = total + analogRead(pin);
    delay(2);
  }
  return total / SAMPLES;
}

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the input.
  int light = readAverage(LIGHT_SENSOR);

  // Solve: scale to percent and hold it inside 0 to 100.
  int percent = map(light, DARK, BRIGHT, 0, 100);
  percent = constrain(percent, 0, 100);
  bool dark = (percent < 20);

  // Write the outputs.
  digitalWrite(LED, dark);
  Serial.print(percent);
  Serial.print(" % ");
  for (int i = 0; i < percent / 5; i++) {
    Serial.print("#");
  }
  if (dark) {
    Serial.println(" DARK");
  } else if (percent < 60) {
    Serial.println(" DIM");
  } else {
    Serial.println(" BRIGHT");
  }
  delay(250);
}
