// Project 9: Stack Light
// The Bench Creek pump panel light: amber for standby,
// green for running, flashing red for alarm.
// Uses the same circuit as Project 8.

const int RED = 11;
const int AMBER = 10;
const int GREEN = 9;

void allOff() {
  digitalWrite(RED, LOW);
  digitalWrite(AMBER, LOW);
  digitalWrite(GREEN, LOW);
}

// Amber steady: ready, waiting for a start.
void standby(int seconds) {
  Serial.println("STANDBY");
  allOff();
  digitalWrite(AMBER, HIGH);
  delay(seconds * 1000L);
}

// Green steady: the pump is on.
void running(int seconds) {
  Serial.println("RUNNING");
  allOff();
  digitalWrite(GREEN, HIGH);
  delay(seconds * 1000L);
}

// Red flashing, twice a second: needs attention.
void alarm(int seconds) {
  Serial.println("ALARM");
  allOff();
  for (int i = 0; i < seconds * 2; i++) {
    digitalWrite(RED, HIGH);
    delay(250);
    digitalWrite(RED, LOW);
    delay(250);
  }
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(AMBER, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600);

  // Lamp test: every light on for one second.
  digitalWrite(RED, HIGH);
  digitalWrite(AMBER, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(1000);
  allOff();
}

void loop() {
  standby(3);
  running(6);
  alarm(4);
}
