# Ejecuta el port nativo de Okami y guarda registros en logs\
param(
    [int]$Segundos = 0,
    [switch]$Ventana,
    [switch]$Fps
)
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot 'common.ps1')

$work = Get-OkamiWorkDir
$exe  = Join-Path $work 'PS2Recomp\out\build\ps2xRuntime\ps2EntryRunner.exe'

if (-not (Test-Path -LiteralPath $exe)) {
    throw "No se encontro el ejecutable ($exe). Corre antes scripts\2_compilar.cmd"
}

# Auto-extraccion del disco si game\SLUS_211.15 no existe todavia
$elf = $null
try { $elf = Get-OkamiElf } catch {}
if (-not $elf) {
    $iso = Get-OkamiIso
    if ($iso) {
        Write-Host "Extrayendo disco con mapeo de sectores desde: $iso"
        $gameDir = Join-Path $RepoRoot 'game'
        New-Item -ItemType Directory -Force -Path $gameDir | Out-Null
        python (Join-Path $RepoRoot 'tools\iso_extract.py') $iso $gameDir --layout
        $elf = Get-OkamiElf
    } else {
        throw "No se encontro el juego ni la ISO para extraer."
    }
}

$env:PS2X_DISC_PATH = Split-Path -Parent $elf
if ($Ventana) { $env:OKAMI_PANTALLA_COMPLETA = '0' }
if ($Fps)     { $env:OKAMI_FPS = '1' }

Write-Host "Ejecutando Okami Native Port..."
Write-Host "Binario: $exe"
Write-Host "Datos:   $env:PS2X_DISC_PATH"

$outLog = Join-Path $LogsDir 'ejecutar.log'
$errLog = Join-Path $LogsDir 'ejecutar_err.log'

$psi = New-Object System.Diagnostics.ProcessStartInfo
$psi.FileName = $exe
$psi.WorkingDirectory = Split-Path -Parent $elf
$psi.UseShellExecute = $false
$psi.RedirectStandardOutput = $true
$psi.RedirectStandardError = $true

$proc = [System.Diagnostics.Process]::Start($psi)

$stdoutTask = [System.Threading.Tasks.Task]::Run([System.Action]{
    $reader = $proc.StandardOutput
    $writer = [System.IO.File]::CreateText($outLog)
    try {
        while (-not $reader.EndOfStream) {
            $line = $reader.ReadLine()
            $writer.WriteLine($line)
            $writer.Flush()
        }
    } finally { $writer.Dispose() }
})

$stderrTask = [System.Threading.Tasks.Task]::Run([System.Action]{
    $reader = $proc.StandardError
    $writer = [System.IO.File]::CreateText($errLog)
    try {
        while (-not $reader.EndOfStream) {
            $line = $reader.ReadLine()
            $writer.WriteLine($line)
            $writer.Flush()
        }
    } finally { $writer.Dispose() }
})

if ($Segundos -gt 0) {
    Write-Host "Ejecutando por $Segundos segundos..."
    if (-not $proc.WaitForExit($Segundos * 1000)) {
        Write-Host "Tiempo cumplido. Cerrando proceso."
        $proc.Kill()
    }
} else {
    $proc.WaitForExit()
}

[System.Threading.Tasks.Task]::WaitAll(@($stdoutTask, $stderrTask))
Write-Host "Proceso terminado con codigo $($proc.ExitCode). Logs en $LogsDir"
