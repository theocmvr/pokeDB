#include <string.h>
#include <string> 
#include <vector>

#include "imgui.h"
#include "pokeGUI.hpp"

PokeGUI::PokeGUI(PokeDB& db)
    : db(db), searchBuffer("") {}

void PokeGUI::renderUI() {
    ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());
    renderMainWindow();
    renderDetailWindow();
}

void PokeGUI::renderMainWindow() {
    ImGui::Begin("PokeDB");

    ImGui::InputText("Search", searchBuffer, sizeof(searchBuffer));

    ImGui::Separator();

    const auto& pokemons = db.listall();

    for (const auto& p : pokemons) {

        if (searchBuffer[0] != '\0' && p.getname().find(searchBuffer) == std::string::npos) {
            continue;
        }

        std::string label = std::to_string(p.getnumber()) + " - " + p.getname();

        bool isSelected = (p.getnumber() == selectedNumber);

        if (ImGui::Selectable(label.c_str(), isSelected)) {
           selectedNumber = p.getnumber();
        }
    }

    if (ImGui::Button("Exit")) {
        closeRequest = true;
    }

    ImGui::End();
}

void PokeGUI::renderDetailWindow() {
    if (selectedNumber < 0) {
        return;
    }
    
    const Pokemon* p = db.searchByNumber(selectedNumber);
    
    if (!p) {
        return;
    }
    
    ImGui::Begin("Pokemon Details");

    ImGui::Text("Name: %s", p->getname().c_str());
    ImGui::Text("Number: %d", p->getnumber());

    ImGui::Text("Types:");
    for (const auto& type : p->gettype()) {
        ImGui::BulletText("%s", typetostring(type).c_str());
    }

    ImGui::End();
}

bool PokeGUI::closeApp() const {
    return closeRequest;
}
