#!/usr/bin/env bash
# Make a new project folder.
# Usage: bash scripts/new-project.sh NNN slug
# Example: bash scripts/new-project.sh 006 external-led
# Makes projects/p006-external-led/ with an empty .ino and a README.md.
# The project name and chapter come from PROJECTS.md when listed there.

set -eu

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 NNN slug" >&2
  exit 2
fi

num="$1"
slug="$2"

if ! [[ "$num" =~ ^[0-9]{3}$ ]]; then
  echo "NNN must be three digits, like 006" >&2
  exit 2
fi

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
folder="p${num}-${slug}"
dir="$ROOT/projects/$folder"

if [ -e "$dir" ]; then
  echo "$dir already exists" >&2
  exit 1
fi

plain=$((10#$num))

# Look up the name and chapter in PROJECTS.md.
# Row format: | No. | `folder` | Project | Chapter | Status |
name=""
chapter="N"
if [ -f "$ROOT/PROJECTS.md" ]; then
  row="$(grep -F "\`$folder\`" "$ROOT/PROJECTS.md" || true)"
  if [ -n "$row" ]; then
    name="$(echo "$row" | awk -F'|' '{gsub(/^ +| +$/, "", $4); print $4}')"
    chapter="$(echo "$row" | awk -F'|' '{gsub(/^ +| +$/, "", $5); print $5}')"
  fi
fi

# Fall back to the slug in title case.
if [ -z "$name" ]; then
  name="$(echo "$slug" | tr '-' ' ' | awk '{for (i = 1; i <= NF; i++) $i = toupper(substr($i, 1, 1)) substr($i, 2); print}')"
fi

mkdir -p "$dir"
: > "$dir/$folder.ino"

cat > "$dir/README.md" <<EOF
# Project $plain: $name

Book chapter: $chapter

## What it does

## Parts

## Wiring

## Upload
1. Open the .ino file in Arduino IDE 2.
2. Select Arduino Uno and its port.
3. Click Upload.

## What you should see

## Change it
EOF

echo "Created projects/$folder/"
