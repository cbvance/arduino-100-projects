// Project 2: Blink Rates
// One light, four messages. Change MODE, upload, and watch.
// Board: Arduino Uno R3. No extra parts.

const int LED = LED_BUILTIN;

// Pick the message the light sends:
// 1 = steady on   (running normally)
// 2 = slow flash  (starting up or waiting)
// 3 = fast flash  (alarm)
// 4 = short blip  (standby)
const int MODE = 2;

int onTime;    // ms the LED stays on
int offTime;   // ms the LED stays off

void setup() {
  pinMode(LED, OUTPUT);

  if (MODE == 1) {
    onTime = 1000;
    offTime = 0;
  } else if (MODE == 2) {
    onTime = 1000;
    offTime = 1000;
  } else if (MODE == 3) {
    onTime = 200;
    offTime = 200;
  } else {
    onTime = 100;
    offTime = 1900;
  }
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(onTime);
  if (offTime > 0) {          // steady on never switches off
    digitalWrite(LED, LOW);
    delay(offTime);
  }
}
