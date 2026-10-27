# Clona o PS2Recomp, recompila SLUS_211.15 para C++ e compila o executavel nativo para PC.
# Invocado por scripts\2_compilar.cmd apos carregar o ambiente do Visual Studio (vcvars64).
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

# Patches do runtime nativo (Waffle565 + melhorias de latencia e subsistemas de PC)
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
$fpsFramesPatch            = Join-Path $RepoRoot 'patches\ps2recomp-fps-frames.patch'
$presentOrderPatch         = Join-Path $RepoRoot 'patches\ps2recomp-present-order.patch'
$stageBatchesPatch         = Join-Path $RepoRoot 'patches\ps2recomp-gs-stage-batches.patch'
$fullscreenPatch           = Join-Path $RepoRoot 'patches\ps2recomp-fullscreen.patch'
$iopAcumuladoPatch         = Join-Path $RepoRoot 'patches\ps2recomp-iop-acumulado.patch'
$finePacingPatch           = Join-Path $RepoRoot 'patches\ps2recomp-fine-pacing.patch'
$halfCyclesPatch           = Join-Path $RepoRoot 'patches\ps2recomp-half-cycles.patch'
$vu1Slot64Patch            = Join-Path $RepoRoot 'patches\ps2recomp-vu1-slot64.patch'
$vuRoundingPatch           = Join-Path $RepoRoot 'patches\ps2recomp-vu-rounding.patch'
$vu1RangeInvalPatch        = Join-Path $RepoRoot 'patches\ps2recomp-vu1-range-invalidation.patch'
$eeCatchupPatch            = Join-Path $RepoRoot 'patches\ps2recomp-ee-catchup.patch'
$testNoControllerPatch     = Join-Path $RepoRoot 'patches\ps2recomp-test-no-controller.patch'
$displayLatchPatch         = Join-Path $RepoRoot 'patches\ps2recomp-display-latch.patch'
$cdStopPatch               = Join-Path $RepoRoot 'patches\ps2recomp-cd-stop.patch'
$iopDelayOutsidePatch      = Join-Path $RepoRoot 'patches\ps2recomp-iop-delay-outside.patch'
$mpegEndProgramPatch       = Join-Path $RepoRoot 'patches\ps2recomp-mpeg-end-program.patch'
$eeFastpathPatch           = Join-Path $RepoRoot 'patches\ps2recomp-ee-fastpath.patch'
$gsPresentPriorityPatch    = Join-Path $RepoRoot 'patches\ps2recomp-gs-present-priority.patch'
$gsEglLinuxPatch           = Join-Path $RepoRoot 'patches\ps2recomp-gs-egl-linux.patch'
$vu1NativeCapturePatch     = Join-Path $RepoRoot 'patches\ps2recomp-vu1-native-capture.patch'
$gsZAsColorPatch           = Join-Path $RepoRoot 'patches\ps2recomp-gs-z-as-color.patch'
$gsGroupedVolumesPatch     = Join-Path $RepoRoot 'patches\ps2recomp-gs-grouped-volumes.patch'
$fpuBarreraPatch           = Join-Path $RepoRoot 'patches\ps2recomp-fpu-barrera.patch'
$ee120hzPatch              = Join-Path $RepoRoot 'patches\ps2recomp-ee-120hz.patch'
$gsFramesInFlightPatch     = Join-Path $RepoRoot 'patches\ps2recomp-gs-frames-in-flight.patch'
$vu1BranchlessClipPatch    = Join-Path $RepoRoot 'patches\ps2recomp-vu1-branchless-clip.patch'
$vu1MaddSaturatedPatch     = Join-Path $RepoRoot 'patches\ps2recomp-vu1-madd-saturated.patch'
$vu0Vf0Patch               = Join-Path $RepoRoot 'patches\ps2recomp-vu0-vf0.patch'
$vu0Vi0Patch               = Join-Path $RepoRoot 'patches\ps2recomp-vu0-vi0.patch'
$vu1nHeadsPatch            = Join-Path $RepoRoot 'patches\ps2recomp-vu1n-heads.patch'

$overrides = Join-Path $RepoRoot 'src\okami_overrides.cpp'

$git = 'git'
if (-not (Get-Command git -ErrorAction SilentlyContinue)) { $git = Join-Path $env:ProgramFiles 'Git\cmd\git.exe' }

# Localizacao automatica do Ninja no Visual Studio caso nao esteja no PATH
if (-not (Get-Command ninja -ErrorAction SilentlyContinue)) {
    $vsWhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    if (Test-Path -LiteralPath $vsWhere) {
        $vsInst = & $vsWhere -latest -products * -property installationPath
        if ($vsInst) {
            $candNinja = Join-Path $vsInst 'Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja'
            if (Test-Path -LiteralPath (Join-Path $candNinja 'ninja.exe')) {
                $env:PATH = "$candNinja;$env:PATH"
            }
        }
    }
}

function Run([string]$exe, [string[]]$a) {
    Write-Host ">> $exe $($a -join ' ')"
    & $exe @a
    if ($LASTEXITCODE -ne 0) { throw "Falha na execucao ($LASTEXITCODE): $exe" }
}
function Etapa([string]$t) { Write-Host ''; Write-Host "==== [$(Get-Date -Format HH:mm:ss)] $t ====" }

Etapa 'Verificando ferramentas do ambiente'
Write-Host "ELF:     $elf"
Write-Host "Work:    $work"
Run $git @('--version'); Run 'cmake' @('--version'); Run 'ninja' @('--version')

