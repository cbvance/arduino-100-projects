// Project 15: Reaction Timer
// Wait for the light, then press as fast as you can.
// Uses the same circuit as Project 12.

const int BUTTON = 2;
const int LED = 9;

unsigned long best = 0;       // fastest time so far, 0 = none

// A function that answers a question: is the button down?
bool pressed() {
  return digitalRead(BUTTON) == LOW;
}

void waitForRelease() {
  while (pressed()) {
    // do nothing until the button comes up
  }
  delay(50);                  // let the contacts settle
}

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(A0)); // shuffle the random numbers
  Serial.println("Reaction timer");
}

void loop() {
  Serial.println("Get ready...");
  digitalWrite(LED, LOW);

  // Wait a random 2 to 5 seconds, watching for a false start.
  unsigned long waitTime = random(2000, 5001);
  unsigned long began = millis();
  bool falseStart = false;

  while (millis() - began < waitTime && !falseStart) {
    if (pressed()) {
      falseStart = true;
    }
  }

  if (falseStart) {
    Serial.println("Too soon! Wait for the light.");
  } else {
    digitalWrite(LED, HIGH);              // GO
    unsigned long start = millis();

    while (!pressed()) {
      // wait for the press
    }

    unsigned long reaction = millis() - start;
    digitalWrite(LED, LOW);

    Serial.print("Your time: ");
    Serial.print(reaction);
    Serial.println(" ms");

    if (best == 0 || reaction < best) {
      best = reaction;
      Serial.println("New best!");
    }
    Serial.print("Best so far: ");
    Serial.print(best);
    Serial.println(" ms");
  }

  waitForRelease();
  delay(1500);
}
