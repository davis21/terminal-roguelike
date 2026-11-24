cmake_minimum_required(VERSION 3.20)
project(Roguelike LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(roguelike_core src/Map.cpp)
target_include_directories(roguelike_core PUBLIC include)
target_compile_options(roguelike_core PRIVATE -Wall -Wextra -Wpedantic)

add_executable(roguelike src/main.cpp)
target_link_libraries(roguelike PRIVATE roguelike_core)
target_compile_options(roguelike PRIVATE -Wall -Wextra -Wpedantic)

# ---- Tests ----
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.15.3
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(Catch2)

add_executable(roguelike_tests tests/MapTests.cpp)
target_link_libraries(roguelike_tests PRIVATE roguelike_core Catch2::Catch2WithMain)
target_compile_options(roguelike_tests PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
add_test(NAME map_tests COMMAND roguelike_tests)