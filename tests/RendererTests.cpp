#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "Game.h"
#include "Map.h"
#include "Renderer.h"

namespace
{
    std::string renderToString(const Game& game)
    {
        std::ostringstream out;
        render(game, out);
        return out.str();
    }
}

TEST_CASE("Renderer draws walls, floors, and the player", "[renderer]")
{
    Game game(Map::fromLayout({
        "#####",
        "#...#",
        "#####",
    }), Position{2, 1});

    REQUIRE(renderToString(game) ==
        "#####\n"
        "#.@.#\n"
        "#####\n");
}

TEST_CASE("Renderer puts the player in the right row and column on a non-square map", "[renderer]")
{
    Game game(Map::fromLayout({
        "######",
        "#....#",
        "#....#",
        "######",
    }), Position{4, 2});

    REQUIRE(renderToString(game) ==
        "######\n"
        "#....#\n"
        "#...@#\n"
        "######\n");
}

TEST_CASE("Renderer shows the player's new position after a move", "[renderer]")
{
    Game game(Map::fromLayout({
        "#####",
        "#...#",
        "#####",
    }), Position{1, 1});

    game.tryToMovePlayer(Direction::Right);

    REQUIRE(renderToString(game) ==
        "#####\n"
        "#.@.#\n"
        "#####\n");
}