#include "Game.h"

#include <stdexcept>

Game::Game(const Map& startMap, Position playerStart) : map(startMap), player(playerStart)
{
    // Check if the start position is inside the map
    if (!map.inBounds(playerStart))
        throw std::out_of_range("The starting point for the game is not in the map parameters.");

    // Check if the start tile is walkable
    if (!map.isWalkable(playerStart))
        throw std::invalid_argument("The starting point for the game is not walkable.");
}

bool Game::tryToMovePlayer(Direction dir)
{
    // Find where the player currently is
    Position startingPosition = player.getPosition();

    // Work out where they would end up
    Position newPosition = step(startingPosition, dir);

    // Decide if this is allowed
    if (map.isWalkable(newPosition))
    {
        player.setPosition(newPosition);
        return true;
    }
    return false;
}

const Map& Game::getMap() const
{
    return map;
}

const Player& Game::getPlayer() const
{
    return player;
}