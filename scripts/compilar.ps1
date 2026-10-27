# Clona PS2Recomp, recompila SLUS_211.15 a C++ y compila el ejecutable nativo para PC.
# Lo llama scripts\2_compilar.cmd, que antes carga el entorno de Visual Studio (vcvars64).
param([switch]$Trazas)
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot 'common.ps1')

$elf  = Get-OkamiElf
$work = Get-OkamiWorkDir
New-Item -ItemType Directory -Force -Path $work | Out-Null
$rec  = Join-Path $work 'PS2Recomp'
$gen  = Join-Path $work 'generado'
$bld  = Join-Path $rec 'out\build'

$template  = Join-Path $RepoRoot 'config\recomp.template.toml'
$funcmap   = Join-Path $RepoRoot 'config\funcmap.csv'

# Parches del runtime nativo (Waffle565 + mejoras estables de arquitectura sin emulacion de PS2)
$waffleRuntimePatch        = Join-Path $RepoRoot 'patches\ps2recomp-waffle-runtime.patch'
$waffleTestsPatch          = Join-Path $RepoRoot 'patches\ps2recomp-waffle-tests.patch'
$waffleGccPatch            = Join-Path $RepoRoot 'patches\ps2recomp-waffle-gcc.patch'
$vu1nLeakPatch             = Join-Path $RepoRoot 'patches\ps2recomp-vu1n-leak.patch'
$vif1UnpackRapidoPatch     = Join-Path $RepoRoot 'patches\ps2recomp-vif1-unpack-rapido.patch'
$dmaBuffersPatch           = Join-Path $RepoRoot 'patches\ps2recomp-dma-buffers.patch'
$padRumbleScanPatch        = Join-Path $RepoRoot 'patches\ps2recomp-pad-rumble-scan.patch'
$vblankNtscPatch           = Join-Path $RepoRoot 'patches\ps2recomp-vblank-ntsc.patch'
$gsWorkerTracePatch        = Join-Path $RepoRoot 'patches\ps2recomp-gs-worker-trace.patch'
$fpsOverlayPatch           = Join-Path $RepoRoot 'patches\ps2recomp-fps-overlay.patch'
$fpsImagenesPatch          = Join-Path $RepoRoot 'patches\ps2recomp-fps-imagenes.patch'
$presentOrdenPatch         = Join-Path $RepoRoot 'patches\ps2recomp-present-orden.patch'
$stageLotesPatch           = Join-Path $RepoRoot 'patches\ps2recomp-stage-lotes.patch'
$pantallaPatch             = Join-Path $RepoRoot 'patches\ps2recomp-pantalla-completa.patch'
$iopAcumuladoPatch         = Join-Path $RepoRoot 'patches\ps2recomp-iop-acumulado.patch'
$ritmoFinoPatch            = Join-Path $RepoRoot 'patches\ps2recomp-ritmo-fino.patch'
$ciclosMitadPatch          = Join-Path $RepoRoot 'patches\ps2recomp-ciclos-mitad.patch'
$vu1Ranura64Patch          = Join-Path $RepoRoot 'patches\ps2recomp-vu1-ranura64.patch'
$vuRedondeoPatch           = Join-Path $RepoRoot 'patches\ps2recomp-vu-redondeo.patch'
$vu1InvalidacionRangoPatch = Join-Path $RepoRoot 'patches\ps2recomp-vu1-invalidacion-rango.patch'
$eePonerseAlDiaPatch       = Join-Path $RepoRoot 'patches\ps2recomp-ee-ponerse-al-dia.patch'
$pruebaSinMandoPatch       = Join-Path $RepoRoot 'patches\ps2recomp-prueba-sin-mando.patch'
$pantallaLatchPatch        = Join-Path $RepoRoot 'patches\ps2recomp-pantalla-latch.patch'
$cdStopPatch               = Join-Path $RepoRoot 'patches\ps2recomp-cd-stop.patch'
$iopDelayFueraPatch        = Join-Path $RepoRoot 'patches\ps2recomp-iop-delay-fuera.patch'
$mpegFinProgramaPatch      = Join-Path $RepoRoot 'patches\ps2recomp-mpeg-fin-programa.patch'
$eeViaRapidaPatch          = Join-Path $RepoRoot 'patches\ps2recomp-ee-via-rapida.patch'
$gsPrioridadPatch          = Join-Path $RepoRoot 'patches\ps2recomp-gs-prioridad-presentacion.patch'
$gsEglLinuxPatch           = Join-Path $RepoRoot 'patches\ps2recomp-gs-egl-linux.patch'
$vu1CapturaNativaPatch     = Join-Path $RepoRoot 'patches\ps2recomp-vu1-captura-nativa.patch'
$gsZComoColorPatch         = Join-Path $RepoRoot 'patches\ps2recomp-gs-z-como-color.patch'
$gsVolumenesAgrupadosPatch = Join-Path $RepoRoot 'patches\ps2recomp-gs-volumenes-agrupados.patch'
$fpuBarreraPatch           = Join-Path $RepoRoot 'patches\ps2recomp-fpu-barrera.patch'
$ee120hzPatch              = Join-Path $RepoRoot 'patches\ps2recomp-ee-120hz.patch'
$gsCuadrosEnVueloPatch     = Join-Path $RepoRoot 'patches\ps2recomp-gs-cuadros-en-vuelo.patch'
$vu1ClipSinSaltosPatch     = Join-Path $RepoRoot 'patches\ps2recomp-vu1-clip-sinsaltos.patch'
$vu1MaddSaturadoPatch      = Join-Path $RepoRoot 'patches\ps2recomp-vu1-madd-saturado.patch'
$vu0Vf0Patch               = Join-Path $RepoRoot 'patches\ps2recomp-vu0-vf0.patch'
$vu0Vi0Patch               = Join-Path $RepoRoot 'patches\ps2recomp-vu0-vi0.patch'
$vu1nHeadsPatch            = Join-Path $RepoRoot 'patches\ps2recomp-vu1n-heads.patch'

