# Antistasi Extender Example
This is an example of how you could extend or overwrite antistasi with new features, maps, templates.

# Important things to modify
- Under addons/core/Includes you need to adapt `script_mod.hpp` to have a unique `PREFIX` and `MODFOLDER`.
- Under all addons **EXCEPT** core you need to update script_component.hpp to have updateded path to match the `MODFOLDER` define in `script_mod.hpp`.
```sqf
#include "\x\${MODFOLDER}\addons\core\Includes\script_mod.hpp"
```
- Next you need to update all `$PBOPREFIX$` with the new path `x\${MODFOLDER}\addons\${COMPONENT}`.

  All *${Something}* should be replaced with their corresponding elements.

*Example: If MODFOLDER is `A3AE` you would replace all ${MODFOLDER} with A3AE*.

# Example additions
## Maps
Antistasi now supports 3rd party map porting.

There are two examples added for working with maps. Adding a new map and overwriting/applying additions for an existing map.

  In this examples there are also demonstrations of mission specific overwrites of `mapInfo` and `navGrid` data as well as global overwrite/addition.

  You will find all the information regarding this under `A3AE/addons/maps`.

  Take care to study all the files in the addon to not miss crucial porting steps.

## Templates
Antistasi now supports 3rd party template additions/overwrites.

  To add new templates or overwrite existing ones follow the demonstration given in `A3AE/addons/templates/Templates/Templates.hpp`.

  Note that while you can add addon vehicle templates to Antistasi at this time, it should be noted that it is still a limited system and you shouldn't expect full functionality from them atm.

  Again it's important to read through all the files in the `templates` addon to not miss important steps.

# Building the mod
To build the mod you first need to navigate to `Tools\Builder` and edit `buildAddons.ps1`.

  On line 6 replace `$addonName = "A3AE"` with `$addonName = "${your addons main folder name}"`,
so if you name your extension A3A-AltisRemade then the line would be `$addonName = "A3A-AltisRemade"`,
save the file and close it.

  Now all you need to do is run the script and it will build the mod for you
*(note: it will not sign it for you, this needs to be done manually before publishing with `Arma 3 Tools` -> `DSUtils` & `Publisher`)*.
