# Antistasi Extender Example
This is an example of how you could extend or overwrite antistasi with new maps, templates

# Requirements
  - Arma 3
  - Arma 3 tools  
    
  Both needs to be run once from steam

# How to get started
- run the `Install.ps1` script and follow the instructions on screen
- Run the `Build.ps1` script this will create a folder in the root folder called build and compile your extension into it.
- Start the launcher and in the launcher to the following:
  1) Under `Mods` -> `...More` select `add watched folder...` then `add custom folder...`
      Navigate to your extensions root folder and select the newly created build folder
      if successfull it will have added that folder in the list of watched folders and a green box would have shown
      stating that a mod has been installed
      
  2) Load `Antistasi - The Mod` and the newly installed `A3 Antistasi Extender example` mods
  3) Start the game and confirm that the new template and/or map is loaded by starting a local host sesion under multiplayer
      and confirming that the new map and overwritten map is there, then start a game of antistasi and confirm that the
      new and overwritten templates are there (these are the example maps and templates provided with the extender)
      
  Assuming everything went well you are now ready to make your own modifications
  Remember to remove unused content and reed thouroughly throug the filles while making any eddits
  As a hint all content is added from the config.cpp files located within each of the addons
  so you can follow that down to the files that govern the different parts like templates and maps etc.


# Example additions
## Maps
Antistasi now supports 3rd party map porting.

There are two examples added for working with maps. Adding a new map and overwriting/applying additions for an existing map.

  In this examples there are also demonstrations of mission specific overwrites of `mapInfo` and `navGrid` data as well as global overwrite/addition.

  You will find all the information regarding this under `your exstension mod/addons/maps`.

  Take care to study all the files in the addon to not miss crucial porting steps.

## Templates
Antistasi now supports 3rd party template additions/overwrites.

  To add new templates or overwrite existing ones follow the demonstration given in `your exstension mod/addons/templates/Templates/Templates.hpp`.

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

Next update the mod.cpp and meta.cpp files to contain the correct information for you. (for steam release you can delete the meta.cpp from the build folder afterwards)

Now simply run the `Build` script in the root folder to build it and use the arma tools for signing and publishing the exstension
*(note: it will not sign it for you, this needs to be done manually before publishing with `Arma 3 Tools` -> `DSUtils` & `Publisher`)*.
You can also distribute it in other ways other than the steam workshop simply by sending the build output to the users
