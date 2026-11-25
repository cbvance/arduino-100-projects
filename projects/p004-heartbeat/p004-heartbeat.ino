// Project 4: Heartbeat
// Two quick pulses, then a rest. One beat every second.
// Board: Arduino Uno R3. No extra parts.

const int LED = LED_BUILTIN;

const int PULSE = 100;        // ms each pulse stays on
const int BETWEEN = 150;      // ms between the two pulses
const int BEAT = 1000;        // ms for one whole beat

// Whatever time is left over becomes the rest.
const int REST = BEAT - PULSE - BETWEEN - PULSE;

void pulse() {
  digitalWrite(LED, HIGH);
  delay(PULSE);
  digitalWrite(LED, LOW);
}

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  pulse();                    // lub
  delay(BETWEEN);
  pulse();                    // dub
  delay(REST);
}
