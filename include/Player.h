#pragma once

#include "Position.h"

class Player
{
private:
    Position playerPos;

public:
    // Constructor that takes the starting position of the player
    explicit Player(Position start);

    // Function that gets the position
    Position getPosition() const;

    // Function that sets the position
    void setPosition(Position position);
};