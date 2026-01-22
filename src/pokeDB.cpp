#include "pokeDB.hpp"
#include "pokemon.hpp"
#include "pokemontype.hpp"
#include "csv.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

PokeDB::PokeDB(std::string filename) {
    csv::CSVFormat format;
    format.delimiter(';')
          .no_header();

    csv::CSVReader reader(filename, format);
    for (auto& row : reader) {
        
        if (row.size() == 0) {
            continue;
        }

        if (row[0].is_null() || row[0].get<std::string>().empty()) {
            continue;
        }

        int number = row[0].get<int>();
        std::string name = row[1].get<std::string>();
        std::string typeColumn = row[2].get<std::string>();
        std::vector<PokemonType> types = parseTypes(typeColumn);
        add(Pokemon(name, types, number));
    
    }
}

void PokeDB::add(const Pokemon& newPokemon) {
    pokedb.push_back(newPokemon);
}

void PokeDB::listall() const {
    for (int i(0); i < (int)pokedb.size(); i++) {
        pokedb[i].print();
    }
}

const Pokemon& PokeDB::searchByName(const std::string& target) const {
    for (size_t i = 0; i < pokedb.size(); i++) {
        if (pokedb[i].getname() == target) {
            return pokedb[i];
        }
    }
    throw std::invalid_argument("Pokemon not found");
}

bool PokeDB::containsNumber(int pokedexNumber) const {
    for (int i(0); i < (int)pokedb.size(); i++) {
        if (pokedb[i].getnumber() == pokedexNumber) {
            return true;
        }
    }
    return false;
}

int PokeDB::sizedb() {
    return (int)pokedb.size();
}