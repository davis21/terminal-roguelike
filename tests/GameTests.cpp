#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include "Game.h"

namespace
{
    // A 5x5 map: walls around the border, floor inside.
    //   #####
    //   #...#
    //   #...#
    //   #...#
    //   #####
    Map makeRoomMap()
    {
        Map map(5, 5);
        for (int y = 1; y <= 3; ++y) {
            for (int x = 1; x <= 3; ++x) {
                map.setFloor(x, y);
            }
        }
        return map;
    }
}

TEST_CASE("The player starts at the given position", "[game]")
{
    Game game(makeRoomMap(), Position{2, 2});

    REQUIRE(game.getPlayer().getPosition() == Position{2, 2});
}

TEST_CASE("Moving into a floor tile succeeds and moves the player", "[game]")
{
    Game game(makeRoomMap(), Position{2, 2});

    bool moved = game.tryToMovePlayer(Direction::Up);

    REQUIRE(moved);
    REQUIRE(game.getPlayer().getPosition() == Position{2, 1});
}

TEST_CASE("Moving into a wall fails and the player stays put", "[game]")
{
    Game game(makeRoomMap(), Position{1, 1});

    bool moved = game.tryToMovePlayer(Direction::Left);   // (0, 1) is a wall

    REQUIRE_FALSE(moved);
    REQUIRE(game.getPlayer().getPosition() == Position{1, 1});
}

TEST_CASE("Moving off the edge of the map is blocked", "[game]")
{
    // A floor tile on the left edge, so the only thing stopping
    // the player is the edge of the map itself.
    Map map(5, 5);
    map.setFloor(0, 2);
    map.setFloor(1, 2);
    Game game(map, Position{0, 2});

    bool moved = game.tryToMovePlayer(Direction::Left);   // (-1, 2) is off the map

    REQUIRE_FALSE(moved);
    REQUIRE(game.getPlayer().getPosition() == Position{0, 2});
}

TEST_CASE("Several moves in a row follow the map", "[game]")
{
    Game game(makeRoomMap(), Position{1, 1});

    CHECK(game.tryToMovePlayer(Direction::Right));        // (2, 1)
    CHECK(game.tryToMovePlayer(Direction::Right));        // (3, 1)
    CHECK_FALSE(game.tryToMovePlayer(Direction::Right));  // (4, 1) is a wall
    CHECK(game.tryToMovePlayer(Direction::Down));         // (3, 2)

    REQUIRE(game.getPlayer().getPosition() == Position{3, 2});
}

TEST_CASE("Starting on a wall throws invalid_argument", "[game]")
{
    REQUIRE_THROWS_AS(Game(makeRoomMap(), Position{0, 0}), std::invalid_argument);
}

TEST_CASE("Starting outside the map throws out_of_range", "[game]")
{
    REQUIRE_THROWS_AS(Game(makeRoomMap(), Position{10, 10}), std::out_of_range);
}

TEST_CASE("getMap exposes the map the game was built with", "[game]")
{
    Game game(makeRoomMap(), Position{2, 2});

    CHECK(game.getMap().getWidth() == 5);
    CHECK(game.getMap().isWalkable(2, 2));
    CHECK_FALSE(game.getMap().isWalkable(0, 0));
}