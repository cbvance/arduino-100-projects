# Project 5: Serial Hello

Book chapter: 1

## What it does

Prints a startup line over serial. Then it prints an uptime line once
per second. The speed is 9600 baud.

## Parts

- Arduino Uno R3
- USB cable

No external parts.

## Wiring

None. Uses the built-in LED on pin 13.

## Upload
1. Open the .ino file in Arduino IDE 2.
2. Select Arduino Uno and its port.
3. Click Upload.

Then open the Serial Monitor (Tools, Serial Monitor) and set it to 9600
baud.

## What you should see

The Serial Monitor shows:

```
Bench Creek online
Uptime: 1 s
Uptime: 2 s
Uptime: 3 s
```

It keeps counting. The L LED blips once a second.

## Change it

Add a second line that prints "Pump: STOPPED" after each uptime line.
