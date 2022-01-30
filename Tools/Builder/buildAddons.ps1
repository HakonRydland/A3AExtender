param (
    [string]$modFileName = "mod.cpp",
    [string]$metaFileName = "meta.cpp"
)

$addonName = "A3AExtender"

"Meta file name: $metaFileName`n`n"
Push-Location

Set-Location "$PSScriptRoot\..\..\$addonName"

"Setup temporary directories..."
if (Test-Path "..\build") {
    Remove-Item -Path "..\build" -Recurse -Force
}
New-Item -Path "..\build" -ItemType Directory -Force > $null
New-Item -Path "..\build\$addonName" -ItemType Directory -Force > $null
New-Item -Path "..\build\$addonName\addons" -ItemType Directory -Force > $null
New-Item -Path "..\build\$addonName\Keys" -ItemType Directory -Force > $null

$buildLocation = "$PSScriptRoot\..\..\build"
$addonLocation = "." # We are here already
$addonOutLocation = "$PSScriptRoot\..\..\build\$addonName"
$addonsOutLocation = "$addonOutLocation\addons"

"`nBuild addons..."
$modules = Get-Childitem "$addonLocation\addons" -Directory
foreach ($module in $modules) {
    $pboName = "$($module.Name).pbo"
    #"Building $pboName...  $addonLocation\addons\$($module.Name)   -> $addonsOutLocation\$pboName"
    "Building $pboName ..."
    .$PSScriptRoot\hemtt armake build --force -i include  $module.fullName "$addonsOutLocation\$pboName" -w unquoted-string -w redefinition-wo-undef -w excessive-concatenation
}

"`nCopy mod.cpp..."
Copy-Item "$modFileName" $addonOutLocation
Push-Location
Set-Location $addonOutLocation
Rename-Item $modFileName "mod.cpp"
Pop-Location

"`nCopy meta.cpp..."
Copy-Item "meta\$metaFileName" $addonOutLocation
Push-Location
Set-Location $addonOutLocation
Rename-Item $metaFileName "meta.cpp"
Pop-Location

Pop-Location

Pop-Location

Pop-Location