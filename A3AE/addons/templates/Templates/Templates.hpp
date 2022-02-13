class Templates
{
    class Vanilla
    {
        class AI
        {
            class CSAT2 { // completely new template
                file = QPATHTOFOLDER(Templates\Vanilla\Vanilla_AI_CSAT2);
            };

            class AAF { // overwrite existing template
                file = QPATHTOFOLDER(Templates\Vanilla\Vanilla_AI_AAF);
            };
        };

        class worldDefaults
        {
            class altis
            {
                Inv = "CSAT2";
            };
        };
    };
};
