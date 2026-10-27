# Monitora em tempo real os registros de execucao
$RepoRoot = Split-Path -Parent $PSScriptRoot
$log = Join-Path $RepoRoot 'logs\executar.log'
$err = Join-Path $RepoRoot 'logs\executar_err.log'

Write-Host "Monitor de logs (Ctrl+C para encerrar)"
Write-Host "Aguardando escrita nos logs..."

if (-not (Test-Path $log)) { "" | Out-File $log }
if (-not (Test-Path $err)) { "" | Out-File $err }

Get-Content -Path @($log, $err) -Wait -Tail 20
