#include"pokemon.hpp"

Pokemon::Pokemon(std::string name, std::string type, int pokedex_number) 
    : name(name), type(type), pokedex_number(pokedex_number) {}

Pokemon::Pokemon()
    : name(""), type(""), pokedex_number(0) {}

