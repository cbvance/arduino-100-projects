// Project 34: Button Piano
// Four buttons, four notes. Hold a key to sound its note.
// If two keys are down, the one on the left wins.

const int PIEZO = 8;
const int KEY1 = 5;           // left key
const int KEY2 = 4;
const int KEY3 = 3;
const int KEY4 = 2;           // right key

const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_G4 = 392;

void setup() {
  pinMode(KEY1, INPUT_PULLUP);
  pinMode(KEY2, INPUT_PULLUP);
  pinMode(KEY3, INPUT_PULLUP);
  pinMode(KEY4, INPUT_PULLUP);
}

void loop() {
  // Read the inputs.
  bool key1 = (digitalRead(KEY1) == LOW);
  bool key2 = (digitalRead(KEY2) == LOW);
  bool key3 = (digitalRead(KEY3) == LOW);
  bool key4 = (digitalRead(KEY4) == LOW);

  // Solve and write: the first key found down gets the piezo.
  if (key1) {
    tone(PIEZO, NOTE_C4);
  } else if (key2) {
    tone(PIEZO, NOTE_D4);
  } else if (key3) {
    tone(PIEZO, NOTE_E4);
  } else if (key4) {
    tone(PIEZO, NOTE_G4);
  } else {
    noTone(PIEZO);
  }
  delay(10);
}
