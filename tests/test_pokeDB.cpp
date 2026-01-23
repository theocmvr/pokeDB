#include <gtest/gtest.h>
#include "pokeDB.hpp"
#include <string>
#include <vector>

class PokeDBTest : public ::testing::Test {
    protected:
    std::string WorkingCSV, OneLineCSV;
    PokeDB db1, db3;
    void SetUp() override {
        WorkingCSV = std::string(TEST_DATA_DIR) + "/test_data.csv";
        OneLineCSV = std::string(TEST_DATA_DIR) + "/test_oneline.csv";
        db1 = PokeDB(WorkingCSV);
        db3 = PokeDB(OneLineCSV);
    }
};

TEST_F(PokeDBTest, CsvTest) {
    ASSERT_EQ(db1.sizedb(), 5);
    ASSERT_EQ(db3.sizedb(), 1);
}

TEST_F(PokeDBTest, SearchTest) {
    Pokemon correct("Charmander", {PokemonType::Fire}, 4);
    EXPECT_EQ(db1.searchByName("Charmander"), correct);
    ASSERT_EQ(db1.searchByName(db1.searchByName("Charmander").getname()), correct);
    EXPECT_THROW(
        db1.searchByName("Rengar"),
        std::invalid_argument
    );
}

TEST_F(PokeDBTest, ContainsNumberTest) {
    EXPECT_EQ(db1.containsNumber(-1), false);
    EXPECT_EQ(db1.containsNumber(6), false);
    EXPECT_EQ(db1.containsNumber(3), true);
}

TEST_F(PokeDBTest, ParseTypesTest) {
    std::vector<PokemonType> correct = {PokemonType::Fire, PokemonType::Grass};
    EXPECT_EQ(parseTypes("Fire,Grass"), correct);
    EXPECT_THROW(
        parseTypes("Fire Grass"),
        std::invalid_argument
    );
}

TEST_F(PokeDBTest, InvalidCsvTest) {
    std::string incorrectCSV = std::string(TEST_DATA_DIR) + "/test_incorrect.csv";
    EXPECT_ANY_THROW(
        PokeDB db(incorrectCSV)
    );
}

TEST_F(PokeDBTest, EmptyCSVTest) {
    std::string EmptyCSV = std::string(TEST_DATA_DIR) + "/test_empty.csv";
    PokeDB db2(EmptyCSV);
    ASSERT_EQ(db2.sizedb(), 0);
}
