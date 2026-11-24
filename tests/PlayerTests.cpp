#include <catch2/catch_test_macros.hpp>
#include "Player.h"

// A new player starts at the position given to the constructor.
TEST_CASE("A new player starts at the given position", "[player]")
{
    Player player(Position{3, 2});               // Arrange
    REQUIRE(player.getPosition() == Position{3, 2}); // Assert
}

// The constructor keeps x and y in the right order (catches a swapped-coordinate bug).
TEST_CASE("The constructor does not swap x and y", "[player]")
{
    Player player(Position{7, 1});                   // Arrange
    REQUIRE(player.getPosition().x == 7);            // Assert
    REQUIRE(player.getPosition().y == 1);            // Assert
}

// setPosition moves the player to the new position.
TEST_CASE("setPosition updates the player's position", "[player]")
{
    Player player(Position{0, 0});                   // Arrange
    player.setPosition(Position{4, 5});              // Act
    REQUIRE(player.getPosition() == Position{4, 5}); // Assert
}

// Calling setPosition more than once keeps only the latest position.
TEST_CASE("setPosition can be called repeatedly", "[player]")
{
    Player player(Position{0, 0});                   // Arrange
    player.setPosition(Position{1, 1});              // Act
    player.setPosition(Position{9, 3});              // Act
    REQUIRE(player.getPosition() == Position{9, 3}); // Assert
}

// Player and step work together: moving a player one tile in each direction.
TEST_CASE("A player can be moved with step", "[player]")
{
    Player player(Position{5, 5}); // Arrange

    SECTION("Up")
    {
        player.setPosition(step(player.getPosition(), Direction::Up)); // Act
        REQUIRE(player.getPosition() == Position{5, 4});               // Assert
    }
    SECTION("Down")
    {
        player.setPosition(step(player.getPosition(), Direction::Down)); // Act
        REQUIRE(player.getPosition() == Position{5, 6});                 // Assert
    }
    SECTION("Left")
    {
        player.setPosition(step(player.getPosition(), Direction::Left)); // Act
        REQUIRE(player.getPosition() == Position{4, 5});                 // Assert
    }
    SECTION("Right")
    {
        player.setPosition(step(player.getPosition(), Direction::Right)); // Act
        REQUIRE(player.getPosition() == Position{6, 5});                  // Assert
    }
}
