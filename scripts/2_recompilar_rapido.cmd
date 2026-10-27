@echo off
rem Recompila rapido solo los overrides de Okami sin regenerar todo el C++ (~1 min).
cd /d "%~dp0.."
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
set "VSPATH="
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSPATH=%%i"
if not defined VSPATH (
  echo No se encontro Visual Studio con C++.
  pause
  exit /b 1
)
call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" > nul 2>&1
powershell -NoProfile -ExecutionPolicy Bypass -Command "& {
    . scripts\common.ps1
    $work = Get-OkamiWorkDir
    $runner = Join-Path $work 'PS2Recomp\ps2xRuntime\src\runner'
    Copy-Item 'src\okami_overrides.cpp' -Destination (Join-Path $runner 'okami_overrides.cpp') -Force
    if (Test-Path 'src\*.h') { Copy-Item 'src\*.h' -Destination $runner -Force }
    $bld = Join-Path $work 'PS2Recomp\out\build'
    cmake --build $bld --target ps2EntryRunner
}"
pause
