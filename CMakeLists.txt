cmake_minimum_required(VERSION 3.16)

project(poke_db VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(imgui
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_tables.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    imgui
    imgui/backends
)

target_link_libraries(imgui PUBLIC
    glfw
    OpenGL::GL
)

add_library(core_lib
    src/pokemontype.cpp
    src/pokemon.cpp
    src/pokeDB.cpp
    src/pokeapp.cpp
)

target_include_directories(core_lib PUBLIC include)
target_compile_options(core_lib PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>)

add_library(gui_lib
    src/pokeGUI.cpp
)

target_include_directories(gui_lib PUBLIC include)
target_link_libraries(gui_lib PUBLIC core_lib imgui)

add_executable(poke_db src/main.cpp)

target_link_libraries(poke_db PRIVATE
    gui_lib
    core_lib
)

add_subdirectory(tests)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/data)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/pokemon_1.csv
    ${CMAKE_CURRENT_BINARY_DIR}/data/pokemon_1.csv
    COPYONLY
)
