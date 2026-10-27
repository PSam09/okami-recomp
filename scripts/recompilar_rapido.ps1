# Recompila rapidamente apenas os overrides de Okami sem regenerar todo o C++ (~1 min).
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot 'common.ps1')

$work = Get-OkamiWorkDir
$runner = Join-Path $work 'PS2Recomp\ps2xRuntime\src\runner'

Write-Host "Copiando arquivos de src\ para o runner ($runner)..."
Copy-Item (Join-Path $RepoRoot 'src\okami_overrides.cpp') -Destination (Join-Path $runner 'okami_overrides.cpp') -Force
if (Test-Path (Join-Path $RepoRoot 'src\*.h')) {
    Copy-Item (Join-Path $RepoRoot 'src\*.h') -Destination $runner -Force
}

$bld = Join-Path $work 'PS2Recomp\out\build'
Write-Host "Compilando ps2EntryRunner com Ninja..."
cmake --build $bld --target ps2EntryRunner
if ($LASTEXITCODE -ne 0) { throw "Falha na compilacao ($LASTEXITCODE)" }
Write-Host "Recompilacao rapida concluida com sucesso!"
