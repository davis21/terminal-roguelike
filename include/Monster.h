#pragma once

#include "Position.h"
#include <string>

class Monster
{
private:
    Position position;
    char glyph;
    std::string name;

public:
    
    Monster(Position start, char glyph, std::string name);

    Position getPosition() const;

    char getGlyph() const;

    const std::string& getName() const;

    void setPosition(Position newPosition);
};