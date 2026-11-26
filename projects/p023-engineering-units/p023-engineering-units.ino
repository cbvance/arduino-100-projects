// Project 23: Engineering Units
// Turns the raw reading into volts, percent, and feet of
// water in a 12 foot tank. The LED is the high level alarm.

const int KNOB = A0;
const int ALARM_LAMP = 9;

const float TANK_FEET = 12.0;   // level when the tank is full
const float HIGH_ALARM = 10.0;  // alarm above this many feet

void setup() {
  pinMode(ALARM_LAMP, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the input.
  int raw = analogRead(KNOB);

  // Solve: scale the raw count three ways.
  float volts = raw * 5.0 / 1023.0;
  float percent = raw * 100.0 / 1023.0;
  float feet = raw * TANK_FEET / 1023.0;
  bool highLevel = (feet > HIGH_ALARM);

  // Write the outputs.
  digitalWrite(ALARM_LAMP, highLevel);
  Serial.print(raw);
  Serial.print(" counts  ");
  Serial.print(volts, 2);
  Serial.print(" V  ");
  Serial.print(percent, 1);
  Serial.print(" %  ");
  Serial.print(feet, 2);
  Serial.print(" ft");
  if (highLevel) {
    Serial.print("  HIGH LEVEL");
  }
  Serial.println();
  delay(250);
}
