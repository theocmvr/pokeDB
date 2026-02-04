#include <cstring>
#include <string> 
#include <vector>
#include <cctype>

#include "imgui.h"
#include "pokeGUI.hpp"

PokeGUI::PokeGUI(PokeDB& db)
    : db(db), searchBuffer("") {}

void PokeGUI::renderUI() {
    ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());
    if (currentScreen == BaseScreen::Menu) {
        renderMainWindow();
        return;
    }
    renderListWindow();
    if (showDetail) {
        renderDetailWindow();
    }
}

void PokeGUI::renderMainWindow() {

    ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
    
    ImGui::Begin("PokeDB", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);

    float windowL = ImGui::GetWindowSize().x;
    float windowA = ImGui::GetWindowSize().y;

    const char* title = "PokeDB";
    float textL = ImGui::CalcTextSize(title).x;
    float textA = ImGui::CalcTextSize(title).y;
    ImGui::SetCursorPosX((windowL - textL) * 0.5f);
    ImGui::SetCursorPosY((windowA - textA) * 0.45f);
    ImGui::Text("%s", title);
    ImGui::Separator();

    const char* subtitle = "Pokemon Database for dummies";
    textL = ImGui::CalcTextSize(subtitle).x;
    textA = ImGui::CalcTextSize(subtitle).y;
    ImGui::SetCursorPosX((windowL - textL) * 0.5f);
    ImGui::SetCursorPosY((windowA - textA) * 0.5f);
    ImGui::Text("%s", subtitle);

    ImGui::Spacing();
    ImGui::Spacing();

    float buttonL = 120.0f;

    ImGui::SetCursorPosX((windowL - buttonL) * 0.5f);
    
    if (ImGui::Button("Enter", ImVec2(buttonL, 0))) {
        currentScreen = BaseScreen::Database;
    }

    ImGui::Spacing();

    ImGui::SetCursorPosX((windowL - buttonL) * 0.5f);
    if (ImGui::Button("Exit", ImVec2(buttonL, 0))) {
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
    
    bool open = true;
    ImGui::Begin("Pokemon Details", &open);

    ImGui::Text("Name: %s", p->getname().c_str());
    ImGui::Text("Number: %d", p->getnumber());

    ImGui::Text("Types:");
    for (const auto& type : p->gettype()) {
        ImGui::BulletText("%s", typetostring(type).c_str());
    }

    ImGui::End();
    
    if (!open) {
        showDetail = false;
    }
}

void PokeGUI::renderListWindow() {
    bool open = true;
    ImGui::Begin("Database", &open);

    ImGui::InputText("Search", searchBuffer, sizeof(searchBuffer));

    ImGui::Separator();

    const auto& pokemons = db.listall();

    for (const auto& p : pokemons) {

        if (searchBuffer[0] != '\0' && LowerString(p.getname()).find(LowerString(searchBuffer)) == std::string::npos) {
            continue;
        }

        std::string label = std::to_string(p.getnumber()) + " - " + p.getname();

        bool isSelected = (p.getnumber() == selectedNumber);

        if (ImGui::Selectable(label.c_str(), isSelected)) {
           selectedNumber = p.getnumber();
           showDetail = true;
        }
    }

    if (!open) {
        currentScreen = BaseScreen::Menu;
        showDetail = false;
    }

    ImGui::End();
}

bool PokeGUI::closeApp() const {
    return closeRequest;
}

std::string PokeGUI::LowerString(std::string s) {
    for (char& c : s) {
        c = std::tolower((unsigned char)c);
    }
    return s;
}