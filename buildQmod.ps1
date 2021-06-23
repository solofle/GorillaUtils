# Builds a .zip file for loading with BMBF
$NDKPath = Get-Content $PSScriptRoot/ndkpath.txt

$buildScript = "$NDKPath/build/ndk-build"
if (-not ($PSVersionTable.PSEdition -eq "Core")) {
    $buildScript += ".cmd"
}

& $buildScript NDK_PROJECT_PATH=$PSScriptRoot APP_BUILD_SCRIPT=$PSScriptRoot/Android.mk NDK_APPLICATION_MK=$PSScriptRoot/Application.mk -j 4
Compress-Archive -Path  "./libs/arm64-v8a/libgorilla-utils.so",`
                        "./libs/arm64-v8a/libcustom-types.so",`
                        "./libs/arm64-v8a/libbeatsaber-hook_1_3_5.so",`
                        "./extern/libbeatsaber-hook_1_3_3.so",`
                        "./cover.png",`
                        "./mod.json" -DestinationPath "./GorillaUtils.zip" -Update

& copy-item -Force "./GorillaUtils.zip" "./GorillaUtils.qmod"