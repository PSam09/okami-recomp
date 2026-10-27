@echo off
rem Carrega o ambiente do Visual Studio e executa scripts\compilar.ps1.
cd /d "%~dp0.."
if not exist logs mkdir logs
echo ==========================================================
echo  Compilando Okami Recomp. Pode levar algum tempo.
echo  O progresso sera registrado em logs\2_compilar.log
echo ==========================================================
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
set "VSPATH="
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSPATH=%%i"
if not defined VSPATH (
  echo Visual Studio com ferramentas C++ nao foi encontrado. > logs\2_compilar.log
  echo Visual Studio com C++ nao foi encontrado. Execute antes scripts\1_instalar_ferramentas.cmd
  pause
  exit /b 1
)
set VSCMD_SKIP_SENDTELEMETRY=1
call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" > logs\vcvars.log 2>&1
if exist "%VSPATH%\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja\ninja.exe" (
  set "PATH=%VSPATH%\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja;%PATH%"
)
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0compilar.ps1" %* > logs\2_compilar.log 2>&1
set "RC=%errorlevel%"
echo [codigo final %RC%] >> logs\2_compilar.log
echo.
echo Processo concluido (codigo %RC%). Verifique logs\2_compilar.log
if %RC% neq 0 (
  echo Detectados erros na compilacao. Analisando padroes automaticamente...
  python tools\analisar_erros.py logs\2_compilar.log
)
if not defined NON_INTERACTIVE pause
exit /b %RC%
