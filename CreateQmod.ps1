if (-not $env:qmodName) 
{
    $env:qmodName = "GorillaUtils"
}

$zip = $env:qmodName + ".zip"
$qmod = $env:qmodName + ".qmod"

$mod = "./mod.json"
$modJson = Get-Content $mod -Raw | ConvertFrom-Json

$allLibs = Get-ChildItem ./libs/arm64-v8a/*.so | Select -Expand Name
$libs = @()

$cover = "./" + $modJson.coverImage

$fileList = @($cover, $mod)

foreach ($lib in $allLibs) 
{
    # ignore modloader

    if ($lib.Contains("modloader") -or $lib.Contains("codegen") )
    {
        continue
    }
    
    $path = "./libs/arm64-v8a/" + $lib
    $fileList += ,$path
    $libs += ,$lib
}

# update version from qpm json
$qpm = "./qpm.json"
$qpmJson = Get-Content $qpm | ConvertFrom-Json 
$modJson.version = $qpmJson.info.version

$modJson.libraryFiles = $libs
$modText = $modJson | ConvertTo-Json -Depth 50 -EscapeHandling EscapeNonAscii

Set-Content $mod $modText

# if the qmod exists, rename it to zip to update it, we'll rename it back later
if (Test-Path $qmod) 
{
    move-item -Force $qmod $zip
}

Compress-Archive -Path $fileList -DestinationPath $zip -Update

& move-item -Force $zip $qmod