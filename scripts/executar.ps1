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
Write-Host "--------------------------------------------------------"
Write-Host "Iniciando a janela grafica nativa do jogo ('PS2-Recomp')..."
Write-Host "Pressione F11 para alternar entre Tela Cheia e Janela. Pressione F2 para medidor de FPS."
Write-Host "--------------------------------------------------------"

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
    NoNewWindow = $true
    PassThru = $true
}

$proc = Start-Process @launchParams

# Tentar focar e trazer a janela grafica do jogo para o primeiro plano
try {
    Add-Type -Name Win32Window -Namespace Native -MemberDefinition @"
        [DllImport("user32.dll", SetLastError = true, CharSet = CharSet.Auto)]
        public static extern IntPtr FindWindow(string lpClassName, string lpWindowName);
        [DllImport("user32.dll")]
        public static extern bool SetForegroundWindow(IntPtr hWnd);
        [DllImport("user32.dll")]
        public static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);
"@ -ErrorAction SilentlyContinue
    for ($i = 0; $i -lt 30; $i++) {
        Start-Sleep -Milliseconds 200
        if ($proc.HasExited) { break }
        $hwnd = [Native.Win32Window]::FindWindow($null, "PS2-Recomp | SLUS_211.15")
        if ($hwnd -eq [IntPtr]::Zero) {
            $p = Get-Process -Id $proc.Id -ErrorAction SilentlyContinue
            if ($p -and $p.MainWindowHandle -ne [IntPtr]::Zero) {
                $hwnd = $p.MainWindowHandle
            }
        }
        if ($hwnd -ne [IntPtr]::Zero) {
            [Native.Win32Window]::ShowWindow($hwnd, 9) | Out-Null
            [Native.Win32Window]::SetForegroundWindow($hwnd) | Out-Null
            break
        }
    }
} catch {}

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
