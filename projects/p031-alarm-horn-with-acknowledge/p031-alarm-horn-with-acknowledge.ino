// Project 31: Alarm Horn with Acknowledge
// Hold TRIP to make an alarm: the horn sounds and the lamp
// flashes. Press ACK: the horn stops, the lamp goes steady.

const int TRIP = 3;           // stands in for a field switch
const int ACK = 2;            // the operator's button
const int HORN = 8;
const int LAMP = LED_BUILTIN; // the L LED on the Uno

bool acked = false;           // has this alarm been answered?
bool flash = false;           // flips on every pass

void setup() {
  pinMode(TRIP, INPUT_PULLUP);
  pinMode(ACK, INPUT_PULLUP);
  pinMode(LAMP, OUTPUT);
}

void loop() {
  // Read the inputs.
  bool alarm = (digitalRead(TRIP) == LOW);
  bool ackPressed = (digitalRead(ACK) == LOW);

  // Solve: remember the acknowledge until the alarm clears.
  if (alarm && ackPressed) {
    acked = true;
  }
  if (!alarm) {
    acked = false;
  }
  flash = !flash;
  bool horn = alarm && !acked;
  bool lamp = alarm && (acked || flash);

  // Write the outputs.
  digitalWrite(LAMP, lamp);
  if (horn && flash) {
    tone(HORN, 880);          // high half of the warble
  } else if (horn) {
    tone(HORN, 660);          // low half of the warble
  } else {
    noTone(HORN);
  }
  delay(250);
}
