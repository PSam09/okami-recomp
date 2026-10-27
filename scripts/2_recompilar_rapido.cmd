@echo off
rem Carrega o ambiente do Visual Studio e executa recompilacao rapida de overrides.
cd /d "%~dp0.."
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
set "VSPATH="
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSPATH=%%i"
if not defined VSPATH (
  echo Visual Studio com C++ nao foi encontrado.
  pause
  exit /b 1
)
set VSCMD_SKIP_SENDTELEMETRY=1
call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" > nul 2>&1
if exist "%VSPATH%\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja\ninja.exe" (
  set "PATH=%VSPATH%\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja;%PATH%"
)
if defined NON_INTERACTIVE (set "PAUSE_CMD=rem") else (set "PAUSE_CMD=pause")
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0recompilar_rapido.ps1"
set "RC=%errorlevel%"
%PAUSE_CMD%
exit /b %RC%
