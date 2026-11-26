// Project 33: Melody
// Plays the first two lines of Beethoven's Ode to Joy.
// Note lengths are counted in eighth notes.

const int PIEZO = 8;
const int EIGHTH = 200;       // ms per eighth note: the tempo

const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;
const int NOTE_G4 = 392;

// Sound one note. 2 eighths is a quarter note, 4 is a half.
void play(int frequency, int eighths) {
  int ms = eighths * EIGHTH;
  tone(PIEZO, frequency);
  delay(ms - 30);
  noTone(PIEZO);
  delay(30);
}

// The eleven notes that both lines start with.
void opening() {
  play(NOTE_E4, 2);
  play(NOTE_E4, 2);
  play(NOTE_F4, 2);
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_F4, 2);
  play(NOTE_E4, 2);
  play(NOTE_D4, 2);
  play(NOTE_C4, 2);
  play(NOTE_C4, 2);
  play(NOTE_D4, 2);
}

void setup() {
}

void loop() {
  opening();                  // line one
  play(NOTE_E4, 2);
  play(NOTE_E4, 3);
  play(NOTE_D4, 1);
  play(NOTE_D4, 4);

  opening();                  // line two
  play(NOTE_E4, 2);
  play(NOTE_D4, 3);
  play(NOTE_C4, 1);
  play(NOTE_C4, 4);

  delay(2000);
}
