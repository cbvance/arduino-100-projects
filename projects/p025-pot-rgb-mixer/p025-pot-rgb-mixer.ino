// Project 25: Pot RGB Mixer
// One knob mixes three colors. The knob sets one color at a
// time. Press the button to move on to the next color.

const int KNOB = A0;
const int BUTTON = 2;
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

int red = 0;                  // the mix so far
int green = 0;
int blue = 0;

int selected = 0;             // 0 red, 1 green, 2 blue
bool wasPressed = false;

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

// Print the mix and which color the knob has now.
void report() {
  Serial.print("mix ");
  Serial.print(red);
  Serial.print(", ");
  Serial.print(green);
  Serial.print(", ");
  Serial.print(blue);
  Serial.print("   knob now sets ");
  if (selected == 0) {
    Serial.println("RED");
  } else if (selected == 1) {
    Serial.println("GREEN");
  } else {
    Serial.println("BLUE");
  }
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
  report();
}

void loop() {
  // Read the inputs.
  int raw = analogRead(KNOB);
  bool pressed = (digitalRead(BUTTON) == LOW);

  // Solve: a new press moves the knob to the next color.
  if (pressed && !wasPressed) {
    selected = (selected + 1) % 3;
    report();
  }
  wasPressed = pressed;

  // Solve: the knob sets the selected color only.
  int level = map(raw, 0, 1023, 0, 255);
  if (selected == 0) {
    red = level;
  } else if (selected == 1) {
    green = level;
  } else {
    blue = level;
  }

  // Write the outputs.
  setColor(red, green, blue);
  delay(20);
}
