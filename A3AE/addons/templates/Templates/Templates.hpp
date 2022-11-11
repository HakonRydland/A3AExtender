class Templates {
    class Vanilla_Base; //import Vanilla_Base from A3A to use with defining a new vanilla template

    class Vanilla_AAF { // overwrite existing template
        basepath = QPATHTOFOLDER(Templates\Vanilla);
        file = "Vanilla_AI_AAF";
    };

    class Vanilla_CSAT2 : Vanilla_Base
    {
        basepath = QPATHTOFOLDER(Templates\Vanilla); //the path to the folder the template is located in, this translates to "\x\A3AE\addons\templates\Templates\Vanilla"
        side = "Inv"; //the side the faction defaults to, one of the following: Inv, Occ, Reb, Civ
        flagTexture = "A3\Data_F\Flags\Flag_CSAT_CO.paa"; //path to an icon to be displayed in the selector
        name = "A3 CSAT 2"; //the name shown in the selector
        file = "Vanilla_AI_CSAT2"; //the template file name
        climate[] = {"arid", "arctic"}; //climate that the template is meant for
    };
};
