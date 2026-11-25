#include <catch2/catch_test_macros.hpp>
#include "Map.h"
#include <stdexcept>


TEST_CASE("A new map is entirely walls", "[map]")
{
    Map map(10, 5);                          // Arrange
    for (int y = 0; y < map.getHeight(); ++y) // Act
    {
        for (int x = 0; x < map.getWidth(); ++x)
        {
            REQUIRE(map.getTile({x, y}) == Tile::Wall); // Assert
        }
    }
}

// A new map has the width and height you gave it.
TEST_CASE("A new map has the correct dimensions", "[map]")
{
    Map map(10, 5); // Arrange
    REQUIRE(map.getWidth() == 10); // Assert
    REQUIRE(map.getHeight() == 5); // Assert
}

// setFloor makes a tile walkable.
TEST_CASE("setFloor makes a tile walkable", "[map]")
{
    Map map(10, 5); // Arrange
    map.setFloor({3, 2}); // Act
    REQUIRE(map.isWalkable({3, 2})); // Assert
}

// The non-square case: on a 10×5 map, setFloor(7, 2) sets getTile(7, 2) to Floor. This is the test that would have caught the [x][y] bug.
TEST_CASE("setFloor works on a non-square map", "[map]")
{
    Map map(10, 5); // Arrange
    map.setFloor({7, 2}); // Act
    REQUIRE(map.getTile({7, 2}) == Tile::Floor); // Assert
}

// inBounds at the edges: (0, 0) and (9, 4) are inside; (10, 0), (0, 5), and (-1, 0) are outside.
TEST_CASE("inBounds works at the edges", "[map]")
{
    Map map(10, 5); // Arrange
    REQUIRE(map.inBounds({0, 0})); // Assert
    REQUIRE(map.inBounds({9, 4})); // Assert
    REQUIRE_FALSE(map.inBounds({10, 0})); // Assert
    REQUIRE_FALSE(map.inBounds({0, 5})); // Assert
    REQUIRE_FALSE(map.inBounds({-1, 0})); // Assert
}

// Out-of-bounds positions: getTile returns Wall, isWalkable returns false, and setFloor doesn't crash.
TEST_CASE("Out-of-bounds positions", "[map]")
{
    Map map(10, 5); // Arrange
    REQUIRE(map.getTile({10, 0}) == Tile::Wall); // Assert
    REQUIRE_FALSE(map.isWalkable({10, 0})); // Assert
    REQUIRE_NOTHROW(map.setFloor({10, 0})); // Assert
}

// Invalid sizes throw. Look up REQUIRE_THROWS_AS. You'll need <stdexcept>, and should test both negative and zero sizes.
TEST_CASE("Invalid sizes throw", "[map]")
{
    REQUIRE_THROWS_AS(Map({-1, 5}), std::invalid_argument); // Assert
    REQUIRE_THROWS_AS(Map({10, 0}), std::invalid_argument); // Assert
}