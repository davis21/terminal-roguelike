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