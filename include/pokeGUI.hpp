#ifndef POKE_GUI
#define POKE_GUI
#include "pokeDB.hpp"
#include <cstring>
#include <string> 
#include <vector>

enum class BaseScreen {
    Menu,
    Database
};
class PokeGUI { 
    private:
        PokeDB& db;
        char searchBuffer[128];
        int selectedNumber = -1;
        bool closeRequest = false;
        void renderMainWindow();
        void renderListWindow();
        void renderDetailWindow();
    public:
        explicit PokeGUI(PokeDB& db);
        void renderUI();
        bool closeApp() const;
        std::string LowerString(std::string s);
        BaseScreen currentScreen = BaseScreen::Menu;
        bool showDetail = false;
};

#endif