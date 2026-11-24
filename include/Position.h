// This will be a small struct to hold a position in the map. It will have two integer members, x and y, to represent the coordinates of the position.
#pragma once

struct Position
{
    int x;
    int y;

    // Place it here, inside the struct
    bool operator==(const Position&) const = default; 
};

enum class Direction { Up, Down, Left, Right };

Position step(Position from, Direction dir);