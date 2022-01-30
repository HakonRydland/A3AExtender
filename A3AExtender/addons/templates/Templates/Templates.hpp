class Templates
{
    class Vanilla
    {
        priorityOcc = 1; //highest is favored when auto picking
        priorityInv = 1; //highest is favored when auto picking
        priorityReb = 1; //highest is favored when auto picking
        priorityCiv = 1; //highest is favored when auto picking

        requiredAddons[] = {}; //the cfgPatches class of the mod these templates are depending on
        path = QPATHTOFOLDER(Templates\Vanilla); //the path to the template folder

        //Type class: AI, Reb, Civ
        class AI
        {
            //optional file overwrite set the `file` attribute here, whitout file extension, overwrites path aswell (ignored in this scope when factions calsses are defined)
            // note if `file` is set it becomes the following: {file}.sqf

            //for multiple templates per modset add the classes of faction names in the type class
            class CSAT
            { //template file name would follow: {path}\{Modset}_{Type}_{Faction}.sqf
                //optional file overwrite set the `file` attribute here, whitout file extension
                // note if `file` is set it becomes the following: {file}.sqf

                //if multiple cammo variations exist add the worldname (all lower case) to camo list like so
                class camo
                { //template file name would follow: {path}\{Modset}_{Type}_{Faction}_{camo}.sqf
                // note if `file` is set it becomes the following: {file}_{camo}.sqf
                    tanoa = "Tropical";
                    enoch = "Enoch";
                    Default = "Arid"; //default is the fallback if the worldname is not in this class
                };
            };

            class LDF
            {
                class camo
                {
                    Default = "Enoch";
                };
            };

            class NATO
            {
                class camo
                {
                    tanoa = "Tropical";
                    cam_lao_nam = "Temperate";
                    enoch = "Temperate";
                    chernarus_summer = "Temperate";
                    vt7 = "Temperate";
                    tembelan = "Temperate";
                    Default = "Arid";
                };
            };

            class AAF
            {
                class camo
                {
                    Default = "Arid";
                };
            };

        };

        class Reb
        {
            class FIA
            {
                class camo
                {
                    enoch = "Enoch";
                    Default = "Arid";
                };
            };

            class SDK
            {
                class camo
                {
                    Default = "Tanoa";
                };
            };
        };

        class Civ {}; //leave empty for a single template for this modset, file name would follow: {path}\{Modset}_{Type}.sqf

        //default template selection, classes within are worldname with side properties with faction name assigned to it (or empty when only one available)
        class worldDefaults
        {
            class Default
            {
                Occ = "NATO";
                Inv = "CSAT";
                Reb = "FIA";
                //Civ left out because we use only one available as there are not multiple civ factions
            };

            class altis: Default
            {
                Occ = "AAF";
            };

            class tanoa: Default
            {
                Reb = "SDK";
            };
        };

        //temporary soulution to load logistics nodes (pending logistics data convertion to class based) add full filename
        Nodes[] = {"Vanilla_Logistics_Nodes.sqf"};
    };
};
