"`n`nWelcome to the A3A Extender first time setup!`n=================================================`n`n"
$exstensionName = Read-Host "Enter your exstension name"

#find witch folder is the modfolder
$folders = Get-Childitem "$PSScriptRoot\..\.." -Directory
foreach ($folder in $folders) {
    $folderName = $folder.Name
    $subFolders = Get-Childitem "$PSScriptRoot\..\..\$folderName" -Directory
    $subFolders = $subFolders | Where-Object { $_.Name -eq "addons" }
    if (($subFolders | Measure-Object).Count -gt 0) {
        $addonName = $folderName
        break
    }
}

"`nRenaming mod folder"
Set-Location "$PSScriptRoot\..\.."
Rename-Item $addonName $exstensionName

"`nPreping mod for building"
Set-Location "$PSScriptRoot\..\..\$exstensionName"

"`nCreate mod_name.hpp in core\includes"
$modNameFile = "addons\core\Includes\mod_name.hpp"
if (Test-Path -Path $modNameFile -PathType Leaf) {
    Remove-Item $modNameFile
}

New-Item $modNameFile
Set-Content $modNameFile "#define MODFOLDER $exstensionName
#ifndef PREFIX
    #define PREFIX $exstensionName
#endif"

#create $PBOPREFIX$ files
forEach ($addon in (Get-Childitem ".\addons" -Directory)) {
    $addonName = $addon.Name

    # x\A3AE\addons\core
    "Creating `$PBOPREFIX$ for $addonName"
    $file = ".\addons\$addonName\`$PBOPREFIX$"
    if (!(Test-Path -Path $file -PathType Leaf)) {
        New-Item $file
    }
    Set-Content $file -NoNewline "x\$exstensionName\addons\$addonName"



    # #define COMPONENT maps
    # #include "\x\A3AE\addons\core\Includes\script_mod.hpp"
    "Createing script_component for $addonName"
    $file = ".\addons\$addonName\script_component.hpp"
    if ($addonName -eq "core") { continue } #core has unique script_component
    if (!(Test-Path -Path $file -PathType Leaf)) {
        New-Item $file
    }
    Set-Content $file "#define COMPONENT $addonName
#include `"\x\$exstensionName\addons\core\Includes\script_mod.hpp`""
}

"`n`nMod preped for building`n=================================================`n"
