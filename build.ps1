$NDKPath = Get-Content $PSScriptRoot/ndkpath.txt

$buildScript = "$NDKPath/build/ndk-build"
if (-not ($PSVersionTable.PSEdition -eq "Core")) {
    $buildScript += ".cmd"
}

$proc = Get-ComputerInfo -Property CsProcessors
$coreCount = $proc.CsProcessors.NumberOfCores

# if on a linux system
if (-not $proc)
{
    $coreCount = & nproc
    
}

if (-not $coreCount)
{
    $coreCount = 4
}

$msg = "Building with " + $coreCount + " Cores!"
echo $msg
& $buildScript NDK_PROJECT_PATH=$PSScriptRoot APP_BUILD_SCRIPT=$PSScriptRoot/Android.mk NDK_APPLICATION_MK=$PSScriptRoot/Application.mk -j $coreCount
