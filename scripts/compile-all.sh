#!/usr/bin/env bash
# Compile every project in projects/ for the Arduino Uno R3.
# Prints PASS or FAIL per project. Exits non-zero if any fail.

set -u

FQBN="arduino:avr:uno"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"

pass=0
fail=0
failed=()

for dir in "$ROOT"/projects/*/; do
  dir="${dir%/}"
  name="$(basename "$dir")"

  # Skip folders with no .ino file.
  if ! ls "$dir"/*.ino >/dev/null 2>&1; then
    continue
  fi

  if output="$(arduino-cli compile --fqbn "$FQBN" --warnings all "$dir" 2>&1)"; then
    echo "PASS  $name"
    pass=$((pass + 1))
  else
    echo "FAIL  $name"
    fail=$((fail + 1))
    failed+=("$name")
  fi

  # Show warnings and size lines so nothing hides.
  echo "$output" | grep -E "warning:|error:|Sketch uses|Global variables" | sed 's/^/      /'
done

echo
echo "Passed: $pass  Failed: $fail"

if [ "$fail" -gt 0 ]; then
  echo "Failed projects: ${failed[*]}"
  exit 1
fi
