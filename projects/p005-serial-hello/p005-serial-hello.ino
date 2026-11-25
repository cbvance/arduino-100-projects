// Project 5: Serial Hello
// The board reports to your computer once a second.
// Open the Serial Monitor and set it to 9600 baud.
// Board: Arduino Uno R3. No extra parts.

const int LED = LED_BUILTIN;

unsigned long seconds = 0;    // how long the station has run

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);         // start talking at 9600 baud
  Serial.println("Bench Creek online");
}

void loop() {
  digitalWrite(LED, HIGH);    // short blip: still alive
  delay(100);
  digitalWrite(LED, LOW);
  delay(900);

  seconds = seconds + 1;

  Serial.print("Uptime: ");
  Serial.print(seconds);
  Serial.println(" s");
}
