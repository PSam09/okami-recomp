# Executa o port nativo de Okami e grava registros em logs\
param(
    [int]$Segundos = 0,
    [switch]$Janela,
    [switch]$Fps
)
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot 'common.ps1')

$work = Get-OkamiWorkDir
$exe  = Join-Path $work 'PS2Recomp\out\build\ps2xRuntime\ps2EntryRunner.exe'

if (-not (Test-Path -LiteralPath $exe)) {
    throw "Executavel nao encontrado ($exe). Execute primeiro scripts\2_compilar.cmd"
}

# Auto-extracao do disco se game\SLUS_211.15 ainda nao existir
$elf = $null
try { $elf = Get-OkamiElf } catch {}
if (-not $elf) {
    $iso = Get-OkamiIso
    if ($iso) {
        Write-Host "Extraindo disco com mapeamento de setores a partir de: $iso"
        $gameDir = Join-Path $RepoRoot 'game'
        New-Item -ItemType Directory -Force -Path $gameDir | Out-Null
        python (Join-Path $RepoRoot 'tools\iso_extract.py') $iso $gameDir --layout
        $elf = Get-OkamiElf
    } else {
        throw "Nenhum arquivo de jogo ou imagem ISO foi encontrada para extracao."
    }
}

$env:PS2X_DISC_PATH = Split-Path -Parent $elf
if ($Janela) { $env:OKAMI_PANTALLA_COMPLETA = '0' }
if ($Fps)    { $env:OKAMI_FPS = '1' }

Write-Host "Iniciando Okami Native Port..."
Write-Host "Binario: $exe"
Write-Host "Dados:   $env:PS2X_DISC_PATH"

$outLog = Join-Path $LogsDir 'executar.log'
$errLog = Join-Path $LogsDir 'executar_err.log'

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
    Write-Host "Executando por $Segundos segundos..."
    if (-not $proc.WaitForExit($Segundos * 1000)) {
        Write-Host "Tempo limite atingido. Encerrando processo."
        $proc.Kill()
    }
} else {
    $proc.WaitForExit()
}

[System.Threading.Tasks.Task]::WaitAll(@($stdoutTask, $stderrTask))
Write-Host "Processo finalizado com codigo $($proc.ExitCode). Logs salvos em $LogsDir"
