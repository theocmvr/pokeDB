#ifndef POKE_GUI
#define POKE_GUI
#include "pokeDB.hpp"
#include <string.h>
#include <string> 
#include <vector>

class PokeGUI { 
    private:
        PokeDB& db;
        char searchBuffer[128];
        int selectedNumber = -1;
        bool closeRequest = false;
        void renderMainWindow();
        void renderDetailWindow();
    public:
        explicit PokeGUI(PokeDB& db);
        void renderUI();
        bool closeApp() const;
};

#endif