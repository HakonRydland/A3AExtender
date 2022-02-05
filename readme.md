# Antistasi Extender Example
This is an example of how you could extend or overwrite antistasi with new maps, templates

# Important things to modify
- Under addons/core/Includes you need to adapt `script_mod.hpp` to have a unique `PREFIX` and `MODFOLDER`  
- under all addons **EXCEPT** core you need to update script_component.hpp to have updateded path to match the `MODFOLDER` define in `script_mod.hpp`
```sqf
#include "\x\${MODFOLDER}\addons\core\Includes\script_mod.hpp"
```
- next you need to update all `$PBOPREFIX$` with the new path `x\${MODFOLDER}\addons\${COMPONENT}`  
*all ${Something} should be replaced with its corresponding element*  
  
*example: if MODFOLDER is `A3AE` you would replace all ${MODFOLDER} with A3AE*

# Building the mod
To build the mod you first need to navigate to Tools\Builder and edit buildAddons.ps1
on line 6 replace `$addonName = "A3AE"` with `$addonName = "${your addons main folder name}"`  
so if you name your extension A3A-AltisRemade then the line would be `$addonName = "A3A-AltisRemade"`  
save the file and close it.  
Now all you need to do is run the script and it will build the mod for you  
*(note: it will not sign it for you, this needs to be done manually before publishing with Arma 3 Tools -> DSUtils & Publisher)*
