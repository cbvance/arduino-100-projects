// Project 32: Scale
// Plays the eight notes of the C major scale up and then
// back down on the piezo, over and over.

const int PIEZO = 8;

const int NOTE_C4 = 262;      // frequencies in hertz
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;
const int NOTE_G4 = 392;
const int NOTE_A4 = 440;
const int NOTE_B4 = 494;
const int NOTE_C5 = 523;

// Sound one note for ms milliseconds, then a short silence.
void play(int frequency, int ms) {
  tone(PIEZO, frequency);
  delay(ms);
  noTone(PIEZO);
  delay(30);
}

void setup() {
}

void loop() {
  play(NOTE_C4, 300);         // up
  play(NOTE_D4, 300);
  play(NOTE_E4, 300);
  play(NOTE_F4, 300);
  play(NOTE_G4, 300);
  play(NOTE_A4, 300);
  play(NOTE_B4, 300);
  play(NOTE_C5, 600);
  play(NOTE_B4, 300);         // and back down
  play(NOTE_A4, 300);
  play(NOTE_G4, 300);
  play(NOTE_F4, 300);
  play(NOTE_E4, 300);
  play(NOTE_D4, 300);
  play(NOTE_C4, 600);
  delay(1500);
}
