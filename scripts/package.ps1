param(
    [string]$Version = '0.3.0',
    [string]$BinariesPath,
    [string]$OutputDirectory,
    [switch]$SkipArchive
)
$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
if (-not $BinariesPath) { $BinariesPath = $root }
if (-not $OutputDirectory) { $OutputDirectory = Join-Path $root 'dist' }
if ($Version -notmatch '^[0-9A-Za-z._-]+$') { throw 'Invalid version' }
$BinariesPath = [IO.Path]::GetFullPath($BinariesPath)
$OutputDirectory = [IO.Path]::GetFullPath($OutputDirectory)
$name = "MaaOKWW-v$Version-win-x64"
$package = Join-Path $OutputDirectory $name
[IO.Directory]::CreateDirectory($package) | Out-Null

function Copy-PackageTree([string]$Source, [string]$Relative) {
    foreach ($file in Get-ChildItem -LiteralPath $Source -File -Recurse) {
        if ($file.Extension -in @('.obj','.pdb','.exe') -and $Relative -ne 'bin') { continue }
        $path = $file.FullName.Substring($Source.TrimEnd('\').Length + 1)
        $target = Join-Path $package (Join-Path $Relative $path)
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
        Copy-Item -LiteralPath $file.FullName -Destination $target -Force
    }
}
foreach ($exe in @('MaaOKWWNative.exe','MaaOKWWGui.exe')) {
    Copy-Item -LiteralPath (Join-Path $BinariesPath $exe) -Destination (Join-Path $package $exe) -Force
}
Copy-PackageTree (Join-Path $BinariesPath 'bin') 'bin'
foreach ($folder in @('src','sdk','licenses','resource','source_reference','docs','scripts','evidence')) {
    Copy-PackageTree (Join-Path $root $folder) $folder
}
foreach ($file in @('README.md','LICENSE','THIRD_PARTY_NOTICES.md','SOURCES.md','SOURCES.json','CHANGELOG.md','CONTRIBUTING.md','build.cmd','config.example.ini','啟動戰鬥.bat')) {
    Copy-Item -LiteralPath (Join-Path $root $file) -Destination (Join-Path $package $file) -Force
}
Copy-Item -LiteralPath (Join-Path $root 'config.example.ini') -Destination (Join-Path $package 'config.ini') -Force
$hashes = @{}
foreach ($exe in @('MaaOKWWNative.exe','MaaOKWWGui.exe')) {
    $hashes[$exe] = (Get-FileHash -LiteralPath (Join-Path $package $exe)).Hash.ToLowerInvariant()
}
$sources=Get-Content -LiteralPath (Join-Path $root 'SOURCES.json') -Raw | ConvertFrom-Json
$manifest = [ordered]@{version=$Version;native_build=$sources.version;gui_build=$sources.gui_build;gui_source_sha256=(Get-FileHash -LiteralPath (Join-Path $root 'src/gui.cpp')).Hash.ToLowerInvariant();official_okww_release=$sources.upstream_release;official_okww_ref=$sources.upstream_ref;official_okww_commit=$sources.upstream_commit;framework_version='5.14.0';characters=@($sources.characters).Count;local_characters=@($sources.characters|Where-Object source_kind -eq 'local').Count;github_characters=@($sources.characters|Where-Object source_kind -eq 'github').Count;binary_sha256=$hashes;source_manifest='SOURCES.json';live_combat_verified=$false}
$encoding = New-Object Text.UTF8Encoding($false)
[IO.File]::WriteAllText((Join-Path $package 'RELEASE.json'), ($manifest | ConvertTo-Json -Depth 4), $encoding)
if ($SkipArchive) { Write-Output "Package directory: $package"; exit 0 }
$archive = Join-Path $OutputDirectory ($name + '.zip')
Compress-Archive -Path (Join-Path $package '*') -DestinationPath $archive -CompressionLevel Optimal -Force
$digest = (Get-FileHash -LiteralPath $archive).Hash.ToLowerInvariant()
[IO.File]::WriteAllText(($archive + '.sha256'), ($digest + '  ' + [IO.Path]::GetFileName($archive) + [Environment]::NewLine), $encoding)
Write-Output "Package: $archive"
Write-Output "SHA256: $digest"
