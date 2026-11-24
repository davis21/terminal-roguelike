#include "Player.h"

Player::Player(Position start) : playerPos(start) {}

Position Player::getPosition() const
{
    return playerPos;
}

void Player::setPosition(Position position)
{
    playerPos = position;
}