$overrides = Join-Path $RepoRoot 'src\okami_overrides.cpp'

$git = 'git'
if (-not (Get-Command git -ErrorAction SilentlyContinue)) { $git = Join-Path $env:ProgramFiles 'Git\cmd\git.exe' }

function Run([string]$exe, [string[]]$a) {
    Write-Host ">> $exe $($a -join ' ')"
    & $exe @a
    if ($LASTEXITCODE -ne 0) { throw "Fallo ($LASTEXITCODE): $exe" }
}
function Paso([string]$t) { Write-Host ''; Write-Host "==== [$(Get-Date -Format HH:mm:ss)] $t ====" }

Paso 'Verificando herramientas'
Write-Host "ELF:     $elf"
Write-Host "Trabajo: $work"
Run $git @('--version'); Run 'cmake' @('--version'); Run 'ninja' @('--version')

if (-not (Test-Path -LiteralPath (Join-Path $rec '.git'))) {
    Paso 'Clonando PS2Recomp'
    Run $git @('clone', $PS2RecompUrl, $rec)
}
Push-Location $rec
Run $git @('fetch', 'origin', $PS2RecompCommit)
Run $git @('checkout', '-f', $PS2RecompCommit)
Run $git @('submodule', 'update', '--init', '--recursive')

# Limpiar archivos nuevos de compilaciones anteriores para asegurar aplicacion limpia
foreach ($patchFile in Get-ChildItem -LiteralPath (Join-Path $RepoRoot 'patches') -Filter '*.patch' -File) {
    $created = $null
    foreach ($line in Get-Content -LiteralPath $patchFile.FullName) {
        if ($line -match '^diff --git a/(\S+) b/') { $created = $Matches[1] }
        elseif ($created -and $line -like 'new file mode*') {
            $extra = Join-Path $rec ($created -replace '/', '\')
            if (Test-Path -LiteralPath $extra) { Remove-Item -LiteralPath $extra -Force }
        }
    }
}

Paso 'Aplicando parches de runtime nativo'
$parches = @(
    $waffleRuntimePatch, $waffleTestsPatch, $vu0Vf0Patch, $vu0Vi0Patch, $vu1nHeadsPatch,
    $waffleGccPatch, $vu1nLeakPatch, $vif1UnpackRapidoPatch, $dmaBuffersPatch, $padRumbleScanPatch,
    $vblankNtscPatch, $gsWorkerTracePatch, $fpsOverlayPatch, $fpsImagenesPatch, $presentOrdenPatch,
    $stageLotesPatch, $pantallaPatch, $iopAcumuladoPatch, $ritmoFinoPatch, $ciclosMitadPatch,
    $vu1Ranura64Patch, $vuRedondeoPatch, $vu1InvalidacionRangoPatch, $eePonerseAlDiaPatch,
    $pruebaSinMandoPatch, $pantallaLatchPatch, $cdStopPatch, $iopDelayFueraPatch, $mpegFinProgramaPatch,
    $eeViaRapidaPatch, $gsPrioridadPatch, $gsEglLinuxPatch, $vu1CapturaNativaPatch, $gsZComoColorPatch,
    $gsVolumenesAgrupadosPatch, $fpuBarreraPatch, $ee120hzPatch, $gsCuadrosEnVueloPatch,
    $vu1ClipSinSaltosPatch, $vu1MaddSaturadoPatch
)
foreach ($p in $parches) {
    if (Test-Path -LiteralPath $p) {
        Run $git @('apply', '--ignore-whitespace', '--verbose', $p)
    }
}
Pop-Location

# Inclusiones y flags del runtime
$cm = Join-Path $rec 'ps2xRuntime\CMakeLists.txt'
if (-not (Select-String -LiteralPath $cm -Pattern 'Okami include' -Quiet)) {
    Add-Content -LiteralPath $cm "`n# Okami include`ntarget_include_directories(ps2EntryRunner PRIVATE `${CMAKE_CURRENT_SOURCE_DIR}/src/runner)"
}

$rm = Join-Path $rec 'ps2xRuntime\cmake\ReleaseMode.cmake'
$t = Get-Content -LiteralPath $rm -Raw
$t2 = $t -replace '(?m)^\s*/GL\b.*\r?\n', '' -replace '(?m)^\s*/LTCG\b.*\r?\n', '' `
         -replace 'set_property\(TARGET \$\{TargetName\} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE\)', '# IPO desactivado (Okami-Port)'
if ($t2 -ne $t) { Set-Content -LiteralPath $rm -Value $t2 -NoNewline }

# Generador de IOP nativo si existen modulos volcados
if ($env:OKAMI_IOP_MODULOS -and (Test-Path -LiteralPath (Join-Path $env:OKAMI_IOP_MODULOS 'modules.txt'))) {
    Paso 'Generando el IOP nativo'
    Run 'python' @('-I', (Join-Path $RepoRoot 'tools\iop\iopn_gen.py'), $env:OKAMI_IOP_MODULOS, (Join-Path $rec 'ps2xIOP\src\native'))
}

Paso 'Configurando CMake'
$logsEnabled = if ($Trazas) { 'ON' } else { 'OFF' }
Run 'cmake' @('-S', $rec, '-B', $bld, '-G', 'Ninja', '-DCMAKE_BUILD_TYPE=Release', '-DCMAKE_INTERPROCEDURAL_OPTIMIZATION=OFF',
              "-DPS2X_ENABLE_RUNTIME_LOGS=$logsEnabled", "-DPS2X_ENABLE_AGRESSIVE_LOGS=$logsEnabled", "-DPS2X_ENABLE_IOP_RPC_TRACE=$logsEnabled",
              '-DPS2X_ENABLE_RUNNER_UNITY_BUILD=ON', '-DPS2X_ENABLE_RUNNER_PCH=ON')

Paso 'Compilando el recompilador ps2_recomp'
Run 'cmake' @('--build', $bld, '--target', 'ps2_recomp')

Paso 'Generando C++ desde SLUS_211.15'
if (Test-Path $gen) { Remove-Item $gen -Recurse -Force }
New-Item -ItemType Directory $gen | Out-Null
$fw = { param($p) $p -replace '\\', '/' }

$elfWork = Join-Path $work 'SLUS_211.15'
$mapWork = Join-Path $work 'funcmap.csv'
Copy-Item -LiteralPath $elf -Destination $elfWork -Force
Copy-Item -LiteralPath $funcmap -Destination $mapWork -Force

(Get-Content -LiteralPath $template -Raw) `
    -replace '@ELF@', (& $fw $elfWork) `
    -replace '@MAP@', (& $fw $mapWork) `
    -replace '@OUT@', ((& $fw $gen) + '/') |
    Set-Content -LiteralPath (Join-Path $work 'config.toml') -Encoding ASCII

$recompExe = Get-ChildItem $bld -Recurse -Filter 'ps2_recomp.exe' | Select-Object -First 1
Run $recompExe.FullName @((Join-Path $work 'config.toml')) | Select-Object -Last 5
Write-Host ("Archivos C++ generados: {0}" -f (Get-ChildItem $gen).Count)

Paso 'Copiando codigo generado al runtime'
$runner = Join-Path $rec 'ps2xRuntime\src\runner'
Get-ChildItem $runner -File | Remove-Item -Force
Get-ChildItem -LiteralPath $gen -File | Copy-Item -Destination $runner
Copy-Item -LiteralPath $overrides -Destination (Join-Path $runner 'okami_overrides.cpp')
Get-ChildItem -LiteralPath (Join-Path $RepoRoot 'src') -Filter '*.h' -File | Copy-Item -Destination $runner

# Limpiar objetos previos para reconstruccion determinista
foreach ($objectRelative in @('ps2xRuntime\CMakeFiles\ps2_runtime.dir',
                             'ps2xTest\CMakeFiles\ps2_test_lib.dir',
                             'ps2xTest\CMakeFiles\ps2_test_function_table.dir')) {
    $objectDir = Join-Path $bld $objectRelative
    if (Test-Path -LiteralPath $objectDir) {
        Get-ChildItem -LiteralPath $objectDir -Recurse -Filter '*.obj' -File | Remove-Item -Force
    }
}
$runnerObjectDir = Join-Path $bld 'ps2xRuntime\CMakeFiles\ps2EntryRunner.dir'
if (Test-Path -LiteralPath $runnerObjectDir) {
    Get-ChildItem -LiteralPath $runnerObjectDir -Filter '*.pch' -File | Remove-Item -Force
    Get-ChildItem -LiteralPath $runnerObjectDir -Filter 'cmake_pch*.obj' -File | Remove-Item -Force
}
$unityDir = Join-Path $bld 'ps2xRuntime\CMakeFiles\ps2EntryRunner.dir\Unity'
if (Test-Path -LiteralPath $unityDir) { Get-ChildItem -LiteralPath $unityDir -Filter '*.obj' | Remove-Item -Force }

Run 'cmake' @('-S', $rec, '-B', $bld)

Paso 'Compilando ps2EntryRunner (ejecutable nativo)'
Run 'cmake' @('--build', $bld, '--target', 'ps2EntryRunner')

$exe = Get-ChildItem $bld -Recurse -Filter 'ps2EntryRunner.exe' | Select-Object -First 1
Paso "Compilacion completada con exito: $($exe.FullName)"
