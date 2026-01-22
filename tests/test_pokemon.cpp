#include <gtest/gtest.h>
#include "pokemon.hpp"
#include <vector>
#include <string>

TEST(PokemonClassTest, ConstructorTest) {
    std::vector<PokemonType> types = {PokemonType::Grass, PokemonType::Poison};
    Pokemon p("Bulbasaur", types, 1);
    EXPECT_EQ(p.getname(), "Bulbasaur");
    EXPECT_EQ(p.getnumber(), 1);
    EXPECT_EQ(p.gettype().size(), 2);
    EXPECT_EQ(p.gettype(), types);
    EXPECT_THROW(
        Pokemon notype("Darkrai", {}, 1000),
        std::invalid_argument
    );
    EXPECT_THROW(
        Pokemon bignumber("Imanaginary", {PokemonType::Psychic}, 1026),
        std::invalid_argument
    );
}

TEST(PokemonClassTest, ValidationTest) {
    EXPECT_THROW(
        Pokemon p("", {PokemonType::Electric}, 1),
        std::invalid_argument
    );

    EXPECT_THROW(
        Pokemon p("Bulbasaur", {PokemonType::Grass}, -1),
        std::invalid_argument
    );

    EXPECT_THROW(
        Pokemon p("", {PokemonType::Fire}, -1),
        std::invalid_argument
    );
}