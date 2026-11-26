// Project 35: Light Theremin
// Hold the right-hand button and wave your other hand over
// the light sensor. More light gives a higher note.

const int LIGHT_SENSOR = A0;
const int PLAY = 2;           // right-hand button
const int PIEZO = 8;

const int DARK = 200;         // your reading with it covered
const int BRIGHT = 700;       // your reading in room light
const int LOW_NOTE = 200;     // hertz
const int HIGH_NOTE = 1500;   // hertz

void setup() {
  pinMode(PLAY, INPUT_PULLUP);
}

void loop() {
  // Read the inputs.
  int light = analogRead(LIGHT_SENSOR);
  bool playing = (digitalRead(PLAY) == LOW);

  // Solve: scale light to pitch and hold it inside the range.
  int pitch = map(light, DARK, BRIGHT, LOW_NOTE, HIGH_NOTE);
  pitch = constrain(pitch, LOW_NOTE, HIGH_NOTE);

  // Write the output.
  if (playing) {
    tone(PIEZO, pitch);
  } else {
    noTone(PIEZO);
  }
  delay(10);
}
