#include <gtest/gtest.h>
#include "pokemontype.hpp"

TEST(PokeTypeClassTest, StringToEnum) {
    EXPECT_EQ(stringtotype("Fire"), PokemonType::Fire);
    EXPECT_EQ(stringtotype("fIrE"), PokemonType::Fire);
    EXPECT_EQ(stringtotype("Grass"), PokemonType::Grass);
    EXPECT_EQ(stringtotype("gRaSs"), PokemonType::Grass);
    EXPECT_THROW(
        stringtotype(" Fire "),
        std::invalid_argument
    );
    EXPECT_THROW(
        stringtotype("F i r e"),
        std::invalid_argument
    );
    EXPECT_THROW(
        stringtotype(""),
        std::invalid_argument
    );
}

TEST(PokeTypeClassTest, EnumToString) {
    EXPECT_EQ(typetostring(PokemonType::Fire), "Fire");
    EXPECT_EQ(typetostring(PokemonType::Water), "Water");
    EXPECT_EQ(typetostring(PokemonType::Poison), "Poison");
    EXPECT_EQ(typetostring(PokemonType::Grass), "Grass");
}

TEST(PokeTypeClassTest, InvalidType) {
    EXPECT_THROW(
        stringtotype("Magic"),
        std::invalid_argument
    );

    EXPECT_THROW(
        stringtotype("Assassin"),
        std::invalid_argument
    );
}
