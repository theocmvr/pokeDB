enable_testing()

add_executable(
    pokedb_tests
    test_pokemon.cpp
    test_pokeDB.cpp
    test_pokemontype.cpp
)

target_link_libraries(
    pokedb_tests
    gtest
    gtest_main
    pokedb_lib
)

file(GLOB TEST_CSV_FILES
    ${PROJECT_SOURCE_DIR}/tests/*.csv
)

file(COPY ${TEST_CSV_FILES}
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


target_compile_definitions(
    pokedb_tests
    PRIVATE
        TEST_DATA_DIR="${CMAKE_CURRENT_BINARY_DIR}"
)

include(GoogleTest)
gtest_discover_tests(pokedb_tests)