if (-not (Test-Path -LiteralPath (Join-Path $rec '.git'))) {
    Etapa 'Clonando PS2Recomp'
    Run $git @('clone', $PS2RecompUrl, $rec)
}
Push-Location $rec
Run $git @('fetch', 'origin', $PS2RecompCommit)
Run $git @('checkout', '-f', $PS2RecompCommit)
Run $git @('submodule', 'update', '--init', '--recursive')

# Limpar arquivos criados anteriormente por patches para permitir aplicacao limpa
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

Etapa 'Aplicando pilha de patches do runtime nativo'
$patches = @(
    $waffleRuntimePatch, $waffleTestsPatch, $vu0Vf0Patch, $vu0Vi0Patch, $vu1nHeadsPatch,
    $waffleGccPatch, $vu1nLeakPatch, $vif1UnpackRapidoPatch, $dmaBuffersPatch, $padRumbleScanPatch,
    $vblankNtscPatch, $gsWorkerTracePatch, $fpsOverlayPatch, $fpsFramesPatch, $presentOrderPatch,
    $stageBatchesPatch, $fullscreenPatch, $iopAcumuladoPatch, $finePacingPatch, $halfCyclesPatch,
    $vu1Slot64Patch, $vuRoundingPatch, $vu1RangeInvalPatch, $eeCatchupPatch,
    $testNoControllerPatch, $displayLatchPatch, $cdStopPatch, $iopDelayOutsidePatch, $mpegEndProgramPatch,
    $eeFastpathPatch, $gsPresentPriorityPatch, $gsEglLinuxPatch, $vu1NativeCapturePatch, $gsZAsColorPatch,
    $gsGroupedVolumesPatch, $fpuBarreraPatch, $ee120hzPatch, $gsFramesInFlightPatch,
    $vu1BranchlessClipPatch, $vu1MaddSaturatedPatch
)
foreach ($p in $patches) {
    if (Test-Path -LiteralPath $p) {
        Run $git @('apply', '--ignore-whitespace', '--verbose', $p)
    }
}
Pop-Location

# Inclusao de headers e flags do runtime
$cm = Join-Path $rec 'ps2xRuntime\CMakeLists.txt'
if (-not (Select-String -LiteralPath $cm -Pattern 'Okami include' -Quiet)) {
    Add-Content -LiteralPath $cm "`n# Okami include`ntarget_include_directories(ps2EntryRunner PRIVATE `${CMAKE_CURRENT_SOURCE_DIR}/src/runner)"
}

$rm = Join-Path $rec 'ps2xRuntime\cmake\ReleaseMode.cmake'
$t = Get-Content -LiteralPath $rm -Raw
$t2 = $t -replace '(?m)^\s*/GL\b.*\r?\n', '' -replace '(?m)^\s*/LTCG\b.*\r?\n', '' `
         -replace 'set_property\(TARGET \$\{TargetName\} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE\)', '# IPO desativado (Okami-Port)'
if ($t2 -ne $t) { Set-Content -LiteralPath $rm -Value $t2 -NoNewline }

# Geracao de IOP nativo a partir de modulos dumpados (se disponivel)
if ($env:OKAMI_IOP_MODULOS -and (Test-Path -LiteralPath (Join-Path $env:OKAMI_IOP_MODULOS 'modules.txt'))) {
    Etapa 'Gerando IOP nativo'
    Run 'python' @('-I', (Join-Path $RepoRoot 'tools\iop\iopn_gen.py'), $env:OKAMI_IOP_MODULOS, (Join-Path $rec 'ps2xIOP\src\native'))
}

Etapa 'Configurando CMake'
$logsEnabled = if ($Trazas) { 'ON' } else { 'OFF' }
Run 'cmake' @('-S', $rec, '-B', $bld, '-G', 'Ninja', '-DCMAKE_BUILD_TYPE=Release', '-DCMAKE_INTERPROCEDURAL_OPTIMIZATION=OFF',
              "-DPS2X_ENABLE_RUNTIME_LOGS=$logsEnabled", "-DPS2X_ENABLE_AGRESSIVE_LOGS=$logsEnabled", "-DPS2X_ENABLE_IOP_RPC_TRACE=$logsEnabled",
              '-DPS2X_ENABLE_RUNNER_UNITY_BUILD=ON', '-DPS2X_ENABLE_RUNNER_PCH=ON')

Etapa 'Compilando o recompilador ps2_recomp'
Run 'cmake' @('--build', $bld, '--target', 'ps2_recomp')

Etapa 'Gerando C++ a partir de SLUS_211.15'
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
Write-Host ("Arquivos C++ gerados: {0}" -f (Get-ChildItem $gen).Count)

Etapa 'Copiando codigo gerado para o runner do runtime'
$runner = Join-Path $rec 'ps2xRuntime\src\runner'
Get-ChildItem $runner -File | Remove-Item -Force
Get-ChildItem -LiteralPath $gen -File | Copy-Item -Destination $runner
Copy-Item -LiteralPath $overrides -Destination (Join-Path $runner 'okami_overrides.cpp')
Get-ChildItem -LiteralPath (Join-Path $RepoRoot 'src') -Filter '*.h' -File | Copy-Item -Destination $runner

# Limpeza de objetos intermediarios para compilacao deterministica
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

Etapa 'Compilando ps2EntryRunner (executavel nativo)'
Run 'cmake' @('--build', $bld, '--target', 'ps2EntryRunner')

$exe = Get-ChildItem $bld -Recurse -Filter 'ps2EntryRunner.exe' | Select-Object -First 1
Etapa "Compilacao finalizada com sucesso: $($exe.FullName)"
