#include <catch2/catch_test_macros.hpp>
#include "Position.h"

TEST_CASE("Positions with the same coordinates are equal", "[position]")
{
    CHECK(Position{3, 2} == Position{3, 2});
    CHECK_FALSE(Position{3, 2} == Position{2, 3});
}

TEST_CASE("step moves up by decreasing y", "[position]")
{
    REQUIRE(step({5, 5}, Direction::Up) == Position{5, 4});
}

TEST_CASE("step moves down by increasing y", "[position]")
{
    REQUIRE(step({5, 5}, Direction::Down) == Position{5, 6});
}

TEST_CASE("step moves left by decreasing x", "[position]")
{
    REQUIRE(step({5, 5}, Direction::Left) == Position{4, 5});
}

TEST_CASE("step moves right by increasing x", "[position]")
{
    REQUIRE(step({5, 5}, Direction::Right) == Position{6, 5});
}

TEST_CASE("step does not modify the original position", "[position]")
{
    Position start{5, 5};

    Position moved = step(start, Direction::Up);

    REQUIRE(start == Position{5, 5});
    REQUIRE(moved == Position{5, 4});
}