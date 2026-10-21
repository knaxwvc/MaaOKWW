param([switch]$Test,[switch]$Rebuild)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$objects=Join-Path $root '.cache/official-objects'
New-Item -ItemType Directory -Path $objects -Force|Out-Null
$sources=@(Get-ChildItem -LiteralPath (Join-Path $root 'src/official/generated') -Filter '*.cpp'|ForEach-Object {$_.FullName})
$sources+=Join-Path $root 'src/official/OfficialCharacter.cpp'
$sources+=Join-Path $root 'src/official/OfficialTask.cpp'
$sources+=Join-Path $root $(if($Test){'src/tests/official_roles_test.cpp'}else{'src/main.cpp'})
$nativeDependencyCache=@{}
function Get-NativeDependencyTime([string]$Path,[Collections.Generic.HashSet[string]]$Stack) {
    $nativePath=[IO.Path]::GetFullPath($Path)
    if($Stack.Contains($nativePath)){return [DateTime]::MinValue}
    if($nativeDependencyCache.ContainsKey($nativePath)){return $nativeDependencyCache[$nativePath]}
    [void]$Stack.Add($nativePath)
    $nativeTime=(Get-Item -LiteralPath $nativePath).LastWriteTimeUtc
    $nativeText=[IO.File]::ReadAllText($nativePath)
    foreach($nativeInclude in [regex]::Matches($nativeText,'(?m)^\s*#include\s*"([^"]+)"')){
        foreach($nativeFolder in @([IO.Path]::GetDirectoryName($nativePath),(Join-Path $root 'src'),(Join-Path $root 'sdk/include'))){
            $nativeCandidate=Join-Path $nativeFolder $nativeInclude.Groups[1].Value
            if(Test-Path -LiteralPath $nativeCandidate -PathType Leaf){
                $nativeIncludedTime=Get-NativeDependencyTime $nativeCandidate $Stack
                if($nativeIncludedTime -gt $nativeTime){$nativeTime=$nativeIncludedTime}
                break
            }
        }
    }
    [void]$Stack.Remove($nativePath)
    $nativeDependencyCache[$nativePath]=$nativeTime
    return $nativeTime
}
$compile=@($sources|Where-Object {
    $object=Join-Path $objects ([IO.Path]::GetFileNameWithoutExtension($_)+'.obj')
    $dependencyTime=Get-NativeDependencyTime $_ (New-Object 'Collections.Generic.HashSet[string]')
    $Rebuild -or -not(Test-Path -LiteralPath $object) -or (Get-Item -LiteralPath $object).LastWriteTimeUtc -lt $dependencyTime
})
$lines=@('/nologo','/utf-8','/O2','/EHsc','/std:c++17','/MP4','/c',('/I"'+(Join-Path $root 'sdk/include')+'"'),('/Fo"'+$objects+'\\"'))+@($compile|ForEach-Object {'"'+$_+'"'})
$response=Join-Path $root '.cache/official-compile.rsp'
[IO.File]::WriteAllLines($response,$lines,(New-Object Text.UTF8Encoding($false)))
$commands=Join-Path $root '.cache/build-official.cmd'
$target=Join-Path $root $(if($Test){'.cache/official-roles-check.exe'}else{'MaaOKWWNative.exe'})
$links=@('/nologo',('/OUT:"'+$target+'"'),'user32.lib')+@($sources|ForEach-Object {'"'+(Join-Path $objects ([IO.Path]::GetFileNameWithoutExtension($_)+'.obj'))+'"'})
[IO.File]::WriteAllLines((Join-Path $root '.cache/official-link.rsp'),$links,(New-Object Text.UTF8Encoding($false)))
$vcvars=Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat'
if (-not (Test-Path -LiteralPath $vcvars)) {
    $vswhere=Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
    $installation=& $vswhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    if (-not $installation) { throw 'Visual Studio C++ tools were not found.' }
    $vcvars=Join-Path $installation 'VC\Auxiliary\Build\vcvars64.bat'
}
$script=@('@echo off',('call "'+$vcvars+'" >nul || exit /b 1'))
if($compile.Count){$script+=('cl @"'+$response+'" || exit /b 1')}
$script+=('link @"'+(Join-Path $root '.cache/official-link.rsp')+'" || exit /b 1')
if($Test){$script+='"'+$target+'"'}
[IO.File]::WriteAllLines($commands,$script,[Text.Encoding]::ASCII)
& cmd.exe /d /c $commands
exit $LASTEXITCODE
