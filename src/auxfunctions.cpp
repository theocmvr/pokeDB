#include<iostream>
#include "pokemon.hpp"
Pokemon getinfo(void) {
    std::string name;
    std::string type;
    int pokedex_number;
    std::cout << "Tell me their name, type, and pokedex number:" << std::endl;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Type: ";
    std::cin >> type;
    std::cout << "Pokedex number: ";
    std::cin >> pokedex_number;
    Pokemon current(name, type, pokedex_number);
    return current;
}