#pragma once

#include <optional>
#include <Position.h>

enum class Command { MoveUp, MoveDown, MoveLeft, MoveRight, Quit };

// Translates a key press into a game command
std::optional<Command> parseCommand(char key);

// w/a/s/d = move, q = quit. Returns a std::nullopt for unrecognized keys
std::optional<Direction> toDirection(Command cmd);