#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
class Pokemon {
    private:
        std::string name;
        std::string type;
        int pokedex_number;
    public:
        Pokemon(std::string name, std::string type, int pokedex_number);
        Pokemon();
        ~Pokemon() = default;
};
#endif