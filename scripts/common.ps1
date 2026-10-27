# Rutas compartidas por los scripts de compilacion y ejecucion de Okami Recomp.
# Se carga con: . (Join-Path $PSScriptRoot 'common.ps1')

$RepoRoot = Split-Path -Parent $PSScriptRoot
$LogsDir  = Join-Path $RepoRoot 'logs'
New-Item -ItemType Directory -Force -Path $LogsDir | Out-Null

# Commit de PS2Recomp sobre el que se aplican los parches del runtime nativo
$PS2RecompUrl    = 'https://github.com/ran-j/PS2Recomp.git'
$PS2RecompCommit = 'c5a9d02573410a2085a4b4b831b0b68ba3515440'

# Carpeta de trabajo: ruta corta para evitar el limite de 260 caracteres de Windows.
# Se puede cambiar con la variable de entorno OKAMI_WORK.
function Get-OkamiWorkDir {
    if ($env:OKAMI_WORK) { return $env:OKAMI_WORK }
    return Join-Path (Split-Path -Qualifier $RepoRoot) 'okamiport'
}

# Ejecutable del juego (SLUS_211.15). Orden de busqueda:
#   1. variable de entorno OKAMI_ELF
#   2. game\SLUS_211.15 dentro del repositorio
#   3. ..\Okami ISO extraida\SLUS_211.15 junto al repositorio
function Get-OkamiElf {
    $candidatos = @()
    if ($env:OKAMI_ELF) { $candidatos += $env:OKAMI_ELF }
    $candidatos += (Join-Path $RepoRoot 'game\SLUS_211.15')
    $candidatos += (Join-Path (Split-Path -Parent $RepoRoot) 'game\SLUS_211.15')
    $candidatos += (Join-Path $RepoRoot 'SLUS_211.15')
    foreach ($c in $candidatos) {
        if (Test-Path -LiteralPath $c) { return (Resolve-Path -LiteralPath $c).Path }
    }
    throw "No se encontro SLUS_211.15. Extraelo en game\ con tools\iso_extract.py o define OKAMI_ELF. Buscado en:`n  $($candidatos -join "`n  ")"
}

# Imagen ISO para extraccion automatica en primera ejecucion
function Get-OkamiIso {
    $candidatos = @()
    if ($env:OKAMI_ISO) { $candidatos += $env:OKAMI_ISO }
    $candidatos += (Join-Path $RepoRoot 'Okami (USA).iso')
    $candidatos += (Join-Path $RepoRoot 'Okami.iso')
    $candidatos += (Join-Path (Split-Path -Parent $RepoRoot) 'Okami (USA).iso')
    foreach ($c in $candidatos) {
        if (Test-Path -LiteralPath $c) { return (Resolve-Path -LiteralPath $c).Path }
    }
    return $null
}
