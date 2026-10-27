# Executa o port nativo de Okami e grava registros em logs\
param(
    [int]$Segundos = 0,
    [switch]$Janela,
    [switch]$Fps
)
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot 'common.ps1')

$work = Get-OkamiWorkDir
$exePath  = Join-Path $work 'PS2Recomp\out\build\ps2xRuntime\ps2EntryRunner.exe'

if (-not (Test-Path -LiteralPath $exePath)) {
    throw "Executavel nao encontrado ($exePath). Execute primeiro scripts\2_compilar.cmd"
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

$elfDir = Split-Path -Parent $elf
$env:PS2X_DISC_PATH = $elfDir
if ($Janela) { 
    $env:GOW_PANTALLA_COMPLETA = '0'
    $env:OKAMI_PANTALLA_COMPLETA = '0' 
}
if ($Fps) { 
    $env:GOW_FPS = '1'
    $env:OKAMI_FPS = '1' 
}

# Variaveis de runtime
if (-not $env:PS2X_GS_WORKER) { $env:PS2X_GS_WORKER = '1' }

Write-Host "Iniciando Okami Native Port..."
Write-Host "Binario: $exePath"
Write-Host "ELF:     $elf"
Write-Host "Dados:   $env:PS2X_DISC_PATH"

$outLog = Join-Path $LogsDir 'executar.log'
$errLog = Join-Path $LogsDir 'executar_err.log'

# Limpar logs anteriores
if (Test-Path -LiteralPath $outLog) { Remove-Item -LiteralPath $outLog -Force }
if (Test-Path -LiteralPath $errLog) { Remove-Item -LiteralPath $errLog -Force }

$launchParams = @{
    FilePath = $exePath
    ArgumentList = ('"' + $elf + '"')
    WorkingDirectory = $elfDir
    RedirectStandardOutput = $outLog
    RedirectStandardError = $errLog
    PassThru = $true
}

$proc = Start-Process @launchParams

if ($Segundos -gt 0) {
    Write-Host "Executando por $Segundos segundos..."
    $timeout = [Diagnostics.Stopwatch]::StartNew()
    while ($timeout.Elapsed.TotalSeconds -lt $Segundos -and -not $proc.HasExited) {
        Start-Sleep -Milliseconds 250
    }
    if (-not $proc.HasExited) {
        Write-Host "Tempo limite de $Segundos s alcancado. Finalizando processo..."
        $proc.Kill()
    }
} else {
    Write-Host "Executando indefinidamente. Feche a janela do jogo para sair."
    $proc.WaitForExit()
}

$proc.WaitForExit(2000) | Out-Null
Write-Host "Processo concluido (codigo $($proc.ExitCode)). Logs salvos em $LogsDir"
