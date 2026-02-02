#ifndef POKE_DB
#define POKE_DB
#include "pokemon.hpp"
#include "pokemontype.hpp"
#include <vector>
#include <string>

class PokeDB {
    private:
        std::vector<Pokemon> pokedb;
    public:
        PokeDB() = default;
        PokeDB(std::string filename);
        void add(const Pokemon& newPokemon);
        const std::vector<Pokemon>&  listall() const;
        const Pokemon& searchByName(const std::string& target) const;
        const Pokemon* searchByNumber(int pokedexNumber) const;
        bool containsNumber(int pokedexNumber) const;
        int sizedb();
};

#endif