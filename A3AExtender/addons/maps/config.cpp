#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3AE_core"};
        author = AUTHOR;
        authors[] = { AUTHORS };
        authorUrl = "";
        VERSION_CONFIG;
    };
};

class CfgMissions
{
    class MPMissions
    {
        class Antistasi_Altis
        {
            briefingName = $STR_A3AE_maps_Altis_mapname;
            directory = "x\A3AE\addons\maps\Antistasi_Altis.Altis";
        };
    };
};
