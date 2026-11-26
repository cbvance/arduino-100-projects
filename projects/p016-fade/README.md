# Project 16: Fade

Book chapter: 4

## What it does

Fades an LED on PWM pin 9 up and down with analogWrite, 8 ms per
level.

## Bill of materials

| Qty | Part | Suggested part |
|---|---|---|
| 1 | Arduino Uno R3 | Arduino A000066 |
| 1 | USB cable, type A to type B | Any USB 2.0 A-to-B cable that carries data, about 1 m |
| 1 | Breadboard, half size, 400 tie points | BusBoard BB400 |
| 1 | LED, 5 mm, any color | Kingbright WP7113ID (red) |
| 1 | Resistor, 220 ohm, 1/4 W, 5% | Yageo CFR-25JT-52-220R |
| 3 | Jumper wires, pin to pin | BusBoard ZW-MM-10 (ribbon of 40, 10 cm) |

## Wiring

![Wiring diagram for Project 16](wiring.svg)

*Wiring diagram (book Figure 4.3)*

![Schematic for Project 16](schematic.svg)

*Schematic (book Figure 4.4)*

- Resistor 220 ohm: h10 to h14
- LED: long leg f14, short leg f15
- Wire: Uno pin 9 to j10
- Wire: j15 to ground rail
- Wire: ground rail to Uno GND

## Upload
1. Open the .ino file in Arduino IDE 2.
2. Select Arduino Uno and its port.
3. Click Upload.

## What you should see

The LED brightens over about 2 s, dims over about 2 s, and repeats.

## Change it

Move the LED to pin 8 (not PWM) and explain what happens.
