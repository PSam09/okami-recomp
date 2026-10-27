@echo off
rem Instala o Git e o Visual Studio 2022 Build Tools (inclui compilador C++, CMake e Ninja).
cd /d "%~dp0.."
if not exist logs mkdir logs
echo ==========================================================
echo  Instalando Git e Visual Studio 2022 Build Tools (C++)
echo  O Windows solicitara permissao de administrador: aceite.
echo  Pode levar de 15 a 30 minutos. Nao feche esta janela.
echo ==========================================================
echo [%date% %time%] Inicio > logs\1_instalar.log
winget install -e --id Git.Git --accept-source-agreements --accept-package-agreements >> logs\1_instalar.log 2>&1
echo [git] codigo %errorlevel% >> logs\1_instalar.log
winget install -e --id Microsoft.VisualStudio.2022.BuildTools --accept-source-agreements --accept-package-agreements --override "--wait --passive --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended" >> logs\1_instalar.log 2>&1
echo [vs] codigo %errorlevel% >> logs\1_instalar.log
echo [%date% %time%] FIM >> logs\1_instalar.log
echo.
echo Concluido. Verifique logs\1_instalar.log
pause
