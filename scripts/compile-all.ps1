# Compile every project in projects\ for the Arduino Uno R3.
# Prints PASS or FAIL per project. Exits non-zero if any fail.

$Fqbn = "arduino:avr:uno"
$Root = Split-Path -Parent $PSScriptRoot

$pass = 0
$fail = 0
$failed = @()

foreach ($dir in Get-ChildItem -Path (Join-Path $Root "projects") -Directory | Sort-Object Name) {
    # Skip folders with no .ino file.
    if (-not (Get-ChildItem -Path $dir.FullName -Filter "*.ino" -File)) {
        continue
    }

    $output = & arduino-cli compile --fqbn $Fqbn --warnings all $dir.FullName 2>&1 | Out-String
    if ($LASTEXITCODE -eq 0) {
        Write-Output ("PASS  " + $dir.Name)
        $pass++
    } else {
        Write-Output ("FAIL  " + $dir.Name)
        $fail++
        $failed += $dir.Name
    }

    # Show warnings and size lines so nothing hides.
    $output -split "`r?`n" |
        Where-Object { $_ -match "warning:|error:|Sketch uses|Global variables" } |
        ForEach-Object { Write-Output ("      " + $_) }
}

Write-Output ""
Write-Output ("Passed: $pass  Failed: $fail")

if ($fail -gt 0) {
    Write-Output ("Failed projects: " + ($failed -join " "))
    exit 1
}
exit 0
