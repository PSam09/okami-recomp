# Monitora en tiempo real los registros de ejecucion
$RepoRoot = Split-Path -Parent $PSScriptRoot
$log = Join-Path $RepoRoot 'logs\ejecutar.log'
$err = Join-Path $RepoRoot 'logs\ejecutar_err.log'

Write-Host "Monitor de logs (Ctrl+C para salir)"
Write-Host "Esperando escritura en logs..."

if (-not (Test-Path $log)) { "" | Out-File $log }
if (-not (Test-Path $err)) { "" | Out-File $err }

Get-Content -Path @($log, $err) -Wait -Tail 20
