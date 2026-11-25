#include <catch2/catch_test_macros.hpp>
#include "Input.h"

TEST_CASE("Movement keys map to movement commands", "[input]")
{
    CHECK(parseCommand('w') == Command::MoveUp);
    CHECK(parseCommand('a') == Command::MoveLeft);
    CHECK(parseCommand('s') == Command::MoveDown);
    CHECK(parseCommand('d') == Command::MoveRight);
}

TEST_CASE("q maps to Quit", "[input]")
{
    REQUIRE(parseCommand('q') == Command::Quit);
}

TEST_CASE("Uppercase keys work the same as lowercase", "[input]")
{
    CHECK(parseCommand('W') == Command::MoveUp);
    CHECK(parseCommand('A') == Command::MoveLeft);
    CHECK(parseCommand('S') == Command::MoveDown);
    CHECK(parseCommand('D') == Command::MoveRight);
    CHECK(parseCommand('Q') == Command::Quit);
}

TEST_CASE("Unrecognized keys return no command", "[input]")
{
    CHECK_FALSE(parseCommand('x').has_value());
    CHECK_FALSE(parseCommand('1').has_value());
    CHECK_FALSE(parseCommand(' ').has_value());
    CHECK_FALSE(parseCommand('\n').has_value());
}

TEST_CASE("Movement commands convert to directions", "[input]")
{
    CHECK(toDirection(Command::MoveUp) == Direction::Up);
    CHECK(toDirection(Command::MoveLeft) == Direction::Left);
    CHECK(toDirection(Command::MoveDown) == Direction::Down);
    CHECK(toDirection(Command::MoveRight) == Direction::Right);
}

TEST_CASE("Quit has no direction", "[input]")
{
    REQUIRE_FALSE(toDirection(Command::Quit).has_value());
}

TEST_CASE("A key can be followed all the way to a direction", "[input]")
{
    std::optional<Command> cmd = parseCommand('d');
    REQUIRE(cmd.has_value());

    std::optional<Direction> dir = toDirection(*cmd);

    REQUIRE(dir == Direction::Right);
}