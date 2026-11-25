// Project 1: Blink
// Turns the built-in LED on for one second, then off for one second.
// Board: Arduino Uno R3. No extra parts.

const int LED = LED_BUILTIN;  // the L LED, wired to pin 13

void setup() {
  pinMode(LED, OUTPUT);       // pin 13 will send voltage out
}

void loop() {
  digitalWrite(LED, HIGH);    // 5 V on the pin: LED on
  delay(1000);                // wait 1000 ms (1 second)
  digitalWrite(LED, LOW);     // 0 V on the pin: LED off
  delay(1000);
}
