//config needs binary true/false
#define true 1
#define false 0
class NavGrid { //overwrite global navgrids of antistasi
    #include "Antistasi_Altis.Altis\navGrid.hpp"
};
#undef true
#undef false
