#include "Monster.h"

// Initialize constructor using a initializer list
Monster::Monster(Position start, char glyph, std::string name) : position(start), glyph(glyph), name(std::move(name)) {}

Position Monster::getPosition() const
{
    return position;
}

char Monster::getGlyph() const
{
    return glyph;
}

const std::string& Monster::getName() const
{
    return name;
}

void Monster::setPosition(Position newPosition)
{
    position = newPosition;
}