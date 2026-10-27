@echo off
cd /d "%~dp0.."
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0ejecutar.ps1" -Segundos 60 %*
pause
