#include "pokemon.hpp"
#include "pokemontype.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

Pokemon::Pokemon(std::string name, std::vector<PokemonType> type, int pokedex_number) 
    : name(name), types(type), pokedex_number(pokedex_number) {

        if (name.empty() and type.empty() and (pokedex_number <= 0  or pokedex_number > 1025)) {
            throw std::invalid_argument("Name is empty , Type is empty and Pokedex number invalid");
        } else if (name.empty() and type.empty()) {
            throw std::invalid_argument("Name is empty and Type is empty");
        } else if ((pokedex_number <= 0 or pokedex_number > 1025) and type.empty()) {
            throw std::invalid_argument("Pokedex number invalid and Type is empty");
        } else if (name.empty()) {
            throw std::invalid_argument("Name is empty");
        } else if (type.empty()) {
            throw std::invalid_argument("Type is empty");
        } else if ((pokedex_number <= 0 or pokedex_number > 1025)) {
            throw std::invalid_argument("Pokedex number invalid");
        }

    }

const std::string& Pokemon::getname() const {
    return this->name;
}

std::vector<PokemonType> Pokemon::gettype() const {
    return this->types;
}

int Pokemon::getnumber() const {
    return this->pokedex_number;
}

void Pokemon::print() const {
    std::cout << "#" << this->pokedex_number << " - " << this->name;
    std::cout << " (";
    for (int i(0); i < (int)this->types.size(); i++) {
        std::cout << typetostring(this->types[i]);
        if (i != (int)this->types.size()-1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;
}

bool Pokemon::operator==(const Pokemon& other) const {
    return (name == other.name && types == other.types && pokedex_number == other.pokedex_number);
}
bool Pokemon::operator!=(const Pokemon& other) const {
    return !(*this == other);
}
