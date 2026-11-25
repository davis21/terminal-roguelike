#include "Input.h"
#include <iostream>

std::optional<Command> parseCommand(char key)
{
    char input = static_cast<char>(std::tolower(static_cast<unsigned char>(key)));
    switch (input)
    {
        case 'w': return Command::MoveUp;
        case 'a': return Command::MoveLeft;
        case 's': return Command::MoveDown;
        case 'd': return Command::MoveRight;
        case 'q': return Command::Quit;
        default: return std::nullopt;
    }
}

std::optional<Direction> toDirection(Command cmd)
{
    switch (cmd)
    {
        case Command::MoveUp: return Direction::Up;
        case Command::MoveLeft: return Direction::Left;
        case Command::MoveDown: return Direction::Down;
        case Command::MoveRight: return Direction::Right;
        case Command::Quit: return std::nullopt;
        // No default: if a new Command is added, -Wswitch flags this switch
        // so we decide whether it maps to a direction.
    }

    return std::nullopt;
}