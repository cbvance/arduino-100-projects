# Arduino 100 Projects

This is the code for the book *Getting Started with Arduino* by Charles
Vance (LearnSCADA). The book has 100 projects in 20 chapters. Each
project has its own folder here. The folder number matches the project
number in the book. You can open any project, upload it, and see it
work. Then you can change it and learn how it works.

See [PROJECTS.md](PROJECTS.md) for the full list.

## Safety first

Every project runs on 5 V from USB or a small battery pack. Nothing
connects to wall power.

## The board

All projects use one board:

| Item       | Value              |
|------------|--------------------|
| Board      | Arduino Uno R3     |
| Part no.   | A000066            |
| Chip       | ATmega328P         |
| FQBN       | `arduino:avr:uno`  |

The FQBN is the board's full name for the command line tools.

## Open a project in Arduino IDE 2

1. Start Arduino IDE 2.
2. Click **File**, then **Open**.
3. Go to the `projects` folder and open a project folder.
4. Pick the `.ino` file. It has the same name as its folder.
5. Select **Arduino Uno** and its port.
6. Click **Upload**.

Each project folder also has a `README.md`. It tells you the parts, the
wiring, and what you should see.

## Compile everything from the command line

You need `arduino-cli`. Install it once:

```sh
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
arduino-cli core update-index
arduino-cli core install arduino:avr
```

Compile one project:

```sh
arduino-cli compile --fqbn arduino:avr:uno --warnings all projects/p001-blink
```

Compile all projects (Linux, macOS, or Git Bash on Windows):

```sh
bash scripts/compile-all.sh
```

Compile all projects (Windows PowerShell):

```powershell
.\scripts\compile-all.ps1
```

Each project prints PASS or FAIL.

Upload to a board. Find your port first, then use it in place of
`/dev/ttyACM0`:

```sh
arduino-cli board list
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno projects/p001-blink
```

Watch serial output (Project 5):

```sh
arduino-cli monitor -p /dev/ttyACM0 -c baudrate=9600
```

Save a `.hex` file for a project:

```sh
arduino-cli compile --fqbn arduino:avr:uno --export-binaries projects/p001-blink
```

## Start a new project folder

```sh
bash scripts/new-project.sh 006 external-led
```

This makes `projects/p006-external-led/` with an empty `.ino` file and
a `README.md` to fill in.

## License

MIT. See [LICENSE](LICENSE).
