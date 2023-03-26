Invoke-Expression "& '$PSScriptRoot\Tools\Builder\firstTimeSetup.ps1'"
New-Item "$PSScriptRoot\Build.ps1"
Set-Content "$PSScriptRoot\Build.ps1" "Invoke-Expression `"& '`$PSScriptRoot\Tools\Builder\buildAddons.ps1'`""
Remove-Item $PSCommandPath -Force
