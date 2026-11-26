// Project 28: TMP36 Thermometer
// Reads the TMP36 temperature sensor on pin A1 and prints
// volts, degrees Celsius, and degrees Fahrenheit.

const int TEMP_SENSOR = A1;
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
  Serial.begin(9600);
}

void loop() {
  // Read the input.
  int raw = readAverage(TEMP_SENSOR);

  // Solve: counts to volts, volts to degrees.
  float volts = raw * 5.0 / 1023.0;
  float degC = (volts - 0.5) * 100.0;
  float degF = degC * 9.0 / 5.0 + 32.0;

  // Write the outputs.
  Serial.print(volts, 3);
  Serial.print(" V  ");
  Serial.print(degC, 1);
  Serial.print(" C  ");
  Serial.print(degF, 1);
  Serial.println(" F");
  delay(500);
}
