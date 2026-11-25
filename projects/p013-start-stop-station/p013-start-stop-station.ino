// Project 13: Start Stop Station
// The Bench Creek pump control station. START latches the
// pump on. STOP drops it out. If both are pressed, STOP wins.

const int START_BUTTON = 3;
const int STOP_BUTTON = 2;
const int STOPPED_LAMP = 10;  // red
const int RUNNING_LAMP = 9;   // green

bool running = false;         // is the pump running?
bool wasRunning = false;      // what it was last time round

void setup() {
  pinMode(START_BUTTON, INPUT_PULLUP);
  pinMode(STOP_BUTTON, INPUT_PULLUP);
  pinMode(STOPPED_LAMP, OUTPUT);
  pinMode(RUNNING_LAMP, OUTPUT);
  Serial.begin(9600);
  Serial.println("Bench Creek pump station ready");
}

void loop() {
  // 1. Read the inputs.
  bool start = (digitalRead(START_BUTTON) == LOW);
  bool stop = (digitalRead(STOP_BUTTON) == LOW);

  // 2. Solve the logic. This one line is the seal-in.
  running = (start || running) && !stop;

  // 3. Write the outputs.
  digitalWrite(RUNNING_LAMP, running);
  digitalWrite(STOPPED_LAMP, !running);

  // Report only when something changes.
  if (running != wasRunning) {
    if (running) {
      Serial.println("PUMP RUNNING");
    } else {
      Serial.println("PUMP STOPPED");
    }
    wasRunning = running;
  }
}
