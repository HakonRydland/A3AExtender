# Antistasi Extender Example
This is an example of how you could extend or overwrite antistasi with new maps, templates

# How to get started
- under `Tools\Builder` run the PowerShell script called `firstTimeSetup`
  This will rename and prepare your mod for being built
- Run the `buildAddons` and move the output from the build folder in the top folder to your ArmA 3 game directory.
- Start the launcher and load the mods: `Antistasi the Mod` and, `your exstension mod`
- start the game and confirm that the new template and/or map is loaded
- start adding the templates/maps/functionality that you want


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

## Functionality
- Antistasi now have events that you can listen to and exstend exsisting functionality.
  A list of all events and their parametes can be found in the in game config under: `A3A >> Events`
- In addition you can overwrite any of Antistasi functions to add change or remove functionality, this includes full systems (be aware that this is more complex and can break on updates)
  To do so simply add a function to the `A3A` class of `CfgFunctions.hpp` under the addon functions (you can also replicate the config.cpp to allow this in any other addon)

# Releasing your exstension
Now that you have added the content/functionality you wanted its time to release the exstension.

You should first make sure that any example content not being used is removed, you can do so either carefully by removing lines from the configs, or by removing a addon folder compleatly
  * **Note that you can not remove the `core` addon**

Next update the mod.cpp and meta.cpp files to contain the correct information for you. (for steam release you can delete the meta.cpp from the buid folder afterwards)

Now simply run the `Build` script in the root folder to build it and use the arma tools for signing and publishing the exstension
*(note: it will not sign it for you, this needs to be done manually before publishing with `Arma 3 Tools` -> `DSUtils` & `Publisher`)*.
You can also distribute it in other ways other than the steam workshop simply by sending the build output to the users
