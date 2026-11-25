# Project 2: Blink Rates

Book chapter: 1

## What it does

One LED sends four messages. The MODE constant picks the message:
steady, slow flash, fast flash, or short blip.

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

## What you should see

With MODE 2, the L LED is on 1 s, then off 1 s.

| MODE | Message    | What the L LED does         |
|-----:|------------|-----------------------------|
| 1    | Steady on  | Stays on                    |
| 2    | Slow flash | On 1 s, off 1 s             |
| 3    | Fast flash | On 200 ms, off 200 ms       |
| 4    | Short blip | On 100 ms, once every 2 s   |

Change MODE, upload again, and watch the new pattern.

## Change it

Add a mode 5 with your own timing.
