class CfgFunctions {
    //be carefull when overwiriting functions as version updates can brake your exstension
    class A3A {
        class Missions {
            class AS_Official {
                file = QPATHTOFOLDER(Missions\fn_as_Official.sqf);
            };
        };
    };

    //your own functions should be keept here
    class ADDON {
        class Events { //these two functions are used to demonstrate use of events
            file = QPATHTOFOLDER(Events);
            class addExampleEventListener { postInit = 1; };
            class AIVehInit {};
        }
    };
};
