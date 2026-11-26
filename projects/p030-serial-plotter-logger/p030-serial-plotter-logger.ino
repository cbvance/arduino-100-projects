// Project 30: Serial Plotter Logger
// Sends light, temperature, and the alarm limit five times a
// second in the form the Serial Plotter draws as a trend.

const int LIGHT_SENSOR = A0;
const int TEMP_SENSOR = A1;
const int ALARM_LAMP = 9;
const int SAMPLES = 16;

const int DARK = 200;           // your reading, covered
const int BRIGHT = 700;         // your reading, room light
const float ALARM_ON = 27.0;    // degrees C: alarm starts
const float ALARM_OFF = 26.0;   // degrees C: alarm clears

bool alarm = false;

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

// Give the TMP36 temperature in degrees Celsius.
float readTempC() {
  float volts = readAverage(TEMP_SENSOR) * 5.0 / 1023.0;
  return (volts - 0.5) * 100.0;
}

// Give the light level as 0 to 100 percent.
int readLightPercent() {
  int light = readAverage(LIGHT_SENSOR);
  int percent = map(light, DARK, BRIGHT, 0, 100);
  return constrain(percent, 0, 100);
}

void setup() {
  pinMode(ALARM_LAMP, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the inputs.
  int light = readLightPercent();
  float degC = readTempC();

  // Solve: the deadband alarm from Project 29.
  if (degC > ALARM_ON) {
    alarm = true;
  } else if (degC < ALARM_OFF) {
    alarm = false;
  }

  // Write the outputs. One line holds one moment in time.
  digitalWrite(ALARM_LAMP, alarm);
  Serial.print("Light:");
  Serial.print(light);
  Serial.print(",TempC:");
  Serial.print(degC, 1);
  Serial.print(",Limit:");
  Serial.println(ALARM_ON, 1);
  delay(130);
}
