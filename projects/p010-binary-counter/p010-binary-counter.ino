// Project 10: Binary Counter
// Counts from 0 to 15 on four LEDs, in binary.
// Parts: 4 LEDs, 4 resistors (220 ohm), breadboard, 9 wires.

const int BIT3 = 11;          // worth 8
const int BIT2 = 10;          // worth 4
const int BIT1 = 9;           // worth 2
const int BIT0 = 8;           // worth 1

int count = 0;

void setup() {
  pinMode(BIT3, OUTPUT);
  pinMode(BIT2, OUTPUT);
  pinMode(BIT1, OUTPUT);
  pinMode(BIT0, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // bitRead(number, n) gives bit n of the number: 1 or 0.
  digitalWrite(BIT3, bitRead(count, 3));
  digitalWrite(BIT2, bitRead(count, 2));
  digitalWrite(BIT1, bitRead(count, 1));
  digitalWrite(BIT0, bitRead(count, 0));

  Serial.print(count);
  Serial.print(" = ");
  Serial.println(count, BIN);       // BIN prints it in binary

  delay(1000);

  count = count + 1;
  if (count > 15) {                 // four bits only reach 15
    count = 0;
  }
}
