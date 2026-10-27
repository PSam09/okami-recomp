# Caminhos compartilhados pelos scripts de compilação e execução de Okami Recomp.
# Carregado com: . (Join-Path $PSScriptRoot 'common.ps1')

$RepoRoot = Split-Path -Parent $PSScriptRoot
$LogsDir  = Join-Path $RepoRoot 'logs'
New-Item -ItemType Directory -Force -Path $LogsDir | Out-Null

# Commit do PS2Recomp sobre o qual os patches do runtime nativo são aplicados
$PS2RecompUrl    = 'https://github.com/ran-j/PS2Recomp.git'
$PS2RecompCommit = 'c5a9d02573410a2085a4b4b831b0b68ba3515440'

# Diretório de trabalho: caminho curto para evitar o limite de 260 caracteres do Windows.
# Pode ser customizado com a variável de ambiente OKAMI_WORK.
function Get-OkamiWorkDir {
    if ($env:OKAMI_WORK) { return $env:OKAMI_WORK }
    return Join-Path (Split-Path -Qualifier $RepoRoot) 'okamiport'
}

# Executável do jogo (SLUS_211.15). Ordem de busca:
#   1. variável de ambiente OKAMI_ELF
#   2. game\SLUS_211.15 dentro do repositório
#   3. ..\Okami ISO extraida\SLUS_211.15 ao lado do repositório
function Get-OkamiElf {
    $candidatos = @()
    if ($env:OKAMI_ELF) { $candidatos += $env:OKAMI_ELF }
    $candidatos += (Join-Path $RepoRoot 'game\SLUS_211.15')
    $candidatos += (Join-Path (Split-Path -Parent $RepoRoot) 'game\SLUS_211.15')
    $candidatos += (Join-Path $RepoRoot 'SLUS_211.15')
    foreach ($c in $candidatos) {
        if (Test-Path -LiteralPath $c) { return (Resolve-Path -LiteralPath $c).Path }
    }
    throw "SLUS_211.15 não foi encontrado. Extraia em game\ com 'python tools\iso_extract.py' ou defina OKAMI_ELF. Procurado em:`n  $($candidatos -join "`n  ")"
}

# Imagem ISO para extração automática na primeira execução
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
