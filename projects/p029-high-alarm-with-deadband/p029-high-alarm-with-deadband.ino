// Project 29: High Alarm with Deadband
// The alarm comes on above ALARM_ON and does not clear until
// the temperature falls below ALARM_OFF. No chattering.

const int TEMP_SENSOR = A1;
const int ALARM_LAMP = 9;
const int SAMPLES = 16;

const float ALARM_ON = 27.0;    // degrees C: alarm starts
const float ALARM_OFF = 26.0;   // degrees C: alarm clears

bool alarm = false;             // remembered between passes

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

void setup() {
  pinMode(ALARM_LAMP, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the input.
  float degC = readTempC();

  // Solve: between the two limits the alarm keeps its state.
  if (degC > ALARM_ON) {
    alarm = true;
  } else if (degC < ALARM_OFF) {
    alarm = false;
  }

  // Write the outputs.
  digitalWrite(ALARM_LAMP, alarm);
  Serial.print(degC, 1);
  Serial.print(" C");
  if (alarm) {
    Serial.print("  HIGH TEMP");
  }
  Serial.println();
  delay(500);
}
