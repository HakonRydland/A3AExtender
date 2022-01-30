# Antistasi Extender Example
This is an example of how you could extend or overwrite antistasi with new features, maps, templates

# Building the mod
To build the mod you first need to navigate to Tools\Builder and eddit buildAddons.ps1
on line 6 replace `$addonName = "A3AExtender"` with `$addonName = "${your addons main folder name}"`
so if you name your extension A3A-AltisRemade then the line would be `$addonName = "A3A-AltisRemade"`
save the file and close it. Now all you need to do is run the script and it will build the mod for you
(note: it will not sign it for you, this needs to be done manually before publishing with Arma 3 Tools -> DSUtils & Publisher)
