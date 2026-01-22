#ifndef POKEMON_H
#define POKEMON_H
#include <vector>
#include "pokemontype.hpp"
#include <string>
#include <vector>
class Pokemon { 
    private:
        std::string name;
        std::vector<PokemonType> types;
        int pokedex_number;
    public:
        Pokemon(std::string name, std::vector<PokemonType> type, int pokedex_number);
        ~Pokemon() = default;
        const std::string& getname() const;
        std::vector<PokemonType> gettype() const;
        int getnumber() const;
        void print() const;

    bool operator==(const Pokemon& other) const;
    bool operator!=(const Pokemon& other) const;

};

#endif