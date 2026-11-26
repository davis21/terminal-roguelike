#include <catch2/catch_test_macros.hpp>
#include "Monster.h"

TEST_CASE("A new monster has the position, glyph, and name it was given", "[monster]")
{
    Monster goblin(Position{3, 2}, 'g', "goblin");

    CHECK(goblin.getPosition() == Position{3, 2});
    CHECK(goblin.getGlyph() == 'g');
    CHECK(goblin.getName() == "goblin");
}

TEST_CASE("setPosition moves the monster", "[monster]")
{
    Monster goblin(Position{3, 2}, 'g', "goblin");

    goblin.setPosition(Position{5, 4});

    REQUIRE(goblin.getPosition() == Position{5, 4});
}

TEST_CASE("Monsters keep their own state independently", "[monster]")
{
    Monster goblin(Position{1, 1}, 'g', "goblin");
    Monster orc(Position{2, 2}, 'o', "orc");

    goblin.setPosition(Position{4, 4});

    CHECK(goblin.getPosition() == Position{4, 4});
    CHECK(orc.getPosition() == Position{2, 2});
    CHECK(orc.getName() == "orc");
}