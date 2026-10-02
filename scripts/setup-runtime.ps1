param([string]$ArchivePath)
$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$version = '5.14.0'
$expectedHash = '036f827bb59215c20eb304378d391742a7db95da8cc78ca3a88e19321c639d79'
$url = "https://github.com/MaaXYZ/MaaFramework/releases/download/v$version/MAA-win-x86_64-v$version.zip"
$cache = Join-Path $root '.cache'
[IO.Directory]::CreateDirectory($cache) | Out-Null
if (-not $ArchivePath) {
    $ArchivePath = Join-Path $cache "MAA-win-x86_64-v$version.zip"
    if (-not (Test-Path -LiteralPath $ArchivePath)) {
        Invoke-WebRequest -Uri $url -OutFile $ArchivePath
    }
}
$ArchivePath = [IO.Path]::GetFullPath($ArchivePath)
if ((Get-FileHash -LiteralPath $ArchivePath -Algorithm SHA256).Hash.ToLowerInvariant() -ne $expectedHash) {
    throw 'MaaFramework release SHA256 mismatch'
}
$extract = Join-Path $cache "MaaFramework-v$version"
Expand-Archive -LiteralPath $ArchivePath -DestinationPath $extract -Force
$matches = @(Get-ChildItem -LiteralPath $extract -Filter 'MaaFramework.dll' -File -Recurse)
if ($matches.Count -ne 1) { throw 'Expected exactly one MaaFramework.dll in the official archive' }
$bin = Join-Path $root 'bin'
[IO.Directory]::CreateDirectory($bin) | Out-Null
foreach ($dll in Get-ChildItem -LiteralPath $matches[0].DirectoryName -Filter '*.dll' -File) {
    Copy-Item -LiteralPath $dll.FullName -Destination (Join-Path $bin $dll.Name) -Force
}
$notices = Join-Path $root 'licenses/runtime'
[IO.Directory]::CreateDirectory($notices) | Out-Null
foreach ($file in Get-ChildItem -LiteralPath $extract -File -Recurse | Where-Object { $_.Name -match '(?i)license|notice' }) {
    $relative = $file.FullName.Substring($extract.Length + 1)
    $target = Join-Path $notices $relative
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
    Copy-Item -LiteralPath $file.FullName -Destination $target -Force
}
Write-Output "MaaFramework v$version installed; archive SHA256 verified."
